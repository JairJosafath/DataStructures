//
// Created by jairj on 8/16/2022.
//


#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H

#include "iostream"

template <typename T>
class Node{
    //the actual data of the value the node holds
    T value;
    //pointers to the previous node and the next node
    Node<T>* prev= nullptr;
    Node<T>* next= nullptr;
public:

    //basic constructor to create a node
    Node(T val){
        this->value=val;
    }
    Node(){};
    //getters and setters and print outs for testing
    T getValue() const {
        return value;
    }

    void setValue(T value) {
        Node::value = value;
    }

    Node<T> *getPrev() const {
        return prev;
    }

    void setPrev(Node<T> *prev) {
        Node::prev = prev;
    }

    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }

    void print(){
        std::cout<<"[ "<<value<<" ]"<<std::endl;

    };
    void printFull(){
        std::cout<<"[ prev:"<<prev->value<<"]"<<"[ "<<value<<" ]"<<"[ next:"<<next->value<<"]"<<std::endl;

    };
};

#endif //DOUBLYLINKEDLIST_NODE_H
