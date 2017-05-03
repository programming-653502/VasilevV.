//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "History.h"
#include "Stat.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THistoryForm *HistoryForm;
//---------------------------------------------------------------------------
__fastcall THistoryForm::THistoryForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THistoryForm::BackButtonClick(TObject *Sender)
{
	HistoryForm->Visible = false;
	StatisticsForm->Visible = true;
}
//---------------------------------------------------------------------------
