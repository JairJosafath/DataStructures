#include <iostream>
#include "LinkedList/Node.h"
#include "LinkedList/LinkedList.h"

int main() {
auto list = new LinkedList<int>();
    for(int i=0;i<10;i+=2)
        list->addNode(i);
    std::cout<<"size"<<list->getSize()<<std::endl;
    list->printFromTail();
//    std::cout<<"size"<<list->getSize()<<std::endl;

//    list->addNodeAfter(list->getNodeAt(5),100);
//    list->getNodeAt(2)->print();
std::cout<<std::endl;
//std::cout<<"index: "<<list->getIndex(list->getNodeAt(3))<<std::endl;
//list->deleteNode(4);
//list->swapNodes(1,2);
    list->printFromTail();
    std::cout<<"size"<<list->getSize()<<std::endl;
    std::cout<<std::endl;

    list->deleteNode(list->getSize()-1);
    list->printFromTail();

    std::cout<<"size"<<list->getSize()<<std::endl;



    return 0;

}
