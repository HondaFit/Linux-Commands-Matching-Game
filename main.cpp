#include "header.hpp"

int main()
{

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    list<string,string> linkedList;
    

    //linkedList.readList(); //used for viewing linked list

    //linkedList.menu();
    linkedList.menu();

    cout << "done" << endl;
    cout << "hello world"<<endl;
    return 0;
}