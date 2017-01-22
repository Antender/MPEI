//---------------------------------------------------------------------------

#ifndef Program1H
#define Program1H
//---------------------------------------------------------------------------
#include "Matrix.cpp"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TUpDown *WidthUpDown;
        TEdit *WidthEdit;
        TEdit *HeightEdit;
        TUpDown *HeightUpDown;
        TLabel *WidthLabel;
        TLabel *HeightLabel;
        TMainMenu *MainMenu1;
        TButton *Process;
        TMenuItem *FileMenu;
        TMenuItem *ImportMenu;
        TMenuItem *ExportMenu;
        TMenuItem *ExitMenu;
        TStringGrid *DataGrid;
        TOpenDialog *ImportDialog;
        TSaveDialog *ExportDialog;
        TMenuItem *N1;
        TMenuItem *N2;
	void __fastcall ExitMenuClick(TObject *Sender);
	void __fastcall ImportMenuClick(TObject *Sender);
	void __fastcall WidthChange(TObject *Sender);
	void __fastcall HeightChange(TObject *Sender);
	void __fastcall ExportMenuClick(TObject *Sender);
	void __fastcall SetGrid(Matrix* mdata);
	Matrix* __fastcall GetGrid();
	void __fastcall ProcessClick(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        bool Mode;
        float Min;
        float Max;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
