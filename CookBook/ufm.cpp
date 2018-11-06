//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ufm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;
//---------------------------------------------------------------------------
const UnicodeString cPath =System::Ioutils::TPath::GetDocumentsPath();

__fastcall Tfm::Tfm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall Tfm::buAddIngrClick(TObject *Sender)
{
	//Создание полей ввода
	ed = new TEdit(fm);
	ed->Name="ed" + IntToStr(i);
    ed->Position->X = 10;
	ed->Position->Y = 50;
	ed->Align= TAlignLayout::Top;

	ed->Height = 22;
	ed->Width = 90;

	ed->Text = "";
	ed->TextPrompt=L"Название";

	ed->Visible = true;
	ed->Enabled = true;
	ed->Parent = sbAdd;
	ed->Margins->Right=270;
	ed->Margins->Left=10;
	ed->Margins->Top=10;

	num = new TNumberBox(fm);
	num->Name="num" + IntToStr(i);

	num->Height = 22;
	num->Width = 65;
	num->Max = 1000;
	num->Visible = true;
	num->Enabled = true;
	num->Parent=ed;
	num->Align= TAlignLayout::Right;




	comb = new TComboBox(fm);
	comb->Name="comb" + IntToStr(i);
	comb->Height = 22;
	comb->Width = 120;
	comb->Items->Add(L"Чайная ложка");
	comb->Items->Add(L"Столовая ложка");
	comb->Items->Add(L"Грамм");
	comb->Items->Add(L"Килограмм" );
	comb->Items->Add(L"Миллилитр");
	comb->Items->Add(L"Литр");
    comb->Items->Add(L"Штука");
	comb->DropDownCount = 8;
	comb->Visible = true;
	comb->Enabled = true;
	comb->Parent=ed;

	comb->Align= TAlignLayout::Right;
	comb->Margins->Right=-200;
	comb->Margins->Left=10;


	i++;



}
//---------------------------------------------------------------------------
void __fastcall Tfm::buBackClick(TObject *Sender)
{
	tc->ActiveTab=tiMain;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buAddNewClick(TObject *Sender)
{
	tc->ActiveTab=tiAddNew;
	sbAdd->ViewportPosition = TPointF(0,0);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::FormCreate(TObject *Sender)
{
// поиск .ini фаила и создание списка по нему
	#ifdef __ANDROID__
	String download = System::Ioutils::TPath::GetDownloadsPath();
	lbItems = System::Ioutils::TPath::Combine(download,L"lb.ini");

	#elif _Windows
	lbItems = System::Ioutils::TPath::Combine("..\\..\\Recepies",L"lb.ini");
	imPrev->Visible=false;
	#endif

	tc->ActiveTab=tiMain;

	TIniFile *Ini = new TIniFile(lbItems);



	TStringList* slist=new TStringList;
	Ini->ReadSectionValues("lb",slist);
	for (int i = 0; i < slist->Count; i++) {
		lb->Items->Insert(i,Ini->ReadString("lb","Item"+IntToStr(i),"<Пусто>"));
	}

	delete slist;

	delete Ini;


}

//---------------------------------------------------------------------------


void __fastcall Tfm::ButtonAddClick(TObject *Sender)
{
//Ввод рецепта в файл и сохранение картинки(для андроид версии)
	lb->Items->Add(edName->Text);

	saveTXT = System::Ioutils::TPath::Combine("..\\..\\Recepies", edName->Text+".txt");

	saveJPG = System::Ioutils::TPath::Combine("..\\..\\Recepies", edName->Text+".jpg");

	for(int j =0; j<i; j++){

			String edFind = "ed" + IntToStr(j);
			ed = ((TEdit*)fm->FindComponent(edFind));

			String numFind = "num" + IntToStr(j);
			num = ((TNumberBox*)fm->FindComponent(numFind));


			String combFind = "comb" + IntToStr(j);
			comb = ((TComboBox*)fm->FindComponent(combFind));


			temp = ed->Text+" "+num->Value+" "+comb->Items->Strings[comb->ItemIndex];


			if(temp.Length() != 0 )
			{



			TStringList *listAdd = new TStringList;  // 1й TStringLis


			if (FileExists(saveTXT) == false) // проверяем наличие файла
				{
					listAdd->Add("Ингредиенты:");
					listAdd->Add(temp);

					listAdd->SaveToFile(saveTXT); // файл не найден, значит сохраняем как есть
				}
			else
				{
				   // если файл уже существует
					listAdd->Add(temp);
					TStringList *listOld = new TStringList;
					listOld->LoadFromFile(saveTXT); // загружаем существующий файл

					listOld->Text = listOld->Text + listAdd->Text;
					listOld->SaveToFile(saveTXT);
					delete listOld;
				}
				delete listAdd;

			}
		else
		{
		// пустой едит
		}


		temp=NULL;

	}


	temp=meDes->Text;
	if(temp.Length() != 0)
	{
		TStringList *listMemo = new TStringList;
		TStringList *listOld = new TStringList;

		if (FileExists(saveTXT) == false)
		{

		listMemo->Add("Процесс приготовления:");

		listMemo->Add(temp);

		listMemo->SaveToFile(saveTXT);
		}

		else
		{

		listMemo->Add("Процесс приготовления:");

		listMemo->Add(temp);

		listOld->LoadFromFile(saveTXT);



		listOld->Text = listOld->Text + listMemo->Text;



		listOld->SaveToFile(saveTXT);

		}


		delete listMemo;
	}



	if(im->Bitmap->IsEmpty()==false){

		im->Bitmap->SaveToFile(saveJPG);
	}

	tc->ActiveTab=tiMain;

	for(int k=0;k<i;k++)
	{
			String edFind = "ed" + IntToStr(k);
			ed = ((TEdit*)fm->FindComponent(edFind));

			delete ed;

			String numFind = "num" + IntToStr(k);
			num = ((TNumberBox*)fm->FindComponent(numFind));

			delete num;


			String combFind = "comb" + IntToStr(k);
			comb = ((TComboBox*)fm->FindComponent(combFind));

			delete num;

	}
   meDes->Text="";
   edName->Text="";
   i=0;
}
//---------------------------------------------------------------------------




void __fastcall Tfm::TakePhotoFromCameraAction1DidFinishTaking(TBitmap *Image)
{
    im->Bitmap->Assign(Image);
}
//---------------------------------------------------------------------------

void __fastcall Tfm::TakePhotoFromLibraryAction1DidFinishTaking(TBitmap *Image)
{
    im->Bitmap->Assign(Image);
}
//---------------------------------------------------------------------------
void Tfm::LoadItem(int aIndex)
{
//Загрузка рецепта
	laMain->Text=lb->Items->Strings[aIndex];


	filenameJPG=System::Ioutils::TPath::Combine("..\\..\\Recepies", laMain->Text+".jpg");
	filenameTXT=System::Ioutils::TPath::Combine("..\\..\\Recepies", laMain->Text+".txt");

	if (FileExists(filenameJPG) == true){

	im->Bitmap->LoadFromFile(filenameJPG);

	}


	TStringList *load = new TStringList;
	__try
	{
		load->LoadFromFile(filenameTXT);
		tx->Text = load->Text;
		}

	__finally{
	  load->DisposeOf();
	}

}


void __fastcall Tfm::FormClose(TObject *Sender, TCloseAction &Action)
{
	TIniFile *Ini = new TIniFile(lbItems);

	for(int i = 0;i < lb->Items->Count; i++)
	{
		Ini->WriteString("lb","Item"+IntToStr(i),lb->Items->Strings[i]);
	}

}
//---------------------------------------------------------------------------

void __fastcall Tfm::lbItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
    //открытие рецепта
	sbInf->ViewportPosition = TPointF(0,0);
	LoadItem(Item->Index);

	lbIndex=Item->Index;

	tx->RecalcSize();
	tc->ActiveTab=tiInf;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buDeleteClick(TObject *Sender)
{
	//удаление
	if (FileExists(filenameTXT) == true){

	DeleteFile(filenameTXT);

	}

   if(im->Bitmap->IsEmpty()==false)
   {

	DeleteFile(filenameJPG);

   }


	lb->Items->Delete(lbIndex);

	tc->ActiveTab=tiMain;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buInfoClick(TObject *Sender)
{
	tc->ActiveTab=tiAbout;
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buBackAboutClick(TObject *Sender)
{
	tc->ActiveTab=tiMain;
}
//---------------------------------------------------------------------------


