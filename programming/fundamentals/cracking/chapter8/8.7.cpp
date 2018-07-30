#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Explain how you would design a chat server. In particular, provide details
 * about the various backend components, classes, and methods. What would be the
 * hardest problem to solve?
 *
 * Hardest problem to solve is potentially load balancing?
 *
 */

class ChatRoom
{
  public:
    Chatroom(const User &admin);

    std::string name() const;

    bool addUser(const User &user);

  private:
    std::set<std::string> users_; // names of users
    std::queue<std::string> msgs_;
};

class MsgDispatcher
{
  public:

};

class ChatServer
{
  public:

  private:
    std::map<std::string,User> users_;
    std::vector<ChatRoom> rooms_;
};


int main(int argc, const char *argv[])
{

  
  return 0;
}
