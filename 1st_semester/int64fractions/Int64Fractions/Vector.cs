using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;


namespace Int64Fractions
{
  public partial class Vector : List<Fraction>
  {
    public override bool Equals(object a)
    {
      if (a!=null && (a is Vector) && ((a as Vector).Count==Count))
      {
        var temp = true;
        for (var i=0;i<Count;i++)
        {
          temp &= ((a as Vector)[i]==this[i]);
        }
        return temp;
      }
      return false;
    }

    public static Vector operator -(Vector a, Vector b)
    {
      if ((a != null) && (b != null)) return new Vector(a.Zip(b, (x, y) => (x - y)));
      throw new ArgumentException("Can't substract empty vectors");
    }

    public static Vector operator -(Vector a)
    {
      return (-1) * a;
    }

    public static bool operator !=(Vector a, Vector b)
    {
      return a != null && !(a.Equals(b));
    }

    public static Fraction operator *(Vector a, Vector b)
    {
// ReSharper disable AssignNullToNotNullAttribute
      if ((a != null) && (b != null)) return a.Zip(b, (x, y) => x * y).Aggregate<Fraction, Fraction>(0, (accum, x) => accum + x);
// ReSharper restore AssignNullToNotNullAttribute
      throw new ArgumentException("Matrix can't be empty");
    }

    public static Vector operator *(Fraction a, Vector b)
    {
      if (b != null) return new Vector(b.Select(x => (a * x)));
      throw new ArgumentException("Vector can't be empty");
    }

    public static Vector operator *(Vector b, Fraction a)
    {
      return a * b;
    }

    public static Vector operator /(Vector a, Fraction b)
    {
      if (a != null) return new Vector(a.Select(x => x / b));
      throw new ArgumentException("Vector can't be empty");
    }

    public static Vector operator +(Vector a, Vector b)
    {
      if ((a != null) && (b != null)) return new Vector(a.Zip(b, (x, y) => (x + y)));
      throw new ArgumentException("Vectors can't be empty");
    }

    public static bool operator ==(Vector a, Vector b)
    {
      return a != null && a.Equals(b);
    }

    public Vector Simplify()
    {
      int i;
      Int64 gcdDen = 0;
      Int64 gcdNum = 0;
      for (i = 0; i < Count; i++)
      {
        if ((this[i].N != 0) && !((this[i].N == 1) && (this[i].D == 1)))
        {
          gcdDen = this[i].D;
          gcdNum = this[i].N;
          break;
        }
      }
      for (; i < Count; i++)
      {
        if (this[i].D != 1L)
        {
          gcdDen = Fraction.GCD(gcdDen, this[i].D);
        }
        if (this[i].N != 0L)
        {
          gcdNum = Fraction.GCD(gcdNum, this[i].N);
        }
      }
      var current = this;
      if (gcdDen != 0)
      {
        current = new Fraction(gcdDen) * current;
      }
      if (gcdNum != 0)
      {
        current = new Fraction(1, gcdNum) * current;
      }
// ReSharper disable AssignNullToNotNullAttribute
      return new Vector(current.Select(x => x.Reduced()));
// ReSharper restore AssignNullToNotNullAttribute
    }

    public Vector()
    {
    }

    public Vector(IEnumerable<Fraction> input)
    {
      if (input != null)
        foreach (var element in input)
        {
          Add(element);
        }
    }

    public static explicit operator Vector(Matrix input)
    {
      return input != null ? input[0] : null;
    }

    public override int GetHashCode()
    {
      //TODO Generate proper hashcode
      return 0;
    }
  }
}
