/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef user_profile_TYPES_H
#define user_profile_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>



namespace something {

typedef struct _UserProfile__isset {
  _UserProfile__isset() : uid(false), name(false), blurb(false) {}
  bool uid;
  bool name;
  bool blurb;
} _UserProfile__isset;

class UserProfile {
 public:

  static const char* ascii_fingerprint; // = "3368C2F81F2FEF71F11EDACDB2A3ECEF";
  static const uint8_t binary_fingerprint[16]; // = {0x33,0x68,0xC2,0xF8,0x1F,0x2F,0xEF,0x71,0xF1,0x1E,0xDA,0xCD,0xB2,0xA3,0xEC,0xEF};

  UserProfile() : uid(0), name(), blurb() {
  }

  virtual ~UserProfile() throw() {}

  int32_t uid;
  std::string name;
  std::string blurb;

  _UserProfile__isset __isset;

  void __set_uid(const int32_t val) {
    uid = val;
  }

  void __set_name(const std::string& val) {
    name = val;
  }

  void __set_blurb(const std::string& val) {
    blurb = val;
  }

  bool operator == (const UserProfile & rhs) const
  {
    if (!(uid == rhs.uid))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(blurb == rhs.blurb))
      return false;
    return true;
  }
  bool operator != (const UserProfile &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserProfile & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(UserProfile &a, UserProfile &b);

} // namespace

#endif
