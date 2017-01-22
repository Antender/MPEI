//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Settings1.h"
#include "Program1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSettings *Settings;
//---------------------------------------------------------------------------
__fastcall TSettings::TSettings(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSettings::FormCreate(TObject *Sender)
{
   if (MainForm->Mode) {
      Mode->ItemIndex = 1;
   } else {
      Mode->ItemIndex = 0;
   }
   Minimum->Text = MainForm->Min;
   Maximum->Text = MainForm->Max;
}
//---------------------------------------------------------------------------
void __fastcall TSettings::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (Mode->ItemIndex) {
      MainForm->Mode = true;
   } else {
      MainForm->Mode = false;
   }
   if (Minimum->Text.ToDouble()>Maximum->Text.ToDouble()) {
     MainForm->Max = (float)Minimum->Text.ToDouble();
     MainForm->Min = (float)Maximum->Text.ToDouble();
   } else {
     MainForm->Min = (float)Minimum->Text.ToDouble();
     MainForm->Max = (float)Maximum->Text.ToDouble();
   }
}
//---------------------------------------------------------------------------
