#define _CRT_SECURE_NO_WARNINGS
#define SFML_NO_DEPRECATED_WARNINGS

#pragma once

#include <iostream>
#define SPACE 10
#include <fstream>
#include <cstdlib>
#include <ctime>
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
    node *getNode() // getting the address of the next node
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
    string command;
    string description;

    node *pNext;
};

class list
{
public:
    list()
    {
        node *pTemp;
        string command = "\0"; // take the entire line which will then be used to find the command and description
        string description =  "\0";

        listFile.open("comList.csv", ios::in);
        while (!listFile.eof())
        {
            pTemp = new node;
            getline(listFile, command, ',');
            getline(listFile, description, '\n');
            cout << command << endl;
            cout << description << endl;
            pTemp->setComDesc(command, description);
        }
    }

private:
    ifstream listFile;

    node *pHead;
};