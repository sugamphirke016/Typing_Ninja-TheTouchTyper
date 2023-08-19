#include"menu.h"
#include"Login.h"
#include"lessons.h"
#include<conio.h>

int main()
{
    system("color 30");
    system("cls");
    TT obj;
    TTaccount user;
    
    do{
        switch(obj.mainMenu())
        {
            case 1:
                user.createAcc();
                break;
            case 2:
            {
                int ret = user.login();
                system("cls");
                if(ret == 1)
                {
                    system("cls 2E");
                    obj.gotoxy(92,22);
                    cout << "WELCOME";
                    obj.gotoxy(88, 24);
                    cout << "TOUCH TYPING TUTOR";
                    obj.gotoxy(20, 43);
                    cout << "Loading! Please wait....";
                    obj.gotoxy(20, 44);
                    cout << "We appreciate your patience!";
                    obj.gotoxy(10, 45);
                    for(int r=1; r<=180; r++)
                    {
                        for(int q=0; q<=10000000; q++);
                            printf( "%c", 177) ; 
                    }
                    obj.display_menu();
                    obj.optionGen();
                }
                else
                    break;
            }
                break;
            case 3:
                user.help();
                system("PAUSE");
                break;
            case 4:
                exit(0);
            default:
                cout << endl << "Invalid Choice!";
        }
    }while(TRUE);

    return 0;
}

