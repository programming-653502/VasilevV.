//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Delivery.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDeliveryForm *DeliveryForm;
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
__fastcall TDeliveryForm::TDeliveryForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDeliveryForm::MenuButtonClick(TObject *Sender)
{
	ConstLabel1->Visible = false;
	ConstLabel2->Visible = false;
	ConstLabel3->Visible = false;
	ConstLabel4->Visible = false;
	ConstLabel5->Visible = false;
	ConstLabel6->Visible = false;
	ErrorLabel1->Visible = false;
	ErrorLabel2->Visible = false;
	AuthorEdit->Visible = false;
	NameEdit->Visible = false;
	GenreEdit->Visible = false;
	NumberEdit->Visible = false;
	InEdit->Visible = false;
	OutEdit->Visible = false;
	NamesComboBox->Visible = false;
	AddButton->Visible = false;
	DeliveryForm->Visible = false;
	MainForm->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TDeliveryForm::OldButtonClick(TObject *Sender)
{
	ConstLabel1->Visible = false;
	ConstLabel2->Visible = true;
	ConstLabel3->Visible = false;
	ConstLabel4->Visible = true;
	ConstLabel5->Visible = false;
	ConstLabel6->Visible = false;
	ErrorLabel1->Visible = false;
	ErrorLabel2->Visible = false;
	AuthorEdit->Visible = false;
	NameEdit->Visible = false;
	GenreEdit->Visible = false;
	NumberEdit->Visible = true;
	InEdit->Visible = false;
	OutEdit->Visible = false;
	NamesComboBox->Visible = true;
	AddButton->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TDeliveryForm::NewButtonClick(TObject *Sender)
{
	ConstLabel1->Visible = true;
	ConstLabel2->Visible = true;
	ConstLabel3->Visible = true;
	ConstLabel4->Visible = true;
	ConstLabel5->Visible = true;
	ConstLabel6->Visible = true;
	ErrorLabel1->Visible = false;
	ErrorLabel2->Visible = false;
	AuthorEdit->Visible = true;
	NameEdit->Visible = true;
	GenreEdit->Visible = true;
	NumberEdit->Visible = true;
	InEdit->Visible = true;
	OutEdit->Visible = true;
	NamesComboBox->Visible = false;
	AddButton->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TDeliveryForm::AddButtonClick(TObject *Sender)
{
	char Num[3][16];
	ErrorLabel1->Visible = false;
	ErrorLabel2->Visible = false;
	if (NamesComboBox->Visible == true)
	{
		if (NamesComboBox->Items->Text == "" || NamesComboBox->ItemIndex == -1 || NumberEdit->Text == "")
		{
			ErrorLabel1->Visible = true;
		}
		else
		{
			strcpy(Num[0], AnsiString(NumberEdit->Text).c_str());
			if (CheckNumber(Num[0]))
			{
            	ErrorLabel2->Visible = true;
			}
			else
			{
				MainBooksList.ChangeNumbersOfBook(NamesComboBox->ItemIndex + 1, StrToInt(NumberEdit->Text));
            }
        }
	}
	else
	{
		if (AuthorEdit->Text == "" || NameEdit->Text == "" || GenreEdit->Text == "" || NumberEdit->Text == "" || InEdit->Text == "" || OutEdit->Text == "")
		{
			ErrorLabel1->Visible = true;
		}
		else
		{
			strcpy(Num[0], AnsiString(NumberEdit->Text).c_str());
			strcpy(Num[1], AnsiString(InEdit->Text).c_str());
			strcpy(Num[2], AnsiString(OutEdit->Text).c_str());
			if (CheckNumber(Num[0])||CheckNumber(Num[1])||CheckNumber(Num[2]))
			{
            	ErrorLabel2->Visible = true;
			}
			else
			{
                BookInfo *temp = new BookInfo;
				temp->author = AuthorEdit->Text;
				temp->name = NameEdit->Text;
				temp->genre = GenreEdit->Text;
				temp->number = StrToInt(NumberEdit->Text);
				temp->inprice = StrToInt(InEdit->Text);
				temp->outprice = StrToInt(OutEdit->Text);
				MainBooksList.AddBook(temp);
				BooksInStock++;
            }
        }
    }
}
//---------------------------------------------------------------------------
