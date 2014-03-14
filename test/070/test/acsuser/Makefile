BOOST_DIR = /usr/include/boost
THRIFT_DIR = /usr/local/thrift/include/thrift
#LIB_DIR = /usr/local/lib
LIB_DIR = /usr/local/thrift/lib/
GEN_SRC = ./gen-cpp/acsuser_types.cpp ./gen-cpp/acsuser_constants.cpp ./gen-cpp/UserService.cpp
default: server client
server: UserServer.cpp
	g++ -g -o UserServer -I${THRIFT_DIR} -I${BOOST_DIR}  -I./gen-cpp -L${LIB_DIR} -lthrift UserServer.cpp ${GEN_SRC}
client: UserClient.cpp
	g++ -g -o UserClient -lm -pthread -lz -lrt -lssl -I${THRIFT_DIR} -I${BOOST_DIR}  -I./gen-cpp -L${LIB_DIR} -lthrift UserClient.cpp ${GEN_SRC}
clean:
	$(RM) -r UserServer UserClient

