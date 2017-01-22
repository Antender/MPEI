#include <stdio.h>
#include <tgmath.h>

static double C1;
static double C2;
static double eps;

typedef struct {
  double value;
  int iter;
} result;

inline double f(double x)
{
  double c = cos(x);
  return c*(c-C1)+C2;
}

inline double fp(double x)
{
  return sin(x)*(-2.0*cos(x)+C1);
}

result Newton(double x_in)
{
  double x=x_in,x0;
  int i=0; 
  do {
    i++;
    x0 = x;
    x -= f(x)/fp(x);
  } while (fabs(x-x0)>eps);
  result r;
  r.value = x;
  r.iter = i;
  return r;
}

result SimpNewton(double x_in)
{
  double csn = fp(x_in);
  double x=x_in,x0;
  int i=0; 
  do {
    i++;
    x0 = x;
    x -= f(x)/csn;
  } while (fabs(x-x0)>eps);
  result r;
  r.value = x;
  r.iter = i;
  return r;
}

int main(int argc, char* argv[])
{
  C1 = 1.0/sqrt(2.0)+1.0/4.0;
  C2 = 1.0/(4.0*sqrt(2.0));
  puts("Enter precision:");
  scanf("%lf",&eps);
  puts("");
  double h;
  puts("Enter grid width:");
  scanf("%lf",&h);
  puts("");
  double k=0;
  double fk = f(k);
  double fkh = f(k+h);
  while (k<1.5) {
    printf("f(%lf)=%lf\n",k,fk);
    if (fk*fkh<0) {
      printf("Localization interval[%lf,%lf]\n",k,k+h);
      result r = Newton(k);
      printf("Newton method; result:%lf  iterations:%i\n",r.value,r.iter);
      r = SimpNewton(k);
      printf("Simplified Newton method; result:%lf  iterations:%i\n",r.value,r.iter);
    }
    k += h;
    fk = fkh;
    fkh = f(k);
  }
  puts("");
  return 0;
}
