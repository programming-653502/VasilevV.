//---------------------------------------------------------------------------

#ifndef DeliveryH
#define DeliveryH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TDeliveryForm : public TForm
{
__published:	// IDE-managed Components
	TButton *MenuButton;
	TButton *OldButton;
	TButton *NewButton;
	TComboBox *NamesComboBox;
	TLabel *ConstLabel1;
	TEdit *AuthorEdit;
	TLabel *ConstLabel2;
	TEdit *NameEdit;
	TEdit *GenreEdit;
	TLabel *ConstLabel3;
	TEdit *NumberEdit;
	TLabel *ConstLabel4;
	TEdit *InEdit;
	TEdit *OutEdit;
	TLabel *ConstLabel5;
	TLabel *ConstLabel6;
	TButton *AddButton;
	TLabel *ErrorLabel1;
	TLabel *ErrorLabel2;
	void __fastcall MenuButtonClick(TObject *Sender);
	void __fastcall OldButtonClick(TObject *Sender);
	void __fastcall NewButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDeliveryForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDeliveryForm *DeliveryForm;
//---------------------------------------------------------------------------
#endif
