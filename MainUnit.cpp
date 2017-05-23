//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "Article.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
//----------------------------------- Глобальные переменные
String SearchName;
bool EditBool = false, ComboBoxBool = false, TagValue[14] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false};
//---------------------------------------------------------------------------
//----------------------------------- Функции формы
//--------------- Обновление ComboBox с годами
void FormYearsComboBox()
{
	MainForm->YearsComboBox->Items->Add("Все");
	for (int i = 0; i < 11; i++)
	{
		MainForm->YearsComboBox->Items->Add(i + 2007);
	}
	MainForm->YearsComboBox->ItemIndex = 0;
}
//--------------- Функция обновления списка статей
void RefreshArticles()
{
	String BasicSqlRequest = "SELECT \"title\" FROM \"Schema1\".\"articles\"";
	bool CheckBool = false;
	MainForm->FDQuery1->SQL->Text = BasicSqlRequest;
	if (EditBool == true)
	{
		MainForm->FDQuery1->SQL->Text = BasicSqlRequest + "WHERE \"title\" LIKE '%" + MainForm->NameSearchEdit->Text +"%'";
		CheckBool = true;
	}
	if (ComboBoxBool == true)
	{
		if (CheckBool == true)
		{
			MainForm->FDQuery1->SQL->Text = MainForm->FDQuery1->SQL->Text + " AND \"years\" = " + IntToStr(MainForm->YearsComboBox->ItemIndex + 2006);
		}
		else
		{
			MainForm->FDQuery1->SQL->Text = MainForm->FDQuery1->SQL->Text + " WHERE \"years\" = " + IntToStr(MainForm->YearsComboBox->ItemIndex + 2006);
		}
		CheckBool = true;
	}
	for (int i = 0; i < 14; i++)
	{
		if (TagValue[i] == true)
		{
			if (CheckBool == true)
			{
				MainForm->FDQuery1->SQL->Text = MainForm->FDQuery1->SQL->Text + " AND \"tag" + IntToStr(i + 1) + "\" = 1";
			}
			else
			{
				MainForm->FDQuery1->SQL->Text = MainForm->FDQuery1->SQL->Text + " WHERE \"tag" + IntToStr(i + 1) + "\" = 1";
			}
            CheckBool = true;
		}
	}
	MainForm->FDQuery1->Active = true;
}
//---------------------------------------------------------------------------
//----------------------------------- Операции, выполняемые при запуске формы
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
    FDQuery1->Active = true;
	FormYearsComboBox();
}
//---------------------------------------------------------------------------
//----------------------------------- Нажатия кнопок
//--------------- Нажатие кнопки очистки
void __fastcall TMainForm::ClearButtonClick(TObject *Sender)
{
	FormYearsComboBox();
	NameSearchEdit->Clear();
	Tag01SpeedButton->Down = false;
	Tag02SpeedButton->Down = false;
	Tag03SpeedButton->Down = false;
	Tag04SpeedButton->Down = false;
	Tag05SpeedButton->Down = false;
	Tag06SpeedButton->Down = false;
	Tag07SpeedButton->Down = false;
	Tag08SpeedButton->Down = false;
	Tag09SpeedButton->Down = false;
	Tag10SpeedButton->Down = false;
	Tag11SpeedButton->Down = false;
	Tag12SpeedButton->Down = false;
	Tag13SpeedButton->Down = false;
	Tag14SpeedButton->Down = false;
	EditBool = false;
	ComboBoxBool = false;
	for (int i = 0; i < 14; i++)
	{
        TagValue[i] = false;
	}
}
//--------------- Нажатие кнопки просмотра
void __fastcall TMainForm::ViewButtonClick(TObject *Sender)
{
	if (MainDBGrid->FieldCount == 1
	&&  MainDBGrid->SelectedField->Text == "")
	{
        return;
    }
	String BasicSqlIDRequest = "SELECT \"id\" FROM \"Schema1\".\"articles\" WHERE \"title\" = '";
	FDQuery2->SQL->Text = BasicSqlIDRequest + MainDBGrid->SelectedField->Text + "'";
	FDQuery2->Active = true;
	OutputId = StrToInt(DBGrid2->SelectedField->Text);

	String BasicSqlTitleRequest = "SELECT \"title\" FROM \"Schema1\".\"articles\" WHERE \"id\" = '";
	ArticleForm->FDQuery1->SQL->Text = BasicSqlTitleRequest + IntToStr(OutputId) + "'";
	ArticleForm->FDQuery1->Active = true;

	String BasicSqlImageRequest = "SELECT \"image\" FROM \"Schema1\".\"articlesinfo\" WHERE \"id\" = '";
	ArticleForm->FDQuery2->SQL->Text = BasicSqlImageRequest + IntToStr(OutputId) + "'";
	ArticleForm->FDQuery2->Active = true;
	ArticleForm->WebBrowser->Navigate(ArticleForm->BuffDBText->Field->Text);

	String BasicSqlDescriptionRequest = "SELECT \"description\" FROM \"Schema1\".\"articlesinfo\" WHERE \"id\" = '";
	ArticleForm->FDQuery3->SQL->Text = BasicSqlDescriptionRequest + IntToStr(OutputId) + "'";
	ArticleForm->FDQuery3->Active = true;

	String BasicSqlHistoryRequest = "SELECT \"history\" FROM \"Schema1\".\"articlesinfo\" WHERE \"id\" = '";
	ArticleForm->FDQuery4->SQL->Text = BasicSqlHistoryRequest + IntToStr(OutputId) + "'";
	ArticleForm->FDQuery4->Active = true;

	ArticleForm->Visible = true;
    MainForm->Visible = false;
}
//--------------- Нажатие кнопки выхода
void __fastcall TMainForm::ExitButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
//----------------------------------- События с наведением курсора на теги
//--------------- События "наезда" курсора на тег 1
void __fastcall TMainForm::Tag01SpeedButtonMouseEnter(TObject *Sender)
{
	Tag01Memo->Visible = true;
}
void __fastcall TMainForm::Tag01SpeedButtonMouseLeave(TObject *Sender)
{
	Tag01Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 2
void __fastcall TMainForm::Tag02SpeedButtonMouseEnter(TObject *Sender)
{
	Tag02Memo->Visible = true;
}
void __fastcall TMainForm::Tag02SpeedButtonMouseLeave(TObject *Sender)
{
	Tag02Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 3
void __fastcall TMainForm::Tag03SpeedButtonMouseEnter(TObject *Sender)
{
	Tag03Memo->Visible = true;
}
void __fastcall TMainForm::Tag03SpeedButtonMouseLeave(TObject *Sender)
{
	Tag03Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 4
void __fastcall TMainForm::Tag04SpeedButtonMouseEnter(TObject *Sender)
{
	Tag04Memo->Visible = true;
}
void __fastcall TMainForm::Tag04SpeedButtonMouseLeave(TObject *Sender)
{
	Tag04Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 5
void __fastcall TMainForm::Tag05SpeedButtonMouseEnter(TObject *Sender)
{
	Tag05Memo->Visible = true;
}
void __fastcall TMainForm::Tag05SpeedButtonMouseLeave(TObject *Sender)
{
	Tag05Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 6
void __fastcall TMainForm::Tag06SpeedButtonMouseEnter(TObject *Sender)
{
	Tag06Memo->Visible = true;
}
void __fastcall TMainForm::Tag06SpeedButtonMouseLeave(TObject *Sender)
{
	Tag06Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 7
void __fastcall TMainForm::Tag07SpeedButtonMouseEnter(TObject *Sender)
{
	Tag07Memo->Visible = true;
}
void __fastcall TMainForm::Tag07SpeedButtonMouseLeave(TObject *Sender)
{
	Tag07Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 8
void __fastcall TMainForm::Tag08SpeedButtonMouseEnter(TObject *Sender)
{
	Tag08Memo->Visible = true;
}
void __fastcall TMainForm::Tag08SpeedButtonMouseLeave(TObject *Sender)
{
	Tag08Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 9
void __fastcall TMainForm::Tag09SpeedButtonMouseEnter(TObject *Sender)
{
	Tag09Memo->Visible = true;
}
void __fastcall TMainForm::Tag09SpeedButtonMouseLeave(TObject *Sender)
{
	Tag09Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 10
void __fastcall TMainForm::Tag10SpeedButtonMouseEnter(TObject *Sender)
{
	Tag10Memo->Visible = true;
}
void __fastcall TMainForm::Tag10SpeedButtonMouseLeave(TObject *Sender)
{
	Tag10Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 11
void __fastcall TMainForm::Tag11SpeedButtonMouseEnter(TObject *Sender)
{
	Tag11Memo->Visible = true;
}
void __fastcall TMainForm::Tag11SpeedButtonMouseLeave(TObject *Sender)
{
	Tag11Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 12
void __fastcall TMainForm::Tag12SpeedButtonMouseEnter(TObject *Sender)
{
	Tag12Memo->Visible = true;
}
void __fastcall TMainForm::Tag12SpeedButtonMouseLeave(TObject *Sender)
{
	Tag12Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 13
void __fastcall TMainForm::Tag13SpeedButtonMouseEnter(TObject *Sender)
{
	Tag13Memo->Visible = true;
}
void __fastcall TMainForm::Tag13SpeedButtonMouseLeave(TObject *Sender)
{
	Tag13Memo->Visible = false;
}
//--------------- События "наезда" курсора на тег 14
void __fastcall TMainForm::Tag14SpeedButtonMouseEnter(TObject *Sender)
{
	Tag14Memo->Visible = true;
}
void __fastcall TMainForm::Tag14SpeedButtonMouseLeave(TObject *Sender)
{
	Tag14Memo->Visible = false;
}
//---------------------------------------------------------------------------
//----------------------------------- Нажатие кнопок тегов
//--------------- Нажатие кнопки тега 1
void __fastcall TMainForm::Tag01SpeedButtonClick(TObject *Sender)
{
	if (TagValue[0] == false)
	{
		TagValue[0] = true;
	}
	else
	{
		TagValue[0] = false;
	}
    Tag02SpeedButton->Down = false;
	TagValue[1] = false;
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 2
void __fastcall TMainForm::Tag02SpeedButtonClick(TObject *Sender)
{
	if (TagValue[1] == false)
	{
		TagValue[1] = true;
	}
	else
	{
		TagValue[1] = false;
	}
    Tag01SpeedButton->Down = false;
	TagValue[0] = false;
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 3
void __fastcall TMainForm::Tag03SpeedButtonClick(TObject *Sender)
{
	if (TagValue[2] == false)
	{
		TagValue[2] = true;
	}
	else
	{
		TagValue[2] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 4
void __fastcall TMainForm::Tag04SpeedButtonClick(TObject *Sender)
{
	if (TagValue[3] == false)
	{
		TagValue[3] = true;
	}
	else
	{
		TagValue[3] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 5
void __fastcall TMainForm::Tag05SpeedButtonClick(TObject *Sender)
{
	if (TagValue[4] == false)
	{
		TagValue[4] = true;
	}
	else
	{
		TagValue[4] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 6
void __fastcall TMainForm::Tag06SpeedButtonClick(TObject *Sender)
{
	if (TagValue[5] == false)
	{
		TagValue[5] = true;
	}
	else
	{
		TagValue[5] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 7
void __fastcall TMainForm::Tag07SpeedButtonClick(TObject *Sender)
{
	if (TagValue[6] == false)
	{
		TagValue[6] = true;
	}
	else
	{
		TagValue[6] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 8
void __fastcall TMainForm::Tag08SpeedButtonClick(TObject *Sender)
{
	if (TagValue[7] == false)
	{
		TagValue[7] = true;
	}
	else
	{
		TagValue[7] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 9
void __fastcall TMainForm::Tag09SpeedButtonClick(TObject *Sender)
{
	if (TagValue[8] == false)
	{
		TagValue[8] = true;
	}
	else
	{
		TagValue[8] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 10
void __fastcall TMainForm::Tag10SpeedButtonClick(TObject *Sender)
{
	if (TagValue[9] == false)
	{
		TagValue[9] = true;
	}
	else
	{
		TagValue[9] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 11
void __fastcall TMainForm::Tag11SpeedButtonClick(TObject *Sender)
{
	if (TagValue[10] == false)
	{
		TagValue[10] = true;
	}
	else
	{
		TagValue[10] = false;
	}
    RefreshArticles();
}
//--------------- Нажатие кнопки тега 12
void __fastcall TMainForm::Tag12SpeedButtonClick(TObject *Sender)
{
	if (TagValue[11] == false)
	{
		TagValue[11] = true;
	}
	else
	{
		TagValue[11] = false;
	}
}
//--------------- Нажатие кнопки тега 13
void __fastcall TMainForm::Tag13SpeedButtonClick(TObject *Sender)
{
	if (TagValue[12] == false)
	{
		TagValue[12] = true;
	}
	else
	{
		TagValue[12] = false;
	}
	Tag14SpeedButton->Down = false;
	TagValue[13] = false;
	RefreshArticles();
}
//--------------- Нажатие кнопки тега 14
void __fastcall TMainForm::Tag14SpeedButtonClick(TObject *Sender)
{
	if (TagValue[13] == false)
	{
		TagValue[13] = true;
	}
	else
	{
		TagValue[13] = false;
	}
    Tag13SpeedButton->Down = false;
	TagValue[12] = false;
	RefreshArticles();
}
//---------------------------------------------------------------------------
//----------------------------------- События изменений
//--------------- Изменение значения Edit
void __fastcall TMainForm::NameSearchEditChange(TObject *Sender)
{
	if (NameSearchEdit->Text != "" && EditBool == false)
	{
		EditBool = true;
	}
	else
	{
		if (NameSearchEdit->Text == "" && EditBool == true)
		{
			EditBool = false;
		}
	}
	RefreshArticles();
}
//--------------- Изменение значения ComboBox
void __fastcall TMainForm::YearsComboBoxChange(TObject *Sender)
{
	if (YearsComboBox->ItemIndex != 0 && ComboBoxBool == false)
	{
		ComboBoxBool = true;
	}
	else
	{
		if (YearsComboBox->ItemIndex == 0 && ComboBoxBool == true)
		{
			ComboBoxBool = false;
		}
	}
    RefreshArticles();
}
//---------------------------------------------------------------------------
