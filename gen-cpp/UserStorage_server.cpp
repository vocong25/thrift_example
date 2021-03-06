// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "UserStorage.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

using namespace ::something;

class UserStorageHandler : virtual public UserStorageIf
{
  public:
    UserStorageHandler()
    {
        // Your initialization goes here
    }

    void store(const UserProfile &user)
    {
        // Your implementation goes here
        printf("store %s - %s - %d\n", user.name.c_str(), user.blurb.c_str(), user.uid);
    }

    void retrieve(UserProfile &_return, const int32_t uid)
    {
        // Your implementation goes here
        printf("retrieve\n");
    }
};

int main(int argc, char **argv)
{

    shared_ptr<UserStorageHandler> handler(new UserStorageHandler());
    shared_ptr<TProcessor> processor(new UserStorageProcessor(handler));
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    // using thread pool with maximum 15 threads to handle incoming requests
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    TNonblockingServer server(processor, protocolFactory, 9090, threadManager);
    server.serve();

    // The following demonstrates the use of thrift's ThreadPoolServe
    //int port = 9090;
    //   shared_ptr<UserStorageHandler> handler(new UserStorageHandler());
    //   shared_ptr<TProcessor> processor(new UserStorageProcessor(handler));
    //   //shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    //   shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    //   shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    //   shared_ptr<ThreadManager> threadManager =  ThreadManager::newSimpleThreadManager(4);
    //   shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    //   threadManager->threadFactory(threadFactory);
    //   threadManager->start();
    //    TNonblockingServer server(processor, protocolFactory, port, threadManager);
    //   //TThreadPoolServer server(processor, serverTransport, transportFactory, protocolFactory, threadManager);
    //   //TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    //   server.serve();
    return 0;
}
