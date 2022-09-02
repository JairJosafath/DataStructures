cmake_minimum_required(VERSION 3.21)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoublyLinkedList  LinkedList/Node.h LinkedList/LinkedList.h algorithms/merge/MergeSort.h Graph/Vertex.cpp Graph/Edge.cpp LinkedList/LLTest.cpp)
