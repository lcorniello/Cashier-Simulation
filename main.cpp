//*******************************************************************************************************
//
//        File:                   main.cpp
//
//        Student:                Lexi Corniello
//
//        Assignment:             Asssignment #12
//
//        Course Name:            Data Structures I
//
//        Course Number:          COSC 3050-10
//
//        Due:                    December 10th, 2021
//
//        This file executes the given functions in the header/text file to calculate the results
//
//        Other files required:
//        1. Node.h
//        2. LLQueue.h
//        3. Cashier.h
//        4. Customer.h
//
//*******************************************************************************************************

#include <iostream>
#include <fstream>
using namespace std;
#include "Customer.h"
#include "Cashier.h"
#include "LLQueue.h"

//*******************************************************************************************************

void fillServer(Queue <Customer> custQ[], Cashier cs[], int time);
int getMinQ (Queue <Customer> custQ[], Cashier cs[]);
void processCashier(Queue <Customer> custQ[], Cashier cs[], int time);
bool isDone(Queue<Customer> custQ[], Cashier cs[]);

//*******************************************************************************************************

int main()
{
    int time = 0,
        i;
    Queue<Customer> custQ[3];
    Cashier cs[i];
    
    fillServer(custQ, cs, time);
    
    return 0;
}

//*******************************************************************************************************

void fillServer(Queue <Customer> custQ[], Cashier cs[], int time)
{
    int next = 0,
        i = 0,
        count = 0;
    
    ifstream myfile("customerList.txt");
    Customer arr[50];
    
    if (myfile.fail())
    {
        cout << "failed to open" << endl;
    }
    else
    {
        while (myfile >> arr[count].Id >> arr[count].arrivalTime >> arr[count].serviceTime)
            {
                count++;
            }
        while ((!isDone(custQ, cs)) || i < count)
            {
                cout << "t = " << time << endl;
                    
                while (arr[i].arrivalTime == time)
                {
                    next = getMinQ(custQ, cs);
                    custQ[next].enqueue(arr[i]);
                    cout << "Cust# " << arr[i].Id << " added to the Q" << next + 1 << endl;
                    i++;
                }
        processCashier(custQ, cs, time);
        time++;
        cout << endl;
            }
        myfile.close();
    }
    cout << "All Customers processed in " << time - 1 << " minutes" << endl;

}

//*******************************************************************************************************

int getMinQ(Queue <Customer> custQ[], Cashier cs[])
{
    int smallest,
        size[3] = {0};
    
    for(int i = 0; i < 3; i++)
    {
        size[i] = custQ[i].getsize();
        
        if(cs[i].busy)
        {
            size[i] += 1;
        }
    }
    smallest = size[0];
    int shortestQueue = 0;
    
    for(int i = 1; i < 3; i++)
    {
        if(size[i] < smallest)
        {
            smallest = size[i];
            shortestQueue = i;
        }
    }
    
    return shortestQueue;
}

//*******************************************************************************************************

void processCashier(Queue <Customer> custQ[], Cashier cs[], int time)
{
    Customer cu;
 
    for(int i = 0; i < 3; i++)
     {
             if (!cs[i].busy || cs[i].endTime == time)
                {
                    if (custQ[i].dequeue(cu))
                        {
                            cs[i].custId = cu.Id;
                            cs[i].endTime = time + cu.serviceTime;
                            cs[i].busy = true;
                            cout << "Cashier #" << i << " start serving cust #" << cs[i].custId <<
                            ", service length = " << cu.serviceTime << ", Service ends at t = "
                            << cs[i].endTime << endl;
                        }
                    else
                        {
                            cs[i].busy = false;
                            cout << "Cashier #" << i << " not busy" << endl;
                        }
                }
                    else
                        {
                            cout << "Cashier #" << i << " serving cust #" << cs[i].custId << " until t = "
                            << cs[i].endTime << endl;
                        }
        }
}

//*******************************************************************************************************

bool isDone(Queue<Customer> custQ[], Cashier cs[])
{
    bool success = true;
    
    for(int i = 0; i < 3; i++)
    {
        if(!custQ[i].isEmpty() || cs[i].busy)
            success = false;
        //else
            //cout << "All Customers processed in 16 minutes" << endl;
    }

    return success;
}

//*******************************************************************************************************
//SAMPLE OUTPUT:
/*
t = 0
Cust# 1 added to the Q1
Cust# 2 added to the Q2
Cashier #0 start serving cust #1, service length = 15, Service ends at t = 15
Cashier #1 start serving cust #2, service length = 3, Service ends at t = 3
Cashier #2 not busy

t = 1
Cust# 3 added to the Q3
Cashier #0 serving cust #1 until t = 15
Cashier #1 serving cust #2 until t = 3
Cashier #2 start serving cust #3, service length = 2, Service ends at t = 3

t = 2
Cashier #0 serving cust #1 until t = 15
Cashier #1 serving cust #2 until t = 3
Cashier #2 serving cust #3 until t = 3

t = 3
Cust# 4 added to the Q1
Cust# 5 added to the Q2
Cashier #0 serving cust #1 until t = 15
Cashier #1 start serving cust #5, service length = 4, Service ends at t = 7
Cashier #2 not busy

t = 4
Cashier #0 serving cust #1 until t = 15
Cashier #1 serving cust #5 until t = 7
Cashier #2 not busy

t = 5
Cashier #0 serving cust #1 until t = 15
Cashier #1 serving cust #5 until t = 7
Cashier #2 not busy

t = 6
Cashier #0 serving cust #1 until t = 15
Cashier #1 serving cust #5 until t = 7
Cashier #2 not busy

t = 7
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 8
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 9
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 10
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 11
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 12
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 13
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 14
Cashier #0 serving cust #1 until t = 15
Cashier #1 not busy
Cashier #2 not busy

t = 15
Cashier #0 start serving cust #4, service length = 1, Service ends at t = 16
Cashier #1 not busy
Cashier #2 not busy

t = 16
Cashier #0 not busy
Cashier #1 not busy
Cashier #2 not busy

All Customers processed in 16 minutes
Program ended with exit code: 0
*/
//*******************************************************************************************************
