#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>

using namespace std;

bool CheckL2(char A[3])
{
	if (A[1]!='\0')
	{
		printf("Error.\n\n(Press any key to return)");
		getch();
		clrscr();
		return true;
	}
	if (A[0]!='1'&&A[0]!='2')
	{
		printf("Error.\n\n(Press any key to return)");
		getch();
		clrscr();
		return true;
	}
	return false;
}

bool CheckInt2(char A[4])
{
	if (A[2]!='\0')
	{
		if (A[1]!='\0')
		{
			printf("Error.\n\n(Press any key to return)");
			getch();
			clrscr();
			return true;
		}
	}
	for (int i=0; i<2; i++)
	{
		if (A[i]!='0'&&A[i]!='1'&&A[i]!='2'&&A[i]!='3'&&A[i]!='4'&&A[i]!='5'&&A[i]!='6'&&A[i]!='7'&&A[i]!='8'&&A[i]!='9'&&A[i]!='\0')
		{
			printf("Error.\n\n(Press any key to return)");
			getch();
			clrscr();
			return true;
		}
	}
	return false;
}

int ConvertInt2(char A[4])
{
	if (A[1]=='\0')
	{
		return A[0]-48;
	}
	else
	{
		return (A[0]-48)*10 + A[1]-48;
    }
}

void Perf(int a)
{
	clrscr();
	int k;
	char S[52], **A = new char*[256];
	for (int i=0; i<a; i++)
	{
		A[i] = new char [256];
	}
	for (int i=0; i<a; i++)
	{
		printf("%d string:",i+1);
		gets(A[i]);
	}
	for (int i=0; i<26; i++)
	{
		S[i] = i+65;
	}
	for (int i=0; i<26; i++)
	{
		S[i+26] = i+97;
	}
	clrscr();
	for (int i1=0; i1<a; i1++)
	{
		for (int i2=0; i2<256; i2++)
		{
			if ((A[i1][i2]>64&&A[i1][i2]<91)||(A[i1][i2]>64&&A[i1][i2]<123))
			{
                k = 0;
				for (int i=0; i<52; i++)
				{
					if (A[i1][i2]==S[i])
					{
						S[i] = 219;
						break;
					}
					else
					{
						k++;
					}
					if (k==51)
					{
                        A[i1][i2] = ' ';
					}
				}
			}
		}
	}
	for (int i1=0; i1<a; i1++)
	{
		for (int i2=0; i2<256; i2++)
		{
			if (((A[i1][i2]>64&&A[i1][i2]<91)||(A[i1][i2]>64&&A[i1][i2]<123))&&(i2==0||A[i1][i2-1]==' ')&&(i2==256||A[i1][i2+1]==' '||A[i1][i2+1]=='.'||A[i1][i2+1]==','||A[i1][i2+1]=='!'||A[i1][i2+1]=='?'||A[i1][i2+1]=='\0'))
			{
				printf("%c ", A[i1][i2]);
			}
		}
	}
	for (int i=0; i<256; i++)
	{
		delete[]A[i];
	}
	printf("\n\n(Press any key to go to menu.)");
	getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
	int Num;
	char L[3], sNum[4];
	bool A;
	while (1)
	{
		A = true;
		clrscr();
		while (A)
		{
			printf("Choose:\n1.Performing.\n2.Exit.\n\n");
			gets(L);
			A = CheckL2(L);
		}
		clrscr();
		if (L[0]=='1')
		{
			A = true;
            clrscr();
			while (A)
			{
				printf("Enter the strings number(2 symbols):");
				gets(sNum);
				A = CheckInt2(sNum);
			}
			Num = ConvertInt2(sNum);
			Perf(Num);
		}
		if (L[0]=='2')
		{
			return 0;
        }
	}
}
