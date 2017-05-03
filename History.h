//---------------------------------------------------------------------------

#ifndef HistoryH
#define HistoryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class THistoryForm : public TForm
{
__published:	// IDE-managed Components
	TButton *BackButton;
	TStringGrid *MainStringGrid;
	void __fastcall BackButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THistoryForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THistoryForm *HistoryForm;
//---------------------------------------------------------------------------
#endif
