#ifndef TT_HEADER
#define TT_HEADER

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include"lessons.h"
#include"Typing_testC.h"
#include"Game1.h"

#define KEY_UP    72
#define KEY_DOWN  80

using namespace std;

class TT
{
private:
    int ch_menu;
    string s1 = "(1) Practice Lessons", s2 = "(2) Take Test"; 
    string s4 = "(3) Typing Games"; 
    string s5 = "(4) Delete Account", s6 = "(5) Logout";
public:
    int mainMenu();
    void display_menu();
    void display_opt(int opt);
    void optionGen();
    void defaultDisp();
    void gotoxy(short x, short y)
    {
        static HANDLE h = NULL;
        if (!h)
            h = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD c = { x, y };
        SetConsoleCursorPosition(h, c);
    }
    int displayGame();
    void executeOPT(int opt);

};

int TT::mainMenu()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |        <----<<<< Menu >>>>---->         |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(86,11);
    cout << "1. Create Account\n";
    gotoxy(86,12);
    cout << "2. Login\n";
    gotoxy(86,13);
    cout << "3. Need Help?\n";
    gotoxy(86,14);
    cout << "4. Exit\n";
    gotoxy(86,16);
    cout << "Enter your choice :  ";
    cin >> ch_menu;
    return (ch_menu);
}

void TT :: display_menu()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    TT :: gotoxy(73,5);
    cout << "    |                                         |";
    TT :: gotoxy(73,6);
    cout << "    |        <----<<<< Menu >>>>---->         |";
    TT :: gotoxy(73,7);
    cout << "    |                                         |";
    TT :: gotoxy(73,8);
    cout << " -------------------------------------------------";
    TT :: gotoxy(85,11); cout << s1;
    TT :: gotoxy(85,13); cout << s4;
    TT :: gotoxy(85,12); cout << s2;
    TT :: gotoxy(85,14); cout << s5;
    TT :: gotoxy(85,15); cout << s6;
    TT :: gotoxy(80, 17);
    cout << "OPTION SELECTED :: " << s1;
}


void TT::display_opt(int opt)
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    TT :: gotoxy(73,5);
    cout << "    |                                         |";
    TT :: gotoxy(73,6);
    cout << "    |        <----<<<< Menu >>>>---->         |";
    TT :: gotoxy(73,7);
    cout << "    |                                         |";
    TT :: gotoxy(73,8);
    cout << " -------------------------------------------------";
    TT :: gotoxy(85,11); cout << s1;
    TT :: gotoxy(85,13); cout << s4;
    TT :: gotoxy(85,12); cout << s2;
    TT :: gotoxy(85,14); cout << s5;
    TT :: gotoxy(85,15); cout << s6;
    TT :: gotoxy(80, 17);
    cout << "OPTION SELECTED :: ";

    if (opt == 1)
        cout << s1;
    else if (opt == 2)
        cout << s2;
    else if (opt == 3)
        cout << s4;
    else if (opt == 4)
        cout << s5;
    else if (opt == 5)
        cout << s6;
}

void TT:: optionGen()
{
    int c, ex, opt = 1;
    while (1)
    {
        c = _getch();

        if (c && c != 224)
        {
            break;
        }
        else
        {
            switch (ex = _getch())
            {
            case KEY_UP:
                opt--;
                break;
            case KEY_DOWN:
                opt++;
                break;
            default:
                cout << endl << (char)ex << endl;
                break;
            }
        }
        if (opt == 0)
        {
            opt++;
        }
        if (opt == 6)
        {
            opt--;
        }        
        TT::display_opt(opt);
    }
    TT :: executeOPT(opt);
}

void TT :: executeOPT(int opt)
{
    TT T;
    Lessons op;
    switch(opt)
    {
        case 1:
            system("cls");
            op.menu();
            op.optionGen();
            break;
        case 2:
        {
            system("cls");
            gotoxy(73,4);
            cout << " -------------------------------------------------";
            gotoxy(73,5);
            cout << "    |                                         |";
            gotoxy(73,6);
            cout << "    |        <----<<<< TEST >>>>---->         |";
            gotoxy(73,7);
            cout << "    |                                         |";
            gotoxy(73,8);
            cout << " -------------------------------------------------";
            gotoxy(15,11);
            test test;
            time_t starttime;
            time_t endtime;
            string s = "The tiger is the largest living cat species and a member of the genus Panthera. It is most recognisable for its dark vertical stripes on orange fur with a white underside.";
            string t;
            cout << s; gotoxy(78, 13);
            cout << "Press Enter and start typing the above lines...";
            cin.get();
            cin.get();
            time(&starttime);
            gotoxy(15, 15);
            getline(cin, t);
            time(&endtime);
            int Time = endtime-starttime;
            gotoxy(80, 29);
            cout << "Time in seconds:" << Time << endl;
            int words = test.printWords(s, t);
            test.calculateWPM(words, Time);
            test.calculateCPS(s.size(), Time);

            int errors = 0;
            for( auto i( s.begin() ); i != s.end(); ++i )
            {
                if( *i != *( t.begin() + distance( s.begin() , i ) ) ) 
                {
                    errors++;
                }
            }
            cout << endl;
            gotoxy(80, 34);
            cout << "There was a total of " << errors << " errors in the sentence with " << s.size() << " letters."; gotoxy(80, 35);
            cout << "Your accuracy is %" << static_cast<double>( ( s.size() - errors ) ) / s.size()  * 100 << '.' << endl;
            gotoxy(125, 40);
            system("PAUSE");
            T.display_menu(); T.optionGen();
        }
            break;
        case 3:
        {
            game g;
            g.setcursor(0,0); 
            srand((unsigned)time(NULL)); 
            
            do{
                system("cls");
                g.gotoxy(10,5); cout<<" <----------------------------> "; 
                g.gotoxy(10,6); cout<<"   |   FALLING ALPHABETS   | "; 
                g.gotoxy(10,7); cout<<" <---------------------------->";
                g.gotoxy(10,9); cout<<"1. Start Game";
                g.gotoxy(10,10); cout<<"2. How to Play?";	 
                g.gotoxy(10,11); cout<<"3. Quit";
                g.gotoxy(10,13); cout<<"Select option: ";
                char op = getche();
                
                if( op=='1') g.play();
                else if( op=='2') g.instructions();
                else if( op=='3') {  T.display_menu(); T.optionGen(); };
                
            }while(1);
        }
            break;
        case 4:
        {
            system("cls");
            gotoxy(73,4);
            cout << " -------------------------------------------------";
            gotoxy(73,5);
            cout << "    |                                         |";
            gotoxy(73,6);
            cout << "    |   <----<<<< Account Deletion >>>>---->  |";
            gotoxy(73,7);
            cout << "    |                                         |";
            gotoxy(73,8);
            cout << " -------------------------------------------------";
            string filename; gotoxy(82, 11);
            cout << "Verify your Username :: ";
            cin >> filename;
            filename = filename + ".txt";
            char *str = new char[filename.length()+1];
            strcpy(str, filename.c_str());
            int status = remove(str);

            if(status == 0)
            {
                gotoxy(85, 16);
                cout << "Account Deleted Successfully!";
            }
            else if(status == 1)
            {
                gotoxy(80, 16);   
                cout << "Oops! Looks like you had a typo in your username!";
            }
            gotoxy(120, 28);
            system("PAUSE");
            T.mainMenu(); T.optionGen();
        }
            break;
        case 5:
            T.mainMenu(); T.optionGen();
            break;
        default:
            break;
    }
}

// lessons.h

void Lessons :: menu()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |        <----<<<< Menu >>>>---->         |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(85,11); cout << t1;
    gotoxy(85,12); cout << t2;
    gotoxy(85,13); cout << t3;
    gotoxy(85,14); cout << t4;
    gotoxy(85,15); cout << t5;
    gotoxy(85,16); cout << t6;
    gotoxy(80, 18);
    cout << "OPTION SELECTED :: " << t1;
}

void Lessons :: optionGen()
{
    int c, ex, opt = 1;
    while (1)
    {
        c = _getch();

        if (c && c != 224)
        {
            break;
        }
        else
        {
            switch (ex = _getch())
            {
            case KEY_UP:
                opt--;
                break;
            case KEY_DOWN:
                opt++;
                break;
            default:
                cout << endl << (char)ex << endl;
                break;
            }
        }
        if (opt == 0)
        {
            opt++;
        }
        if (opt == 7)
        {
            opt--;
        }
        Lessons::display_opt(opt);
    }
    Lessons :: executeOPT(opt);
}

void Lessons ::display_opt(int opt)
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |        <----<<<< Menu >>>>---->         |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(85,11); cout << t1;
    gotoxy(85,12); cout << t2;
    gotoxy(85,13); cout << t3;
    gotoxy(85,14); cout << t4;
    gotoxy(85,15); cout << t5;
    gotoxy(85,16); cout << t6;
    gotoxy(80, 18);
    cout << "OPTION SELECTED :: ";

    if (opt == 1)
        cout << t1;
    else if (opt == 2)
        cout << t2;
    else if (opt == 3)
        cout << t3;
    else if (opt == 4)
        cout << t4;
    else if (opt == 5)
        cout << t5;
    else if (opt == 6) 
        cout << t6;
}

void Lessons :: executeOPT(int opt)
{
    TT T;
    switch(opt)
    {
        case 1:
            Lessons :: homeRow();
            T.display_menu();
            T.optionGen();
            break;
        case 2:
            Lessons :: topRow();
            T.display_menu();
            T.optionGen();
            break;
        case 3:
            Lessons :: bottomRow();
            T.display_menu();
            T.optionGen();
            break;
        case 4:
            Lessons :: keyPad();
            T.display_menu();
            T.optionGen();
            break;
        case 5:
            Lessons :: fullKeyboard();
            T.display_menu();
            T.optionGen();
            break;
        case 6:
            T.display_menu();
            T.optionGen();
            break;
    }
}

void Lessons :: fullKeyboard()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |      <----<<<< HOME  ROW >>>>---->      |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(60,11);
    time_t start,end;
    string ans, type = "The tiger is the largest living cat species and a member of the genus Panthera. It is most recognisable for its dark vertical stripes on orange fur with a white underside.";
    cout << type; gotoxy(70, 13);
    cout  << "Press Enter ans start typing the above keywords...";
    cin.get();
    cin.get();
    start=time(NULL);
    gotoxy(60, 16);
    getline(cin, ans);
    end=time(NULL);
    int Time = difftime(end,start);
    Lessons :: printWords(type, ans);
    gotoxy(80, 30);
    cout << "Total time taken(in secs) :: " << Time << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
    system("PAUSE");
}

void Lessons :: homeRow()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |      <----<<<< HOME  ROW >>>>---->      |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(60,11);
    time_t start,end;
    string ans, type = "ashfalls flash salad glass shall half lakh asks flags lads saga lags hash halls";
    cout << type; gotoxy(70, 13);
    cout << "Press Enter ans start typing the above keywords..."; 
    cin.get();
    cin.get();
    start=time(NULL);
    gotoxy(60, 16);
    getline(cin, ans);
    end=time(NULL);
    int Time = difftime(end,start);
    Lessons :: printWords(type, ans);
    gotoxy(80, 30);
    cout << "Total time taken(in secs) :: " << Time << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
    system("PAUSE");
}

void Lessons :: topRow()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |       <----<<<< Top ROW >>>>---->       |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(60,11);
    time_t start,end;
    string ans, type = "equity query toper wrote pout port poet quit rope tier qwerty typo wire pity";
    cout << type; gotoxy(70, 13);
    cout << "Press Enter ans start typing the above keywords...";
    cin.get();
    cin.get();
    start=time(NULL);
    gotoxy(60, 16);
    getline(cin, ans);
    end=time(NULL);
    int Time = difftime(end,start);
    Lessons :: printWords(type, ans);
    gotoxy(80, 30);
    cout << "Total time taken(in secs) :: " << Time << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
    system("PAUSE");
}

void Lessons :: bottomRow()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |      <----<<<< Bottom ROW >>>>---->     |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(60,11);
    time_t start,end; 
    string ans, type = "cmbv xnbc mxcv zmxb bcxn mznx cbxm nxbz mxbz mxbb xmnx bcmz mncm vvvv bmbx";
    cout << type; gotoxy(70, 13);
    cout  << "Press Enter ans start typing the above keywords...";
    cin.get();
    cin.get();
    start=time(NULL);
    gotoxy(60, 16);
    getline(cin, ans);
    end=time(NULL);
    int Time = difftime(end,start);
    Lessons :: printWords(type, ans);
    gotoxy(80, 30);
    cout << "Total time taken(in secs) :: " << Time << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
    system("PAUSE");
}

void Lessons :: keyPad()
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |       <----<<<< KEY PAD >>>>---->       |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    gotoxy(60,11);
    time_t start,end;
    string ans, type = "8249 6724 1752 4931 7613 5378 4566 4862 2684 1111 7989 5645 2312 1478 2589 3691";
    cout << type; gotoxy(70, 13);
    cout  << "Press Enter ans start typing the above keywords...";
    cin.get();
    cin.get();
    start=time(NULL);
    gotoxy(60, 16);
    getline(cin, ans);
    end=time(NULL);
    int Time = difftime(end,start);
    Lessons :: printWords(type, ans);
    gotoxy(80, 30);
    cout << "Total time taken(in secs) :: " << Time << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
    system("PAUSE");
}


void Lessons :: printWords(string str, string ptr)
{
    test y;
    y.gotoxy(90, 20); cout << "STATISTICS";
    y.gotoxy(80, 22);
    int ct=0, tc=0;
    string word, let;
    stringstream iss(str);
    stringstream isst(ptr);
    while(iss >> word && isst >> let)
    {
        if(word == let)
            ct++;
        else
        {
            tc++;
            cout << "\n\t\t\t\t\t\t\t\t\t\tWrong Word :: " << let;
            cout << "[At location " << ptr.find(let) << "]";
        }
    }
    y.gotoxy(80, 26);
    cout << "Total number of words typed :: " << ct+tc;
    y.gotoxy(80, 27);
    cout << "Wrong words :: " << tc; 
    y.gotoxy(80, 28);
    cout << "Correct words :: " << ct;
}

//Typing_testC.h

int test :: printWords(string str, string ptr)
{
    test y;
    y.gotoxy(90, 20); cout << "STATISTICS";
    y.gotoxy(80, 22);
    int ct=0, tc=0;
    string word, let;
    stringstream iss(str);
    stringstream isst(ptr);
    while(iss >> word && isst >> let)
    {
        if(word == let)
            ct++;
        else
        {
            tc++;
            cout << "\n\t\t\t\t\t\t\t\t\t\tWrong Word :: " << let;
            cout << "[At location " << ptr.find(let) << "]";
        }
    }
    y.gotoxy(80, 26);
    cout << "Total number of words typed :: " << ct+tc;
    y.gotoxy(80, 27);
    cout << "Wrong words :: " << tc; 
    y.gotoxy(80, 28);
    cout << "Correct words :: " << ct;
    return (tc+ct);
}

#endif