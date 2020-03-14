
#include <stdio.h>

#include <windows.h>

#define N 50

HANDLE hConsole;

void gotoxy(int x, int y)

{

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(hConsole, coord);

}

int main()

{

 int i,j,k;

 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

 SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);

 for(k=0;k<3;k++)

 {

  gotoxy(4,6);

 

  for(i = 0;i<11;i ++)

 

  {

   printf("*");

   Sleep(N);

 

  }

 

  for(i = 0;i<12;i++)

  {

   gotoxy(9,7+i);

   printf("*");

   Sleep(N);

  }

  gotoxy(4,18);

  for(i = 0;i<11;i ++)

  {

   printf("*");

   Sleep(N);

  }

  gotoxy(36,10);

  printf("*");

  Sleep(N);

 

  gotoxy(25,10);

  printf("*");

  Sleep(N);

 

  gotoxy(47,10);

  printf("*");

  Sleep(N);

 

  gotoxy(34,8);

  printf("*");

  Sleep(N);

 

  gotoxy(38,8);

  printf("*");

  Sleep(N);

 

  gotoxy(30,7);

  printf("*");

  Sleep(N);

 

  gotoxy(42,7);

  printf("*");

  Sleep(N);

 

  gotoxy(27,8);

  printf("*");

  Sleep(N);

 

  gotoxy(45,8);

  printf("*");

  Sleep(N);

 

  gotoxy(25,11);

  printf("*");

  Sleep(N);

 

  gotoxy(47,11);

  printf("*");

  Sleep(N);

  for(i=1,j=1;i<6,j<6;i++,j++)

  {

   gotoxy(25+i,11+j);

   printf("*");

   Sleep(N);

  }

  gotoxy(32,17);

  printf("*");

  Sleep(N);

 

  gotoxy(34,18);

  printf("*");

  Sleep(N);

 

 

  for(i=1,j=1;i<6,j<6;i++,j++)

  {

   gotoxy(47-i,11+j);

   printf("*");

   Sleep(N);

  }

  gotoxy(40,17);

  printf("*");

  Sleep(N);

 

  gotoxy(38,18);

  printf("*");

  Sleep(N);

 

  gotoxy(36,19);

  printf("*");

  Sleep(N);

  for(i=0;i<11;i++)

  {

   gotoxy(59,6+i);

   printf("*");

   Sleep(N);

  }

  gotoxy(61,17);

  printf("*");

  Sleep(N);

  for(i=0;i<11;i++)

  {

   gotoxy(63+i,18);

   printf("*");

   Sleep(N);

  }

  gotoxy(74,17);

  printf("*");

  Sleep(N);

 

  gotoxy(76,16);

  printf("*");

  Sleep(N);

  for(i=0;i<10;i++)

  {

   gotoxy(76,15-i);

   printf("*");

   Sleep(N);

  }

  system("cls");

 }

 while(1)

 {

  gotoxy(4,6);

 

  for(i = 0;i<11;i ++)

 

  {

   printf("*");

 

 

  }

 

  for(i = 0;i<12;i++)

  {

   gotoxy(9,7+i);

   printf("*");

 

  }

  gotoxy(4,18);

  for(i = 0;i<11;i ++)

  {

   printf("*");

 

  }

  gotoxy(36,10);

  printf("*");

 

 

  gotoxy(25,10);

  printf("*");

 

 

  gotoxy(47,10);

  printf("*");

 

 

  gotoxy(34,8);

  printf("*");

 

 

  gotoxy(38,8);

  printf("*");

 

 

  gotoxy(30,7);

  printf("*");

 

  gotoxy(42,7);

  printf("*");

 

 

  gotoxy(27,8);

  printf("*");

 

 

  gotoxy(45,8);

  printf("*");

 

 

  gotoxy(25,11);

  printf("*");

 

 

  gotoxy(47,11);

  printf("*");

 

  for(i=1,j=1;i<6,j<6;i++,j++)

  {

   gotoxy(25+i,11+j);

   printf("*");

 

  }

  gotoxy(32,17);

  printf("*");

 

 

  gotoxy(34,18);

  printf("*");

 

 

 

  for(i=1,j=1;i<6,j<6;i++,j++)

  {

   gotoxy(47-i,11+j);

   printf("*");

 

  }

  gotoxy(40,17);

  printf("*");

 

 

  gotoxy(38,18);

  printf("*");

 

 

  gotoxy(36,19);

  printf("*");

 

  for(i=0;i<11;i++)

  {

   gotoxy(59,6+i);

   printf("*");

 

  }

  gotoxy(61,17);

  printf("*");

 

  for(i=0;i<11;i++)

  {

   gotoxy(63+i,18);

   printf("*");

 

  }

  gotoxy(74,17);

  printf("*");

  Sleep(100);

  gotoxy(76,16);

  printf("*");

 

  for(i=0;i<10;i++)

  {

   gotoxy(76,15-i);

   printf("*");

 

  }

  gotoxy(25,22);

  Sleep(1000);

  system("cls");

 }

 

 
system("pause"); 
}

