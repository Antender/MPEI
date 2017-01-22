import java.util.*;

class Main
{
  static final int mS = 40; //Matrix size
  static final int cP = 4-1; //Non-zero column
  static final int icP = mS-cP-1; //Matrix size - non-zero column position
  static final double mainConst = 40.0;
  static final double sideConst = 6.0;
  static final double columnConst = 40.0;
  static double[][] array = new double[mS][mS];
  static double[][] result;
  static double norm1(double[][] ar)
  {
    double max = 0.0;
    for (int i=0;i<mS;i++)
    {
      double sum = 0.0;
      for (int j=0;j<mS;j++)
      {
        sum += Math.abs(ar[j][i]);
      }
      if (sum>max)
      {
        max = sum;
      }
    }
    return max;
  }
  static void fillMatrix(double[][] ar)
  {
    for (int i=0;i<mS;i++)
    {
      for (int j=0;j<mS;j++)
      {
        if (i==j) 
        {
          ar[i][j] = mainConst;
        }
        else
        {
          if (i==(mS-j-1))
          {
            ar[i][j] = sideConst;
          }
          else
          {
            if (j==cP)
            {
              ar[i][j] = columnConst;
            }
            else
            {
              ar[i][j] = 0.0;
            }
          }
        }
      }
    } 
  }
  static void fillOnes(double[][] ar)
  {
    for (int i=0;i<mS;i++)
    {
      ar[i][i] = 1.0;
    }
  }
  static double[][] findInverse(double[][] ar)
  {
    double[][] res = new double[mS][mS];
    fillOnes(res);
    
    res[cP][cP] /= ar[cP][cP];
    ar[cP][icP] /= ar[cP][cP];
    ar[cP][cP] = 1.0;
    
    res[icP][icP] /= ar[icP][cP];
    ar[icP][icP] /= ar[icP][cP];
    ar[icP][cP] = 1.0;
    
    res[icP][cP] -= res[cP][cP];
    ar[icP][cP]  -= ar[cP][cP];
    ar[icP][icP] -= ar[cP][icP];
    
    res[icP][cP] /= ar[icP][icP];
    res[icP][icP] /= ar[icP][icP];
    ar[icP][icP] = 1.0;
    
    res[cP][cP] -= res[icP][cP]*ar[cP][icP];
    res[cP][icP] -= res[icP][icP]*ar[cP][icP];
    ar[cP][icP] -= ar[icP][icP]*ar[cP][icP];

    for (int i=0;i<mS;i++)
    {
      if ((i!=cP) && (i!=icP))
      {
        res[i][i] /= ar[i][i];
        ar[i][mS-i-1] /= ar[i][i];
        ar[i][i] = 1.0;
        ar[i][cP] = 0.0;
        res[i][cP] -= res[cP][cP];
        res[i][icP] -= res[cP][icP];
      }
    }
    for (int i=0;i<(mS/2);i++)
    {
      if (i!=cP)
      {
        res[mS-i-1][i]      -= res[i][i]*ar[mS-i-1][i];
        res[mS-i-1][cP]     -= res[i][cP]*ar[mS-i-1][i];
        res[mS-i-1][icP]    -= res[i][icP]*ar[mS-i-1][i];
        res[mS-i-1][mS-i-1] -= res[i][mS-i-1]*ar[mS-i-1][i];
        ar[mS-i-1][mS-i-1] -= ar[mS-i-1][i]*ar[i][mS-i-1]; 
        ar[mS-i-1][i] = 0.0; 
      }
    }
    for (int i=mS/2;i<mS;i++)
    {
      if (i!=icP)
      {
        res[i][i]      /= ar[i][i];
        res[i][cP]     /= ar[i][i];
        res[i][icP]    /= ar[i][i];
        res[i][mS-i-1] /= ar[i][i];
        ar[i][i] = 1.0; 
      }
    }
    for (int i=0;i<(mS/2);i++)
    {
      if (i!=cP)
      {
        res[i][i]      -= res[mS-i-1][i]*ar[i][mS-i-1];
        res[i][cP]     -= res[mS-i-1][cP]*ar[i][mS-i-1];
        res[i][icP]    -= res[mS-i-1][icP]*ar[i][mS-i-1];
        res[i][mS-i-1] -= res[mS-i-1][mS-i-1]*ar[i][mS-i-1];
        ar[i][mS-i-1]  -= ar[mS-i-1][mS-i-1]*ar[i][mS-i-1]; 
      }
    }
    return res;
  }
  static void printMatrix(double[][] ar)
  {
    for (int i=0; i<mS; i++)
    {
       for (int j=0; j<mS; j++)
       {
          System.out.printf("%7.3f",ar[i][j]);
          System.out.print(" ");
       }
       System.out.println();
    }
    System.out.println();
  }
  public static void main(String[] args)
  {
    fillMatrix(array);
    result = findInverse(array);
    fillMatrix(array);
    System.out.print(norm1(array)*norm1(result));
  }
}