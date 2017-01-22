import java.util.*;
import java.io.*;

class Project43 {
  static final int N = 4;
  static final double h = 1.0/N;

  static double normi(double[][] A, double[][] B) {
    double max = 0;
    for (int i = 0; i<= 3*N; i++) {
      double sum = 0;
      for (int j = 0; j < 3*N; j++) {
        sum +=Math.abs(A[i][j]-B[i][j]);
      }
      if (sum>max) {
        max = sum;
      }
    }
    return max;
  }

  static void Print(double[][] ar) {
    for (int j = 3*N ; j>=0; j--) {
      for (int i = 0; i<= 3*N; i++) {
        System.out.printf("%2.1f ",ar[i][j]);
        System.out.print(" ");
      }
      System.out.println();
    }
  }

  static void Copy(double[][] input, double[][] output) {
    for (int i = 0; i < input.length; i++) {
      System.arraycopy(input[i],0,output[i],0,input[i].length);
    }
  }

  static double f(double x, double y) {
    return 0;
    //sin(x)*cos(y);
  }

  static void Border(double[][] ar,
  double a, double b, double c,
  double d, double e, double f,
  double g, double h
  ) {
    for (int i = 0; i<= N; i++) {
      ar[i][3*N] = a;
    }
    for (int i = N; i< 3*N; i++) {
      ar[N][i] = b;
    }
    for (int i = N+1; i<= 2*N; i++) {
      ar[i][N] = c;
    }
    for (int i = N+1; i<=3*N; i++) {
      ar[2*N][i] = d;
    }
    for (int i = 2*N+1; i<=3*N; i++) {
      ar[i][3*N] = e;
    }
    for (int i = 0; i<=3*N; i++) {
      ar[3*N][i] = f;
    }
    for (int i = 0; i<=3*N; i++) {
      ar[i][0] = g;
    }
    for (int i = 1; i<3*N; i++) {
      ar[0][i] = h;
    }
  }

  static void fij(double[][] ar, int i, int j, double w) {
    ar[i][j] = (1-w)*ar[i][j] + w*(0.25*(ar[i-1][j]+ar[i+1][j]+ar[i][j-1]+ar[i][j+1])+0.25*h*h*f(i,j));
  }

  static int Solve(double w, double eps, double[][] a, double[][] b) {
    int k = 0;
    do {
      k++;
      Copy(a,b);
      for (int i = 1; i<N; i++) {
        for (int j = 1; j < 3*N; j++) {
          fij(a,i,j,w);
        }
      }
      for (int i = N; i <= 2*N; i++) {
        for (int j = 1; j < N; j++) {
          fij(a,i,j,w);
        }
      }
      for (int i = 2*N+1; i < 3*N; i++) {
        for (int j = 1; j < 3*N; j++) {
          fij(a,i,j,w);
        }
      }
    }
    while (normi(a,b)>=eps);
    return k;
  }
  
  static double readDouble(Scanner in) {
    try {
      return in.nextDouble();
    } catch(Exception e) {
      return 0.0;
    }
  }

  public static void main(String[] args) {
    double[][] A = new double [3*N+1][3*N+1];
    double[][] B = new double [3*N+1][3*N+1];
    Scanner in = new Scanner(System.in);
    System.out.print("Enter epsilon:");
    double eps = readDouble(in);
    System.out.print("Enter borders (8):");
    double a = readDouble(in);
    double b = readDouble(in);
    double c = readDouble(in);
    double d = readDouble(in);
    double e = readDouble(in);
    double f = readDouble(in);
    double g = readDouble(in);
    double h = readDouble(in);
    System.out.println();
    Border(A,a,b,c,d,e,f,g,h);
    Print(A);
    System.out.println();
    int k;
    double w;
    System.out.println("1 for Seidel method, relaxation parameter otherwise:");
    w = readDouble(in);
    k = Solve(w,eps,A,B);
    Print(A);
    System.out.print("Number of iterations:");
    System.out.println(k);
  }
}