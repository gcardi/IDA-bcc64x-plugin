//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <ida.hpp>
#include <kernwin.hpp>

#include "FormMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TfrmMain *frmMain;
//---------------------------------------------------------------------------

__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
	msg("TfrmMain::TfrmMain");
}
//---------------------------------------------------------------------------

__fastcall TfrmMain::~TfrmMain()
{
	msg("TfrmMain::~TfrmMain");
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Timer1Timer(TObject *Sender)
{
	Label1->Caption = ++n_;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

