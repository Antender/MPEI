// lab5.2(6Var).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

const int nmax = 100;


// Матрица в левой части м.Ньютона
void F1(double mas[][nmax], double z[], double x[], int N)
{
	double a = 0; // левая граница стержня
	double b = 2.8; // правая граница стержня
	double h = (b-a)/N; // шаг 
	
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
		{
			mas[0][0] = 1;
			if ((i != 0) & (i != N))
				mas[i][i] = 2+h*h*(pow(2.0,-x[i]))-2*h*h*z[i];
			mas[N][N] = 1;
			if  (i != N-1)
				mas[i+1][i] = -1;
			mas[i+1][i+2] = -1;
		}
}

// Правая часть м.Ньютона)
void F(double mas[], double z[], double x[], int N, double grA, double grB)
{
	double a = 0; // левая граница стержня
	double b = 2.8; // правая граница стержня
	double h = (b-a)/N; // шаг 
	
	mas[0] = -z[0]+grA;
	for (int i = 1; i < N; i++)
			mas[i] = -(-z[i-1]+2*z[i]-z[i+1]+h*h*z[i]*(pow(2.0,-x[i]))-h*h*(z[i]*z[i]+x[i]*x[i]));
	mas[N] = -z[N]+grB;
}

// Диагональные элементы матрицы производных
void diagElem(double mas[], double z[], double x[], int N)
{
	double a = 0; // левая граница стержня
	double b = 2.8; // правая граница стержня
	double h = (b-a)/N; // шаг 
	
	for (int i = 0; i <= N; i++)
	{
		mas[0] = 1;
		if ((i != 0) & (i != N))
			mas[i] = 2+h*h*(pow(2.0,-x[i]))-2*h*h*z[i];
		mas[N] = 1;
	}
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
        x[i]=alpha[i]*x[i+1] + betta[i];
}

// Бесконечная норма вектора
double normi(double x[], int n)
{
	double max;

	max = abs(x[0]);
	for (int i = 0; i <= n; i++)
		if (abs(x[i]) > max)
			max = abs(x[i]);
	return max;

}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL,"rus");
	double a = 0; // левая граница стержня
	double b = 2.8;  // правая граница стержня
	int N;
	double ua = 0.0; double ub = 0.0; // граничные условия
	double eps; 
	double norma;

	cout << "Введите количество разбиений отрезка [a,b]" << '\n';
	cin >> N;

	cout << "Введите  точность эпсилон" << '\n';
	cin >> eps;
	
	cout << "Введите значение функции в точке а" << '\n';
	cin >> ua;
	
	cout << "Введите значение функции в точке b" << '\n';
	cin >> ub;

	cout << "Граничные условия. Ua: " << ua << ", Ub: " << ub << '\n';

	double h = (b-a)/N; // шаг 
	double setka[nmax]; // сетка на отрезке
	double proizvodF[nmax][nmax]; //матрица производных 
	double funcF[nmax]; //вектор функции
	double z[nmax]; // искомая
	double temp[nmax]; // для сравнения со следующим значением
	double delta[nmax]; // решение м.Ньютона
	double podDiag[nmax], nadDiag[nmax], glavnDiag[nmax];

	for (int i = 0; i <= N; i++)
		setka[i] = a + i*h;

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			proizvodF[i][j] = 0;

	for (int i = 0; i <= N; i++)
		funcF[i] = 0;

	z[0] = ua;
	for (int i = 1; i < N; i++)
		z[i] = -2;
	z[N] = ub;

	nadDiag[0] = 0;
	for (int i = 1; i < N; i++)
		nadDiag[i] = -1;
	nadDiag[N] = 0;

	podDiag[0] = 0;
	for (int i = 1; i < N; i++)
		podDiag[i] = -1;
	podDiag[N] = 0;
	
	cout << "Деления отрезка:" << '\n';
	for (int i = 0; i <= N; i++)
		cout << setka[i] << ' ';

	cout << '\n';

	F1(proizvodF,z,setka,N);

	cout << "Матрица производных:" << '\n';
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
			cout << proizvodF[i][j] << ' ';
		cout << '\n';
	}

	/*cout << "Над диагональ:" << '\n';
	for (int i = 0; i <= N; i++)
		cout << nadDiag[i] << ' ';
	cout << '\n';

	cout << "Под диагональ:" << '\n';
	for (int i = 0; i <= N; i++)
		cout << podDiag[i] << ' ';
	cout << '\n';*/

	diagElem(glavnDiag, z, setka, N);

	/*cout << "Главная диагональ:" << '\n';
	for (int i = 0; i <= N; i++)
		cout << glavnDiag[i] << ' ';
	cout << '\n';*/

	F(funcF, z, setka, N, ua, ub);

	cout << "Правая часть:" << '\n';
	for (int i = 0; i <= N; i++)
		cout << funcF[i] << ' ';
	cout << '\n';

	for (int i = 0; i <= N; i++)
		temp[i] = z[i];

	cout << "Начальное приближение:" << '\n';
	for (int i = 0; i <= N; i++)
		cout << temp[i] << ' ';
	cout << '\n';

	solveProgonka(delta, podDiag, glavnDiag, nadDiag, funcF, N);
	norma = normi(delta,N);
	
	for (int i = 0; i <= N; i++)
		z[i]=delta[i]+temp[i];

	cout << '\n';

	while (norma > eps)
	{
		// сохраняем старое значение
		for (int i = 0; i <= N; i++)
			temp[i] = z[i];

		// изменяем матрицу производных
		diagElem(glavnDiag, z, setka, N);

		// изменяем правую часть
		F(funcF, z, setka, N, ua, ub);

		solveProgonka(delta, podDiag, glavnDiag, nadDiag, funcF, N);
		norma = normi(delta,N);

		//обновляем вектор решения
		for (int i = 0; i <= N; i++)
		{
			z[i]=delta[i]+temp[i];
		}

	}

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



