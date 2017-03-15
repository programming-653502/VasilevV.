#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream.h>
#include <conio.h>

using namespace std;

int Days(int day, int mounth, int year)
{
	int a, b, All=0, Number=0, MD[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	a = year/4;
	b = year - a*4;
	for (int i=0; i<mounth-1; i++)
	{
		All+= MD[i];
	}
	Number = All + day;
	while (year>99)
	{
		if (year%100==0)
		{
			if (year%400!=0)
			{
				All-= 1;
			}
		}
		year-= 1;
	}
	All +=  a*1461 + (b-1)*365 + day;
	cout<<"\n"<<All<<" days from 0-year.\n"<<"Day-in-the-year-number:"<<Number<<"\n";
	return All;
}

void Weekday(int All)
{
	char D[7][12] = {{"Sunday"},{"Monday"},{"Tuesday"},{"Wednesday"},{"Thursday"},{"Friday"},{"Saturday"}};
	All = All%7;
	cout<<"Weekday:";
	for (int i=0; i<12; i++)
	{
		cout<<D[All][i];
	}
	cout<<"\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	int day, mounth, year, All;
	char date[10], M[13][10] = {{"X"},{"January"},{"February"},{"March"},{"April"},{"ìàÿ"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"Decemder"}};
	Input:
	cout<<"\nDate(XX.XX.XXXX)=";
	cin>>date;
	for (int i=0; i<10; i++)
	{
    	if ((date[i]<48||date[i]>57)&&(date[i]!='.'))
		{
			cout<<"Input error.\n";
			goto Input;
		}
	}
	day = (date[0]-48)*10 + date[1]-48;
	mounth = (date[3]-48)*10 + date[4]-48;
	year = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)*10 + date[9]-48;
	if (day>31||day<=0||mounth>12||mounth<=0||year<=0||date[2]!='.'||date[5]!='.')
	{
		cout<<"Input error.\n";
		goto Input;
	}
	cout<<day<<" ";
	for (int i=0; i<10; i++)
	{
		cout<<M[mounth][i];
	}
	cout<<" "<<year<<"year\n";
	for (int i=0; i<10; i++)
	{
		cout<<date[i];
	}
	cout<<"\n";
	All = Days(day, mounth, year);
	Weekday(All);
	cout<<"\nVersion 1.\nMade by Vital.\n\n(Press any key to exit)";
	getch();
	return 0;
}
