#include<iostream>
#include<string>
#include<sstream>
#include<time.h>
using namespace std;

class test
{
    public:
        int printWords(string str, string ptr);
        
        void gotoxy(short x, short y)
        {
            static HANDLE h = NULL;
            if (!h)
                h = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD c = { x, y };
            SetConsoleCursorPosition(h, c);
        }
        void calculateWPM(int x, int time)
        { 
            double t = double(x)/(double(time)/60.0);
            test :: gotoxy(80, 31);
            cout << "WPM = " << t;
        }

        double calculateCPS(int x, int time)
        {
            double t = double(x)/(double(time));
            test :: gotoxy(80, 32);
            cout << "CPS = " << t;
        }
};