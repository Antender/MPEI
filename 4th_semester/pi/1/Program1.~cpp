#include <vcl.h>
#pragma hdrstop
#include "Matrix.cpp"
#include "Program1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExitMenuClick(TObject *Sender)
{
  exit(0);	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ImportMenuClick(TObject *Sender)
{
   Matrix* mdata;
   if(!MainForm->ImportDialog->Execute()) return;
   mdata = new Matrix();
   mdata->readFromFile(MainForm->ImportDialog->FileName.c_str());
   SetGrid(mdata);
   delete mdata;
}

void __fastcall TMainForm::SetGrid(Matrix* mdata)
{
   for(int row=0;row<(mdata->height);++row)
   {
	 for(int column=0;column<(mdata->width);++column)
	 {
		MainForm->DataGrid->Cells[column][row] = mdata->at(row)->at(column);
	 }
   }
   MainForm->WidthEdit->Text = mdata->width;
   MainForm->HeightEdit->Text = mdata->height;
   MainForm->DataGrid->ColCount = mdata->width;
   MainForm->DataGrid->RowCount = mdata->height;
}

Matrix* __fastcall TMainForm::GetGrid()
{
   Matrix* mdata = new Matrix();
   mdata->height = MainForm->HeightEdit->Text.ToInt();
   mdata->width  = MainForm->WidthEdit->Text.ToInt();
   mdata->reserve(mdata->height);
   for(int column=0;column<mdata->height;++column)
   {
	  Vector* vecptr = new Vector();
	  mdata->push_back(vecptr);
	  vecptr->reserve(mdata->width);
	  for(int row=0;row<mdata->width;++row)
	  {
		if(MainForm->DataGrid->Cells[row][column]=="")
		{
          vecptr->push_back(0);
		}
		else
		{
		  vecptr->push_back(MainForm->DataGrid->Cells[row][column].ToInt());
		}
	  }
   }
   return mdata;
}
void __fastcall TMainForm::WidthChange(TObject *Sender)
{
   MainForm->DataGrid->ColCount = ((TEdit*)Sender)->Text.ToInt();
}
void __fastcall TMainForm::HeightChange(TObject *Sender)
{
   MainForm->DataGrid->RowCount = ((TEdit*)Sender)->Text.ToInt();
}

void __fastcall TMainForm::ExportMenuClick(TObject *Sender)
{
   if(!MainForm->ExportDialog->Execute()) return;
   Matrix* mdata = GetGrid();
   mdata->writeToFile(MainForm->ExportDialog->FileName.c_str());
   delete mdata;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ClipRowsButtonClick(TObject *Sender)
{
   Matrix* mdata = GetGrid();
   mdata->moveToEnd();
   mdata->height = mdata->cpos;
   SetGrid(mdata);
   delete mdata;
}
