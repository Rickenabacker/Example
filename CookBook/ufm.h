//---------------------------------------------------------------------------

#ifndef ufmH
#define ufmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.EditBox.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.NumberBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ActnList.hpp>
#include <FMX.MediaLibrary.Actions.hpp>
#include <FMX.StdActns.hpp>
#include <System.Actions.hpp>
#include <System.IniFiles.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
class Tfm : public TForm
{
__published:	// IDE-managed Components
	TTabControl *tc;
	TTabItem *tiMain;
	TTabItem *tiInf;
	TTabItem *tiAddNew;
	TListBox *lb;
	TToolBar *ToolBar2;
	TButton *buBack1;
	TToolBar *tb1;
	TButton *buBack2;
	TToolBar *ToolBar4;
	TButton *buInfo;
	TButton *buAddNew;
	TEdit *edName;
	TLabel *laIng;
	TLabel *laName;
	TScrollBox *sbAdd;
	TButton *buAddIngr;
	TButton *buAdd;
	TMemo *meDes;
	TLabel *laProc;
	TImage *imPrev;
	TButton *buCam;
	TButton *buFold;
	TActionList *AL;
	TTakePhotoFromCameraAction *TakePhotoFromCameraAction1;
	TTakePhotoFromLibraryAction *TakePhotoFromLibraryAction1;
	TScrollBox *sbInf;
	TImage *im;
	TText *tx;
	TLabel *laMain;
	TButton *buDelete;
	TStyleBook *stylebook;
	TTabItem *tiAbout;
	TLabel *Label1;
	TLabel *Label2;
	TToolBar *ToolBar1;
	TButton *buBackAbout;
	TLabel *Label3;
	void __fastcall buAddIngrClick(TObject *Sender);
	void __fastcall buBackClick(TObject *Sender);
	void __fastcall buAddNewClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall TakePhotoFromCameraAction1DidFinishTaking(TBitmap *Image);
	void __fastcall TakePhotoFromLibraryAction1DidFinishTaking(TBitmap *Image);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall lbItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall buDeleteClick(TObject *Sender);
	void __fastcall buInfoClick(TObject *Sender);
	void __fastcall buBackAboutClick(TObject *Sender);



private:
	TEdit* ed;
	TNumberBox* num;
	TComboBox* comb;
	String lbItems;
	String saveTXT;
	String saveJPG;
	String filenameJPG;
	String filenameTXT;
	String temp;
	void LoadItem(int aIndex);
    int lbIndex;
	int i;	// User declarations
public:		// User declarations
	__fastcall Tfm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tfm *fm;
//---------------------------------------------------------------------------
#endif
