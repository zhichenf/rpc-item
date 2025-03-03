# set(SRC_LIST call_user_service.cc ../public/user.pb.cc)
set(SRC_LIST call_friend_service.cc ../public/friend.pb.cc)
add_executable(caller ${SRC_LIST})

target_link_libraries(caller mprpc protobuf) 