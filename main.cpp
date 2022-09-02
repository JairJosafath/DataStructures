#include <iostream>
#include "LinkedList/Node.h"
#include "LinkedList/LinkedList.h"
#include "algorithms/merge/MergeSort.h"



int main() {
     auto  list= new LinkedList<int>();

    list->addNode(1);
    list->addNode(78);
    list->addNode(7);
    list->addNode(700);
    list->addNode(-12);
    list->print();
    list->mergeSort(list->getSize(),list);
    return 0;
}
