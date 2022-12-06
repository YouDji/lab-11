#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;
void gotoxy(int xp, int yp) 
{
COORD new_xy;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
new_xy.X = xp; new_xy.Y = yp;
SetConsoleCursorPosition(hStdOut,new_xy);
}
int main()
{
system("cls");
SetConsoleCP(1251); 
SetConsoleOutputCP(1251); 
const int ln=20;
char MP[ln];
int n, sel, i, j, t, p, pp,pk, j2,t2;
struct biblio
{
char name[ln];
int page;
char avtor[ln];
char s_a[ln];
};
biblio b_m[100];

char sear[ln];
char st[ln]="";

n=0;
do
{
system("cls");
gotoxy(20,5);
cout << " Головне меню ";
gotoxy(20,7); cout << " 1. Введення записів";
gotoxy(20,8); cout << " 2. Усі записи";
gotoxy(20,9); cout << " 3. Пошук за ім'ям автора {-[^-^]-}";
gotoxy(20,12); cout << " 6. Вихід";
gotoxy(20,13); cout << " Введіть номер пункту : ";
cin >>p;
switch (p)
{
case 1:
{
i=n-1;
s11:
pp=1;
pk=0;
i++;
system("cls");
printf("Введіть запису номер %d : \n", i+1);
cout << "Введіть назву книги, що складається з одного слова -> ";
cin >>b_m[i].name;
t=strlen(b_m[i].name);
for (j = t; j < ln-2; j++)
strcat(b_m[i].name," ");
cout << "Введіть кількість сторінок -> ";
cin >> b_m[i].page;
cout << "Введіть ім'я автора -> ";
cin >> b_m[i].avtor;
t2=strlen(b_m[i].avtor);
for(j2=t2; j2<ln-2; j2++)
strcat(b_m[i].avtor," ");
printf("Для продовження натисність -> Enter, для вихода -> Esc \n");
s12:
while (!kbhit()); 
pp=getch();
if (pp!=27)
if (pp==13)
goto s11;
else
goto s12;
n=i+1;
break;
}
case 2:
{
s2:
pp=1;
system("cls");
pk=0;
if (n<1)
{
printf(" Записів в масиві не має\n");
goto s6;
}
for (i=0; i < n; i++)
{
if (pk==0)
{
system("cls");
cout<<" Масив записів \n"
<<" _____________________________________\n"
<<" | № | Назва книги | Кіл. стор. |Ім'я автора |\n"
<<" ____________________________________\n";
pk=4;
}
printf(" |%3d | %20s | %4d | %20s \n",i+1,b_m[i].name,b_m[i].page,b_m[i].avtor);
if ((pk==20)||((i+1)==n))
{
cout<<"________________________________\n";
}
if ((pk==20)&&((i+1)>=n))
{
printf(" Записів в масиві %d\n",n);
printf(" Натисність Enter для продовження виведення записів\n");
while (!kbhit()); 
}
}
s6:
printf("Для повторного виведення записів натисність -> Enter, для виходу -> Esc \n");
s1:
while (!kbhit()); 
pp=getch();
if (pp!=27)
if (pp==13)
goto s2;
else
goto s1;
break;
}
case 3:
{
s4:
pp=1;
pk=0;
system("cls");
if (n<1)
{
printf(" Записів в масиві немає\n");
goto s5;
}
cout << "Введіть ім'я автора  -> ";
cin>>sear;
for (i=0; i < n; i++)
{
if (pk==0)
{
system("cls");
cout<<" Масив записів \n"
<<" _____________________________________\n"
<<" | № | Назва книги | Кіл. стор. |Ім'я автора |\n"
<<" ____________________________________\n";
pk=4;
}

if (strstr(b_m[i].avtor,sear))
printf(" |%3d | %20s | %4d | %20s \n",i+1,b_m[i].name,b_m[i].page,b_m[i].avtor);
if ((pk==20)||((i+1)==n))
{
cout<<"________________________________\n";
}
if ((pk==20)&&((i+1)>=n))
{
printf(" Записів в масиві %d\n",n);
printf(" Натисність Enter для продовження виведення записів\n");
while (!kbhit()); 
}
}
s5:
printf("Для повторного виконання функції натисніть -> Enter, для виходу -> Esc \n",n);
s3:
while (!kbhit()); 
pp=getch();
if (pp!=27)
if (pp==13)
goto s4;
else
goto s3;
break;
}
}
}
while (p != 6);
return 0;
}

