//
// Created by jairj on 1/9/2023.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H
// a stack with a fixed size

#include <iostream>

template <typename T>
class Stack{
    int size=0;
    bool isEmpty=true;
    //how we keep track of where we pop or push
    int head=0;
    T *array;
public:


    Stack(int size,T array[]){
        this->size=size;
        this->array=array;
        head=0;
        isEmpty=false;
    }

    int push(T val){
        array[(head--)-1]=val;
        isEmpty=false;
        ++size;
    }

    T top(){

        if(isEmpty) {
            std::cout<<"stack isEmpty"<<std::endl;
            try{
                return array[head];
            }
            catch (std::exception e) {
                std::cout<<e.what();
            }
        };
        return array[head];
    }

    T pop(){
        if(isEmpty) {
            std::cout<<"stack isEmpty"<<std::endl;
            try{
                return array[head];
            }
            catch (std::exception e) {
                std::cout<<e.what();
            }
        };

        --size;
        if(!size) isEmpty=true;
        return array[head++];
    }


    void print(){
        std::cout<<"array"<<std::endl;
        for(int i=0;i<head+size;i++)
            (i==head)
            ?   std::cout<<array[i]<<"<--head"<<std::endl
        :
        std::cout<<array[i]<<std::endl;
    }
};

#endif //DATASTRUCTURES_STACK_H
