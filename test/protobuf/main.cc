#include <iostream>
#include <string>

#include "test.pb.h"

void test1() {
     //封装了login请求对象的数据
     fixbug::LoginRequest req;
     req.set_name("zhang san");
     req.set_pwd("123");
 
     //对象数据序列化为 string
     std::string send_str = "";
     if (req.SerializeToString(&send_str)) {
         std::cout << send_str << std::endl;
     }
 
     //反序列化
     fixbug::LoginRequest reqB;
     if (reqB.ParseFromString(send_str)) {
         std::cout << reqB.name() << std::endl;
         std::cout << reqB.pwd() << std::endl;
     }
}

void test2() {
    fixbug::LoginResponse rsp1;
    fixbug::ResultCode *rc1 = rsp1.mutable_result();
    rc1->set_errcode(1);
    rc1->set_errmsg("failed");

    fixbug::GetFriendListsResponse rsp;
    fixbug::ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(0);
    fixbug::User* user1 = rsp.add_friend_list();
    user1->set_name("lisi");
    user1->set_age(20);
    user1->set_sex(fixbug::User::MAN);

    fixbug::User* user2 = rsp.add_friend_list();
    user2->set_name("wang wu");
    user2->set_age(21);
    user2->set_sex(fixbug::User::WOMAN);
 
    
    std::cout << "num" << rsp.friend_list_size() << std::endl;
}

int main() {
    test2();

    return 0;
}