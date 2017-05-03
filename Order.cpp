//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Order.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TOrderForm *OrderForm;
//--------------- Вспомогательные функции
bool CheckNumber(char Num[16])
{
	if (Num[0] == '\0')
	{
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
			return true;
		}
	}
	return false;
}
//--------------- Глобальные переменные
extern int BooksInStock, NumberOfOrders;
extern BookList MainBooksList;
extern OrderList MainOrdersList;
//---------------------------------------------------------------------------
__fastcall TOrderForm::TOrderForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOrderForm::MenuButtonClick(TObject *Sender)
{
	OrderForm->Visible = false;
	MainForm->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TOrderForm::AddButtonClick(TObject *Sender)
{
	char Num[16];
	ErrorLabel1->Visible = false;
	ErrorLabel2->Visible = false;
	ErrorLabel3->Visible = false;
	if (NamesComboBox->Items->Text == "" || NamesComboBox->ItemIndex == -1 || NumberEdit->Text == "")
	{
    	ErrorLabel2->Visible = true;
	}
	else
	{
		strcpy(Num, AnsiString(NumberEdit->Text).c_str());
		if (CheckNumber(Num))
		{
			ErrorLabel3->Visible = true;
		}
		else
		{
			BookInfo *temp = new BookInfo;
			BookInfo *Btemp = new BookInfo;
			Btemp = MainBooksList.LoadBook(NamesComboBox->ItemIndex + 1);
			if (Btemp->number < NumberEdit->Text)
			{
            	ErrorLabel1->Visible = true;
			}
			else
			{
				temp->name = Btemp->name;
				temp->outprice = Btemp->outprice;
				temp->number = StrToInt(NumberEdit->Text);
				if (Btemp->number == NumberEdit->Text)
				{
					MainBooksList.RemoveBook(NamesComboBox->ItemIndex + 1, BooksInStock);
					BooksInStock--;
				}
				else
				{
					MainBooksList.ChangeNumbersOfBook(NamesComboBox->ItemIndex + 1, -StrToInt(NumberEdit->Text));
				}
				MainOrdersList.AddOrder(temp);
				NumberOfOrders++;
			}
		}
    }
}
//---------------------------------------------------------------------------
