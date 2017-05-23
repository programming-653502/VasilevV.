//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.DB2.hpp>
#include <FireDAC.Phys.DB2Def.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
#include <Vcl.Bind.Grid.hpp>
#include <Vcl.Grids.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBGrids.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TComboBox *YearsComboBox;
	TLabel *ConstLabel2;
	TSpeedButton *Tag02SpeedButton;
	TSpeedButton *Tag01SpeedButton;
	TFDQuery *FDQuery1;
	TFDConnection *LibraryConnection;
	TDataSource *DataSource1;
	TDBGrid *MainDBGrid;
	TButton *ExitButton;
	TFDQuery *FDQuery2;
	TLabel *ConstLabel1;
	TEdit *NameSearchEdit;
	TSpeedButton *Tag03SpeedButton;
	TSpeedButton *Tag04SpeedButton;
	TSpeedButton *Tag05SpeedButton;
	TSpeedButton *Tag06SpeedButton;
	TSpeedButton *Tag07SpeedButton;
	TSpeedButton *Tag08SpeedButton;
	TSpeedButton *Tag09SpeedButton;
	TSpeedButton *Tag10SpeedButton;
	TSpeedButton *Tag11SpeedButton;
	TSpeedButton *Tag12SpeedButton;
	TSpeedButton *Tag13SpeedButton;
	TSpeedButton *Tag14SpeedButton;
	TMemo *Tag01Memo;
	TMemo *Tag02Memo;
	TMemo *Tag03Memo;
	TMemo *Tag04Memo;
	TMemo *Tag05Memo;
	TMemo *Tag06Memo;
	TMemo *Tag07Memo;
	TMemo *Tag08Memo;
	TMemo *Tag09Memo;
	TMemo *Tag10Memo;
	TMemo *Tag11Memo;
	TMemo *Tag12Memo;
	TMemo *Tag14Memo;
	TMemo *Tag13Memo;
	TButton *ViewButton;
	TButton *ClearButton;
	TDataSource *DataSource2;
	TDBGrid *DBGrid2;
	TLabel *VersionLabel;
	void __fastcall Tag01SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag01SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag02SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag02SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag03SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag03SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag04SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag04SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag05SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag05SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag06SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag06SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag07SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag07SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag08SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag08SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag09SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag09SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag11SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag11SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag12SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag12SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag13SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag13SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag14SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag14SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall Tag10SpeedButtonMouseEnter(TObject *Sender);
	void __fastcall Tag10SpeedButtonMouseLeave(TObject *Sender);
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall Tag01SpeedButtonClick(TObject *Sender);
	void __fastcall Tag02SpeedButtonClick(TObject *Sender);
	void __fastcall Tag03SpeedButtonClick(TObject *Sender);
	void __fastcall Tag04SpeedButtonClick(TObject *Sender);
	void __fastcall Tag05SpeedButtonClick(TObject *Sender);
	void __fastcall Tag06SpeedButtonClick(TObject *Sender);
	void __fastcall Tag07SpeedButtonClick(TObject *Sender);
	void __fastcall Tag08SpeedButtonClick(TObject *Sender);
	void __fastcall Tag09SpeedButtonClick(TObject *Sender);
	void __fastcall Tag10SpeedButtonClick(TObject *Sender);
	void __fastcall Tag11SpeedButtonClick(TObject *Sender);
	void __fastcall Tag12SpeedButtonClick(TObject *Sender);
	void __fastcall Tag13SpeedButtonClick(TObject *Sender);
	void __fastcall Tag14SpeedButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall NameSearchEditChange(TObject *Sender);
	void __fastcall YearsComboBoxChange(TObject *Sender);
	void __fastcall ViewButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
//----------------------------------- Глобальные переменные
int OutputId;
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
