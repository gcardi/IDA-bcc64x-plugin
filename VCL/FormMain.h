//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TLabel *Label1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	int n_ {};
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
	__fastcall ~TfrmMain();
};
//---------------------------------------------------------------------------
//extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
