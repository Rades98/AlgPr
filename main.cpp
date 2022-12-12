#include <iostream>
#include <windows.h>  
#include <regex>
#include <string>

using namespace std;

const int DEFAULT_CONSOLE_COLOR = 1;
const int DEFAULT_CONSOLE_ERROR_COLOR = 4;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

long ReadNumber(string message);
LONGLONG Multiply(long num1, long num2);

int main()
{
    SetConsoleTextAttribute(hConsole, 10);

    cout << "Program pro vynasobeni 2 celych cisel" << endl << "Radek Reznicek" << endl << "rez0054" << endl << endl;
    SetConsoleTextAttribute(hConsole, DEFAULT_CONSOLE_COLOR);
    
    long num1 = ReadNumber("Zadejte prvni cislo: "), num2 = ReadNumber("Zadejte druhe cislo: ");

    cout << "Vysledek vynasobeni techto cisel je: " << Multiply(num1, num2);

    return 0;
}

long ReadNumber(string message)
{ 
    smatch matches;
    regex reg{R"(^-?[0-9]{0,6}$)"};
    string input;

    cout << message;

    cin >> input;

    while(!regex_match(input, matches, reg))
    {
        SetConsoleTextAttribute(hConsole, DEFAULT_CONSOLE_ERROR_COLOR);
        cout << "Vstup neni validni, zadejte cislo o maximalni delce 6 cifer" << endl;

        SetConsoleTextAttribute(hConsole, DEFAULT_CONSOLE_COLOR);
        cout << message;

        cin.clear();
        cin.ignore(10000, '\n' );

        cin >> input;
    }

    SetConsoleTextAttribute(hConsole, DEFAULT_CONSOLE_COLOR);

    return stol(matches[0].str()); 
}

LONGLONG Multiply(long num1, long num2)
{
    if(num1 == 0 || num2 == 0)
    {
        return 0;
    }

    LONGLONG result = 0;

    bool isNegative = num1 < 0 && num2 > 0 || num1 > 0 && num2 < 0;

    long mult1 = abs(num1), mult2 = abs(num2);
    
    if(mult1 > mult2)
    {
        long foo = mult1;
        mult1 = mult2;
        mult2 = foo;
    }

    for(long i = 0; i < mult1; i++)
    {
        result += mult2;
    }

    return isNegative ? -(result) : result;
}
