aux_source_directory(. SRC_LIST)
add_library(mprpc STATIC ${SRC_LIST})

target_link_libraries(mprpc pthread muduo_net muduo_base zookeeper_mt)

