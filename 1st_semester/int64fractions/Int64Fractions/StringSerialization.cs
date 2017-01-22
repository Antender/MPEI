using System;
using System.Globalization;
using System.Linq;
using System.Text;

namespace Int64Fractions
{
  public partial struct Fraction
  {
    public static Fraction Parse(string s)
    {
      if (s == null)
      {
        throw new ArgumentException("String can't be null or empty");
      }
      var pos = s.IndexOf('/');
      return pos == -1 ? new Fraction(Int64.Parse(s), 1) : new Fraction(Int64.Parse(s.Substring(0, pos)), Int64.Parse(s.Substring(pos + 1, s.Length - pos - 1)));
    }

    public new string ToString()
    {
      if ((D == 1) || (N == 0))
      {
        return N.ToString();
      }
      return N.ToString() + "/" + D.ToString() + " ";
    }
  }

  public partial class Vector
  {
    public static Vector Parse(string s)
    {
      if (s==null)
      {
        throw new ArgumentException("String can't be empty or null");
      }
      return new Vector(s.Split(' ').Select(Fraction.Parse));
    }
    public new string ToString()
    {
      var str = new StringBuilder();
      foreach (var fraction in this)
      {
        str.Append(" " + fraction.ToString());
      }
      return str.ToString();
    }
  }
  public partial class Matrix
  {
    public static Matrix Parse(string s)
    {
      if (s == null)
      {
        throw new ArgumentException("String can't be null or empty");
      }
      return new Matrix(s.Split('\n').Select(Vector.Parse));
    }
    public new string ToString()
    {
      var str = new StringBuilder("");
      foreach (var vector in this)
      {
        if (vector != null)
        {
          str.Append(vector.ToString() + "\n");
        }
      }
      return str.ToString();
    }
  }
}