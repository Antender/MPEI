#include <stdio.h>
#include <float.h>
#include <fenv.h>

void fepsComp(void)
{
  float feps,fepsPr;
  int iter=0; /* k - счетчик итераций */
  feps=1.0;
  do
  {
      feps=feps/2.0;
      fepsPr=feps+1.0;
      ++iter;
  } while (fepsPr>1.0);
  printf("Number of divisions by 2: %d\n",iter);
  printf("Epsilon: %e\n",feps);
}

void depsComp(void)
{
  double deps,depsPr;
  int iter=0; /* k - счетчик итераций */
  deps=1.0;
  do
  {
      deps=deps/2.0;
      depsPr=deps+1.0;
      ++iter;
  } while (depsPr>1.0);
  printf("Number of divisions by 2: %d\n",iter);
  printf("Epsilon: %e\n",deps);
}

void ldepsComp(void)
{
  long double ldeps,ldepsPr;
  int iter=0; /* k - счетчик итераций */
  ldeps=1.0;
  do
  {
      ldeps=ldeps/2.0;
      ldepsPr=ldeps+1.0;
      ++iter;
  } while (ldepsPr>1.0);
  printf("Number of divisions by 2: %d\n",iter);
  printf("Epsilon: %e\n",(double)ldeps);
}

void fnullComp(void)
{
  float fnull,fnullPr;
  int iter=0; /* k - счетчик итераций */
  fnullPr=1.0;
  do
  {
      fnull=fnullPr;
      fnullPr=fnullPr/2.0;
      ++iter;
  } while (fnullPr!=0.0);
  printf("Number of divisions by 2: %d\n",iter);
  printf("Null: %e\n",fnull);
}

void dnullComp(void)
{
  double dnull,dnullPr;
  int iter=0; /* k - счетчик итераций */
  dnullPr=1.0;
  do
  {
      dnull=dnullPr;
      dnullPr=dnullPr/2.0;
      ++iter;
  } while (dnullPr!=0.0);
  printf("Number of divisions by 2: %d\n",iter);
  printf("Null: %e\n",dnull);
}

void ldnullComp(void)
{
  long double ldnull,ldnullPr;
  int iter=0; /* k - счетчик итераций */
  ldnullPr=1.0;
  do
  {
      ldnull=ldnullPr;
      ldnullPr=ldnullPr/2.0;
      ++iter;
  } while (ldnullPr!=0.0);
  printf("Number of divisions by 2: %d\n",iter);
  printf("Null: %e\n",(double)ldnull);
}

void finfComp(void)
{
  feclearexcept(FE_OVERFLOW); 
  float finf;
  int iter=0; /* k - счетчик итераций */
  finf=1.0;
  do
  {
      finf=finf*2.0;
      ++iter;
  } while (!fetestexcept(FE_OVERFLOW));
  printf("Number of multiplications by 2: %d\n",iter);
  printf("Infinity: %e\n",finf);
}

void dinfComp(void)
{
  feclearexcept(FE_OVERFLOW);
  double dinf;
  int iter=0; /* k - счетчик итераций */
  dinf=1.0;
  do
  {
      dinf=dinf*2.0;
      ++iter;
  } while (!fetestexcept(FE_OVERFLOW));
  printf("Number of multiplications by 2: %d\n",iter);
  printf("Infinity: %e\n",dinf);
}

void ldinfComp(void)
{
  feclearexcept(FE_OVERFLOW);
  long double ldinf;
  int iter=0; /* k - счетчик итераций */
  ldinf=1.0;
  do
  {
      ldinf=ldinf*2.0;
      ++iter;
  } while (!fetestexcept(FE_OVERFLOW));
  printf("Number of multiplications by 2: %d\n",iter);
  printf("Infinity: %e\n",(double)ldinf);
}

int main(void)
{
  fepsComp();
  depsComp();
  ldepsComp();
  fnullComp();
  dnullComp();
  ldnullComp();
  finfComp();
  dinfComp();
  ldinfComp();
  return 0;
}
