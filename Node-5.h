//*******************************************************************************************************
//
//        File:                   Node.h
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
//        This file define the functions used in the main.cpp
//
//        Other files required:
//        1. Node.h
//        2. LLQueue.h
//        3. Cashier.h
//        4. Customer.h
//        5. customerList.txt
//
//*******************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*******************************************************************************************************

template <typename T>
class Node
{
public:
    T data;
    Node<T> *prev;
    Node<T> *next;
    Node<T>();
    Node(const T&, Node<T> *n = nullptr, Node<T> *p = nullptr);
};

//*******************************************************************************************************

template <typename T>
Node<T>::Node()
{
    data = 0;
    next = nullptr;
    prev = nullptr;
}

//*******************************************************************************************************

template <typename T>
Node<T>::Node(const T &d, Node<T> *n, Node<T> *p)
{
    data = d;
    next = n;
    prev = p;
}

//*******************************************************************************************************

#endif /* Node_h */
