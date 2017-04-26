#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct Digit
{
	int value;
    Digit *next;
};

class ChainNumber
{
	Digit *Head;
	public:
		ChainNumber(){Head = NULL;}
		~ChainNumber()
		{
			while (Head!=NULL)
			{
				Digit *temp = Head->next;
				delete Head;
				Head = temp;
			}
		};
		void AddDigit(int input)
		{
			Digit *temp = new Digit;
			temp->next = Head;
			temp->value = input;
			Head = temp;
		};
		int CountDidits()
		{
			int counter = 0;
			Digit *temp = new Digit;
			if (Head != NULL)
			{
				counter++;
				temp = Head->next;
				while (1)
				{
					counter++;
					if (temp->next == NULL)
					{
						break;
					}
					temp = temp->next;
				}
/*				while (temp->next != NULL)
				{
					temp = temp->next;
					counter++;
				}  */
			}
			delete temp;
			return counter;
		};
		int LoadDigitValue(int position)
		{
			if (position == 1)
			{
				return Head->value;
			}
			else
			{
				Digit *temp = new Digit;
				temp = Head->next;
				if (position > 2)
				{
					for (int i = 3; i <= position ; i++)
					{
						temp = temp->next;
					}
				}
				return temp->value;
			}
		};
};

bool CheckL(char A[3])
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

bool CheckNumber(char Num[16])
{
	if (Num[0] == '\0')
	{
		printf("\nError\n(Press any key to return)");
		getch();
		return true;
	}
	for (int i = 0; i < 16; i++)
	{
		if (Num[i] == '\0')
		{
        	break;
		}
		if (Num[i] != '0' && Num[i] != '1' && Num[i] != '2' && Num[i] != '3' && Num[i] != '4' && Num[i] != '5' && Num[i] != '6' && Num[i] != '7' && Num[i] != '8' && Num[i] != '9')
		{
			printf("\nError\n(Press any key to return)");
			getch();
        	return true;
		}
	}
	return false;
}

int Char16ToInt(char Num[16])                 // Не понадобилось
{
	int Res = 0, a = strlen(Num);
	for (int i = 0; i < strlen(Num); i++)
	{
		Res += (Num[strlen(Num) - i - 1] - 48)*pow(10.,i);
	}
	return Res;
}

void Expand(ChainNumber Chain, char Num[])
{
	int number = 0;
	bool R;
	Digit *temp = new Digit;
	for (int i = 1; i <= Chain.CountDidits(); i++)
	{
		number += (pow(10.,Chain.CountDidits()-i)*Chain.LoadDigitValue(i));
	}
	delete temp;
	for (int i = 2; i <= number; i++)
	{
		if (number == 1)
		{
			break;
		}
		R = true;
		for (int k = 2; k < i; k++)
		{
			if (i % k == 0)
			{
				R = false;
            	break;
			}
		}
		if (number % i == 0 && R == true)
		{
			printf("\n%d",i);
			number /= i;
			i--;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char L[3], Num[16];  // L - "рычаг"
	bool B;
	while(1)
	{
		B = true;
		while (B)
		{
			clrscr();
			printf("Choose:\n1.Perform.\n2.Exit.\n");
			gets(L);
			B = CheckL(L);
		}
		if (L[0] == '1')
		{
			B = true;
			while (B)
			{
				clrscr();
				printf("Enter the number:");
				gets(Num);
				B = CheckNumber(Num);
			}
			ChainNumber MainChain;
			for (int i = 0; i < strlen(Num); i++)
			{
				MainChain.AddDigit(Num[strlen(Num)-i-1] - 48);
			}
			Expand(MainChain,Num);
			getch();
		}
		else
		{
			break;
		}
	}
}
