//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Article.h"
#include "MainUnit.h"

#include <Jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TArticleForm *ArticleForm;
//---------------------------------------------------------------------------
//----------------------------------- Глобальные переменные
int extern OutputId;
//---------------------------------------------------------------------------
__fastcall TArticleForm::TArticleForm(TComponent* Owner)
	: TForm(Owner)
{
/*
	TJPEGImage *Picture = new TJPEGImage();
	Picture->Assign((TPersistent*));
	Picture->LoadFromFile("https://upload.wikimedia.org/wikipedia/commons/c/c5/JPEG_example_down.jpg");
	DBImage->Picture->Assign((TPersistent*)Picture); */
}
//---------------------------------------------------------------------------
//----------------------------------- Нажатие кнопок
//--------------- Нажатие нопки "Назад"
void __fastcall TArticleForm::BackButtonClick(TObject *Sender)
{
	ArticleForm->Visible = false;
    MainForm->Visible = true;
}
//---------------------------------------------------------------------------
