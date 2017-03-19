#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

bool CheckMenuInt1(char A[3])
{
	if (A[1]!='\0')
	{
		cout<<"Error.\n\n(Press any key to go to menu.)";
		getch();
		clrscr();
		return true;
	}
	if (A[0]!='0'&&A[0]!='1'&&A[0]!='2'&&A[0]!='3')
	{
		cout<<"Error.\n\n(Press any key to go to menu.)";
		getch();
		clrscr();
		return true;
	}
	return false;
}

bool CheckL(char A[3])
{
	if (A[1]!='\0')
	{
		cout<<"Error.\n\n(Press any key to return.)";
		getch();
		clrscr();
		return true;
	}
	if (A[0]!='Y'&&A[0]!='y'&&A[0]!='+'&&A[0]!='n'&&A[0]!='N'&&A[0]!='-')
	{
		cout<<"Error.\n\n(Press any key to return.)";
		getch();
		clrscr();
		return true;
	}
	return false;
}

int CountSqlen(int len)
{
	int x=1;
	while (pow(x, 2.) < len)
	{
		x++;
	}
	return x;
}

void Enc(char M[1024], int a, int len)
{
	int P[4]={1,0,-1,0}, i, xi=3, yi=0, x=0, y=0, Count=0, c=0, ci=0;
	char L[3], **A = new char*[a];
	bool C;
	for (i=0; i<a; i++)
	{
		A[i] = new char [a];
	}
	for (int i1=0; i1<a; i1++)
	{
		for (int i2=0; i2<a; i2++)
		{
			A[i1][i2] = '~';
		}
	}
	while (1)
	{
		A[y][x] = M[Count];
		Count++;
		if ((x==c&&y==a-c-1)||(x==a-c-1&&y==a-c-1)||(x==a-c-1&&y==c)||(x==c+1&&y==c))
		{
			ci++;
        	xi++;
			yi++;
			if (xi==4)
			{
				xi -= 4;
			}
			if (yi==4)
			{
				yi -= 4;
			}
			if (ci>3)
			{
				c++;
				ci -= 4;
			}
		}
		x += P[xi];
		y += P[yi];
		if (Count==len)
		{
			break;
		}
	}
	Count = 0;
	for (int i1=0; i1<a; i1++)
	{
		for (int i2=0; i2<a; i2++)
		{
			M[Count] = A[i1][i2];
			Count++;
		}
	}
	for (i=0; i<len; i++)
	{
		cout<<M[i];
	}
	printf("\n");
	while (C)
	{
		printf("\n Do you want to see the matrix(y/n,Y/N,+/-)?\n\n");
		gets(L);
		C = CheckL(L);
	}
	if (L[0]=='Y'||L[0]=='y'||L[0]=='+')
	{
		for (int i1=0; i1<a; i1++)
		{
			for (int i2=0; i2<a; i2++)
			{
				printf("%c ",A[i1][i2]);
			}
			printf("\n");
		}
	}
	for (i=0; i<a; i++)
	{
		delete[]A[i];
	}
	delete[]A;
	printf("\n\n(Press any key to go to menu.)");
	getch();
	clrscr();
}

void Dec(char M[1024], int a, int len)
{
	int P[4]={1,0,-1,0}, x=0, y=0, c=0, xi=3, yi=0, ci=0, Count=0;
	len = strlen(M);
	char **A = new char*[a];
	for (int i=0; i<a; i++)
	{
		A[i] = new char [a];
	}
	for (int i1=0; i1<a; i1++)
	{
		for (int i2=0; i2<a; i2++)
		{
			A[i1][i2] = M[Count];
			Count++;
		}
	}
	Count = 0;
	while (1)
	{
		M[Count] = A[y][x];
		Count++;
		if ((x==c&&y==a-c-1)||(x==a-c-1&&y==a-c-1)||(x==a-c-1&&y==c)||(x==c+1&&y==c))
		{
			ci++;
        	xi++;
			yi++;
			if (xi==4)
			{
				xi -= 4;
			}
			if (yi==4)
			{
				yi -= 4;
			}
			if (ci>3)
			{
				c++;
				ci -= 4;
			}
		}
		x += P[xi];
		y += P[yi];
		if (Count==len)
		{
			break;
		}
	}
	for (int i1=0; i1<a; i1++)
		{
			for (int i2=0; i2<a; i2++)
			{
				printf("%c ",A[i1][i2]);
			}
			printf("\n");
		}
	printf("\n%s",M);
	for (int i=0; i<a; i++)
	{
		delete[]A[i];
	}
	delete[]A;
	printf("\n\n(Press any key to go to menu.)");
	getch();
	clrscr();
}
int _tmain(int argc, _TCHAR* argv[])
{
	char L[3];
	bool A;
	while (1)
	{
		A = true;
		while (A)
		{
			printf("Choose:\n1.Encrypting.\n2.Deciphering.\n3.Exit.\n\n");
			gets(L);
			A = CheckMenuInt1(L);
		}
		clrscr();
		if (L[0]=='1')
		{
			char s='0', Mes[1025];
			printf("Write your message(max 1024 symbols):");
			gets(Mes);
			int len = strlen(Mes);
			int a = CountSqlen(len);
			Enc(Mes,a,len);
		}
		if (L[0]=='2')
		{
			char Mes[1025];
			printf("Write your message(max 1024 symbols):");
			gets(Mes);
			int len = strlen(Mes);
			int a = CountSqlen(len);
			Dec(Mes,a, len);
		}
		if (L[0]=='3')
		{
			return 0;
		}
	}
}
