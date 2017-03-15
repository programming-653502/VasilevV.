#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>

using namespace std;

bool Check(int a, int i)
{
	int i1, i2;
	i1 = i/10;
	i2 = i - i1*10;
	if (a<100)
	{
		int b, c;
		b = a/10;
		c = a - b*10;
		if (b+c==i1+i2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		int b, c, d;
		b = a/100;
		c = (a - b*100)/10;
		d = a - b*100 - c*10;
		if (b+c+d==i1+i2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void CheckAll()
{
	int a, S;
	cout<<"All: ";
	for (int i=10; i<100; i++)
	{
		S = 0;
		for (int i0=2; i0<10; i0++)
		{
			a = i*i0;
			if (Check(a,i))
			{
				S++;
			}
			if (S==8)
			{
				cout<<i<<" | ";
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	for (int i0=2; i0<10; i0++)
	{
		cout<<i0<<": ";
		for (int i=10; i<100; i++)
		{
			a = i0*i;
			if (Check(a,i))
			{
				cout<<i<<" | ";
			}
		}
		cout<<"\n";
	}
	CheckAll();
	getch();
	return 0;
}
