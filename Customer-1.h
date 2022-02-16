//*******************************************************************************************************
//
//        File:                   Customer.h
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
//        this program defines customer ADT
//
//        Other files required:
//        1. Node.h
//        2. LLQueue.h
//        3. main.cpp
//        4. Cashier.h
//        5. customerList.txt
//
//*******************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

//*******************************************************************************************************

struct Customer
{
    int Id;
    int arrivalTime;
    int serviceTime;
    Customer();
};

//*******************************************************************************************************

Customer::Customer()
{
    Id = 0;
    arrivalTime = 0;
    serviceTime = 0;
}

//*******************************************************************************************************

#endif
