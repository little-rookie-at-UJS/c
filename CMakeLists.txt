cmake_minimum_required(VERSION 3.28)
project(c__)

set(CMAKE_CXX_STANDARD 23)

add_executable(cdc main.cpp)
add_executable(t t.cpp)
add_executable(dp dp.cpp)
add_executable(gen gen.cpp)


add_executable(D ICPC/taipei2021/D.cpp)
add_executable(MD ICPC/yinchuan2020/MD.cpp)
add_executable(A ICPC/yinchuan2020/A.cpp)
add_executable(H ICPC/yinchuan2020/H.cpp)