//---------------------------------------------------------------------------

#ifndef StatH
#define StatH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>

//---------------------------------------------------------------------------
class TStatisticsForm : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *MainStringGrid;
	TButton *MenuButton;
	TLabel *ConstLabel1;
	TLabel *BooksInStockLabel;
	TLabel *ConstLabel2;
	TLabel *AllPriceLabel;
	TLabel *ConstLabel3;
	TLabel *NumberOfOrdersLabel;
	TLabel *ConstLabel4;
	TLabel *NumberOfSoldLabel;
	TLabel *ConstLabel5;
	TLabel *FullProfitLabel;
	TButton *OrderHistoryButton;
	void __fastcall MenuButtonClick(TObject *Sender);
	void __fastcall OrderHistoryButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TStatisticsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStatisticsForm *StatisticsForm;
//---------------------------------------------------------------------------
#endif
