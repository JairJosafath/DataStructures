cmake_minimum_required(VERSION 3.21)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

add_executable(DoublyLinkedList  LinkedList/Node.h LinkedList/LinkedList.h algorithms/merge/MergeSort.h Graph/Vertex.cpp Graph/Edge.cpp LinkedList/LLTest.cpp Graph/Graph.h)
add_executable(Stack Stack/Stack.h Stack/StackV2.h Stack/StackTest.cpp)
add_executable(Queue Queue/Queue.h Queue/QueueTest.cpp)
