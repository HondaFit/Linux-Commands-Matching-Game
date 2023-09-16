#define _CRT_SECURE_NO_WARNINGS
#define SFML_NO_DEPRECATED_WARNINGS

#pragma once

#include <iostream>
#define SPACE 10
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout; // we can now use cout without explicitly writing std::cout
using std::endl;
using std::fstream;
using std::getline;
using std::ifstream;
using std::ios;
using std::localtime;
using std::ofstream;
using std::put_time;
using std::string;
using std::toupper;
using std::vector;

using std::stoi;

template<typename T1, typename T2>
class node
{
public:
    node() // defualt constructor
    {
        command = '\0';
        description = '\0';
        pNext = NULL;
    }
    node(node *next, string uCommand, string uDescription)
    {
        pNext = next;
        command = uCommand;
        description = uDescription;
    }
    ~node()
    {
    }

    void setNext(node *next) // setting the address of the next node
    {
        pNext = next;
    }
    node *getNext() // getting the address of the next node
    {
        return pNext;
    }

    void setComDesc(string uCommand, string uDescription) // setting the command and the description of current node
    {
        command = uCommand;
        description = uDescription;
    }

    string getCom() // getting command
    {
        return command;
    }
    string getDesc() // getting description
    {
        return description;
    }

private:
    T1 command;
    T2 description;

    node *pNext;
};



template<typename T1, typename T2>
class list
{
public:
    list()
    {
        node<T1,T2> *pTemp;
        string command = "\0"; // take the entire line which will then be used to find the command and description
        string description = "\0";
        listFile.open("comList.csv", ios::in);
        while (!listFile.eof())
        {
            /*pTemp = new node;
            getline(listFile, command, ',');
            getline(listFile, description, '\n');
            //cout << command << endl;
            //cout << description << endl;
            pTemp->setComDesc(command, description);

            if (pHead == NULL) // is the list empty?
            {
                pHead = pTemp;
                pCurrent = pHead;
            }
            else
            {
                pCurrent->setNext(pTemp);
                pCurrent = pTemp;
            }*/
            pTemp = new node<T1,T2>;
            getline(listFile, command, ',');
            getline(listFile, description, '\n');

            pTemp->setComDesc(command, description); //assigning command and desciption to the new node

            if(pHead != NULL) // If head is not empty 
            {
                pTemp->setNext(pHead);
                pHead = pTemp;
            }
            else // if head is empty 
            {
            pHead = pTemp;

            }
        
        
        }
    }

   void readList()
   {
    node<T1,T2> *pCurrent =pHead;
    while(pCurrent != NULL)
    {
        cout << pCurrent->getCom()<<","<<pCurrent->getDesc()<<endl;
        pCurrent = pCurrent->getNext();
    }
   }

    void game()
    {
        int exit = false;
        while (exit == false)
        {
           
            switch (menuSelection())
            {
            case 1:
                //system("CLS");
                cout << "Selected Game Rules" << endl;
                break;

            case 2:
                //system("CLS");
                cout << "Selected Play Game" << endl;
                break;

            case 3:
                //system("CLS");
                cout << "Selected Load Previous Game" << endl;
                break;

            case 4:
                //system("CLS");
                cout << "Selected Add Command" << endl;
                break;

            case 5:
                //system("CLS");
                cout << "Selected Remove Command" << endl;
                break;

            case 6:
                //system("CLS");
                cout << "Selected Exit Game" << endl;
                exit = true;
                break;
            }
        }
    }

private:
    ifstream listFile;

    vector<int> profiles;

    node<T1,T2> *pHead = NULL;
    node<T1,T2> *pCurrent = NULL;

     int menuSelection()
    {
        char dummy;
        int correctInput = false;
        string choice;
        while (correctInput != true)
        {
            cout << "Please select an option listed below:" << endl;
            cout << "1) Game Rules" << endl;
            cout << "2) Play Game" << endl;
            cout << "3) Load Previuos Game" << endl;
            cout << "4) Add Command" << endl;
            cout << "5) Remove Command" << endl;
            cout << "6) Exit" << endl;
            cin >> choice;

            if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
            {
                cout << "incorrect input try again" << endl;
                cout << "Press any key to continue" << endl;
                cin >> dummy;
                system("clear");
            }
            else
            {
                correctInput = true;
            }
        }
        return stoi(choice);
    }



};
