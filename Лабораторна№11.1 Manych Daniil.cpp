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
cout << " ������� ���� ";
gotoxy(20,7); cout << " 1. �������� ������";
gotoxy(20,8); cout << " 2. �� ������";
gotoxy(20,9); cout << " 3. ����� �� ��'�� ������ {-[^-^]-}";
gotoxy(20,12); cout << " 6. �����";
gotoxy(20,13); cout << " ������ ����� ������ : ";
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
printf("������ ������ ����� %d : \n", i+1);
cout << "������ ����� �����, �� ���������� � ������ ����� -> ";
cin >>b_m[i].name;
t=strlen(b_m[i].name);
for (j = t; j < ln-2; j++)
strcat(b_m[i].name," ");
cout << "������ ������� ������� -> ";
cin >> b_m[i].page;
cout << "������ ��'� ������ -> ";
cin >> b_m[i].avtor;
t2=strlen(b_m[i].avtor);
for(j2=t2; j2<ln-2; j2++)
strcat(b_m[i].avtor," ");
printf("��� ����������� ��������� -> Enter, ��� ������ -> Esc \n");
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
printf(" ������ � ����� �� ��\n");
goto s6;
}
for (i=0; i < n; i++)
{
if (pk==0)
{
system("cls");
cout<<" ����� ������ \n"
<<" _____________________________________\n"
<<" | � | ����� ����� | ʳ�. ����. |��'� ������ |\n"
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
printf(" ������ � ����� %d\n",n);
printf(" ��������� Enter ��� ����������� ��������� ������\n");
while (!kbhit()); 
}
}
s6:
printf("��� ���������� ��������� ������ ��������� -> Enter, ��� ������ -> Esc \n");
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
printf(" ������ � ����� ����\n");
goto s5;
}
cout << "������ ��'� ������  -> ";
cin>>sear;
for (i=0; i < n; i++)
{
if (pk==0)
{
system("cls");
cout<<" ����� ������ \n"
<<" _____________________________________\n"
<<" | � | ����� ����� | ʳ�. ����. |��'� ������ |\n"
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
printf(" ������ � ����� %d\n",n);
printf(" ��������� Enter ��� ����������� ��������� ������\n");
while (!kbhit()); 
}
}
s5:
printf("��� ���������� ��������� ������� �������� -> Enter, ��� ������ -> Esc \n",n);
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

