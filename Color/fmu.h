//---------------------------------------------------------------------------

#ifndef fmuH
#define fmuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <System.IOUtils.hpp>

//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tc;
	TTabItem *tiMenu;
	TTabItem *tiSet;
	TTabItem *tiResult;
	TTabItem *tiDiff;
	TLayout *Layout1;
	TButton *buGame;
	TButton *buResult;
	TButton *buSet;
	TButton *buHelp;
	TButton *buAbout;
	TTabItem *tiGame;
	TTrackBar *tbTime;
	TLabel *Label1;
	TLabel *Label2;
	TMemo *meScore;
	TToolBar *ToolBar1;
	TLayout *Layout2;
	TButton *buEasy;
	TButton *buNotEasy;
	TGridPanelLayout *GridPanelLayout1;
	TLabel *laValSec;
	TLabel *laCheckFir;
	TLabel *laValFir;
	TLayout *Layout3;
	TLabel *laCheckSec;
	TButton *buNo;
	TButton *buYes;
	TToolBar *tbTop;
	TToolBar *tbBot;
	TTabItem *tiHelp;
	TToolBar *ToolBar4;
	TButton *buBack1;
	TButton *buBack2;
	TToolBar *ToolBar5;
	TButton *buBack3;
	TButton *buBack4;
	TToolBar *ToolBar6;
	TButton *buBack5;
	TGridPanelLayout *GridPanelLayout2;
	TLabel *laQ;
	TLabel *laScore;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TGridPanelLayout *GridPanelLayout3;
	TLabel *Label6;
	TEdit *edR;
	TLabel *Label8;
	TEdit *edG;
	TLabel *Label9;
	TEdit *edB;
	TButton *buAddColor;
	TButton *buWhite;
	TLabel *laTbValue;
	TTabItem *tiEndGame;
	TLabel *laEndScore;
	TButton *buRestart;
	TButton *buMenu;
	TEdit *edName;
	TLabel *laName;
	TTimer *tmGame;
	TLabel *laTime;
	TRectangle *rec1;
	TRectangle *rec2;
	TRectangle *rec3;
	TRectangle *rec4;
	TRectangle *rec5;
	TRectangle *rec6;
	TRectangle *Rec7;
	TLabel *Label10;
	TLabel *laStart;
	TButton *buAdd;
	TMemo *Memo1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall buGameClick(TObject *Sender);
	void __fastcall buResultClick(TObject *Sender);
	void __fastcall buSetClick(TObject *Sender);
	void __fastcall buHelpClick(TObject *Sender);
	void __fastcall buAboutClick(TObject *Sender);
	void __fastcall buBack(TObject *Sender);
	void __fastcall buBack4Click(TObject *Sender);
	void __fastcall buEasyClick(TObject *Sender);
	void __fastcall buNotEasyClick(TObject *Sender);
	void __fastcall buYesClick(TObject *Sender);
	void __fastcall buNoClick(TObject *Sender);
	void __fastcall buWhiteClick(TObject *Sender);
	void __fastcall tmGameTimer(TObject *Sender);
	void __fastcall tbTimeChange(TObject *Sender);
	void __fastcall buAddColorClick(TObject *Sender);
	void __fastcall buGameMouseEnter(TObject *Sender);
	void __fastcall buGameMouseLeave(TObject *Sender);
	void __fastcall buAddClick(TObject *Sender);
	void __fastcall KeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);


private:
	void DoGame();
	void DoColor(int i);
	void DoReset();
	void DoFinish();
	void DoAnim();
	void DoStart();
	void Yes();
	void No();
    void Back();
	int Score;
	int Rand;
	double FTimeValue;


    TRectangle* rec;
	TLabel* la;	// User declarations
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
