/* ************************************************************************
Name: David Boyd
Assignment: 03, Doubly Linked List
Purpose: Main program - source file
Notes: none.
Completed: 2018.10.27
************************************************************************ */
#include "main.h"
#include "Functions.h"

int main(int argc, char** argv) {

    // validate main arguments
    if (!verify(argc, argv)){ return 0; }

    // Declare size of list
    int sizeOfList = atoi(argv[1]);

    std::cout<<"Your Random Numbers Created and Listed in sorted order is :\n";
    List *lst = new List(sizeOfList);
    lst->printList(lst->headptr);

    int key;
    std::cout<<"\n\nEnter a key to delete from linked list\n";
    std::cin>>key;
    lst->deleteNode(lst->headptr,key);
    std::cout<<"\nThe above key is deleted and listed below \n";
    lst->printList(lst->headptr);

    std::cout<<"\n\nDeleting the head of the Linked list \n";
    lst->deleteHeadNode(lst->headptr);
    std::cout<<"\nThe head is deleted and listed below \n";
    lst->printList(lst->headptr);

    std::cout<<"\n\nDeleting the tail of the Linked list \n";
    lst->deleteTailNode(lst->headptr);
    std::cout<<"\nThe tail is deleted and listed below \n";
    lst->printList(lst->headptr);

    std::cout<<"\n\nDeleting the Middle Object/Node of the Linked list \n";
    lst->deleteMiddleNode(lst->headptr);
    std::cout<<"\nThe Middle Node is deleted and listed below \n";
    lst->printList(lst->headptr);

    return 0;
}

