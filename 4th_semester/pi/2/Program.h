//---------------------------------------------------------------------------

#ifndef ProgramH
#define ProgramH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <map>
#include <string>
#include <cstdio>
#include <utility>
//---------------------------------------------------------------------------
typedef std::map<std::string,std::string> Map;
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *WordLabel;
        TLabel *TranslationLabel;
        TEdit *Word;
        TEdit *Translation;
        void __fastcall OnCreate(TObject *Sender);
        void __fastcall OnDestroy(TObject *Sender);
        void __fastcall Translate(TObject *Sender);
        void __fastcall ChangeTranslation(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        Map* translations;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
