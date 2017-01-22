//---------------------------------------------------------------------------

#ifndef Program1H
#define Program1H
//---------------------------------------------------------------------------
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
        TButton *ClipRowsButton;
        TMenuItem *FileMenu;
        TMenuItem *ImportMenu;
        TMenuItem *ExportMenu;
        TMenuItem *ExitMenu;
        TStringGrid *DataGrid;
        TOpenDialog *ImportDialog;
        TSaveDialog *ExportDialog;
	void __fastcall ExitMenuClick(TObject *Sender);
	void __fastcall ImportMenuClick(TObject *Sender);
	void __fastcall WidthChange(TObject *Sender);
	void __fastcall HeightChange(TObject *Sender);
	void __fastcall ExportMenuClick(TObject *Sender);
	void __fastcall SetGrid(Matrix* mdata);
	Matrix* __fastcall GetGrid();
	void __fastcall ClipRowsButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
