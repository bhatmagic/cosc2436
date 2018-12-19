/* ************************************************************************
Name: David Boyd
Assignment: 04, Stacks
Purpose: Main program.
Notes: None.
Completed: 2018.10.04
************************************************************************ */
#include "main.h"
#include "stack.h"

int main(int argc, char** argv)
{
    Stack mystack;

    // declare pointers
    DATA *newData1 = new DATA;
    DATA *newData2 = new DATA;
    DATA *newData3 = new DATA;
    DATA *newData4 = new DATA;
    DATA *newData5 = new DATA;
    DATA *newData6 = new DATA;
    DATA *newData7 = new DATA;

    // declare pointers
    DATA *peakData;
    DATA *popData;

    // initialize pointer->id
    newData1->data_ = "My Array 1.";
    newData2->data_ = "My Array 2.";
    newData3->data_ = "My Array 3.";
    newData4->data_ = "My Array 4.";
    newData5->data_ = "My Array 5.";
    newData6->data_ = "My Array 6.";
    newData7->data_ = "My Array 7.";

    // push data_
    mystack.push(newData1);
    mystack.push(newData2);
    mystack.push(newData3);
    mystack.push(newData4);
    mystack.push(newData5);
    mystack.push(newData6);

    std::cout << "Testing if Stack if is Full...\n";
    if (mystack.is_full()) {
        std::cout << "Stack is full\n";
    } else {
        std::cout << "Stack is not full\n";
    }

    std::cout<<"\nClearing Stack..\n";
    mystack.clear();

    std::cout << "\nTesting if Stack is Empty...\n";
    if (mystack.is_empty()){
        std::cout << "Stack is empty\n";
    } else {
        std::cout << "Stack is not empty\n";
    }

    std::cout << "\nTesting Random push and pop...\n";
    mystack.push(newData5);
    mystack.push(newData6);

    // pop stack and return ptr DATA as ptr popData
    popData = mystack.pop();
    std::cout << "id_: " << popData->id_ << ", Data: " << popData->data_ << std::endl;

    mystack.push(newData3);
    mystack.push(newData7);

    popData = mystack.pop();

    std::cout << "id_: " << popData->id_ << ", Data: " << popData->data_ << std::endl;
    std::cout << "\nTesting peak...\n";

    // find top and return ptr DATA as ptr peakData
    peakData = mystack.peak();

    std::cout << "id: " << peakData->id_ << ", Data: " << peakData->data_ << std::endl;

    std::cout << "\nClosing Program.....\n\n";

    return 0;
}