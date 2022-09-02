//
// Created by jairj on 9/2/2022.
//

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

int main() {
    auto  list= new LinkedList<int>();
    list->addNode(1);
    list->addNodeBefore(list->getHead(),233);
    list->addNode(7);
    list->addNode(700);
    list->addNodeAsHead(-12);
    list->swapNodes(0,list->getSize()-1);
    list->print();
    delete list;
    return 0;
}
