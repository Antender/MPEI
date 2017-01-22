using System;
using System.Collections.Generic;
using System.Text;
using System.Data;
using Int64Fractions;

namespace Linal5Con
{
  class Program
  {
    static void Main(string[] args)
    {
      List<Vector> A = new List<Vector>();
      string input;
      int i=0;
      do {
        Console.Write("A"+i+"=");
        input = Console.ReadLine();
        if (input!="") 
        {
          A.Add(Vector.Parse(input));
        }
        i++;
      } while (input!="");
      Console.WriteLine();
      List<Vector> B = new List<Vector>();
      for (i=0;i<A.Count;i++) 
      {
        Vector BI = A[i];
        Console.Write("B"+i+"=A"+i);

        for (int j=0;j<i;j++)
        {
          Fraction a = (A[i] * B[j]);
          Fraction b = (B[j] * B[j]);
          
          Fraction proj =(a / b).Reduced();
          BI = BI - proj * B[j];          
          Console.Write("-" + proj.ToString() + "*B"+j);
          Console.Write("{A"+i+"*B"+i+"=" + a.ToString() + "|");
          Console.Write("|B"+i+"*B"+i+"=" + b.ToString() + "}");
        }
        BI = BI.Simplify();
        B.Add(BI);
        Console.WriteLine();
        Console.WriteLine("B"+i+"="+BI.ToString());
      }
      Console.WriteLine();


      Console.WriteLine("Результат:");
      foreach (Vector vect in B)
      {
        Console.WriteLine(vect.Simplify().ToString());
      }
      Console.ReadLine();
    }
  }
}
