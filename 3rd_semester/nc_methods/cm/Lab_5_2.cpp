// Lab.5.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

const int nmax = 100;


//матрица производных. Параметры: mas - рыба матрицы, z- нач.прибл, х - значения на отрезке разбиения, N - кол-во размений
void F1(double mas[][nmax], double z[], double x[], int N)
{
	double a = 0; // левая граница стержня
	double b = 2.3; // правая граница стержня
	double h = (b-a)/N; // шаг 
	
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
		{
			mas[0][0] = 1;
			mas[N][N] = 1;
			if ((i != 0) & (i != N))
				mas[i][i] = (2+h*h*(2+x[i]))-h*h*(1/(2*sqrt(1+z[i])));
			if  (i != N-1)
				mas[i+1][i] = -1;
			mas[i+1][i+2] = -1;
		}
}

// Функция (правая часть м.Ньютона)
void F(double mas[], double z[], double x[], int N, double grA, double grB)
{
	double a = 0; // левая граница стержня
	double b = 2.3; // правая граница стержня
	double h = (b-a)/N; // шаг 
	
	mas[0] = -z[0]+grA;
	for (int i = 1; i < N; i++)
		{
			
			mas[i] = -(-z[i-1]+2*z[i]-z[i+1]+(2+x[i])*z[i]*h*h-h*h*(sqrt(1+z[i])));
		}
	mas[N] = -z[N]+grB;
}

/**
	 * n - число уравнений (строк матрицы)
	 * b - диагональ, лежащая над главной (нумеруется: [0;n-2])
	 * c - главная диагональ матрицы A (нумеруется: [0;n-1])
	 * a - диагональ, лежащая под главной (нумеруется: [1;n-1])
	 * f - правая часть (столбец)
	 * x - решение, массив x будет содержать ответ
	 Данный код работает при предположении, что a[0] = 0, b[n-1] = 0.
	 */
void solve (int n, double *a, double *c, double *b, double *f, double *x)
{
	double m;
	for (int i = 1; i < n; i++)
	{
		m = a[i]/c[i-1];  
		c[i] = c[i] - m*b[i-1];
		f[i] = f[i] - m*f[i-1];
	}
 
	x[n-1] = f[n-1]/c[n-1]; 
 
	for (int i = n - 2; i >= 0; i--) 
		x[i]=(f[i]-b[i]*x[i+1])/c[i];
 
}

// Метод прогонки
void solveProgonka(double x[], double a[], double b[], double c[], double d[], int n)
{
	double alpha[nmax],betta[nmax];

	alpha[0]=-c[0]/b[0];
    betta[0]=d[0]/b[0];

    for (int i = 1; i < n; i++)
    {
        alpha[i] =-c[i]/(b[i]+a[i]*alpha[i-1]);
        betta[i] =(d[i]-a[i]*betta[i-1])/(b[i]+a[i]*alpha[i-1]);
    }

	betta[n] = (d[n]-a[n]*betta[n-1])/b[n]+a[n]*alpha[n-1];
	x[n] = betta[n];
	
    for (int i = n-1; i >= 0; i--)
    {
        x[i]=alpha[i]*x[i+1] + betta[i];
    }
}

// Значения, стоящие в матрице производных на главной диагонале
void diagElem(double mas[], double z[], double x[], int N)
{
	double a = 0; // левая граница стержня
	double b = 2.3; // правая граница стержня
	double h = (b-a)/N; // шаг 
	
	for (int i = 0; i <= N; i++)
	{
		mas[0] = 1;
		if ((i != 0) & (i != N))
			mas[i] = (2+h*h*(2+x[i]))-h*h*(1/(2*sqrt(1+z[i])));
		mas[N] = 1;
	}
}

// Первая норма вектора
double norm1(double x[], int n)
{
	double sum;

	sum = 0.0;
	for (int i = 0; i <= n; i++)
		sum = sum + abs(x[i]);
	return sum;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"rus");
	double a = 0; // левая граница стержня
	double b = 2.3; // правая граница стержня
	int N;
	double ua = 0.0; double ub = 0.0; // граничные условия
	double eps; 
	double norma;

	cout << "Введите количество разбиений отрезка [a,b]" << '\n';
	cin >> N;

	cout << "Введите  точность эпсилон" << '\n';
	cin >> eps;
	
	printf("\n");
	cout << "Введите значение в точке а" << '\n';
	cin >> ua;
	
	cout << "Введите значение в точке b" << '\n';
	cin >> ub;

	cout << "Ua: " << ua << ", Ub: " << ub << '\n';

	double h = (b-a)/N; // шаг 
	double setka[nmax]; // сетка на отрезке
	double sistema1[nmax][nmax]; //первая система уравнений
	double proizvodF[nmax][nmax]; //матрица производных 
	double funcF[nmax]; //вектор функции
	double z[nmax]; //искомая
	double temp[nmax]; //для сравнения со следующим значением
	double delta[nmax];
	double podDiag[nmax];
	double nadDiag[nmax];
	double mainDiag[nmax];

	//данные для теста из учебника (стр.570-571)
	double xtest[9] = {0, 0, 0, 0, 0, 0, 0, 0};
	double atest[9] = {0, -1, -1, -1, -1, -1, -1, 0}; //диагональ, лежащая под главной
	double btest[9] = {0, -1, -1, -1, -1, -1, -1, 0}; //диагональ, лежащая над главной
	double ctest[9] = {1, 2.00024, 2.00098, 2.00220, 2.00391, 2.00610, 2.00897, 2.01196, 1}; //главная диагональ 
	double ftest[9] = {1, 0.0380518, 0.0365207, 0.0338827, 0.0300233, 0.0248099, 0.0181171, 0.0098552, 0}; //столбец правой части
	int ntest = 9;

	for (int i = 0; i <= N; i++)
	{
		setka[i] = a + i*h;
	}

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			proizvodF[i][j] = 0;

	for (int i = 0; i <= N; i++)
		funcF[i] = 0;

	z[0] = ua;
	for (int i = 1; i < N; i++)
	{
		z[i] = 0;
	}
	z[N] = ub;

	nadDiag[0] = 0;
	for (int i = 1; i < N; i++)
	{
		nadDiag[i] = -1;
	}
	nadDiag[N] = 0;

	podDiag[0] = 0;
	for (int i = 1; i < N; i++)
	{
		podDiag[i] = -1;
	}
	podDiag[N] = 0;


	
	cout << "Деления отрезка:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		//printf(" %d",setka[i]);
		cout << setka[i] << ' ';
	}

	cout << '\n';

	F1(proizvodF,z,setka,N);

	cout << "Матрица производных:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			cout << proizvodF[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "Наддиагональ:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		cout << nadDiag[i] << ' ';
	}
	cout << '\n';

	cout << "Поддиагональ:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		cout << podDiag[i] << ' ';
	}
	cout << '\n';

	diagElem(mainDiag, z, setka, N);

	cout << "Главная диагональ:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		cout << mainDiag[i] << ' ';
	}
	cout << '\n';



	F(funcF, z, setka, N, ua, ub);

	cout << "Правая часть:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		cout << funcF[i] << ' ';
	}

	cout << '\n';

	/*solve(ntest, atest, ctest, btest, ftest, xtest);

	cout << "Результат теста:" << '\n';
	for (int i = 0; i < ntest; i++)
	{
		cout << xtest[i] << ' ';
	}
*/

	//double s = ui(setka,1,ua,ub);
	//cout << "Вывод функции:" << s << '\n';

	for (int i = 0; i <= N; i++)
		temp[i] = z[i];

	cout << "Начальное значение:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		cout << temp[i] << ' ';
	}
	cout << '\n';

	solveProgonka(delta, podDiag, mainDiag, nadDiag, funcF, N);

	/*cout << "Результат после прогонки:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		cout << delta[i] << ' ';
	}
	cout << '\n';*/

	norma = norm1(delta,N);
	//cout << "Норма вектора:" << norma << '\n';

	
	for (int i = 0; i <= N; i++)
	{
		z[i]=delta[i]+temp[i];
	}

	printf("\n");

	while (norma > eps)
	{
		// сохраняем старое значение
		for (int i = 0; i <= N; i++)
			temp[i] = z[i];

		// изменяем матрицу производных
		diagElem(mainDiag, z, setka, N);

		// изменяем правую часть
		F(funcF, z, setka, N, ua, ub);

		solveProgonka(delta, podDiag, mainDiag, nadDiag, funcF, N);
		norma = norm1(delta,N);

		//обновляем вектор решения
		for (int i = 0; i <= N; i++)
		{
			z[i]=delta[i]+temp[i];
		}

	}

	cout << '\n';
	cout << "Ответ:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		cout << z[i] << ' ';
	}
	cout << '\n';


	printf("\n");
	system("pause");
	return 0;
}

