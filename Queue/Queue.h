//
// Created by jairj on 1/9/2023.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H
// a queue with a fixed size

#include <iostream>
//I need to add pointers that know when to loop back when they reach start/end of the array
template <typename T>
class Queue{
    int size=0;
    bool isEmpty=true;
    //how we keep track of where we enqueue or dequeue
    int head=0;
    int tail=0;
    T *array;
public:


    Queue(int size,T array[]){
        this->size=size;
        this->array=array;
        head=size-1;
        tail=0;
        isEmpty=false;
    }

    int enqueue(T val){
        array[(tail--)-1]=val;
        isEmpty=false;
        ++size;
    }

    T front(){

        if(isEmpty) {
            std::cout<<"stack isEmpty"<<std::endl;
            try{
                return array[tail];
            }
            catch (std::exception e) {
                std::cout<<e.what();
            }
        };
        return array[tail];
    }

    T dequeue(){
        if(isEmpty) {
            std::cout<<"stack isEmpty"<<std::endl;
            try{
                return array[tail];
            }
            catch (std::exception e) {
                std::cout<<e.what();
            }
        };

        --size;
        if(!size) isEmpty=true;
        return array[head--];
    }


    void print(){
        if(size){
            std::cout<<"array"<<std::endl;

            for(int i=tail;i<=tail+size;i++)
                (i==head)
                ?   std::cout<<array[i]<<"<--head"<<std::endl
                :(i==tail)
                ?std::cout<<array[i]<<"<--tail"<<std::endl
                :std::cout<<array[i]<<std::endl;
        }else{
            std::cout<<"queue is empty"<<std::endl;

        }

    }

};


#endif //DATASTRUCTURES_QUEUE_H
