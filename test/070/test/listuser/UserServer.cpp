#include "UserService.h"
#include <vector>
#include <config.h>
//#include <protocol/TBinaryProtocol.h>
#include <protocol/TCompactProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>
#include <concurrency/ThreadManager.h>
#include <concurrency/PosixThreadFactory.h>
#include <server/TThreadPoolServer.h>
#include <server/TThreadedServer.h>
using namespace std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency; 

using boost::shared_ptr;

class UserServiceHandler : virtual public UserServiceIf {
 public:
  UserServiceHandler() {
    // Your initialization goes here
  }

  void add(const User& u) {
    // Your implementation goes here
    printf("uid=%s uname=%s usex=%d uage=%d\n", u.uid.c_str(), u.uname.c_str(), u.usex, u.uage);
    printf("add\n");
  }
  //void addlist(const std::vector<User, std::allocator<User> > & u) {
  void addlist(const std::vector<User> & u) {
    std::vector<User>::const_iterator iter;
    for(iter=u.begin();iter!=u.end();iter++) {
      printf("u size: %d\n",u.size());
      printf("send 1: %s, %s\n",(*iter).uid.c_str(),(*iter).uname.c_str());
    }    
    //User rect;
    //rect.uid="ning";
    //rect.uname="haohao";
    //rect.usex=0;
    //rect.uage=3;
    //u.push_back(rect);
    //for(int x = 0; x < 5; x++)
    //{
      //  u.push_back(new User());
    //}
    //std::vector<User, std::allocator<User>>::iterator it=u.begin();
    //for(it=u.begin();it!=u.end();it++){
    //    std::cout<<"test"<<std::endl;
       // cout<<(*it).id<<endl;
     //   printf("addlist---\n");
   // }   
    printf("addlist---\n");
  }
 // void addlist(const std::Vector<User>& vec) {
 //   std::vector<User>::iterator it=vec.begin();
 //   for(it=vec.begin();it!=vec.end();it++){
 //      // cout<<"test"<<endl;
 //     //  std::cout<<"addlist:"<<(*it).uid<<std::endl;
 //     printf("addlist id --%s\n",(*it).uid,c_str()); 
 //   } 
 //   printf("addlist ---------\n");
 // }

  void get(User& _return, const std::string& uid) {
// Your implementation goes here  
    _return.uid = "tinghaode";  
    _return.uname = "ningge";  
    _return.usex = 1;  
    _return.uage = 3;  
    printf("uid=%s uname=%s usex=%d uage=%d\n", _return.uid.c_str(), _return.uname.c_str(), _return.usex, _return.uage);  
    printf("get\n");
  }

};

int main(int argc, char **argv) {
  shared_ptr<UserServiceHandler> handler(new UserServiceHandler());
  shared_ptr<TProcessor> processor(new UserServiceProcessor(handler));
  shared_ptr<TProtocolFactory> protocolFactory(new TCompactProtocolFactory());
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(9090));

  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(10);
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();
  printf("start user server...\n");

  TThreadPoolServer server(processor, serverTransport, transportFactory, protocolFactory, threadManager);
  server.serve();
  return 0;
}

