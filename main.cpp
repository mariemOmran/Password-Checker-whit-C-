#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <conio.h>
#include <string>
#define down 80
#define up 72
#define right 77
#define left 75
#define home 71
#define end 79
#define page_up 73
#define page_down 81
#define tab 9
#define enter 13
#define esc 27
#define space 32
#define Back_Space 8
#define delete_1 127
void moveCursor(int x, int y)
{
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    std::cout << "\033[" << y << ";" << x << "H";
#endif
}

using namespace std;
int main()
{
    moveCursor(10, 2);
    system("color 07");
    cout << "enter your passward: " << endl;
    moveCursor(10, 4);
    int flag = 0;
    char ch;
    string userInput;
    string astriq;
    string countCharacters = "1- at least 8 charachters";
    string countCapitalChar = "2- at least one capital character";
    string countNumbers = "3- at least one number";
    string countSpecilaChar = "4- at least one special number";
    int count_Capital_Char = 0;
    int count_Numbers = 0;
    int count_Special = 0;
    system("color 0C");
    moveCursor(10, 20);
    cout << countCharacters << endl;
    moveCursor(10, 21);
    cout << countCapitalChar << endl;
    moveCursor(10, 22);
    cout << countNumbers << endl;
    moveCursor(10, 23);
    cout << countSpecilaChar << endl;
    moveCursor(10, 6);
    while (flag == 0)
    {
        ch = _getch();
        system("cls");
        // Append the character to the string
        switch (ch)
        {
        case esc:
        case enter:
            if (userInput.length() >= 10 && count_Capital_Char > 0 && count_Numbers > 0 && count_Special > 0)
            {
                system("cls");
                system("Color 0A");
                moveCursor(10, 10);
                cout << userInput << endl;
                moveCursor(10, 12);
                cout << "Correct\n"
                     << endl;
            }
            else
            {
                system("cls");
                system("Color 0C");
                moveCursor(10, 10);
                cout << userInput << endl;
                moveCursor(10, 12);
                cout << "Passward Incorrect\n"
                     << endl;
            }
            flag = 1;
            break;
        case delete_1:
        case Back_Space:
            if (ch == delete_1 || ch == Back_Space)
            {
                if (userInput.length() > 0)
                {
                    int tempCh = (int)userInput[(userInput.length()) - 1];
                    if (tempCh >= 65 && tempCh <= 90)
                    {
                        count_Capital_Char--;
                    }
                    else if (tempCh >= 48 && tempCh <= 57)
                    {
                        count_Numbers--;
                    }
                    else if (tempCh >= 33 && tempCh <= 47)
                    {
                        count_Special--;
                    }
                    userInput.erase((userInput.length()) - 1);
                    astriq.erase((astriq.length()) - 1);
                }
            }
            break;
        case -32:
        case 0:
        case 224:
            ch = getch();
            break;
        default:
            userInput.push_back(ch);
            astriq.push_back('*');
            break;
        }

        if ((int)ch >= 65 && (int)ch <= 90)
        {
            count_Capital_Char++;
        }
        else if ((int)ch >= 48 && (int)ch <= 57)
        {
            count_Numbers++;
        }
        else if ((int)ch >= 33 && (int)ch <= 47)
        {
            count_Special++;
        }
        if (userInput.length() >= 8)
        {
            countCharacters = "";
        }
        else
        {
            countCharacters = "1- at least 8 charachters";
        }
        if (count_Capital_Char > 0)
        {
            countCapitalChar = "";
        }
        else
        {
            countCapitalChar = "2- at least one capital character";
        }
        if (count_Numbers > 0)
        {
            countNumbers = "";
        }
        else
        {
            countNumbers = "3- at least one number";
        }
        if (count_Special > 0)
        {
            countSpecilaChar = "";
        }
        else
        {
            countSpecilaChar = "4- at least one special number";
        }
        if (userInput.length() >= 10 && count_Capital_Char > 0 && count_Numbers > 0 && count_Special > 0)
        {
            system("Color 0A");
            moveCursor(10, 12);
            cout << "Correct\n"
                 << endl;
        }
        else
        {
            system("Color 0C");
            moveCursor(10, 20);
            cout << countCharacters << endl;
            moveCursor(10, 21);
            cout << countCapitalChar << endl;
            moveCursor(10, 22);
            cout << countNumbers << endl;
            moveCursor(10, 23);
            cout << countSpecilaChar << endl;
        }
        moveCursor(10, 4);
        // Print the current input
        cout << "\033[1;37m"
             << "\renter your password: "
             << "\033[0m"
             << endl;
        moveCursor(10, 6);
        cout << "\033[1;34m" << userInput << " \033[0m" << flush;
        moveCursor(10, 7);
        cout << astriq << endl;
    }

    cout << endl;

    return 0;
}
