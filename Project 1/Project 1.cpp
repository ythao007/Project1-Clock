// Project One
// Author: Yeng Thao
// 9/15/2022

#include "Clock.h"
#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

bool validateMenuChoice(int value, int min, int max) {

    if ((value >= min) || (value <= max)) { // If the value is less than or equal to min
        return true;                        // Or greater than or eqaul to max, return true
    }
    else {
        return false;  // Otherwise, return false
    }

    return false;
}

void handleInvalidInput(int min, int max) {  // Outputs invalid message if user input is out of range

    if ((min < 1) || (max > 4)) { // User inputs must between 1 and 4
        cout << "Invalid input. Pick from the menu." << endl;
    }
}

string border(size_t n, char c) { // Creates a row of characters for a border
    char ch = '*'; // Character I want as the border
    string length(n, ch); // String varible for number of said characters

    cout << length; // Outputs the string

    return length; // Returns the string to be output
}

void printMainMenu() { // Display the main menu
    cout << border(11, '*') << endl; // Top border
    cout << "* Main Menu          *" << endl;
    cout << "* 1 - Display Clock  *" << endl;        // Menu options with side borders
    cout << "* 2 - Update Clock   *" << endl;
    cout << "* 3 - Exit Program   *" << endl;
    cout << border(11, '*') << endl; // Bottom border
}

void printMenu() { // Display the update clock menu
    cout << endl;
    cout << border(11, '*') << endl;  // Top border
    cout << "* Update CLock       *" << endl;
    cout << "* 1 - Add One Hour   *" << endl;       // Update menu options with side borders
    cout << "* 2 - Add One Minute *" << endl;
    cout << "* 3 - Add One Second *" << endl;
    cout << "* 4 - Exit Program   *" << endl;
    cout << border(11, '*') << endl; // Bottom border
}


void printClock(Clock clock) { //Display the clocks
    cout << border(18, '*') << endl; // Top border
    cout << "* 12-Hour Clock " << " *" << "  24-Hour Clock  *" << endl;
    cout << "*  " << clock.get12HourFormat() << "   *"; // Time formats with side and middle borders
    cout << "     " <<clock.get24HourFormat() << "    *" << endl;
    cout << border(18, '*') << endl; // Bottom border
}



int main()
{
    printMainMenu(); //Display main menu for start

    int userInput;

    cin >> userInput; //Get user input to validate

    //Create the clock instance
    Clock clock(0, 0, 0);

    while (validateMenuChoice(userInput, 1, 3) == true) { // While loop to go through main menu while true
        system("cls"); //Clear the console screen

        printClock(clock); //Display the clock times

        if (userInput == 1) { // prints the clock, add a second and clear screen if 1 is choosen
            clock.addSecond();
        }
        else if (userInput == 2) {  // prints the update menu if 2 is choosen
            do { // Do-while loop to go through printMenu options while true
                printMenu(); // Display menu options for update clock
                int userInput1;

                cin >> userInput1; // Gets user input
            
                if (userInput1 == 1) { // Add hour if choosen
                    clock.addHour();
                    system("cls"); // Clears the screen
                    printClock(clock); // Display clock
                }
                else if (userInput1 == 2) { // Add minute if choosen
                    clock.addMinute();
                    system("cls"); // Clear Screen
                    printClock(clock);  // Display clock
                }
                else if (userInput1 == 3) { // Add second if choosen
                    clock.addSecond();
                    system("cls"); // Clears the screen
                    printClock(clock); // Display clock
                }
                else if (userInput1 == 4) {
                    exit(0); // Exits program
                }
                else {
                    handleInvalidInput(userInput1, userInput1); // Handle Invalid Inputs
                }
            }while (validateMenuChoice(userInput, 1, 3) == true);   
        }
        else if (userInput == 3) {
            exit(0); // Exits program
        }
        else {
            handleInvalidInput(userInput,userInput); // Handle Invalid Inputs
        }

        printMainMenu(); // Display main menu

        cin >> userInput; //Get user input to validate
    }

    return 0;
}
