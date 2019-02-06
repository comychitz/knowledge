#include <mutex>
#include <vector>
#include <string>
#include <thread>
#include <future>
#include <condition_variable>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sstream>

using namespace std;

static int popCount = 0;

class Queue {
  public:
    Queue() { }

    ~Queue() { }

    void push(const string &str) {
      unique_lock<mutex> lck(lock_);
      q_.push_back(str);
      cout << "PUSH: " << str << endl;
      cond_.notify_all();
    }

    string pop() {
      unique_lock<mutex> lck(lock_);
      while (q_.empty()) {
        if(cond_.wait_for(lck, std::chrono::seconds(3))==std::cv_status::timeout) {
          cout << "TIMED-OUT WAITING FOR DATA" << endl;
          return "";
        }
      }
      string str = *(q_.begin());
      q_.erase(q_.begin());
      cout << "POP: " << str << endl;
      popCount++;
      return str;
    }

  private:
    mutex lock_;
    condition_variable cond_;
    vector<string> q_;
};

Queue q;

static void addItems() {
  int r = rand() % 500;
  for(int i = 0; i < r; i++) {
    std::stringstream ss;
    ss << rand()%100;
    q.push(ss.str());
  }
}


static void removeItems() {
  while(!q.pop().empty()) {
    usleep(1);
  }
}

int main(int argc, const char *argv[]) {

  srand (time(NULL));

  std::thread t1(addItems);
  std::thread t2(addItems);
  std::thread t3(removeItems);
  std::thread t4(removeItems);

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  cout << "TOTAL POP COUNT: " << popCount << endl;

  return 0;
}
