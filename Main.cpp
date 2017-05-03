//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

#include "Main.h"
#include "Delivery.h"
#include "Stat.h"
#include "Order.h"
#include "History.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

using namespace std;

//----------------------------------- Вспомогательные функции
int Char16ToInt(char Num[16])
{
	int Res = 0;
	for (int i = 0; i < strlen(Num); i++)
	{
		Res += (Num[strlen(Num) - i - 1] - 48)*pow(10.,i);
	}
	return Res;
}
int IntLenth(int Number)
{
	int lenth = 1;
	while (pow(10.,lenth) <= Number)
	{
		lenth++;
	}
    return lenth;
}
//--------------- Общие переменные
int BooksInStock, NumberOfOrders;
BookList MainBooksList;
OrderList MainOrdersList;
//--------------- Функции обновления
void UploadDeliveryComboBox()
{
	DeliveryForm->NamesComboBox->Items->Clear();
	BookInfo *temp = new BookInfo;
	for (int i = 1; i <= BooksInStock; i++)
	{
		temp = MainBooksList.LoadBook(i);
        DeliveryForm->NamesComboBox->Items->Add(temp->name);
	}
}
void UploadOrderComboBox()
{
	OrderForm->NamesComboBox->Items->Clear();
	BookInfo *temp = new BookInfo;
	for (int i = 1; i <= BooksInStock; i++)
	{
		temp = MainBooksList.LoadBook(i);
        OrderForm->NamesComboBox->Items->Add(temp->name);
	}
}
void UploadStatistics()
{
	StatisticsForm->MainStringGrid->RowCount = BooksInStock + 1;
	StatisticsForm->MainStringGrid->Cells[0][0] = "Автор";
	StatisticsForm->MainStringGrid->Cells[1][0] = "Название";
	StatisticsForm->MainStringGrid->Cells[2][0] = "Жанр";
	StatisticsForm->MainStringGrid->Cells[3][0] = "На складе";
	StatisticsForm->MainStringGrid->Cells[4][0] = "Цена закупки, р";
	StatisticsForm->MainStringGrid->Cells[5][0] = "Цена продажи, р";
	BookInfo *temp = new BookInfo;
	for (int i = 0; i < BooksInStock; i++)
	{
		temp = MainBooksList.LoadBook(i+1);
		StatisticsForm->MainStringGrid->Cells[0][i + 1] = temp->author;
		StatisticsForm->MainStringGrid->Cells[1][i + 1] = temp->name;
		StatisticsForm->MainStringGrid->Cells[2][i + 1] = temp->genre;
		StatisticsForm->MainStringGrid->Cells[3][i + 1] = temp->number;
		StatisticsForm->MainStringGrid->Cells[4][i + 1] = temp->inprice;
		StatisticsForm->MainStringGrid->Cells[5][i + 1] = temp->outprice;
	}
	int NuberOfAllBooksInStock = 0;
	for (int i = 1; i <= BooksInStock; i++)
	{
		temp = MainBooksList.LoadBook(i);
		NuberOfAllBooksInStock += temp->number;
	}
	StatisticsForm->BooksInStockLabel->Caption = IntToStr(BooksInStock)+" | "+IntToStr(NuberOfAllBooksInStock);
	int AllPriceIn = 0, AllPriceOut = 0;
	for (int i = 1; i <= BooksInStock; i++)
	{
		temp = MainBooksList.LoadBook(i);
		AllPriceIn += temp->inprice * temp->number;
		AllPriceOut += temp->outprice * temp->number;
	}
	int SoldBooks = 0;
	for (int i = 1; i <= NumberOfOrders; i++)
	{
		temp = MainOrdersList.LoadOrder(i);
        SoldBooks += temp->number;
	}
	int FullProfit = 0;
	for (int i = 1; i <= NumberOfOrders; i++)
	{
		temp = MainOrdersList.LoadOrder(i);
    	FullProfit += temp->number*temp->outprice;
	}
	StatisticsForm->BooksInStockLabel->Caption = IntToStr(BooksInStock)+" | "+IntToStr(NuberOfAllBooksInStock);
	StatisticsForm->AllPriceLabel->Caption = IntToStr(AllPriceIn)+" | "+IntToStr(AllPriceOut);
	StatisticsForm->NumberOfOrdersLabel->Caption = NumberOfOrders;
	StatisticsForm->NumberOfSoldLabel->Caption = SoldBooks;
	StatisticsForm->FullProfitLabel->Caption = FullProfit;
}
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
//--------------- Загрузка Данных
	char Buff[8192];
	char Name[30], Number[16];
	TFileStream *NumbersStream = new TFileStream("Numbers.txt",fmOpenRead);
	TFileStream *BooksStream = new TFileStream("Books.txt",fmOpenRead);
	TFileStream *OrdersStream = new TFileStream("Orders.txt",fmOpenRead);
	NumbersStream->Read(Buff,sizeof(Buff));
	for (int i = 0; i < 16; i++)
	{
		if (Buff[i] == ' ')
		{
			Number[i] = '\0';
			break;
		}
		Number[i] = Buff[i];
	}
	BooksInStock = Char16ToInt(Number);
	for (int i = 0; i < 16; i++)
	{
		if (Buff[i] == ' ')
		{
			Number[i] = '\0';
			break;
		}
		Number[i] = Buff[i + 20];
	}
	NumberOfOrders = Char16ToInt(Number);
	BooksStream->Read(Buff,sizeof(Buff));
	BookInfo *temp = new BookInfo;
	for (int i = 0; i < BooksInStock; i++)
	{
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*162] == ' '&&Buff[k + i*162 + 1] == ' ')
			{
				Name[k] = '\0';
            	break;
			}
			Name[k] = Buff[k + i*162];
		}
		temp->author = Name;
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*162 + 34] == ' '&&Buff[k + i*162 + 35] == ' ')
			{
				Name[k] = '\0';
            	break;
			}
			Name[k] = Buff[k + i*162 + 34];
		}
		temp->name = Name;
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*162 + 68] == ' '&&Buff[k + i*162 + 69] == ' ')
			{
				Name[k] = '\0';
            	break;
			}
			Name[k] = Buff[k + i*162 + 68];
		}
		temp->genre = Name;
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*162 + 102] == ' ')
			{
				Number[k] = '\0';
            	break;    
			}
			Number[k] = Buff[k + i*162 + 102];
		}
		temp->number = Char16ToInt(Number);
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*162 + 122] == ' ')
			{
				Number[k] = '\0';
				break;
			}
			Number[k] = Buff[k + i*162 + 122];
		}
		temp->inprice = Char16ToInt(Number);
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*162 + 142] == ' ')
			{
				Number[k] = '\0';
				break;    
			}
			Number[k] = Buff[k + i*162 + 142];
		}
		temp->outprice = Char16ToInt(Number);
    	MainBooksList.AddBook(temp);
	}
	OrdersStream->Read(Buff,sizeof(Buff));
	for (int i = 0; i < NumberOfOrders; i++)
	{
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*74] == ' '&& Buff[k + i*74 + 1] == ' ')
			{
				Name[k] = '\0';
            	break;
			}
			Name[k] = Buff[k + i*74];
		}
		temp->name = Name;
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*74 + 34] == ' ')
			{
				Number[k] = '\0';
            	break;
			}
			Number[k] = Buff[k + i*74 + 34];
		}
		temp->number = Char16ToInt(Number);
		for (int k = 0; k < 30; k++)
		{
			if (Buff[k + i*74 + 54] == ' ')
			{
				Number[k] = '\0';
            	break;
			}
			Number[k] = Buff[k + i*74 + 54];
		}
		temp->outprice = Char16ToInt(Number);
		MainOrdersList.AddOrder(temp);
	}
	delete NumbersStream;
	delete BooksStream;
	delete OrdersStream;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::StatisticsButtonClick(TObject *Sender)
{
	MainForm->Visible = false;
	UploadStatistics();
	StatisticsForm->Visible = true;	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExitButtonClick(TObject *Sender)
{
//--------------- Сохранение Данных
	int Lenth;
	char Buff[8192];
	TFileStream *NumbersStream = new TFileStream("Numbers.txt",fmOpenWrite);
	for (int i = 0; i < IntLenth(BooksInStock); i++)
	{
		Buff[i] = BooksInStock/pow(10.,IntLenth(BooksInStock) - i - 1) + 48;
	}
	for (int i = IntLenth(BooksInStock); i < 16; i++)
	{
		Buff[i] = ' ';
	}
	Buff[16] = '|';
	Buff[17] = '|';
	Buff[18] = '\r';
	Buff[19] = '\n';
	for (int i = 0; i < IntLenth(NumberOfOrders); i++)
	{
		Buff[i + 20] = NumberOfOrders/pow(10.,IntLenth(NumberOfOrders) - i - 1) + 48;
	}
	for (int i = IntLenth(NumberOfOrders); i < 16; i++)
	{
		Buff[i + 20] = ' ';
	}
	Buff[36] = '|';
	Buff[37] = '|';
	Buff[38] = '\r';
	Buff[39] = '\n';
	NumbersStream->Position = soFromBeginning;
	NumbersStream->Write(&Buff,40);
	delete NumbersStream;
	TFileStream *BooksStream = new TFileStream("Books.txt",fmOpenWrite);
	BookInfo *temp = new BookInfo;
	Buff[0] = '\0';
	for (int i = 0; i < BooksInStock; i++)
	{
		temp = MainBooksList.LoadBook(i+1);
		strcat(Buff, AnsiString(temp->author).c_str());
		for (int k = temp->author.Length(); k < 30; k++)
		{
			Buff[k + i*162] = ' ';
		}
		Buff[30 + i*162] = '|';
		Buff[31 + i*162] = '|';
		Buff[32 + i*162] = '\r';
		Buff[33 + i*162] = '\n';
		Buff[34 + i*162] = '\0';
		strcat(Buff, AnsiString(temp->name).c_str());
		for (int k = temp->name.Length(); k < 30; k++)
		{
			Buff[k + i*162 + 34] = ' ';
		}
		Buff[64 + i*162] = '|';
		Buff[65 + i*162] = '|';
		Buff[66 + i*162] = '\r';
		Buff[67 + i*162] = '\n';
		Buff[68 + i*162] = '\0';
		strcat(Buff, AnsiString(temp->genre).c_str());
		for (int k = temp->genre.Length(); k < 30; k++)
		{
			Buff[k + i*162 + 68] = ' ';
		}
		Buff[98 + i*162] = '|';
		Buff[99 + i*162] = '|';
		Buff[100 + i*162] = '\r';
		Buff[101 + i*162] = '\n';
		Lenth = IntLenth(temp->number);
		for (int k = 0; k < Lenth; k++)
		{
			Buff[k + i*162 + 102] = temp->number/pow(10.,Lenth - k - 1) + 48;
			int a = temp->number/pow(10.,Lenth - k - 1);
			int b = pow(10.,Lenth - k - 1);
			temp->number -= a*b;
		}
		for (int k = Lenth; k < 16; k++)
		{
			Buff[k + i*162 + 102] = ' ';
		}
		Buff[118 + i*162] = '|';
		Buff[119 + i*162] = '|';
		Buff[120 + i*162] = '\r';
		Buff[121 + i*162] = '\n';
		Lenth = IntLenth(temp->inprice);
		for (int k = 0; k < Lenth; k++)
		{
			Buff[k + i*162 + 122] = temp->inprice/pow(10.,Lenth - k - 1) + 48;
			int a = temp->number/pow(10.,Lenth - k - 1);
			int b = pow(10.,Lenth - k - 1);
			temp->number -= a*b;
		}
		for (int k = Lenth; k < 16; k++)
		{
			Buff[k + i*162 + 122] = ' ';
		}
		Buff[138 + i*162] = '|';
		Buff[139 + i*162] = '|';
		Buff[140 + i*162] = '\r';
		Buff[141 + i*162] = '\n';
		Lenth = IntLenth(temp->outprice);
		for (int k = 0; k < Lenth; k++)
		{
			Buff[k + i*162 + 142] = temp->outprice/pow(10.,Lenth - k - 1) + 48;
			int a = temp->number/pow(10.,Lenth - k - 1);
			int b = pow(10.,Lenth - k - 1);
			temp->number -= a*b;
		}
		for (int k = Lenth; k < 16; k++)
		{
			Buff[k + i*162 + 142] = ' ';
		}
		Buff[158 + i*162] = '|';
		Buff[159 + i*162] = '|';
		Buff[160 + i*162] = '\r';
		Buff[161 + i*162] = '\n';
		if (i != BooksInStock - 1)
		{
        	Buff[162 + i*162] = '\0';
		}
	}
	BooksStream->Write(Buff,162*BooksInStock);
	delete BooksStream;
	TFileStream *OrdersStream = new TFileStream("Orders.txt",fmOpenWrite);
	Buff[0] = '\0';
	for (int i = 0; i < NumberOfOrders; i++)
	{
    	temp = MainOrdersList.LoadOrder(i + 1);
		strcat(Buff, AnsiString(temp->name).c_str());
		for (int k = temp->name.Length(); k < 30; k++)
		{
			Buff[k + i*74] = ' ';
		}
		Buff[30 + i*74] = '|';
		Buff[31 + i*74] = '|';
		Buff[32 + i*74] = '\r';
		Buff[33 + i*74] = '\n';
		Buff[34 + i*74] = '\0';
		Lenth = IntLenth(temp->number);
		for (int k = 0; k < Lenth; k++)
		{
			Buff[k + i*74 + 34] = temp->number/pow(10.,Lenth - k - 1) + 48;
			int a = temp->number/pow(10.,Lenth - k - 1);
			int b = pow(10.,Lenth - k - 1);
			temp->number -= a*b;
		}
		for (int k = Lenth; k < 16; k++)
		{
			Buff[k + i*74 + 34] = ' ';
		}
		Buff[50 + i*74] = '|';
		Buff[51 + i*74] = '|';
		Buff[52 + i*74] = '\r';
		Buff[53 + i*74] = '\n';
		Lenth = IntLenth(temp->outprice);
		for (int k = 0; k < Lenth; k++)
		{
			Buff[k + i*74 + 54] = temp->outprice/pow(10.,Lenth - k - 1) + 48;
			int a = temp->outprice/pow(10.,Lenth - k - 1);
			int b = pow(10.,Lenth - k - 1);
			temp->outprice -= a*b;
		}
		for (int k = Lenth; k < 16; k++)
		{
			Buff[k + i*74 + 54] = ' ';
		}
		Buff[70 + i*74] = '|';
		Buff[71 + i*74] = '|';
		Buff[72 + i*74] = '\r';
		Buff[73 + i*74] = '\n';
		Buff[74 + i*74] = '\0';
	}
	OrdersStream->Write(Buff,74*NumberOfOrders);
	delete OrdersStream;
//--------------- Close
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DeliveryButtonClick(TObject *Sender)
{
	MainForm->Visible = false;
	UploadDeliveryComboBox();
	DeliveryForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OrderButtonClick(TObject *Sender)
{
	MainForm->Visible = false;
	UploadOrderComboBox();
    OrderForm->ErrorLabel1->Visible = false;
	OrderForm->ErrorLabel2->Visible = false;
	OrderForm->ErrorLabel3->Visible = false;
	OrderForm->Visible = true;
}
//---------------------------------------------------------------------------

