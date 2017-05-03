//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------



















USEFORM("Main.cpp", MainForm);
USEFORM("Stat.cpp", StatisticsForm);
USEFORM("Delivery.cpp", DeliveryForm);
USEFORM("Order.cpp", OrderForm);
USEFORM("History.cpp", HistoryForm);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TStatisticsForm), &StatisticsForm);
		Application->CreateForm(__classid(TDeliveryForm), &DeliveryForm);
		Application->CreateForm(__classid(TOrderForm), &OrderForm);
		Application->CreateForm(__classid(THistoryForm), &HistoryForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
