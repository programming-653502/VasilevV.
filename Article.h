//---------------------------------------------------------------------------

#ifndef ArticleH
#define ArticleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.DB2.hpp>
#include <FireDAC.Phys.DB2Def.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <SHDocVw.hpp>
#include <Vcl.OleCtrls.hpp>


//---------------------------------------------------------------------------
class TArticleForm : public TForm
{
__published:	// IDE-managed Components
	TButton *BackButton;
	TDBMemo *TitleDBMemo;
	TMemo *ConstMemo1;
	TDBMemo *DescriptionDBMemo;
	TMemo *ConstMemo2;
	TDBMemo *DBMemo1;
	TFDQuery *FDQuery1;
	TDataSource *DataSource1;
	TWebBrowser *WebBrowser;
	TFDQuery *FDQuery2;
	TDataSource *DataSource2;
	TDBText *BuffDBText;
	TFDQuery *FDQuery4;
	TDataSource *DataSource3;
	TDataSource *DataSource4;
	TFDQuery *FDQuery3;
	void __fastcall BackButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TArticleForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TArticleForm *ArticleForm;
//---------------------------------------------------------------------------
#endif
