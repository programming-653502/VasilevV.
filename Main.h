//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *DeliveryButton;
	TButton *OrderButton;
	TButton *StatisticsButton;
	TButton *ExitButton;
	void __fastcall StatisticsButtonClick(TObject *Sender);
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall DeliveryButtonClick(TObject *Sender);
	void __fastcall OrderButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//----------------------------------- Класс Списка Книг
struct BookInfo
{
	String author;
	String name;
	String genre;
	int number;
	int inprice;
	int outprice;
	BookInfo *next;
};
class BookList
{
	BookInfo *Head;
	public:
		BookList(){Head = NULL;};
		void AddBook(BookInfo *Input)
		{
			BookInfo *temp = new BookInfo;
			temp->author = Input->author;
			temp->name = Input->name;
			temp->genre = Input->genre;
			temp->number = Input->number;
			temp->inprice = Input->inprice;
			temp->outprice = Input->outprice;
			temp->next = Head;
			Head = temp;
		};
		BookInfo* LoadBook(int number)
		{
			if (number == 1)
			{
				return Head;
			}
			else
			{
				BookInfo *temp = new BookInfo;
				temp = Head->next;
				for (int i = 3; i <= number; i++)
				{
					temp = temp->next;
				}
				return temp;
			}
		}
		void ChangeNumbersOfBook(int number, int BooksNumber)
		{
			if (number == 1)
			{
				Head->number += BooksNumber;
			}
			else
			{
				BookInfo *temp = new BookInfo;
				temp = Head->next;
				for (int i = 3; i <= number; i++)
				{
					temp = temp->next;
				}
				temp->number += BooksNumber;
			}
		}
		void RemoveBook(int number, int All)
		{
			if (number == 1 || number == All)
			{
				if (number == 1)
				{
                	Head = Head->next;
				}
				else
				{
					number--;
					BookInfo *temp = new BookInfo;
					if (number > 1)
					{
						temp = Head->next;
						for (int i = 3; i <= number; i++)
						{
							temp = temp->next;
						}
					}
					temp->next = NULL;
				}
			}
			else
			{
				number--;
				BookInfo *tempFirst = new BookInfo;
				tempFirst = Head;
				if (number > 1)
				{
					tempFirst = Head->next;
					for (int i = 3; i <= number; i++)
					{
						tempFirst = tempFirst->next;
					}
				}
				number+= 2;
				BookInfo *tempSecond = new BookInfo;
				if (number > 1)
				{
					tempSecond = Head->next;
					for (int i = 3; i <= number; i++)
					{
						tempSecond = tempSecond->next;
					}
				}
				tempFirst->next = tempSecond;
            }
		}
};
//----------------------------------- Класс Списка Заказов
class OrderList
{
	BookInfo *Head;
	public:
		OrderList(){Head = NULL;};
		void AddOrder(BookInfo *Input)
		{
			BookInfo *temp = new BookInfo;
			temp->name = Input->name;
			temp->number = Input->number;
			temp->outprice = Input->outprice;
			temp->next = Head;
			Head = temp;
		};
		BookInfo* LoadOrder(int number)
		{
			if (number == 1)
			{
				return Head;
			}
			else
			{
				BookInfo *temp = new BookInfo;
				temp = Head->next;
				for (int i = 3; i <= number; i++)
				{
					temp = temp->next;
				}
				return temp;
            }
		}
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
