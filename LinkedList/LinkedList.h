//
// Created by jairj on 8/16/2022.
//

#ifndef DOUBLYLINKEDLIST_LINKEDLIST_H
#define DOUBLYLINKEDLIST_LINKEDLIST_H

#include <cmath>
#include "iostream"

template <typename T>
class LinkedList{
    //the first node in the list is the head
    Node<T>* head= nullptr;
    //the last node in the list is the tail *not mandatory
    Node<T>* tail= nullptr;
    //the size of the list *not mandatory
    int size=0;

public:
    int addNode(T val){
        //check if the list has values
        // could be done by checking the size, but since not all LL require size,so the size will not be used for the check
        //store the address if the head exists, in pointer p
        auto p=head;
        if(p){
            //if the list has at least one value, execute this scope
            while(p->getNext()){
                //if p is not the last node, go to the next node
                p=p->getNext();
            }
            //create the new node and set it as the current node's next node
            p->setNext(new Node<T>(val));
            //set the newly added node's previous to the current node, p
            p->getNext()->setPrev(p);
            //update the tail data
            tail=p->getNext();
            //update the size
            size++;
            return 1;
        }
        //the list is empty so the value goes in the first node which is the head
        head = new Node<T>(val);
        tail=head;
        //update size
        size=1;

        return 1;
    }

    int addNodeAfter(Node<T>* node,T val){
        auto p = head;
        int index=0;
        while(p!=node){
            //find the node that equals the given node
            p=p->getNext();
            index++;
        }
        if(p){
            return addAtIndex(index+1,val);
        }
        return 0;
    };
    int addNodeBefore(Node<T>* node,T val){
        auto p = head;
        int index=0;
        while(p!=node){
            //find the node that equals the given node
               p=p->getNext();
               index++;
        }
        if(p){
            return addAtIndex(index,val);
        }
        return 0;
    };
    int addAtIndex(int index,T value){
        auto p= head;
        int i=0;
        if(index==size){
            //this means insert as tail
            return addNodeAsTail(value);
        }
        if(size<index+1||index<0)return 0;
        if(index==0){
            //this means insert as head
            return addNodeAsHead(value);
        }

        while(p->getNext()){
            //go through the list until you reach the i-th node
            if(i==index)break;
            i++;
            p=p->getNext();
        }
        auto q= new Node<T>(value);
        //add q between p and it's prev
        q->setPrev(p->getPrev());
        q->setNext(p);
        q->getPrev()->setNext(q);
        size++;
        return 1;
    }
    int addNodeAsHead(T val){
        auto p = new Node<T>(val);
        if(head){
     //the list has values
            head->setPrev(p);
            p->setNext(head);
            head=p;
            size++;
            return 1;
        }
        //the list is empty
        head=p;
        tail=p;
        size++;
        return 1;
    };
    int addNodeAsTail(T val){
        auto p = new Node<T>(val);
        if(tail){
            //the list has values
            tail->setNext(p);
            p->setPrev(tail);
            tail=p;
            size++;
            return 1;
        }
        //the list is empty
        head=p;
        tail=p;
        size++;
        return 1;
    };

    int swapNodes(int index1,int index2){
        auto p= getNodeAt(index1);
        auto q= getNodeAt(index2);

        auto temp = new Node<T>();
        temp->setPrev(p->getPrev());
        temp->setNext(p->getNext());

        auto tempQ=new Node<T>();
        tempQ->setPrev(q->getPrev());
        tempQ->setNext(q->getNext());
        //check if nodes are next to each other
        const int d = index1-index2;
        if(d==-1){
            //check if node is the head
            if(p->getPrev())
                p->getPrev()->setNext(q);
            else
                head=q;
            q->setPrev(p->getPrev());
            q->setNext(p);
            if(tempQ->getPrev())
                tempQ->getPrev()->setNext(p);
            p->setNext(tempQ->getNext());
            p->setPrev(tempQ->getPrev());
            if(!q->getNext())
                tail=p;
            if(!p->getNext())
                tail=q;
            return 1;
        }
        if(d==1){
            //check if node is the head
            if(q->getPrev())
                q->getPrev()->setNext(p);
            else
                head=p;
            p->setPrev(q->getPrev());

            p->setNext(q);
            if(temp->getPrev())
            temp->getPrev()->setNext(q);
            q->setNext(temp->getNext());
            q->setPrev(temp->getPrev());
            if(!p->getNext())
                tail=q;
            return 1;
        }

        p->setPrev(q->getPrev());
        p->setNext(q->getNext());

        if(q->getPrev())
            q->getPrev()->setNext(p);
        else
            head=p;

        if(q->getNext())
            q->getNext()->setPrev(p);
        else
            tail=p;

        q->setPrev(temp->getPrev());
        q->setNext(temp->getNext());

        if(temp->getPrev())
            temp->getPrev()->setNext(q);
        else
            head=q;
        if(temp->getNext())
            temp->getNext()->setPrev(q);
        else
            tail=q;


        return 1;
    };
    int swapNodes(Node<T>* val1,Node<T>* val2){
        return swapNodes(getIndex(val1), getIndex(val2));
    };
int deleteNode(int index){
    if(size==0||index>size-1)return 0;
    if(size==1&&index==0){head=tail= nullptr;return 0;}
    if(index==0){
        head->getNext()->setPrev(nullptr);
        head=head->getNext();
        size--;
        return 1;
    }
    if(index==size-1){
        tail->getPrev()->setNext(nullptr);
        tail=tail->getPrev();
        size--;
        return 1;
    }
    auto p= getNodeAt(index);
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    delete p;
    p= nullptr;
    size--;
    return 1;
};
int deleteNode(Node<T>* node){
    return deleteNode(getIndex(node));
};
    Node<T>* getNodeAt(int index){
        auto p=head;
        int i=0;
        while(p->getNext()){
            if(i==index)break;
            i++;
            p=p->getNext();
        }
        return p;
    }
    int getIndex(Node<T>* node){
        auto p=head;
        int index=0;
        while(p!=node){
            index++;
            p=p->getNext();
        }
        if(p) return index;
        return 0;
    }

    //getters and setters and prints
    Node<T> *getHead() const {
        return head;
    }

    void setHead(Node<T> *head) {
        LinkedList::head = head;
    }

    Node<T> *getTail() const {
        return tail;
    }

    void setTail(Node<T> *tail) {
        LinkedList::tail = tail;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        LinkedList::size = size;
    }

    void print(){
        auto p=head;
        while(p) {
            std::cout << "[ " << p->getValue() << " ]" << std::endl;
            p = p->getNext();
        }
    }

    void print(int index){
        std::cout<<getNodeAt(index)->getValue()<<std::endl;
    }
};

#endif //DOUBLYLINKEDLIST_LINKEDLIST_H
