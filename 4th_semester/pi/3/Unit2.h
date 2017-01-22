//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TResult : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *ResultGrid;
private:	// User declarations
public:		// User declarations
        __fastcall TResult(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TResult *Result;
//---------------------------------------------------------------------------
#endif
