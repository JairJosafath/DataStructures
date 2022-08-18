cmake_minimum_required(VERSION 3.21)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoublyLinkedList main.cpp LinkedList/Node.h LinkedList/LinkedList.h)
