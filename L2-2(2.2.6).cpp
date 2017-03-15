#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <math.h>

using namespace std;

//Íå ðåêîìåíäóåòñÿ ââîäèòü X>1, ò.ê. äëÿ ýòîãî íåîáõîäèìî ñ÷èòàòü ôàêòîðèàëû îò áîëüøèõ ÷èñåë

bool CheckN(char N[4])
{
	if (N[2]!='\0')
	{
		if (N[1]!='\0')
		{
			cout<<"Error.\n";
			return true;
		}
	}
	for (int i=0; i<2; i++)
	{
		if (N[i]!='0'&&N[i]!='1'&&N[i]!='2'&&N[i]!='3'&&N[i]!='4'&&N[i]!='5'&&N[i]!='6'&&N[i]!='7'&&N[i]!='8'&&N[i]!='9'&&N[i]!='\0')
		{
			cout<<"Error.\n";
			return true;
		}
	}
	return false;
}

bool CheckX(char X[34])
{
	int l1=0, l2=0;
	if (X[0]=='.')
	{
    	return true;
	}
	for (int i=0; i<33; i++)
	{
		if (X[i]!='\0')
		{
			l1++;
		}
	}
	if (l1==33)
	{
		cout<<"Error.\n";
		return true;
	}
	for (int i=0; i<32; i++)
	{
		if (X[i]=='\0')
		{
			break;
		}
		if (X[i]=='.')
		{
			l2++;
		}
		if (X[i]!='0'&&X[i]!='1'&&X[i]!='2'&&X[i]!='3'&&X[i]!='4'&&X[i]!='5'&&X[i]!='6'&&X[i]!='7'&&X[i]!='8'&&X[i]!='9'&&X[i]!='.')
		{
			cout<<"Error.\n";
			return true;
		}
	}
	if (l2>1)
	{
		cout<<"Error.\n";
		return true;
	}
	return false;
}

bool CheckE(char E[18])
{
	int l1=0, l2=0;
	for (int i=0; i<17; i++)
	{
		if (E[i]!='\0')
		{
			l1++;
		}
	}
	if (l1==17)
	{
		cout<<"Error.\n";
		return true;
	}
	for (int i=0; i<16; i++)
	{
		if (E[i]=='\0')
		{
			break;
		}
		if (E[i]=='.')
		{
			l2++;
		}
		if (E[i]!='0'&&E[i]!='1'&&E[i]!='2'&&E[i]!='3'&&E[i]!='4'&&E[i]!='5'&&E[i]!='6'&&E[i]!='7'&&E[i]!='8'&&E[i]!='9'&&E[i]!='.')
		{
			cout<<"Error.\n";
			return true;
		}
	}
	if (l2>1)
	{
		cout<<"Error.\n";
		return true;
	}
	return false;
}

int ConvertN(char N[4])
{
	int p, a=0;
	for (int i=0; i<3; i++)
	{
		if (N[i]=='\0')
		{
			p = i-1;
			break;
		}
	}
	for (int i=p; i>=0; i--)
	{
		a += (N[i] - 48)*pow(10.,p-i);
	}
	return a;
}

double ConvertX(char X[34])
{
	int dot, p;
	double a=0;
	for (int i=1; i<32; i++)
	{
		if (X[i]=='.')
		{
			dot = i;
			break;
		}
		else
		{
			dot = '0';
		}
	}
	if (dot!='0')
	{
		for (int i=dot-1; i>=0; i--)
		{
			a += (X[i]-48)*pow(10.,dot-1-i);
		}
		for (int i=dot+1; i<32; i++)
		{
			if (X[i]=='\0')
			{
				break;
			}
			a += (X[i]-48)*pow(10.,dot-i);
		}
	}
	else
	{
		for (int i=0; i<33; i++)
		{
			if (X[i]=='\0')
			{
				p = i;
				break;
			}
		}
		for (int i=p-1; i>=0; i--)
		{
			a += (X[i]-48)*pow(10.,p-1-i);
		}
	}
	return a;
}

double ConvertE(char E[18])
{
	int dot, p;
    double a=0;
	for (int i=1; i<16; i++)
	{
		if (E[i]=='.')
		{
			dot = i;
			break;
		}
		else
		{
			dot = '0';
		}
	}
	if (dot!='0')
	{
		for (int i=dot-1; i>=0; i--)
		{
			a += (E[i]-48)*pow(10.,dot-1-i);
		}
		for (int i=dot+1; i<32; i++)
		{
			if (E[i]=='\0')
			{
				break;
			}
			a += (E[i]-48)*pow(10.,dot-i);
		}
	}
	else
	{
		for (int i=0; i<17; i++)
		{
			if (E[i]=='\0')
			{
				p = i;
				break;
			}
		}
		for (int i=p-1; i>=0; i--)
		{
			a += (E[i]-48)*pow(10.,p-1-i);
		}
	}
	return a;
}

int Fact(int a)
{
	if (a>1)
	{
		return a*Fact(a-1);
	}
	else
	{
		return 1;
	}
}

void First(int n, double x)
{
	double left, right=0;
	left = sin(x);
	for (int i=1; i<=n; i++)
	{
		right+= pow(-1.,i-1)*pow(x,2*i-1)/Fact(2*i-1);
	}
	cout<<"\nright="<<right<<".\nleft="<<left<<".\n(Press any key.)";
	getch();
}

void Second(double e, double x)
{
	int n=0;
	double a=10000000, right=0;
	while (a>e)
	{
		n++;
		right+= pow(-1.,n-1)*pow(x,2*n-1)/Fact(2*n-1);
		a = right - sin(x);
		if (a<0)
		{
			a = a*(-1);
		}
//      a = abs(a);
		cout<<sin(x)<<"|"<<right<<"|"<<a<<"|\n";
	}
	cout<<"N="<<n<<".\n(Press any key.)";
	getch();
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	double x, e;
	char A[10], N[4], X[34], E[18];
	bool B1, B2;
	while (1)
	{
		Choose:
		cout<<"\n--------\n1.Count whith N.\n2.Searching N with E.\n3.Exit.\n--------\n";
		cin>>A;
		if (A[0]=='1'&&A[1]=='\0')
		{
			B1 = true;
			while (B1)
			{
				cout<<"\nN(1-2symbols)=";
				cin>>N;
				B1 = CheckN(N);
			}
			B2 = true;
			while (B2)
			{
				cout<<"\nX(1-32symbols)=";
				cin>>X;
				B2 = CheckX(X);
			}
			n = ConvertN(N);
			x = ConvertX(X);
			First(n,x);
		}
		if (A[0]=='2'&&A[1]=='\0')
		{
			B1 = true;
			while (B1)
			{
				cout<<"\nE(1-16symbols)=";
				cin>>E;
				B1 = CheckE(E);
			}
			B2 = true;
			while (B2)
			{
				cout<<"\nX(1-32symbols)=";
				cin>>X;
				B2 = CheckX(X);
			}
			e = ConvertE(E);
			x = ConvertX(X);
			Second(e,x);
		}
		if (A[0]=='3'&&A[1]=='\0')
		{
			return 0;
		}
	}
}
