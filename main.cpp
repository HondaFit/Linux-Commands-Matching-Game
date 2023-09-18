#include "header.hpp"

int main()
{
    /*
    ADVANTAGES/DISADVANTAGES LINKED LIST

    One big advantage of using a Single Linked List that you can essentially have buddle of data linked to each other.
    Compared to using a vector or array, you can only store 1 data type. Linked Lists are good for this very reason. One 
    good usecase of this, is a phone book. A linked list can store a list of people's name, phone #, address, and etc. 
    Without it, you would need multiple arrays for each data set and you need the exact order and size to make sure everyone 
    is aligned 
    
    One big disadvantage of using a Single Linked Array is Sorting/Finding a node. For a single linked list, we have to go from 
    left to right to find what we're looking for. On the other hand, we can go to any index in the array 
    */


   /*
   ADVANTAGES/DISADVANTAGES ARRAY

    One advantage of array is simplicity. For simple one data type lists, arrays are the best for this reason. It can be sorted and found
    in a relativly quick manner. Another plus is able to navigate through the array (left and right)

    One BIG disadvantage is the lack of editing. If you need to insert a value in the middle of the node, we have to move everything to the
    left of it by 1. Same goes for deleteting and sorting. Some arrays also are static in size which can be limiting somtimes
   
   */

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    list<string,string> linkedList;
    
    linkedList.menu();

    return 0;
}