#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <conio.h>
#include <cctype>
#include <windows.h>
#include <iomanip>
#include <graphics.h>

using namespace std;

void colorfulTextWithBorder(string, int, int);
void printInMiddle(string);
void drawshapes();
void graphics();

// QUIZ FUNCTION
void quiz(string arr1[], string arr2[], int size) {
    while (true) {
        int points = 0;

        int randomIndex1 = rand() % size;
        
        int randomIndex2;
        do {
            randomIndex2 = rand() % size;
        } while (randomIndex1 == randomIndex2);

        int randomIndex3;
        do {
            randomIndex3 = rand() % size;
        } while (randomIndex3 == randomIndex2  || randomIndex3 == randomIndex1);

        string questionArray[] = {arr1[randomIndex1], arr1[randomIndex2], arr1[randomIndex3]};
        string answersArray[] = {arr2[randomIndex1], arr2[randomIndex2], arr2[randomIndex3]};

        for (int i = 0; i < 3; i++) {
            system("cls");
            string guess;
            cout << "\nQuestion no." << (i+1) << ":" << endl;
            cout << questionArray[i] << endl;

            cout << "\nEnter your answer: ";
            cin >> guess;
            
            for (char& c : guess) {
                c = tolower(c);
            }

            if (guess == answersArray[i]) {
                points++;
                cout << "Great job! You guessed the riddle correctly!";
            }
            else
                cout << "Oops thats not the right answer. The correct answer is " << answersArray[i] << ". Better luck next time!" << endl;

            if (i < 2) {
                cout << "\n(Press any key to move to the next question)" << endl;
                getche();
            }       
        }
        cout << "\n~~~ Your total points are " << points << " ~~~\n";
        cout << "\nDo you want to play again? (Y/N)";
        char yn;
        cin >> yn;

        if (yn == 'y' || yn == 'Y') {
            points = 0;
            continue;
        } 
        else {
            system("cls");
            break;
        }
    }
}

// HANGMAN GAME FUNCTION
void hangman() {
    string words[] = {"rainbow", "volcano", "cave", "thunder", "sand", "stone", "mountain", "forest", "dragonfly","sunrise", "ocean", "rain", "animals", "insect", "coral", "meadow", "flower", "cloud", "snow", "oyster", "mist", "leaf", "haze", "swamp", "spring", "beach", "tides"};

    int arrayLength = sizeof(words) / sizeof(words[0]);

    string random_word = words[rand() % arrayLength];

    int wordLength = random_word.length();

    string guessedLetters = "";
    int attempts = 6;
    int incorrectGuesses = 0;
    bool guessed = false;
    
    system("cls");

    colorfulTextWithBorder("Welcome to Hangman", 11, 15);
    printInMiddle("  +---+");
    printInMiddle("  |   |");
    printInMiddle("  O   |");
    printInMiddle(" /|\\  |");
    printInMiddle(" /|\\  |");
    printInMiddle("=======");
    printInMiddle(" ");
    printInMiddle("Guess the word! It's related to nature.");
    printInMiddle(" ");

    while (!guessed && attempts > 0) {
        cout << "Incorrect guesses remaining: " << attempts << "\n";

        // Display the current state of the word
        for (char letter : random_word) {
            if (guessedLetters.find(letter) != string::npos) {
                cout << letter << ' ';
            } else {
                cout << "_ ";
            }
        }
        cout << "\n\n";

        char guess;
        cout << "Enter a letter guess: ";
        cin >> guess;

        int found = random_word.find(guess);

        if (found != -1) {
            guessedLetters += guess;
            system("cls");
            printInMiddle("  +---+");
		    printInMiddle("  |   |");
		    printInMiddle("  O   |");
		    printInMiddle(" /|\\  |");
		    printInMiddle(" /|\\  |");
		    printInMiddle("=======");
		    printInMiddle(" ");
		    printInMiddle(" ");
            cout << "\nGreat job! You guessed a letter correctly.\n\n";

            // Checking if the entire word has been guessed
            guessed = guessedLetters.length() == wordLength;
        } else {
            attempts--;
            system("cls");
            printInMiddle("  +---+");
		    printInMiddle("  |   |");
		    printInMiddle("  O   |");
		    printInMiddle(" /|\\  |");
		    printInMiddle(" /|\\  |");
		    printInMiddle("=======");
		    printInMiddle(" ");
		    printInMiddle(" ");
            cout << "\nThe letter '" << guess << "' is not present in the word.\n\n";
        }
    }
    // Displaying the final state of the word
    for (char letter : random_word) {
        if (guessedLetters.find(letter) != -1) {
            cout << letter << ' ';
        } else {
            cout << "_ ";
        }
    }
    cout << "\n\n";

    if (guessed) {
        cout << "Congratulations! You guessed the word: " << random_word << "\n";
    } else {
        cout << "Sorry, you ran out of guesses. The correct word was: " << random_word << "\n";
    }
}

// TIC-TAC-TOE GAME FUNCTION
void tictactoe() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int choice;
    int row, column;
    char turn = 'X';
    bool draw = false;

    cout << "\tT I C -- T A C -- T O E -- G A M E\t";
    cout << "\n\t\tFOR 2 PLAYERS\n\t";

    while (true) {
        // Rendering game board layout
        system("cls");
        cout << "\tPLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << "\n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << "\n";
        cout << "\t\t_____|_____|_____\n";
        cout << "\t\t     |     |     \n";
        cout << "\t\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << "\n";
        cout << "\t\t     |     |     \n";

        if (!draw && (board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
                      board[1][0] == board[1][1] && board[1][0] == board[1][2] ||
                      board[2][0] == board[2][1] && board[2][0] == board[2][2] ||
                      board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
                      board[0][1] == board[1][1] && board[0][1] == board[2][1] ||
                      board[0][2] == board[1][2] && board[0][2] == board[2][2] ||
                      board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
                      board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
            if (turn == 'X') {
                cout << "\n\nCongratulations! Player 2 has won the game";
            } else {
                cout << "\n\nCongratulations! Player 1 has won the game";
            }
            break;
        } else if (!draw) {
            cout << "\n\tPlayer " << (turn == 'X' ? "1 [X]" : "2 [O]") << " turn : ";
            cin >> choice;

            switch (choice) {
                case 1: row = 0; column = 0; 
				break;
                case 2: row = 0; column = 1; 
				break;
                case 3: row = 0; column = 2; 
				break;
                case 4: row = 1; column = 0; 
				break;
                case 5: row = 1; column = 1; 
				break;
                case 6: row = 1; column = 2; 
				break;
                case 7: row = 2; column = 0; 
				break;
                case 8: row = 2; column = 1; 
				break;
                case 9: row = 2; column = 2; 
				break;
				
                default:
                    cout << "Invalid Move";
                    continue;
            }

            if (board[row][column] != 'X' && board[row][column] != 'O') {
                board[row][column] = turn;
                turn = (turn == 'X') ? 'O' : 'X';
            } else {
                cout << "Box already filled!\n Please choose another!!\n\n";
                continue;
            }
        } else {
            cout << "\n\nGAME DRAW!!!\n\n";
            break;
        }
    }
}

// FUNCTION TO SET THE CONSOLE SIZE
void setConsoleFontSize(int fontSize) {

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(console, FALSE, &fontInfo);

    fontInfo.dwFontSize.X = fontSize;
    fontInfo.dwFontSize.Y = fontSize;

    SetCurrentConsoleFontEx(console, FALSE, &fontInfo);
}

// FUNCTION TO SET THE CONSOLE SCREEN TO COVER FULL SCREEN
void setConsoleFullScreenAndCentered() {
    HWND consoleWindow = GetConsoleWindow();

    // Get the screen width and height
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Set the console window size to full screen
    SetWindowPos(consoleWindow, 0, 0, 0, screenWidth, screenHeight, SWP_NOZORDER | SWP_NOACTIVATE);

    // Calculate the position to center the console window
    int consoleWidth = GetSystemMetrics(SM_CXFULLSCREEN);
    int consoleHeight = GetSystemMetrics(SM_CYFULLSCREEN);

    int consoleX = max(0, (screenWidth - consoleWidth) / 2);
    int consoleY = max(0, (screenHeight - consoleHeight) / 2);

    // Set the console window position to be centered
    SetWindowPos(consoleWindow, 0, consoleX, consoleY, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

// FUNCTION TO PRINT COLORFUL TEXT IN THE MIDDLE OF THE CONSOLE
void colorfulTextWithBorder(string text, int borderColor, int textColor) {
	
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the width of the console window
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console, &csbi);
    int consoleWidth = csbi.dwSize.X;

    // Calculate the starting X position to print the text and border in the middle
    int textAndBorderLength = static_cast<int>(text.length()) + 4;
    int middleX = max(0, (consoleWidth - textAndBorderLength) / 2);

    // Set the border color
    SetConsoleTextAttribute(console, borderColor);

    // Draw the top border
    for (int i = 0; i < middleX; ++i) {
        cout << ' ';
    }
    for (int i = 0; i < textAndBorderLength; ++i) {
        cout << '*';
    }
    cout << endl;

    // Draw the left border
    for (int i = 0; i < middleX; ++i) {
        cout << ' ';
    }
    cout << '*';

    // Set the text color
    SetConsoleTextAttribute(console, textColor);
    cout << " " << text << " ";
    
    // Reset the text color
    SetConsoleTextAttribute(console, borderColor);

    // Draw the right border
    cout << '*' << endl;

    // Draw the bottom border
    for (int i = 0; i < middleX; ++i) {
        cout << ' ';
    }
    for (int i = 0; i < textAndBorderLength; ++i) {
        cout << '*';
    }
    cout << endl;
    // Reset the text color
    SetConsoleTextAttribute(console, 7); // 7 is the default text color
}

// FUNCTION TO PRINT TEXT IN THE MIDDLE OF THE CONSOLE
void printInMiddle(string text) {
    // Get the width of the console window
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.dwSize.X;

    // Calculate the padding needed to center the text
    int padding = (consoleWidth - text.length()) / 2;

    // Print the padded text
    cout << setw(padding + text.length()) << text << endl;
}

// FUNCTION TO DISPLAY THE OPENING GRAPHICS SCREEN UTILIZING GRAPHICS.H LIBRARY
void graphics() {
	int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    int width=GetSystemMetrics(SM_CXSCREEN);
    int height=GetSystemMetrics(SM_CYSCREEN);
    initwindow(width+6, height+6, "", -3, -3);
    
    rectangle(0, 0,GetSystemMetrics(SM_CXSCREEN)-5,GetSystemMetrics(SM_CYSCREEN)-5);

	settextstyle(GOTHIC_FONT, HORIZ_DIR, 4); // looks good
	
	// Set the background color to light gray
    setbkcolor(LIGHTGRAY);

    // Clear the screen with the new background color
    cleardevice();

    int maxX = getmaxx();
    int maxY = getmaxy();

    // Array of lines to be displayed
    char lines[][50] = {
    	
        "Welcome to the game!",
        "",
        "",
        "(Press any key to continue)"
    };

    int numLines = sizeof(lines) / sizeof(lines[0]);
    int textHeight = textheight(lines[0]);

    // Adjust the vertical gap between lines
    int lineSpacing = 20;  // Change this value to adjust the gap
    int yPos = (maxY - (numLines - 1) * lineSpacing - numLines * textHeight) / 2;
    
    // Display each line with increased gap
    for (int i = 0; i < numLines; ++i) {
    	if (i == 0) {
    		setcolor(MAGENTA);
    		settextstyle(BOLD_FONT, HORIZ_DIR, 7-i);
					
		} else{
			settextstyle(SCRIPT_FONT, HORIZ_DIR, 7-i);

			setcolor(BLACK); }
    	
        int xPos = (maxX - textwidth(lines[i])) / 2;
        outtextxy(xPos, yPos, lines[i]);
        yPos += textHeight + lineSpacing;  // Increase the gap
    }  
    drawshapes();
    getch();
    closegraph();
}

// FUNCTION TO DRAW MULTIPLE SHAPES ON THE OPENING GRAPHICS SCREEN
void drawshapes() {
	// Setting border line thickness of the shapes
	setlinestyle(SOLID_LINE, 0, 4);
	    
    // Drawing a rectangle with color cyan
    setcolor(CYAN);
    rectangle(100, 150, 300, 250);
    
    // Drawing a circle with color magenta
	setcolor(MAGENTA);
    circle(800, 130, 50);

    // Drawing a green colored star by first setting its start and end coordinates
    int startX = 1100;
    int startY = 350;

	setcolor(GREEN);
    line(startX + 100, startY + 85, startX + 80, startY + 140);
    line(startX + 100, startY + 85, startX + 120, startY + 140);
    line(startX + 20, startY + 140, startX + 80, startY + 140);
    line(startX + 120, startY + 140, startX + 180, startY + 140);
    line(startX + 60, startY + 175, startX + 20, startY + 140);
    line(startX + 60, startY + 175, startX + 45, startY + 230);
    line(startX + 45, startY + 230, startX + 100, startY + 190);
    line(startX + 155, startY + 230, startX + 100, startY + 190);
    line(startX + 155, startY + 230, startX + 140, startY + 175);
    line(startX + 140, startY + 175, startX + 180, startY + 140);
    
    // Drawing a red colored triangle by setting its start and end coordinates
    setcolor(RED);
    
    int x = 270;
    int y = 600;
    
    int points[] = {x, y, x + 50, y - 100, x + 100, y, x, y};
    line(points[0], points[1], points[2], points[3]);
    line(points[2], points[3], points[4], points[5]);
    line(points[4], points[5], points[0], points[1]);
}


// PUZZLE COMPONENT CLASS

class PuzzleGame {
public:
    void play() {

        int choice;
        cout << "\nWhich puzzle game would you like to pick?\n\n1. Hangman\n2. Scrambled words\n3. Riddles\n4. Tic-Tac-Toe\n\nEnter your choice (1-4): ";
        
        cin >> choice;

        int points = 0;

        switch(choice) {
            case 1:
                while(true) {
                    hangman();

                    cout << "\nDo you want to play again? (Y/N) \n";
                    char yn;
                    cin >> yn;

                    if (yn == 'y' || yn == 'Y') {
                        continue;
                    } 
                    else {
                        system("cls");
                        break;
                    }
                break;
                }

			// Scrambled words
            case 2: {
            	system("cls");
                while (true) {
                    string words[] = {"programming", "algorithm", "computer", "developer", "software"};

                    // Randomly select a word
                    int randomIndex = rand() % (sizeof(words) / sizeof(words[0]));
                    string originalWord = words[randomIndex];

                    string jumbledWord = originalWord;

                    // Jumble the word
                    random_shuffle(jumbledWord.begin(), jumbledWord.end());

                    // Display the jumbled word to the user
                    cout << "Unscramble the word: " << jumbledWord << endl;

                    // Get user's guess
                    string userGuess;
                    cout << "Your guess: ";
                    cin >> userGuess;

                    if (userGuess == originalWord) {
                        cout << "Correct! You unscrambled the word." << endl;
                    }
                    else {
                        cout << "Incorrect. The correct word is: " << originalWord << endl;
                    }

                    cout << "\nDo you want to play again? (Y/N) \n";
                    char yn;
                    cin >> yn;

                    if (yn == 'y' || yn == 'Y') {
                        continue;
                    } 
                    else {
                        system("cls");
                        break;
                    }
                }    
            break; }
            

            // Riddles
            case 3: {
            	system("cls");
				colorfulTextWithBorder("Riddle Challenge: Fun Brain Twisters for Everyone!", 11, 15);
				
                printInMiddle(" ");
				printInMiddle("Get ready for a mind-bending adventure!");
                printInMiddle("Answer these interesting riddles to challenge your thinking and entertain your curiosity.");
                printInMiddle(" ");
                printInMiddle("(Press any key to continue)");
                
				getche();
                string quesArray[] = {
                    "I have many voices, but never speak. I have many faces, but never peek. What am I?",
                    "I have cities, but no houses. I have mountains, but no rocks. I have water, but no fish. What am I?",
                    "What has one neck, but no head, and can hold water?",
                    "I have keys, but I open no doors. I have space, but hold no rooms. I have a spine, but no bones. What am I?",
                    "I am taller when I'm younger, and shorter when I'm older. What am I?",
                    "I get wetter the more I dry. What am I?",
                    "What is full of holes yet can still hold water?",
                    "What has one head, one foot, and four legs?",
                    "What has to be broken before you can use it?",
                    "What has no beginning, end, or middle?",
                    "The more you have of it, the less you see. What is it?",
                    "The more you take, the more you leave behind. What am I?",
                    "I fly without wings. I cry without eyes. Wherever I go, darkness follows me. What am I?",
                    "I'm not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, but water kills me. What am I?"
                };
                string ansArray[] = {"book", "map", "bottle", "keyboard", "candle", "towel", "sponge", "bed", "egg", "circle", "darkness", "footsteps", "cloud", "fire"};

                int size = sizeof(quesArray) / sizeof(quesArray[0]);

                quiz(quesArray, ansArray, size);

                break; }
            
			case 4: {
				while(true) {
                    tictactoe();

                    cout << "\nDo you want to play again? (Y/N) \n";
                    char yn;
                    cin >> yn;

                    if (yn == 'y' || yn == 'Y') {
                        continue;
                    } 
                    else {
                        system("cls");
                        break;
                    }
                break; }
			}

            default:
                cout << "Invalid input. Please enter a number between 1 to 4.";
                break;
        }
    }
};


// MATHS COMPONENT CLASS
class MathQuiz {
public:
    void start()
    {
		colorfulTextWithBorder("Math Mayhem: Dive into the Quiz Fun!", 11, 15);
		
        int choice;
        cout << "\nWhich concept do you want to test your skills on?\nYou will get a point each time you answer a question correctly.\n\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Greater than or less than.\n\nEnter your choice (1-5): ";
        cin >> choice;

        int points = 0;

        switch (choice)
        {
        case 1:
        	system("cls");
            cout << "\nSumming It Up: Time to Add!\n";
            while(true) {
                for (int i = 1; i <= 3; i++) {
                    int num1 = rand() % 100;
                    int num2 = rand() % 100;
                    int userAnswer;
                    cout << "What is " << num1 << " + " << num2 << "?\n";
                    cin >> userAnswer;

                    if (userAnswer == num1 + num2) {
                        points++;
                        cout << "Correct! Great job!\n";
                    }
                    else {
                        cout << "Oops! That's not right. The correct answer is " + to_string(num1 + num2) + ".\n";
                    }                                        
                }
                
                cout << "Your total points are " << points << "\n";
                cout << "Do you want to play again? (Y/N) \n";
                char yn;
                cin >> yn;
                if (yn == 'y' || yn == 'Y') {
                    points = 0;
                    continue;
                } 
                else {
                    system("cls");
                    break;
                }
            }
            break;

        case 2:
        	system("cls");
            cout << "\nSubtract-a-Thon: Get Set to Solve!\n";
            while(true) {
                for (int i = 1; i <= 3; i++) {
                    int num1 = ((rand() % 50) + 50);
                    int num2 = rand() % 50;
                    int userAnswer;
                    cout << "What is " << num1 << " - " << num2 << "?\n";
                    cin >> userAnswer;

                    if (userAnswer == num1 - num2) {
                        points++;
                        cout << "Correct! Great job!\n";
                    }
                    else {
                        cout << "Oops! That's not right. The correct answer is " + to_string(num1 - num2) + ".\n";
                    }                
                }

                cout << "Your total points are " << points << "\n";
                cout << "Do you want to play again? (Y/N)";
                char yn;
                cin >> yn;
                if (yn == 'y' || yn == 'Y') {
                    points = 0;
                    continue;
                } 
                else {
                    system("cls");
                    break;
                }
            }
            break;

        case 3:
        	system("cls");
            cout << "\nMultiplication Delight: Ready, Set, Solve!\n";
            while(true) {
                for (int i = 1; i <= 3; i++) {
                    int num1 = rand() % 10;
                    int num2 = rand() % 10;
                    int userAnswer;
                    cout << "What is " << num1 << " * " << num2 << "?\n";
                    cin >> userAnswer;
                    
                    if (userAnswer == num1 * num2) {
                        points++;
                        cout << "Correct! Great job!\n";
                    }
                    else {
                        cout << "Oops! That's not right. The correct answer is " + to_string(num1 * num2) + ".\n";
                    }                   
                }
                
                cout << "Your total points are " << points << "\n";
                cout << "Do you want to play again? (Y/N)";
                char yn;
                cin >> yn;
                if (yn == 'y' || yn == 'Y') {
                    points = 0;
                    continue;
                } 
                else {
                    system("cls");
                    break;
                }
            }
            break;

        case 4:
        	system("cls");
            cout << "\nDivide & Conquer: Let's Embark on the Challenge!\n";
            while(true) {
                for (int i = 1; i <= 3; i++) {
                    int num1 = ((rand() % 90) + 10);
                    int num2 = rand() % 10;
                    int userAnswer;
                    cout << "What is " << num1 << " / " << num2 << "?\n";
                    cin >> userAnswer;
                    if (userAnswer == num1 / num2) {
                        points++;
                        cout << "Correct! Great job!\n";
                    }
                    else {
                        cout << "Oops! That's not right. The correct answer is " + to_string(num1 / num2) + ".\n";
                    }                   
                }
                
                cout << "Your total points are " << points << "\n";
                cout << "Do you want to play again? (Y/N)";
                char yn;
                cin >> yn;
                if (yn == 'y' || yn == 'Y') {
                    points = 0;
                    continue;
                } 
                else {
                    system("cls");
                    break;
                }
            }
            break;

        case 5:
        	system ("cls");

            cout << "\nComparison Quest: Get Ready to Choose!\n";
            while(true) {
                for (int i = 1; i <= 3; i++) {
                    int num1 = rand() % 100;
                    int num2 = rand() % 100;
                    int greater_num = max(num1, num2);
                    int userAnswer;
                    cout << "Which number is greater? " << num1 << " or " << num2 << "?\n";
                    cin >> userAnswer;

                    if (userAnswer == greater_num) {
                        points++;
                        cout << "Correct! Great job!\n";
                    }
                    else {
                        cout << "Oops! That's not right. The correct answer is " + to_string(greater_num) + ".\n";
                    }                   
                }
                
                cout << "Your total points are " << points << "\n";
                cout << "Do you want to play again? (Y/N)";
                char yn;
                cin >> yn;
                if (yn == 'y' || yn == 'Y') {
                    points = 0;
                    continue;
                } 
                else {
                    system("cls");
                    break;
                }
            }
            break;
                
        default:
            cout << "\nInvalid input. Please enter a number between 1 to 5.";
            break;
        }
    }
};


// GEOGRAPHY COMPONENT CLASS
class GeographyExplorer {
public:
    void explore()
    {
    	system("cls");
		colorfulTextWithBorder("Welcome to the Geography Quiz!", 11, 15);
		
        printInMiddle(" ");
        printInMiddle("Answer these interesting geography questions to test your geography skills.");
        printInMiddle(" ");
        printInMiddle("(Press any key to continue)");
        
		getche();
        string quesArray[] = {
            "What is the world's largest island?",
            "Which sea is the saltiest on Earth?",
            "Which ocean is the smallest and shallowest?",
            "Name the largest hot desert in the world.",
            "Which country is known as the \"Land of the Rising Sun\"?",
            "Which country has the most pyramids?",
            "Which country is known as the \"Land of Fire and Ice\"?",
            "In which ocean would you find the Mariana Trench, the deepest part of the world's oceans?",
            "What is the largest island country in the world?",
            "What is the second-largest country in the world by land area?",
            "In which country is Mount Fuji located?",
            "Name the longest river in Asia.",
            "Which river is the longest in the world?",
            "In which continent is the Sahara Desert located?",
            "What is the smallest country in the world?",
            "Name the country known as the \"Land of the Pharaohs.\"",
            "In which ocean is the Bermuda Triangle located?",
            "Which country is known as the \"Land of the Thunder Dragon\"?",
            "What is the capital city of China?",
            "What is the highest waterfall in the world?",
            "In which country would you find the Nile River?",
            "In which ocean is the Great Barrier Reef situated?",
            "In which continent is the Amazon Rainforest located?",
            "What is the capital city of Canada?",
            "What is the capital city of India?",
            "What is the capital city of South Korea?"
        };
        string ansArray[] = {"greenland", "dead sea", "arctic", "sahara", "japan", "sudan", "iceland", "pacific", "indonesia", "canada", "japan", "yangtze", "nile", "africa", "vatican city", "egypt", "atlantic", "bhutan", "beijing", "angel falls", "egypt", "pacific", "south america", "ottawa", "delhi", "seoul"};

        int size = sizeof(quesArray) / sizeof(quesArray[0]);

        quiz(quesArray, ansArray, size);
	}
};

class LearningSoftware
{
public:
    void run()
    {
        system("cls");

        colorfulTextWithBorder("Welcome to the Learning Adventure!", 11, 15);
//        system("color 70");
	
        PuzzleGame puzzleGame;
        MathQuiz mathQuiz;
        GeographyExplorer geographyExplorer;

        int choice;
        do
        {
            displayMenu();
            cout << "Enter your choice (1-3): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                system("cls");
                puzzleGame.play();
                break;
            case 2:
                system("cls");
                mathQuiz.start();
                break;
            case 3:
                system("cls");
                geographyExplorer.explore();
                break;
            case 0:
	            cout << "Thanks for playing and learning with us! Goodbye!\n";
	            break;
            
        	default:
            	cout << "Invalid choice. Please enter a number between 0 and 3.\n";
        	}
        } while (choice != 0);
    }

private:
    void displayMenu()
    {
        cout << "\n Choose an activity: \n\n";
        cout << "1. Puzzle Game\n";
        cout << "2. Math Quiz\n";
        cout << "3. Geography Explorer\n";
        cout << "0. Quit\n";
    }
};


// MAIN FUNCTION

int main()
{
	// Calling the graphics function to execute the opening graphics
	graphics();
	
    // Seed the random number generator for variety in games
    srand(static_cast<unsigned int>(time(0)));
    
//    system("color 70");
	setConsoleFontSize(25);
	setConsoleFullScreenAndCentered();
    LearningSoftware learningSoftware;
    learningSoftware.run();

    return 0;
}
// END OF MAIN FUNCTION

