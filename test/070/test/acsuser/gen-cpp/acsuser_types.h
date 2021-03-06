/**
 * Autogenerated by Thrift Compiler (0.7.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef acsuser_TYPES_H
#define acsuser_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>





typedef struct _User__isset {
  _User__isset() : uid(false), uname(false), usex(false), uage(false) {}
  bool uid;
  bool uname;
  bool usex;
  bool uage;
} _User__isset;

class User {
 public:

  static const char* ascii_fingerprint; // = "E48A6B2623C488281E3E50E5732AA7A0";
  static const uint8_t binary_fingerprint[16]; // = {0xE4,0x8A,0x6B,0x26,0x23,0xC4,0x88,0x28,0x1E,0x3E,0x50,0xE5,0x73,0x2A,0xA7,0xA0};

  User() : uid(""), uname(""), usex(0), uage(0) {
  }

  virtual ~User() throw() {}

  std::string uid;
  std::string uname;
  bool usex;
  int16_t uage;

  _User__isset __isset;

  void __set_uid(const std::string& val) {
    uid = val;
  }

  void __set_uname(const std::string& val) {
    uname = val;
  }

  void __set_usex(const bool val) {
    usex = val;
  }

  void __set_uage(const int16_t val) {
    uage = val;
  }

  bool operator == (const User & rhs) const
  {
    if (!(uid == rhs.uid))
      return false;
    if (!(uname == rhs.uname))
      return false;
    if (!(usex == rhs.usex))
      return false;
    if (!(uage == rhs.uage))
      return false;
    return true;
  }
  bool operator != (const User &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const User & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};



#endif
