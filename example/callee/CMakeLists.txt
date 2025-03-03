#set(SRC_LIST user_service.cc ../public/user.pb.cc)
set(SRC_LIST friend_service.cc ../public/friend.pb.cc)
add_executable(provider ${SRC_LIST})

target_link_libraries(provider mprpc protobuf) 