//
// Created by jairj on 9/2/2022.
//

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main() {
    auto  list= new LinkedList<int>();
    std::cout<<"Doubly Linked List"<<std::endl;
    std::cout<<"adding nodes 0 till 9"<<std::endl;
    for(int i=0;i<10;i++) list->addNode(i);
    list->print();
    std::cout<<"delete nodes at i = 0, at i=3"<<std::endl;
    list->deleteNode(0);
    list->print();
    list->deleteNode(3);
    list->print();
    std::cout<<"add node 34, before i = 4"<<std::endl;
    list->addNodeBefore(list->getNodeAt(4),34);
    list->print();
    std::cout<<"swap nodes i=3 and tail, node i=6 and head, node i=2 and i=5"<<std::endl;
    list->swapNodes2(3,list->getSize()-1);
    list->print();
    list->swapNodes2(6,0);
    list->print();
    list->swapNodes2(2,5);
    list->print();
    std::cout<<"0<-E<=>N<=>D->0"<<std::endl;



    delete list;
    return 0;
}
