using System;


namespace Int64Fractions
{
  public partial struct Fraction
  {
    public readonly Int64 D;
    public readonly Int64 N;

    public override bool Equals(object obj)
    {
      if (ReferenceEquals(null, obj)) return false;
      return (obj is Fraction) && D.Equals(((Fraction)obj).D) && N.Equals(((Fraction)obj).N);
    }

    public Fraction(Int64 num, Int64 den)
    {
      if (den == 0)
      {
        N = 0;
        D = 1;
      }
      else
      {
        if ((num < 0) && (den < 0))
        {
          N = (-1) * num;
          D = (-1) * den;
        }
        else
        {
          N = num;
          D = den;
        }
      }
    }

    public Fraction(Int64 num)
    {
      N = num;
      D = 1;
    }

    public static Int64 GCD(Int64 a, Int64 b)
    {
      Int64 gcd;
      if (a == 0)
      {
        gcd = b;
      }
      else if (b == 0)
      {
        gcd = a;
      }
      else
      {
        a = Math.Abs(a);
        b = Math.Abs(b);
        gcd = 1;
        while ((a != 1) && (b != 1))
        {
          if (a == b)
          {
            gcd = a;
            a = 1;
          }
          else
          {
            if ((a & 1) == 0)
            {
              if ((b & 1) == 0)
              {
                gcd <<= 1;
                a >>= 1;
                b >>= 1;
              }
              else
              {
                a >>= 1;
              }
            }
            else
            {
              if ((b & 1) == 0)
              {
                b >>= 1;
              }
              else
              {
                if (a >= b)
                  a = (a - b) >> 1;
                else
                {
                  var temp = a;
                  a = (b - a) >> 1;
                  b = temp;
                }
              }
            }
          }
        }
      }
      return gcd;
    }

    public static implicit operator Fraction(Int64 input)
    {
      return new Fraction(input);
    }

    public static implicit operator Fraction(Int32 input)
    {
      return new Fraction(input);
    }

    public static implicit operator Fraction(Int16 input)
    {
      return new Fraction(input);
    }

    public static explicit operator Fraction(UInt64 input)
    {
      return new Fraction((Int64)input);
    }

    public static implicit operator Fraction(UInt32 input)
    {
      return new Fraction(input);
    }

    public static implicit operator Fraction(UInt16 input)
    {
      return new Fraction(input);
    }

    public static Int64 LCM(Int64 a, Int64 b)
    {
      return Math.Abs(a * b / GCD(a, b));
    }

    public static Fraction operator -(Fraction a, Fraction b)
    {
      var c = LCM(a.D, b.D);
      return new Fraction((a.N * c / a.D) - (b.N * c / b.D), c);
    }

    public static Fraction operator -(Fraction a)
    {
      return new Fraction(-a.N, a.D);
    }

    public static bool operator !=(Fraction a, Fraction b)
    {
      return !(a.Equals(b));
    }

    public static Fraction operator *(Fraction a, Fraction b)
    {
      return new Fraction(a.N * b.N, a.D * b.D);
    }

    public static Fraction operator /(Fraction a, Fraction b)
    {
      return new Fraction(a.N * b.D, a.D * b.N);
    }

    public static Fraction operator +(Fraction a, Fraction b)
    {
      var c = LCM(a.D, b.D);
      return new Fraction((a.N * c / a.D) + (b.N * c / b.D), c);
    }

    public static bool operator ==(Fraction a, Fraction b)
    {
      return a.Equals(b);
    }

    public Fraction Reduced()
    {
      var gcd = GCD(N, D);
      if ((N < 0) && (D < 0))
      {
        gcd *= -1;
      }
      return new Fraction(N/gcd,D/gcd);
    }

    public bool Equals(Fraction other)
    {
      return other.D == D && other.N == N;
    }

    public override int GetHashCode()
    {
      unchecked
      {
        return (D.GetHashCode()*397) ^ N.GetHashCode();
      }
    }
  }
}
