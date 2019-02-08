#include <future>
#include <iostream>
#include <chrono>

using namespace std;

bool counter(int x) {
  for(int i = 0; i < x; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    cout << ".";
    cout.flush();
  }
  cout << "done!" << endl;
  return true;
}

int main(int argc, const char *argv[]) {

  future<bool> fut = std::async(launch::async, counter, 100);
  bool x = fut.get();
  return 0;
}
