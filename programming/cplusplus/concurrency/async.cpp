#include <future>
#include <iostream>
#include <unistd.h>

using namespace std;

void printStuff() {
  cout << "1" << endl;
  cout << "2" << endl;
  cout << "3" << endl;
  cout << "4" << endl;
}

int main( int argc, const char *argv[] )
{

  async(launch::async, printStuff);
  async(launch::async, printStuff);
  async(launch::async, printStuff);
  async(launch::async, printStuff);
  async(launch::async, printStuff);

  sleep(2);

  return 0;
}
