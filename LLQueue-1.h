//*******************************************************************************************************
//
//        File:                   LLQueue.h
//
//        Student:                Lexi Corniello
//
//        Assignment:             Asssignment #11
//
//        Course Name:            Data Structures I
//
//        Course Number:          COSC 3050-10
//
//        Due:                    December 10th, 2021
//
//        Defines a Queue ADT
//
//        Other files required:
//        1. Node.h
//        2. main.cpp
//        3. Cashier.h
//        4. Customer.h
//        5. customerList.txt
//
//*******************************************************************************************************

#ifndef LLQUEUE_H
#define LLQUEUE_H
#include <new>
using namespace std;
#include "Node.h"

//*******************************************************************************************************

template <typename T>
class Queue

{
private:
    Node<T> *front;
    Node<T> *back;
    
public:
    Queue();
    ~Queue();
    bool enqueue(const T & );
    bool dequeue(T & );
    bool viewFront(T & )const;
    bool viewBack(T & )const;
    bool isEmpty()const;
    bool isFull()const;
    int getsize()const;
};

//*******************************************************************************************************

template <typename T>
Queue<T>::Queue()
{
    front = nullptr;
    back = nullptr;
}

//*******************************************************************************************************

template <typename T>
Queue<T>::~Queue() 
{
    Node<T> *pTemp;
    
    while(front != nullptr)
    {
        pTemp = front;
        front = front -> next;
        delete pTemp;
    }
    back = nullptr;
}

//*******************************************************************************************************

template <typename T>
bool Queue<T>::enqueue(const T & dataIn)
{
    bool success = false;
    Node<T> *pNew = new(nothrow)Node<T>(dataIn);

        if (pNew != nullptr)
            {
                if(back == nullptr)
                    front = pNew;
                    
                else
                    back -> next = pNew;
            success = true;
            back = pNew;
            }
        return success;
    }

//*******************************************************************************************************

template <typename T>
bool Queue<T>::dequeue(T & dataOut)
{
    Node<T> *pFront = front;
    bool success = false;

    if(front != nullptr)
    {
        if (front == back)
            back = nullptr;
        
        dataOut = front -> data;
        front = pFront -> next;
        delete pFront;
        success = true;
    }

    return success;
}

//*******************************************************************************************************

template <typename T>
bool Queue<T>::viewFront(T & dataOut) const
{
    bool success = false;
    
    if(front != nullptr)
    {
        dataOut = front -> data;
        success = true;
    }
    
    return success;
}

//*******************************************************************************************************

template <typename T>
bool Queue<T>::viewBack(T & dataOut)const
{
    bool success = false;
    
    if(back != nullptr)
    {
        dataOut = back -> data;
        success = true;
    }
    
    return success;
}

//*******************************************************************************************************

template <typename T>
bool Queue<T>::isEmpty()const
{
    return front == nullptr;
}

//*******************************************************************************************************

template <typename T>
bool Queue<T>::isFull()const
{
    bool success = false;
    
    Queue<T> *pNew = new(nothrow) Queue<T>;

    if(pNew != nullptr)
    {
        success = true;
        delete pNew;
    }
    return success;
}

//*******************************************************************************************************

template <typename T>
int Queue<T>::getsize()const
{
    bool success = false;
    
    Node<T> *pTemp = front;
    int count = 0;
    
    while(pTemp != nullptr)
    {
        count++;
        pTemp = pTemp->next;
        success = true;
    }
    return count;
}

//*******************************************************************************************************

#endif /* LLQueue_h */
