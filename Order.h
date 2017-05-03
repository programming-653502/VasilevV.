//---------------------------------------------------------------------------

#ifndef OrderH
#define OrderH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TOrderForm : public TForm
{
__published:	// IDE-managed Components
	TButton *MenuButton;
	TComboBox *NamesComboBox;
	TLabel *ConstLabel1;
	TEdit *NumberEdit;
	TLabel *ConstLabel2;
	TButton *AddButton;
	TLabel *ErrorLabel1;
	TLabel *ErrorLabel2;
	TLabel *ErrorLabel3;
	void __fastcall MenuButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TOrderForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOrderForm *OrderForm;
//---------------------------------------------------------------------------
#endif
