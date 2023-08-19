#include"menu.h"
#include<windows.h>
#include<string>

using namespace std;

class TTaccount : public TT
{
private:
    struct newUser
    {
        char newpass[20];
        string newuser, fname;
        long long int phone_no;
    }U;
    int stat = 0;
    string name, password, new_username, newPassd;
    char new_password[20], rePass[20];
public:
    void createAcc(), help(), operateOnPass(int i);
    bool validityCheck_password(char passd[20]), validate_username(string str), login();
    bool isEmpty(std::ifstream& pFile);
};

bool TTaccount :: isEmpty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void TTaccount :: operateOnPass(int i)   
{
    string vuser, file_name, file_name2, fname, lname, id, passd, phoneNo, vpass;
    int found;
    ifstream fout, fie;
    ofstream fin;
    system("cls");
    gotoxy(34,4);
    cout << " -----------------------------------------------------------------";
    gotoxy(34,5);
    cout << "    |                                                         |";
    gotoxy(34,6);
    cout << "    |        <----<<<< Account VERIFICATION >>>>---->         |";
    gotoxy(34,7);
    cout << "    |                                                         |";
    gotoxy(34,8);
    cout << " -----------------------------------------------------------------";
    cout << "\n\n\n";
    cout << "\t\t\t\t\t    Enter your Username: ";
    cin >> vuser;
    file_name = vuser + ".txt";
    file_name2 = vuser + "CP.txt";
    fout.open(file_name.c_str());
    fin.open(file_name2.c_str());
    fie.open(file_name2.c_str());

    if(!fout.is_open() && fout.fail())
    {
        cout << endl << "Inputed username is wrong!";
    }
    while(!fout.eof())
    {
        fout >> fname >> lname >> id >> phoneNo >> passd;
        if(vuser == id)
            found = 1;
    }

    if(found  == 1 && i == 1)
        cout << endl << "Your Password is :: " << passd << endl;
    if(found == 1 && i == 2)
    {
        int j = TTaccount :: isEmpty(fie);
        if(j == 0)
        {
            cout << endl << "You have aldready changed password upto maximum limit!";
            cout << endl << "You cannot change it anymore!";
            goto Next;
        }
        cout << endl << "Enter your Previous password :: ";
        cin >> vpass;
        if(vpass == passd)
        {
            cout << endl << "Enter your New password :: ";
            cin >> newPassd;
            // validityCheck_password(newPassd);
            fin << newPassd;
            cout << endl << "Password changed successfully!";
            stat = -1;
        }
    }
Next:
    fout.close();
    fin.close();
}

void TTaccount :: help()
{
    system("cls");
    int i;
    gotoxy(40,4);
    cout << " -------------------------------------------------";
    gotoxy(40,5);
    cout << "    |                                         |";
    gotoxy(40,6);
    cout << "    |        <----<<<< HELP >>>>---->         |";
    gotoxy(40,7);
    cout << "    |                                         |";
    gotoxy(40,8);
    cout << " -------------------------------------------------";

    cout << "\n\n\n\t\t\t\t\t\t1. Forgot Password?\n";
    cout << "\t\t\t\t\t\t2. Change Password?\n";
    cout << "\t\t\t\t\t\t3. Back\n";
    cout << "\n\t\t\t\t\t\tEnter your choice :  ";
    cin >> i;
    TTaccount :: operateOnPass(i);
}

void TTaccount::createAcc()   
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |   <----<<<< Create  Account >>>>---->   |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";
    string file_name;
    ofstream fin;
    gotoxy(80, 11);
    cout << "Enter your Name :: ";
    cin.ignore();
    getline(cin, U.fname);
    gotoxy(80,13);
    cout << "Create a new Username :: ";
    cin >> U.newuser;
    int stat = validate_username(U.newuser);
    if (stat == 1)
        goto Next;
    else if (stat == 0)
    {
        cout << endl << "You have exceeded the limits of re-entry!\nPlease consider refilling your information!";
        TTaccount::createAcc();
    }

    if (U.newuser == new_username)
        goto Next;
    else
        U.newuser = new_username;

Next:
    gotoxy(80,15);
    cout << "Enter your Cell Phone number :: ";
    cin >> U.phone_no;
    gotoxy(80,17);
    cout << "Create a Strong Password :: ";
    cin >> U.newpass;

    int returningValue = validityCheck_password(U.newpass);
    if (returningValue == 1)
        goto Next1;
    else if (returningValue == 0)
        TTaccount::createAcc();

Next1:
    gotoxy(80,19);
    cout << "Re-enter your Password :: ";
    int i = 0;
    char c = ' ';
    while(i<strlen(U.newpass))
    {
        rePass[i] = getch();
        c = rePass[i];
        if(c==13) break;
        else cout << "*";
        i++;
    }
    rePass[i] = '\0';
    i = 0;
    if (strcmp(rePass, U.newpass) == 0)
        goto Next2;
    else
    {
        gotoxy(80,21);
        cout << "Password Mismatched!";
        goto Next1;
    }

Next2:
    file_name = string(U.newuser) + ".txt";
    fin.open(file_name.c_str());
    fin << U.fname << " " << U.newuser << " " << U.phone_no << " " << U.newpass << endl;
    fin.close();
    gotoxy(80,21);
    cout << "You have successfully created a new Account!";
    gotoxy(120, 35);
    system("PAUSE");
}

bool TTaccount::login()  
{
    system("cls");
    gotoxy(73,4);
    cout << " -------------------------------------------------";
    gotoxy(73,5);
    cout << "    |                                         |";
    gotoxy(73,6);
    cout << "    |        <----<<<< Login >>>>---->        |";
    gotoxy(73,7);
    cout << "    |                                         |";
    gotoxy(73,8);
    cout << " -------------------------------------------------";

    int found;
    string first_name, last_name, id, pass, file_name, file_name2, phoneNo, changedPass;
    ifstream fout, fin;
    gotoxy(80, 11);
    cout << "Enter your Username :: ";
    cin >> name;
    gotoxy(80, 13);
    cout << "Enter your Password :: ";
    cin >> password;
    file_name = string(name) + ".txt";
    file_name2 = string(name) + "CP.txt";
    fout.open(file_name.c_str());
    fin.open(file_name2.c_str());

    if (!fout.is_open() && fout.fail())
        cout << endl << "You are not registered! Please create a new account!";

    while (!fout.eof())
    {
        fout >> first_name >> last_name >> id >> phoneNo >> pass;
        fin >> changedPass;

        if(!fin.is_open() && fin.fail())
        {
            if(name == id && password == pass)
                found = 1;
        }
        else
        {
            if(name == id && password == changedPass)
                found = 1;
        }
    }
    fout.close();
    fin.close();
    if (found == 1)
    {
        gotoxy(88, 15);
        cout << "LOGIN SUCCESSFULL!";
        gotoxy(75, 16);
        cout << "You have successfully logged in to your account!";
        gotoxy(120, 35);
        system("PAUSE");
        return TRUE;
    }
    else
    {
        gotoxy(70, 13);
        cout << "OOPS! Username or Password seems to be incorrect!";
        gotoxy(120, 35);
        system("PAUSE");
        return FALSE;
    }
}

bool TTaccount :: validate_username(string str)  
{
    int count = 0;
    char choice;
    string dat, new_usn;
    ifstream file;
    dat = str + ".txt";
    file.open(dat.c_str());
    if (!file.is_open() && file.fail())
        return TRUE;
    else
    {
        count++;
        if (count == 3)
        {
            cout << endl << "This username aldready exists! Please try again!";
            return FALSE;
        }
        cout << endl << "This username aldready exists! Please try again!";
        cout << endl << "Do you want to create a different Username[y/n]: ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y' || choice != 'n' || choice != 'N')
        {
            cout << endl << "Enter your new Username :: ";
            cin >> new_usn;
            int stat = validate_username(new_usn);
            if (stat == 1)
                new_username = new_usn;
        }
    }
}

bool TTaccount :: validityCheck_password(char passd[20])   
{
    int sizeflag = 1, digitflag = 0, splcharflag = 0, charflag = 0, choice, times = 0;
    int len = string(passd).length();
    if (len < 6 || len>12)
        sizeflag = 0;
    for (int i = 0; i < len; i++)
    {
        if (passd[i] >= 48 && passd[i] <= 57)
            digitflag = 1;
        if ((passd[i] >= 65 && passd[i] <= 90) || passd[i] >= 97 && passd[i] <= 122)
            charflag = 1;
        if ((passd[i] >= 33 && passd[i] <= 47) || (passd[i] >= 58 && passd[i] <= 64) || (passd[i] >= 91 && passd[i] <= 96))
            splcharflag = 1;
    }
    if (!sizeflag || !charflag || !digitflag || !splcharflag)
        cout << endl << "This Password isn't valid";
    if (!sizeflag)
    {
        cout << endl << "Password length must be minimum 6 and maximum 12!";
    }
    if (!charflag)
    {
        cout << endl << "Password must consist minimum one character!";
    }
    if (!digitflag)
    {
        cout << endl << "Password must consist of at least one digit!";
    }
    if (!splcharflag)
    {
        cout << endl << "Password must contain of minimum one special character.";
    }
    int v = sizeflag + charflag + digitflag + splcharflag;
    if (sizeflag && charflag && digitflag && splcharflag)
    {
        gotoxy(75,18);
        cout << "!###### Strength of your Password: " << v << "/4 ######!";
        return TRUE;
    }
    else
    {
        times++;
        if (times == 3)
        {
            cout << "You have exceeded the limits of re-entry! Please consider refilling your information!";
            return FALSE;
        }
        cout << endl << endl << "Looks like your Password is too weak and vulnerable! \nDo you want to Re-create a new Password[1/0] :: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << endl << "Enter a new Password :: ";
            cin >> new_password;
            int stat = TTaccount::validityCheck_password(new_password);
            if (stat == 1)
                strcpy(U.newpass, new_password);
        }
    }
}
