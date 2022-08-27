cmake_minimum_required(VERSION 3.0.2)
project(json_samples)

include_directories(include/rapidjson/include) ## add

find_package(catkin REQUIRED)

catkin_package(
)

## add
add_executable(main src/main.cpp) 
target_link_libraries(main 
)

add_executable(main2 src/main2.cpp) 
target_link_libraries(main2
)
