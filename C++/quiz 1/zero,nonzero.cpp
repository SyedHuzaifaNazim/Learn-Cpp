//A library function, islower(), takes a single character (a letter) as
//an argument and returns a nonzero integer if the letter is lowercase,
//or zero if it is uppercase. This function requires the header 
//file CTYPE.H. Write a program that allows the user to enter a letter,
//and then displays either zero or nonzero, depending on whether a 
//lowercase or uppercase letter was entered.

//#include <iostream>
//#include <cctype>
//using namespace std;
//
//int main() {
//    char letter;
//    
//    cout << "Enter a letter: ";
//    cin >> letter;
//    
//    if (islower(letter)) {
//        cout << "Nonzero\n";
//    } else {
//        cout << "Zero\n";
//    }
//    
//    return 0;
//}


//Assume that you want to generate a table of multiples of any given number.
//Write a program that allows the user to enter the number and then generates
//the table, formatting it into 10 columns and 20 lines. Interaction with the
//program should look like this (only the first three lines are shown):
//Enter a number: 7
//7 14 21
//28 35
//56 63
//77
//84
//147
//105
//168
//49
//112
//119
//126
//133,196,140,91 98,154,161,42,175,182,189,203,70,210

#include <iostream>
using namespace std;

int main ()
{
	    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < 10; j++) {
            cout << number * (i - 1) + (j + 1) * number << " ";
            if (j == 9 || (i == 20 && j == 4)) {
                cout << std::endl;
            }
        }
    }
    
    return 0;
}
