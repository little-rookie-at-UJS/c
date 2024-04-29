cmake_minimum_required(VERSION 3.28)
project(c__)

set(CMAKE_CXX_STANDARD 23)

add_executable(cdc main.cpp)
add_executable(t t.cpp)
add_executable(dp dp.cpp)
add_executable(gen gen.cpp)


add_executable(D jscpc2021/D.cpp)
add_executable(MD ICPC/yinchuan2020/MD.cpp)
add_executable(A jscpc2021/A.cpp)
add_executable(H jscpc2021/H.cpp)

add_executable(I jscpc2021/I.cpp)
add_executable(J jscpc2021/J.cpp)
add_executable(JJ jscpc2021/JJ.cpp)
add_executable(C jscpc2021/C.cpp)
