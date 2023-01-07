//
// Created by jairj on 9/2/2022.
//

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main() {
    auto  list= new LinkedList<int>();
    list->addNode(1);
    list->addNode(7);
    list->addNode(700);
//    list->addNodeAfter(list->getHead(),233);
    list->addNode(-12);
    list->addNode(-1);
    list->addNode(8);
//    list->printFromTail();
//    std::cout<<"====="<<std::endl;
    list->print();    std::cout<<"====="<<std::endl;

    list->deleteNode(1);
    list->print(); std::cout<<"====="<<std::endl;  list->printFromTail();

//list->getNodeAt(2)->print();


    delete list;
    return 0;
}
