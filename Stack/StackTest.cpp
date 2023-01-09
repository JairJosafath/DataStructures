//
// Created by jairj on 1/9/2023.
//

#include "Stack.h"

int main(){
    int *array=new int[7]{3,4,5,6,12,14,20};
    auto stack = new Stack<int>(7,array);
    stack->print();
    std::cout<<"---------"<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    std::cout<<stack->pop()<<std::endl;
    stack->print();
    stack->push(700);
    stack->push(78);
    stack->push(870);
    stack->print();
}