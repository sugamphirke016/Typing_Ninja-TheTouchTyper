#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<dos.h> 
#include<windows.h>
#include<time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70 

using namespace std; 
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

char keys[10];	
int keyPos[10][2];	
int score = 0; 


class game
{
	public:
	int score;
		void gotoxy(int x, int y){
			CursorPosition.X = x;
			CursorPosition.Y = y;
			SetConsoleCursorPosition(console, CursorPosition);
		}

		void setcursor(bool visible, DWORD size) {
			if(size == 0) size = 20;	

			CONSOLE_CURSOR_INFO Cursor;	
			Cursor.bVisible = visible;
			Cursor.dwSize = size;
			SetConsoleCursorInfo(console,&Cursor);
		}

		void drawBorder(){  
			for(int i=0; i<SCREEN_WIDTH; i++){ 
				gotoxy(i,SCREEN_HEIGHT); printf("\xB2");
			}
			
			for(int i=0; i<=SCREEN_HEIGHT; i++){
				gotoxy(0,i); 
				printf("\xB2");
				gotoxy(SCREEN_WIDTH,i); 
				printf("\xB2");
			}
			for(int i=0; i<SCREEN_HEIGHT; i++){
				gotoxy(WIN_WIDTH,i); 
				printf("\xB2");
			}
		}

		void genAlphabet(int x){
			keys[x] = 65+rand()%25;
			keyPos[x][0] = 2 + rand()%(WIN_WIDTH-2);
			keyPos[x][1] = 1;
		}

		void drawAlphabet(int x){
			if(keyPos[x][0] != 0){
				gotoxy(keyPos[x][0], keyPos[x][1]); 
				cout<<keys[x];  
			} 
		}

		void eraseAlphabet(int x){
			if(keyPos[x][0] != 0){
				gotoxy(keyPos[x][0], keyPos[x][1]); 
				cout<<" ";  
			}
		}

		void resetAlphabet(int x){
			eraseAlphabet(x);
			genAlphabet(x);
		}

		void gameover(){
			system("cls");
			cout<<endl;
			cout<<"\t\t--------------------------"<<endl;
			cout<<"\t\t-------- Game Over -------"<<endl;
			cout<<"\t\t--------------------------"<<endl<<endl;
			cout <<"\t\t Final Score :: " << score;
			cout<<"\n\t\tPress any key to go back to menu.";
			getch();
		}

		void updateScore(){
			gotoxy(WIN_WIDTH + 6, 5);
			cout<<"Score: "<<score<<endl;
		}

		void instructions(){
			
			system("cls");
			cout<<"Instructions";
			cout<<"\n----------------";
			cout<<"\n On Left side you will see falling characters ";
			cout<<"\n You have to keep them away from touching floor";
			cout<<"\n Press respective key from keyboard to keep playing";
			cout<<"\n\n Press 'escape' to exit";
			cout<<"\n\nPress any key to go back to menu";
			getch();
		}

		void play(){
			score = 0;
			for(int i=0; i<10; i++){
				keyPos[i][0] = keyPos[i][1] = 1;	
			}
			
			system("cls"); 
			drawBorder(); 
			updateScore();
			
			for(int i=0; i<10; i++)
				genAlphabet(i); 
			
			gotoxy(WIN_WIDTH + 5, 2);cout<<" Falling";
			gotoxy(WIN_WIDTH + 5, 3);cout<<"Alphabets";
			gotoxy(WIN_WIDTH + 5, 4);cout<<"----------";
			gotoxy(WIN_WIDTH + 5, 6);cout<<"----------";
			
			gotoxy(18, 5);cout<<"Press any key to start";
			getch();
			gotoxy(18, 5);cout<<"                      ";
			
			while(1){
				if(kbhit()){
					char ch = getch();
					for(int i=0; i<10; i++){
						if( ch == keys[i] || ch-32 == keys[i] ){
							resetAlphabet(i);
							score++;
							updateScore();
						}
					}
					if(ch==27){
						break;
					}
				} 
				
				for(int i=0; i<10; i++)
					drawAlphabet(i);  
					
				Sleep(700); 
				
				for(int i=0; i<10; i++){
					eraseAlphabet(i);  
					keyPos[i][1] += 1;
					if( keyPos[i][1] > SCREEN_HEIGHT ){
						gameover();
						return;
					}
				}
			}
		}
};
