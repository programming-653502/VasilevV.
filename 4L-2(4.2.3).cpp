#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <cmath>

using namespace std;

bool CheckL2(char A[3])
{
	if (A[1]!='\0')
	{
		printf("Error.\n\n(Press any key to return)");
		getch();
		return true;
	}
	if (A[0]!='1'&&A[0]!='2')
	{
		printf("Error.\n\n(Press any key to return)");
		getch();
		return true;
	}
	return false;
}

double SumOfNum(char A[128])
{
	int k, dot, end;
	double F=0, f;
	char Num[128];
	for (int i=0; i<128; i++)
	{
		if ((A[i]=='0'||A[i]=='1'||A[i]=='2'||A[i]=='3'||A[i]=='4'||A[i]=='5'||A[i]=='6'||A[i]=='7'||A[i]=='8'||A[i]=='9')&&(i==0||A[i-1]==' '))
		{
			for (int i=0; i<128; i++)
			{
				Num[i] = '\0';
			}
			Num[0] = A[i];
			k = 1;
			while (A[i+k]=='0'||A[i+k]=='1'||A[i+k]=='2'||A[i+k]=='3'||A[i+k]=='4'||A[i+k]=='5'||A[i+k]=='6'||A[i+k]=='7'||A[i+k]=='8'||A[i+k]=='9'||A[i+k]=='.')
			{
				Num[k] = A[i+k];
				k++;
			}
			k = 0;
			dot = 0;
			end = 0;
			while (1)
			{
				k++;
				if (Num[k]=='.')
				{
					dot = k;
				}
				if (Num[k]=='\0')
				{
					end = k-1;
					break;
				}
			}
			if (dot==end)
			{
            	dot = 0;
			}
			if (dot!=0)
			{
				for (k=dot-1; k>=0; k--)
				{
					F += pow(10.,dot-k-1)*(Num[k]-48);
				}
				for (k=dot+1; k<=end; k++)
				{
					F += pow(10.,dot-k)*(Num[k]-48);
				}
			}
			else
			{
				for (k=end; k>=0; k--)
				{
					F += pow(10.,end-k)*(Num[k]-48);
				}
            }
		}
	}
	return F;
}

int NumOfNum(char A[128])
{
	int F=0, k;
	char Num[128];
	for (int i=0; i<128; i++)
	{
		if ((A[i]=='0'||A[i]=='1'||A[i]=='2'||A[i]=='3'||A[i]=='4'||A[i]=='5'||A[i]=='6'||A[i]=='7'||A[i]=='8'||A[i]=='9')&&(i==0||A[i-1]==' '))
		{
			for (int i=0; i<128; i++)
			{
				Num[i] = '\0';
			}
			Num[0] = A[i];
			k = 1;
			while (A[i+k]=='0'||A[i+k]=='1'||A[i+k]=='2'||A[i+k]=='3'||A[i+k]=='4'||A[i+k]=='5'||A[i+k]=='6'||A[i+k]=='7'||A[i+k]=='8'||A[i+k]=='9'||A[i+k]=='.')
			{
				Num[k] = A[i+k];
				k++;
			}
			F++;
		}
	}
	return F;
}

double CountFinal(int Num, double Sum)
{
    return Sum/Num;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char L[3];
	bool A;
	while (1)
	{
		Begin:
        A = true;
		while (A)
		{
			clrscr();
			printf("Choose:\n1.Performing.\n2.Exit.\n\n");
			gets(L);
			A = CheckL2(L);
		}
		clrscr();
		if (L[0]=='1')
		{
			int Num;
			double Sum, Final;
			char Buff[128];
			FILE *f;
			f = fopen("Numbers.txt","r");
			if (!f)
			{
				printf("File not found.\n\n(Press any key to go to menu.)");
				getch();
				clrscr();
				goto Begin;
			}
			while (fgets(Buff, 128, f)!=NULL)
			{
				printf("%s",Buff);
			}
			Sum = SumOfNum(Buff);
			Num = NumOfNum(Buff);
			Final = CountFinal(Num,Sum);
			printf("\n\nSum=%f;\nNum=%d;\nFinal=%f;\n\n(Press any key to go to menu.)",Sum,Num,Final);
       		getch();
			clrscr();
		}
		else
		{
        	return 0;
		}
	}
