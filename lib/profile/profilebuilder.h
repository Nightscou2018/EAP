// Copyright 2018 Rick van Schijndel

#ifndef LIB_PROFILE_PROFILEBUILDER_H_
#define LIB_PROFILE_PROFILEBUILDER_H_

namespace profile {
class ProfileBuilder {
 public:
  ProfileBuilder();
  int build();
  struct Profile getProfile();
 private:
};
};

#endif  // LIB_PROFILE_PROFILEBUILDER_H_
