struct User{
 1: string uid,
 2: string uname,
 3: bool usex,
 4: i16 uage,
 5: list<i32> subNodeList,
 6: map<i32,string> subNodeMap,
 7: set<i32> subNodeSet
}
service UserService{
 void add(1: User u),
 void addlist(1: list<User> u),
 User get(1: string uid),
}

