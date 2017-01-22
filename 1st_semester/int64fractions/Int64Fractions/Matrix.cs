using System;
using System.Collections.Generic;
using System.Linq;

namespace Int64Fractions
{
	public partial class Matrix : List<Vector>
	{
    public Matrix()
    {
    }
    public Matrix(IEnumerable<Vector> input)
    {
      if (input != null)
        foreach (var element in input)
        {
          Add(new Vector(element));
        }
    }

	  public static Matrix UnitMatrix(int size)
    {
      var result = new Matrix();
      for (var i = 0;i < size; i++)
      {
        var temp = new Vector();
        for (var j = 0; j < size; j++)
        {
          temp.Add(i == j ? 1 : 0);
        }
        result.Add(temp);
      }
      return result;
    }
    public static implicit operator Matrix(Vector input)
    {
      var result = new Matrix {input};
      return result;
    }
    public override bool Equals(object a)
    {
      if ((a!=null) && (a is Matrix) && ((a as Matrix).Count==Count))
      {
        var temp = true;
        for (var i=0;i<Count;i++)
        {
          temp &= ((a as Matrix)[i]==this[i]);
        }
        return temp;
      }
      return false;
    }
    public static bool operator ==(Matrix a, Matrix b)
    {
      return a != null && a.Equals(b);
    }
    public static bool operator !=(Matrix a, Matrix b)
    {
      return a != null && !(a.Equals(b));
    }
    public static Matrix operator +(Matrix a,Matrix b)
    {
      if ((a != null) && (b != null)) return new Matrix(a.Zip(b,(x,y)=>x+y));
      throw new ArgumentException("Matrix can't be empty");
    }

	  public static Matrix operator -(Matrix a, Matrix b)
	  {
	    if ((a != null) && (b != null)) return new Matrix(a.Zip(b, (x, y) => x - y));
      throw new ArgumentException("Matrix can't be empty");
	  }

	  public static Matrix operator *(Matrix a,Matrix b)
    {
      if ((a==null) || (b==null)) throw new ArgumentException("Matrix can't be empty");
      var c = new Matrix();
      foreach (var t in a)
      {
        var cI = new Vector();
        for (var j=0;j<b[0].Count;j++)
        {
          var accum = new Fraction(0);
          for (int r=0;r<a[0].Count;r++)
          {
            accum += t[r] * b[r][j];
          }
          cI.Add(accum);
        }
        c.Add(cI);
      }
      return c;
    }
    public static Matrix operator *(Matrix a,Fraction b)
    {
      if (a != null) return new Matrix(a.Select(vector => vector*b));
      throw new ArgumentException("Matrix can't be empty");
    }

	  public static Matrix operator *(Fraction b,Matrix a)
    {
      return a*b;
    }
    public Matrix Gauss()
    {
      for (var i=0;i<(Count-1);i++)
      {
        for (var j=i+1;j<Count;j++)
        {
          this[j]=this[j]-this[j][i]/this[i][i] * this[i];
        }
      }
      return this;
    }
    public Matrix GaussB()
    {
      var result = Gauss();
      if (result == null)
      {
        throw new ArgumentException("Matrix can't be null");
      }
      for (var i = result.Count - 1; i > 0; i--)
      {
        for (var j = i - 1; j >= 0; j--)
        {
          result[j] = result[j] - result[j][i]/this[i][i]*result[i];
        }
      }
      return result;
    }
    public Fraction Det()
    {
      var temp = Gauss();
      var accum = new Fraction(1);
      for (var i=0;i<Count;i++)
      {
        accum = accum * temp[i][i];
      }
      return accum;
    }
    public Matrix Minor(int a,int b)
    {
      var result = new Matrix(this);
      result.RemoveAt(a);
      foreach (var t in result)
      {
// ReSharper disable PossibleNullReferenceException
        t.RemoveAt(b);
// ReSharper restore PossibleNullReferenceException
      }
      return result;
    }
    public Matrix Inverse()
    {
      var temp = new Matrix();
      for (var i=0;i<Count;i++)
      {
        var tempv = this[i];
        for (var j=0;j<Count;j++)
        {
// ReSharper disable PossibleNullReferenceException
          tempv.Add(i==j ? 1 : 0);
// ReSharper restore PossibleNullReferenceException
        }
        temp.Add(tempv);
      }
      temp = temp.GaussB();
      if (temp==null) throw new ArgumentException("Matrix can't be null");
      var result = new Matrix();
      for (var i=0;i<Count;i++)
      {
        var tempv = new Vector((temp[i]/temp[i][i]).GetRange(temp[i].Count/2, temp[i].Count/2));
        result.Add(tempv);
      }
      return result;
    }
    public Matrix Transpose()
    {
      var temp = new Fraction[this[0].Count,Count];
      for (var i = 0; i < Count; i++ )
      {
        for (var j=0; j<this[i].Count;j++)
        {
          temp[j,i]=this[i][j];
        }
      }
      var result= new Matrix();
      for (var j = 0; j < this[0].Count; j++)
      {
        var tempv = new Vector();
        for (var i = 0; i < Count; i++)
        {
          tempv.Add(temp[j,i]);
        }
        result.Add(tempv);
      }
      return result;
    }

	  public override int GetHashCode()
	  {
      //TODO Generate proper hashcode
	    return 0;
	  }
	} 
}
