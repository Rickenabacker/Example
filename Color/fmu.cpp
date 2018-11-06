//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfm *fm;
//---------------------------------------------------------------------------
__fastcall Tfm::Tfm(TComponent* Owner)
	: TForm(Owner)
{
}

const UnicodeString cList[] = {L"Красный","Зеленый","Синий","Черный","Оранжевый","Фиолетовый","Желтый","Серый","Салатовый"};
String saveTXT=System::Ioutils::TPath::Combine("..\\..\\Score", "Score.txt");

//---------------------------------------------------------------------------
void __fastcall Tfm::FormCreate(TObject *Sender)
{

	tmGame->Enabled = false;

	randomize();

	this->Fill->Kind = TBrushKind::Solid;

	Score = 0;
	Rand = 0;

	tc->ActiveTab = tiMenu;
	DoAnim();
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buGameClick(TObject *Sender)
{
	tc->ActiveTab = tiDiff;
	tmGame->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buResultClick(TObject *Sender)
{
	tc->ActiveTab = tiResult;

    TStringList *load = new TStringList;
	__try
	{
		load->LoadFromFile(saveTXT);
		meScore->Text = load->Text;
		}

	__finally{
	  load->DisposeOf();
	}

}
//---------------------------------------------------------------------------
void __fastcall Tfm::buSetClick(TObject *Sender)
{
	tc->ActiveTab = tiSet;
	laTbValue->Text = FloatToStr(tbTime->Value)+ " Секунд" ;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buHelpClick(TObject *Sender)
{
    tc->ActiveTab = tiHelp;
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buAboutClick(TObject *Sender)
{
    ShowMessage(L"Цветовод — Зайцев Кирилл(151-362)");
}
//---------------------------------------------------------------------------
void __fastcall Tfm::buBack(TObject *Sender)
{
   Back();

}

 void Tfm::Back()
 {
	tc->ActiveTab = tiMenu;
	DoAnim();
 }
//---------------------------------------------------------------------------
void __fastcall Tfm::buBack4Click(TObject *Sender)
{
	Back();
	tmGame->Enabled = false;

}
//---------------------------------------------------------------------------
void __fastcall Tfm::buEasyClick(TObject *Sender)
{
	tc->ActiveTab = tiGame;
	DoStart();

	DoGame();

	DoReset();
	tmGame->Enabled = true;


}
//---------------------------------------------------------------------------
void __fastcall Tfm::buNotEasyClick(TObject *Sender)
{
	tc->ActiveTab = tiGame;

	DoGame();

	DoStart();
	DoReset();
	tmGame->Enabled = true;

    laValSec->Enabled = true;
	laValSec->Visible = true;

	laCheckSec->Enabled = true;
	laCheckSec->Visible = true;
}
//---------------------------------------------------------------------------
 void Tfm::DoGame()
 {
	//запуск игры
	Rand = Random(8);
	laValFir->Text=cList[Rand];
	laValFir->Tag = Rand;

	Rand = Random(8);

	DoColor(1);




	Rand = Random(8);
	laCheckFir->Text=cList[Rand];

	DoColor(2);


	if (laCheckSec->Enabled == true)
	{

		Rand = Random(8);
		laValSec->Text=cList[Rand];
		laValSec->Tag = Rand;
		DoColor(3);


		Rand = Random(8);
		laCheckSec->Text=cList[Rand];

		DoColor(4);


	}



 }

 void Tfm::DoColor(int i)
 {
 //выбор цвета и надписи
	String x;

	switch(i)
	{
	case 1:
	 x="laValFir";
	break;

	case 2:
	 x="laCheckFir";
	break;

	case 3:
	 x="laValSec";
	break;

	case 4:
	 x="laCheckSec";
	break;

	}


	la= new TLabel(fm);
	la=((TLabel*)fm->FindComponent(x));



   int j = random(8);

   switch(j)
   {

	case 0:
	la->FontColor=(TAlphaColorRec:: Red);
	if(i==2||i==4) la->Tag=j;
	break;

	case 1:
	la->FontColor=(TAlphaColorRec:: Green);
	if(i==2||i==4) la->Tag=j;
	break;

	case 2:
	la->FontColor=(TAlphaColorRec:: Blue);
	if(i==2||i==4) la->Tag=j;
	break;

	case 3:
	la->FontColor=(TAlphaColorRec:: Black);
	if(i==2||i==4) la->Tag=j;
	break;

	case 4:
	la->FontColor=(TAlphaColorRec:: Orange);
	if(i==2||i==4) la->Tag=j;
	break;

	case 5:
	la->FontColor=(TAlphaColorRec:: Purple);
	if(i==2||i==4) la->Tag=j;
	break;

	case 6:
	la->FontColor=(TAlphaColorRec:: Yellow);
	if(i==2||i==4) la->Tag=j;
	break;

	case 7:
	la->FontColor=(TAlphaColorRec:: Grey);
	if(i==2||i==4) la->Tag=j;
	break;

	case 8:
	la->FontColor=(TAlphaColorRec:: Lightgreen);
	if(i==2||i==4) la->Tag=j;
	break;


   }
 }

void __fastcall Tfm::buYesClick(TObject *Sender)
{
	Yes();
}

void __fastcall Tfm::buNoClick(TObject *Sender)
{

  	No();
}

 void Tfm::Yes()
 {
 //проверка правильного ответа(кнопка да)
 if (laValSec->Enabled==true)
   {
		if(laValFir->Tag == laCheckFir->Tag && laValSec->Tag == laCheckSec->Tag)
		{
			Score=Score+1;
		}
		else Score--;
   }

	if (laValSec->Enabled!=true)
	{
		if(laValFir->Tag == laCheckFir->Tag)
		{
		Score=Score+1;
		}
		else Score--;
	}




	laScore->Text ="Очки:" + IntToStr(Score) ;

	DoGame();
 }

  void Tfm::No()
 {
 //проверка правильного ответа(кнопка нет)
    if (laValSec->Enabled==true)
	{
		if(laValFir->Tag != laCheckFir->Tag || laValSec->Tag != laCheckSec->Tag)
		{
			Score=Score+1;
		}
		else Score--;
	}


   if (laValSec->Enabled!=true)
	{
		if(laValFir->Tag != laCheckFir->Tag)
		{
			Score=Score+1;
		}
		else Score--;
	}



	laScore->Text ="Очки: " + IntToStr(Score) ;

	DoGame();
 }

 void Tfm::DoReset()
 {
   FTimeValue = Time().Val + (double)(tbTime->Value)/(24*60*60);
   Score = 0;
   laScore->Text ="Очки: " + IntToStr(Score) ;
 }

  void Tfm::DoFinish()
 {
    tmGame->Enabled = false;
	laEndScore->Text = "Ваши очки: " + IntToStr(Score);
	tc->ActiveTab = tiEndGame;
 }

  void Tfm::DoAnim()
 {
 //анимация главного меню
	buGame->Position->X = - buGame->Width;
	TAnimator::AnimateInt(buGame,"Position.X",20,1,TAnimationType::Out,TInterpolationType::Back);


	buResult->Position->X =this->Width + buGame->Width;
	TAnimator::AnimateInt(buResult,"Position.X",20,1,TAnimationType::Out,TInterpolationType::Back);

	buSet->Position->X = - buSet->Width;
	TAnimator::AnimateInt(buSet,"Position.X",20,1,TAnimationType::Out,TInterpolationType::Back);

	buHelp->Position->X =this->Width + buGame->Width;
	TAnimator::AnimateInt(buHelp,"Position.X",20,1,TAnimationType::Out,TInterpolationType::Back);


	buAbout->Position->X = - buAbout->Width;
	TAnimator::AnimateInt(buAbout,"Position.X",20,1,TAnimationType::Out,TInterpolationType::Back);

 }


   void Tfm::DoStart()
 {
 // анимация начала игры
	laStart->Enabled = true;
	laStart->Visible = true;


	tbTop->Enabled = false;
	tbTop->Visible = false;

	tbBot->Enabled = false;
	tbBot->Visible = false;

	laQ->Enabled = false;
	laQ->Visible = false;

	laValFir->Enabled = false;
	laValFir->Visible = false;

	laCheckFir->Enabled = false;
	laCheckFir->Visible = false;

	laValSec->Enabled = false;
	laValSec->Visible = false;

	laCheckSec->Enabled = false;
	laCheckSec->Visible = false;



	laStart->Text=3;
	laStart->AutoSize = true;
	laStart->TextSettings->Font->Size = 400;
	laStart->FontColor=(TAlphaColorRec:: Green);
	TAnimator::AnimateIntWait(laStart,"TextSettings.Font.Size",50,1,TAnimationType::Out, TInterpolationType::Linear);

	laStart->Text=2;
	laStart->AutoSize = true;
	laStart->TextSettings->Font->Size = 400;
	laStart->FontColor=(TAlphaColorRec:: Yellow);
	TAnimator::AnimateIntWait(laStart,"TextSettings.Font.Size",50,1,TAnimationType::Out, TInterpolationType::Linear);

	laStart->Text=1;
	laStart->AutoSize = true;
	laStart->TextSettings->Font->Size = 400;
	laStart->FontColor=(TAlphaColorRec:: Red);
	TAnimator::AnimateIntWait(laStart,"TextSettings.Font.Size",50,1,TAnimationType::Out, TInterpolationType::Linear);

	laStart->Enabled = false;
	laStart->Visible = false;


	tbTop->Enabled = true;
	tbTop->Visible = true;

	tbBot->Enabled = true;
	tbBot->Visible = true;

	laQ->Enabled = true;
	laQ->Visible = true;

	laValFir->Enabled = true;
	laValFir->Visible = true;

	laCheckFir->Enabled = true;
	laCheckFir->Visible = true;


}

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
   //	FTimeValue = Time().Val + (double)30/(24*60*60);

void __fastcall Tfm::buWhiteClick(TObject *Sender)
{
	rec= new TRectangle(fm);
	int i=1;
	while (i<8){

		String recName = "rec" + IntToStr(i);
		rec=((TRectangle*)fm->FindComponent(recName));
		rec->Fill->Color = TAlphaColor(TAlphaColorRec:: White);
		i++;
	}
}
//---------------------------------------------------------------------------


void __fastcall Tfm::tmGameTimer(TObject *Sender)
{
	double x = FTimeValue - Time().Val;
	laTime->Text = FormatDateTime("nn:ss",x);
	if (x<=0){


		DoFinish();
	}

}
//---------------------------------------------------------------------------

void __fastcall Tfm::tbTimeChange(TObject *Sender)
{
	laTbValue->Text = FloatToStr(tbTime->Value) + " Секунд" ;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall Tfm::buAddColorClick(TObject *Sender)
{
//смена цвета
	rec= new TRectangle(fm);
	int i=1;
	while (i<8){

		String recName = "rec" + IntToStr(i);
		rec=((TRectangle*)fm->FindComponent(recName));
		rec->Fill->Color = TAlphaColorF::Create(256 - StrToIntDef(edR->Text,0),256 - StrToIntDef(edG->Text,0),256 - StrToIntDef(edB->Text,0))
		.ToAlphaColor();
;
		i++;
	}
}
//---------------------------------------------------------------------------

void __fastcall Tfm::buGameMouseEnter(TObject *Sender)
{
	TButton *x = ((TButton*)Sender);

	x->TextSettings->Font->Size +=10;
	x->TextSettings->Font->Style = x->TextSettings->Font->Style << TFontStyle::fsBold;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buGameMouseLeave(TObject *Sender)
{
	TButton *x = ((TButton*)Sender);
	x->TextSettings->Font->Size -=10;
	x->TextSettings->Font->Style = x->TextSettings->Font->Style >> TFontStyle::fsBold;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::buAddClick(TObject *Sender)
{
//запись в таблицу рекордов
	String temp = edName->Text+L" — "+ IntToStr(Score);


			if(temp.Length() != 0 )
			{



			TStringList *listAdd = new TStringList;  // 1й TStringLis


			if (FileExists(saveTXT) == false) // проверяем наличие файла
				{
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
			temp=NULL;


		  buAdd->Text="Внесено!";
		  buAdd->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall Tfm::KeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(Key == vkReturn){

		Yes();
	}

	if(Key == vkEscape){

		No();
	}


	if(Key == vkHardwareBack){

		Back();
	}


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


