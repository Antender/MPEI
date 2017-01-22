using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using Int64Fractions;

namespace Linal5Con
{
  class Program
  {
    static void Main(string[] args)
    {
      var B = new Matrix();
      string input;
      int i=0;
      do {
        Console.Write("A"+i+"=");
        input = Console.ReadLine();
        if (input!="") 
        {
          B.Add(Vector.Parse(input));
        }
        i++;
      } while (input!="");
      Console.WriteLine();
      Console.WriteLine("Введите вектор X:");
      Vector x =Vector.Parse(Console.ReadLine());
      Vector result = new Vector();
      result.AddRange(x.Select(fraction => new Fraction(0)));
      Console.WriteLine("x_|_=");
      for (i = 0; i < B.Count; i++)
      {
        Fraction a = (x * B[i]);
        Fraction b = (B[i] * B[i]);
        Fraction proj = (a / b).Reduced();
        Vector xproj = proj*x;
        Console.WriteLine("+((x*B"+i+")/(B"+i+"*B"+i+"))*B"+i+"||x*B"+i+"="+a.ToString()+",B"+i+"*B"+i+"="+b.ToString()+"||");
        result = result + xproj;
      }
      Console.WriteLine();
      Console.WriteLine("Результат:");
      Console.WriteLine(result.Simplify().ToString());
    }
  }
}
