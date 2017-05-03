//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Stat.h"
#include "Main.h"
#include "History.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStatisticsForm *StatisticsForm;
//--------------- Глобальные переменные
extern int BooksInStock, NumberOfOrders;
extern BookList MainBooksList;
extern OrderList MainOrdersList;
//--------------- Функции Обновления
void UpdateMainGrid()
{
	HistoryForm->MainStringGrid->RowCount = NumberOfOrders + 1;
	HistoryForm->MainStringGrid->Cells[0][0] = "Название";
	HistoryForm->MainStringGrid->Cells[1][0] = "Количество";
	HistoryForm->MainStringGrid->Cells[2][0] = "Цена продажи";
	BookInfo *temp = new BookInfo;
	for (int i = 1; i <= NumberOfOrders; i++)
	{
		temp = MainOrdersList.LoadOrder(i);
		HistoryForm->MainStringGrid->Cells[0][i] = temp->name;
		HistoryForm->MainStringGrid->Cells[1][i] = temp->number;
		HistoryForm->MainStringGrid->Cells[2][i] = temp->outprice;
	}
}
//---------------------------------------------------------------------------
__fastcall TStatisticsForm::TStatisticsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TStatisticsForm::MenuButtonClick(TObject *Sender)
{
    StatisticsForm->Visible = false;
	MainForm->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TStatisticsForm::OrderHistoryButtonClick(TObject *Sender)
{
	StatisticsForm->Visible = false;
	UpdateMainGrid();
	HistoryForm->Visible = true;
}
//---------------------------------------------------------------------------

