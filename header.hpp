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
#include <cstring>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <random>

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

template <typename T1, typename T2>
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

template <typename T1, typename T2>
class list
{
public:
    list()
    {
        loadCommands();
        loadProfiles();
        totalCount = countList();
        // system("clear");
    }

    int readList()
    {
        int count = 1;
        node<T1, T2> *pCurrent = pHead;
        while (pCurrent != NULL)
        {
            cout << count << ") " << pCurrent->getCom() << "," << pCurrent->getDesc() << endl;
            pCurrent = pCurrent->getNext();
            count++;
        }
        return count;
    }
    int countList()
    {
        int count = 1;
        node<T1, T2> *pCurrent = pHead;
        while (pCurrent->getNext() != NULL)
        {
            // cout << count << ") " << pCurrent->getCom() << "," << pCurrent->getDesc() << endl;
            pCurrent = pCurrent->getNext();
            count++;
        }
        return count;
    }

    void menu() // MAIN FUNCTION
    {
        int exit = false;
        while (exit == false)
        {

            switch (menuSelection())
            {
            case 1: // done
                system("clear");
                cout << "Selected Game Rules" << endl;
                displayRules();
                break;

            case 2:
                system("clear");
                cout << "Selected Play Game" << endl;
                game();
                break;

            case 3:
                system("clear"); // done
                cout << "Selected Load Previous Game" << endl;
                selectProfile();
                break;

            case 4:
                system("clear"); // done
                cout << "Selected Add Command" << endl;
                addCommand();
                break;

            case 5:
                system("clear"); // done
                cout << "Selected Remove Command" << endl;
                removeCommand();
                break;

            case 6:
                system("clear");
                cout << "Selected Exit Game" << endl;
                exit = true;
                break;
            }
        }
    }

    void game()
    {

        bool exit = false;
        int randCommand = 0;
        char dummy;
        while (profiles[currentProfile - 1] <= 30 || exit == false)
        {
            randCommand = generateRandomNumber(totalCount);
            // cout << randCommand << endl;
            comFinder(randCommand);
            problemMaker(randCommand);
            if (answerQuestion() == true)
            {
                cout << "\nCorrect, You got the Answer Correct! You get a Point!" << endl;
                profiles[currentProfile - 1]++;
            }
            else
            {
                cout << "\nIncorrect, You got the Answer Wrong. Minus 1 Point" << endl;
                profiles[currentProfile - 1]--;
            }
            cout << "Press any key to continue" << endl;
            cin >> dummy;
            system("clear");
        }
    }

    int generateRandomNumber(int max)
    {
        return (std::rand() % max) + 1;
    }

private:
    ifstream listFile;
    ifstream playerFile;
    ifstream ruleFile;

    vector<int> profiles;
    int currentProfile = 1; // does not give score but index of the vector profiles indicating who is curretnly playing

    node<T1, T2> *pHead = NULL;
    node<T1, T2> *pCurrent = NULL;

    int totalCount;
    vector<string> possibleAnswer;
    string correctCommand;
    string correctDescription;

    void loadCommands()
    {
        node<T1, T2> *pTemp;
        string command = "\0"; // take the entire line which will then be used to find the command and description
        string description = "\0";
        listFile.open("comList.csv", ios::in);
        while (!listFile.eof())
        {
            pTemp = new node<T1, T2>;
            getline(listFile, command, ',');
            getline(listFile, description, '\n');

            pTemp->setComDesc(command, description); // assigning command and desciption to the new node

            if (pHead != NULL) // If head is not empty
            {
                pTemp->setNext(pHead);
                pHead = pTemp;
            }
            else // if head is empty
            {
                pHead = pTemp;
            }
        }
        listFile.close();
    }
    void loadProfiles()
    {
        int currentProfile = 0;
        playerFile.open("profiles.csv", ios::in);
        while (!playerFile.eof())
        {
            playerFile >> currentProfile;
            profiles.push_back(currentProfile);
        }
        playerFile.close();
    }

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
                cout << "\nincorrect input try again" << endl;
                cout << "Press any key to continue";
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

    void displayRules()
    {
        string line;
        char dummy;
        ruleFile.open("rules.txt", ios::in);
        while (!ruleFile.eof())
        {
            getline(ruleFile, line);
            cout << line << endl;
        }
        ruleFile.close();
        cout << "\npress any key to continue: ";
        cin >> dummy;
        system("clear");
    }

    void selectProfile()
    {
        string userInput;
        int exit = false;
        char dummy;

        while (exit == false)
        {
            int profileIndex = profiles.size(); // shows how many players are there
            for (int i = 1; i <= profileIndex; i++)
            {
                cout << "Player " << i << "    Score: " << profiles[i - 1] << endl;
            }

            cout << "Select a Player by their Number: ";
            cin >> userInput;

            if (digitChecker(userInput) == true)
            {
                if (stoi(userInput) >= 1 && stoi(userInput) <= profileIndex)
                {
                    exit = true;
                }
                else
                {
                    cout << "\nInvalid Selection, Press any key to continue ";
                    cin >> dummy;
                    system("clear");
                }
            }
            else
            {
                cout << "\nInvalid Selection, Press any key to continue ";
                cin >> dummy;
                system("clear");
            }
        }
        currentProfile = stoi(userInput) - 1;
        system("clear");
    }

    void addCommand()
    {
        char dummy;
        int exit = false;
        string command;
        string description;

        while (exit == false)
        {
            cout << "Type in a new command (no space at end): " << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, command);
            if (command[command.length() - 1] == ' ')
            {
                cout << "\nYou have a space at the end of your command. Retype it" << endl;
                cout << "Press any key to continue  ";
                cin >> dummy;
                system("clear");
            }
            else
            {
                exit = true;
            }
        }
        exit = false;

        while (exit == false)
        {
            cout << "Type in a descroption of your new command (no space in the front): ";
            // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, description);
            if (description[0] == ' ')
            {
                cout << "\nYou have a space at the front of your description. Retype it" << endl;
                cout << "Press any key to continue  ";
                cin >> dummy;
                system("clear");
            }
            else
            {
                exit = true;
            }
        }

        node<T1, T2> *pTemp;
        pTemp = new node<T1, T2>;
        pTemp->setComDesc(command, description); // assigning command and desciption to the new node

        if (pHead != NULL) // If head is not empty
        {
            pTemp->setNext(pHead);
            pHead = pTemp;
        }
        else // if head is empty
        {
            pHead = pTemp;
        }

        cout << "Press any key to continue";
        cin >> dummy;
        system("clear");
    }
    void removeCommand()
    {
        char dummy;
        string userInput;
        int count;
        int exit = false;

        while (exit == false)
        {
            count = readList();
            cout << "\nSelect a Command you want to Delete" << endl;
            cin >> userInput;

            if (digitChecker(userInput) == true)
            {
                if (stoi(userInput) >= 1 && stoi(userInput) <= count)
                {
                    exit = true;
                }
                else
                {
                    cout << "\nInvalid Selection, Press any key to continue ";
                    cin >> dummy;
                    system("clear");
                }
            }
            else
            {
                cout << "\nInvalid Selection, Press any key to continue ";
                cin >> dummy;
                system("clear");
            }
        }

        totalCount = count;
        count = stoi(userInput); // repurposing count. It is now the "index" that needs to be deleted

        node<T1, T2> *pPrev;
        node<T1, T2> *pCurrent;
        if (count == 1) // needs to be deleted at the head
        {
            pCurrent = pHead; // acting as a temp pointer
            pHead = pHead->getNext();
            delete pCurrent;
        }
        else if (count == totalCount) // if we need to delete at the end of the list
        {
            while (pCurrent->getNext() != NULL)
            {
                pCurrent = pCurrent->getNext();
            }
            delete pCurrent->getNext();
            pCurrent->setNext(NULL);
        }
        else
        {
            pPrev = pHead;
            pCurrent = pHead->getNext();
            for (int i = 2; i < count; i++)
            {
                pPrev = pCurrent;
                pCurrent = pCurrent->getNext();
            }

            pPrev->setNext(pCurrent->getNext());
            delete pCurrent;
        }

        system("clear");
        totalCount = countList();
    }

    bool digitChecker(string userInput) // checkin gif user typed in anything other than numbers
    {
        bool isAlpha = false;
        for (long unsigned int i = 0; i < userInput.length(); i++)
        {
            if (isalpha(userInput[i]))
            {
                isAlpha = true;
            }
        }
        if (isAlpha == true)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void comFinder(int number)
    {
        node<T1, T2> *pCurrent = pHead;
        for (int i = 1; i < number; i++)
        {
            pCurrent = pCurrent->getNext();
        }
        
        if(pCurrent != NULL)
        {
    correctCommand = pCurrent->getCom();
        correctDescription = pCurrent->getDesc();
        }
        else
        {
            cout << "comFinder pCurrent is NULL!" << endl;
        }

        // cout << pCurrent->getCom() << endl;
    }

    string descFinder(int desc)
    {

        node<T1, T2> *pCurrent = pHead;
        for (int i = 1; i < desc; i++)
        {
            pCurrent = pCurrent->getNext();
        }

        if(pCurrent !=NULL)
        {
        return pCurrent->getDesc();
        }
        else
        {
            cout << "descFinder pCurrent is NULL   " <<desc << endl;
            return NULL;
        }
    }

    void problemMaker(int cAnswer)
    {

        int randomDesc;   // what desc we're trying to find
        int descLocation; // where in the array it wil be stored

        possibleAnswer.push_back(""); // making an array of strings
        possibleAnswer.push_back("");
        possibleAnswer.push_back("");
        possibleAnswer.push_back("");

        descLocation = generateRandomNumber(4);
        possibleAnswer[descLocation - 1] = descFinder(cAnswer); // taking the correct answer and putting it somehwere in the arrray

        for (int i = 0; i < 3; i++) // make the possible answers. This will include 3 wrong answers and 1 correct answer
        {
            randomDesc = generateRandomNumber(totalCount);

            while (!possibleAnswer[descLocation - 1].empty()) // looking for an empty spot in the array
            {
                descLocation = generateRandomNumber(4);
            }
            possibleAnswer[descLocation - 1] = descFinder(randomDesc);
        }

        /*for (int i = 0; i < 4; i++)
        {
            cout << i + 1 << ") " << possibleAnswer[i] << endl;
        }*/
    }
    void problemPrinter()
    {

        for (int i = 0; i < 4; i++)
        {
            cout << i + 1 << ") " << possibleAnswer[i] << endl;
        }
    }
    bool answerQuestion()
    {
        char dummy;
        string userInput;
        int exit = false;

        while (exit == false)
        {
            cout << "Current Points for Player " << currentProfile << ": " << profiles[currentProfile - 1] << endl;
            cout << "Problem: What is the Description that best fits the Command: " << correctCommand << endl;
            problemPrinter();
            cout << "\nSelect your Description ";
            cin >> userInput;

            if (digitChecker(userInput) == true)
            {
                if (stoi(userInput) >= 1 && stoi(userInput) <= 4)
                {
                    exit = true;
                }
                else
                {
                    cout << "\nInvalid Selection, Press any key to continue ";
                    cin >> dummy;
                    system("clear");
                }
            }
            else
            {
                cout << "\nInvalid Selection, Press any key to continue ";
                cin >> dummy;
                system("clear");
            }
        }

        int selection = stoi(userInput);

        node<T1, T2> *pCurrent = pHead;
        while (pCurrent != NULL && pCurrent->getDesc() != possibleAnswer[selection - 1])
        {
            pCurrent = pCurrent->getNext();
        }
        if (pCurrent != NULL && pCurrent->getDesc() == correctDescription)
        {
            possibleAnswer.clear();
            correctCommand.clear();
            correctDescription.clear();
            return true;
        }
        else
        {
            possibleAnswer.clear();
            correctCommand.clear();
            correctDescription.clear();
            return false;
        }
    }
};
