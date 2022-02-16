//*******************************************************************************************************
//
//        File:                   Cashier.h
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
//        3. main.cpp
//        4. Customer.h
//        5. customerList.txt
//
//*******************************************************************************************************

#ifndef CASHIER_H
#define CASHIER_H

//*******************************************************************************************************

struct Cashier
{
    int custId,
        endTime;
    bool busy;
    Cashier();
};

//*******************************************************************************************************

Cashier::Cashier()
{
    custId = 0;
    endTime = 0;
    busy = false;
}

//*******************************************************************************************************

#endif
