from __future__ import division
import matplotlib
matplotlib.use('TkAgg') 
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import matplotlib.pyplot as plt        ## Для графики
import numpy as np
from numpy import linalg 
import math
import copy

foo = lambda x,y: 0 

def SolveLaplace(a, b, c, d, e, f, g, h, i, k, om, epsilon = 1e-5, nx = 10, imax = 10000):

    ## Создаём массив
    T = np.zeros((nx*3 + 1, nx*3 + 1))
    

    ## Граничные условия
    T[0,:] = a
    T[:nx*2 + 1,nx*3] = b
    T[nx*2,nx*2:nx*3] = c
    T[nx*2:nx*3+1,nx*2] = d
    T[nx*3,:nx*2] = e
    T[nx*2:nx*3,0] = f
    T[nx*2,:nx] = g
    T[nx:nx*2 + 1,nx] = h
    T[nx,:nx] = i
    T[:nx,0] = k
    om = float(om)
    epsilon = float(epsilon)
    


    ## Копируем исходную матрицу для сохранения предыдущей
    ## итерации и проверки критерия окончания
    
    TN = copy.deepcopy(T)  ## особенность динамической типизации в Питоне
    err = TN - T

    k = 1

    
    while k <= imax:                          ## Метод Зейделя
        for i in np.arange(1., nx*3.):
            for j in np.arange(1.,  nx*3.):
                if not (((i >= nx) & (i <= nx*2) & (j <= nx)) | ((i >= nx*2) & (j >= nx*2))): 
                    TN[i,j] = (1-om)*T[i,j] + om*((T[i-1,j] + T[i+1,j] + T[i,j-1] + T[i,j+1])/4 + (0.01/4)*foo(i,j))
                    err[i,j] = np.abs(TN[i,j] - T[i,j])

        T = copy.deepcopy(TN)
        k += 1
        errmax = np.linalg.norm(err, np.inf)

        #print(errmax)

        if errmax < epsilon:

            print("Критерий окончания выполнен после", k, " итераций.")
            return T

    print("Метод расходится")
    return False

def PlotSolution(nx,ny,dx,T):     ## Построение графики, творчество не моё :-)

    ## Set up x and y vectors for meshgrid
    x = np.linspace(0, nx * dx, nx+1)
    y = np.linspace(0, ny * dx, ny+1)

    X, Y = np.meshgrid(x,y)
    fig2 = plt.figure()
    cs = plt.contourf(Y, -X, T, nx+1, rstride=1, cstride=1)
    plt.colorbar()
    plt.xlabel("X")
    plt.ylabel("Y")

    plt.show()

a = input("Введите граничное условие на отрезке AB: ")
b = input("Введите граничное условие на отрезке BC: ")
c = input("Введите граничное условие на отрезке CD: ")
d = input("Введите граничное условие на отрезке DE: ")
e = input("Введите граничное условие на отрезке EF: ")
f = input("Введите граничное условие на отрезке FG: ")
g = input("Введите граничное условие на отрезке GH: ")
h = input("Введите граничное условие на отрезке HI: ")
i = input("Введите граничное условие на отрезке IK: ")
k = input("Введите граничное условие на отрезке KA: ")
nx = input("Введите количество узлов на сторону квадрата: ")
om = input("Введите параметр релаксации: ")
eps = input("Введите точность решения: ")
print("Идёт вычисление, дождитесь окна с решением")
nx = int(nx)
Matrix = SolveLaplace(a, b, c, d, e, f, g, h, i, k, om, eps, nx)
PlotSolution(3*nx, 3*nx, 1, Matrix)
