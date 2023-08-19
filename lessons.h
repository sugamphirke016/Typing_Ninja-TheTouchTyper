#ifndef Lessons_HEADER
#define Lessons_HEADER

#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string>
#include<cstring>
#include<Windows.h>
#include<sstream>
#include"menu.h"

#define KEY_UP    72
#define KEY_DOWN  80

using namespace std;

class Lessons
{
    private:
        string t1 = "(1) Home Row", t2 = "(2) Top Row", t3 = "(3) Bottom Row", t4 = "(4) Keypad", t5 = "(5) Entire Keyboard", t6 = "(6) Exit";
    public:
        void menu();
        void optionGen();
        void display_opt(int opt);      
        void executeOPT(int opt);
        void homeRow();
        void topRow();
        void bottomRow();
        void keyPad();
        void printWords(string str, string ptr);
        void fullKeyboard();
        void gotoxy(short x, short y)
        {
            static HANDLE h = NULL;
            if (!h)
                h = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD c = { x, y };
            SetConsoleCursorPosition(h, c);
        }
};

#endif