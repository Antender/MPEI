using Int64Fractions;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace Int64FractionsTest
{
    
    
    /// <summary>
    ///This is a test class for Matrix and is intended
    ///to contain all Matrix Unit Tests
    ///</summary>
  [TestClass()]
  public class MatrixTest
  {


    private TestContext testContextInstance;

    /// <summary>
    ///Gets or sets the test context which provides
    ///information about and functionality for the current test run.
    ///</summary>
    public TestContext TestContext
    {
      get
      {
        return testContextInstance;
      }
      set
      {
        testContextInstance = value;
      }
    }

    #region Additional test attributes
    // 
    //You can use the following additional attributes as you write your tests:
    //
    //Use ClassInitialize to run code before running the first test in the class
    //[ClassInitialize()]
    //public static void MyClassInitialize(TestContext testContext)
    //{
    //}
    //
    //Use ClassCleanup to run code after all tests in a class have run
    //[ClassCleanup()]
    //public static void MyClassCleanup()
    //{
    //}
    //
    //Use TestInitialize to run code before running each test
    //[TestInitialize()]
    //public void MyTestInitialize()
    //{
    //}
    //
    //Use TestCleanup to run code after each test has run
    //[TestCleanup()]
    //public void MyTestCleanup()
    //{
    //}
    //
    #endregion


    /// <summary>
    ///A test for Determinant
    ///</summary>
    [TestMethod()]
    public void DetTest()
    {
      Matrix target = new Matrix() {new Vector(){1,7,6},new Vector(){-2,-8,-6},new Vector(){-2,2,0}}; 
      Fraction expected = new Fraction(-1);
      Fraction actual;
      actual = target.Det();
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for Minor
    ///</summary>
    [TestMethod()]
    public void MinorTest()
    {
      Matrix target = new Matrix() { new Vector() { 1, 2, 3 }, new Vector() { 2, 3, 4 }, new Vector() { 3, 4, 6 } }; 
      int a = 1; 
      int b = 1; // 
      Matrix expected = new Matrix() { new Vector() { 1, 3 }, new Vector() { 3, 6 } }; // 
      Matrix actual;
      actual = target.Minor(a, b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for Gauss
    ///</summary>
    [TestMethod()]
    public void GaussTest()
    {
      Matrix target = new Matrix() { new Vector() { 3, -20, -8,-8 }, new Vector() { -4 , -13, -8,-8 }, new Vector() { 9 , 45, 25, 18 }, new Vector() {3, 15 , 6, 13} }; 
      Matrix expected = new Matrix() { new Vector() { 1, 2, 3 }, new Vector() { 0, -1, -2 }, new Vector() { 0, 0, 1 } }; 
      Matrix actual = target.Gauss();
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for GaussB
    ///</summary>
    [TestMethod()]
    public void GaussBTest()
    {
      Matrix target = new Matrix() { new Vector() { 1, 2, 3 }, new Vector() { 2, 3, 4 }, new Vector() { 3, 4, 6 } }; 
      Matrix expected = new Matrix() { new Vector() { 1, 0, 0 }, new Vector() { 0, -1, 0 }, new Vector() { 0, 0, 1 } };
      Matrix actual= target.GaussB();
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for Inverse
    ///</summary>
    [TestMethod()]
    public void InverseTest()
    {
      Matrix target = new Matrix() { new Vector() { 1, 2, 3 }, new Vector() { 2, 3, 4 }, new Vector() { 3, 4, 6 } };
      Matrix expected = new Matrix() { new Vector() { -2, 0, 1 }, new Vector() { 0, 3, -2 }, new Vector() { 1, -2, 1 } };
      Matrix actual;
      actual = target.Inverse();
      Assert.AreEqual(expected,actual);
    }

    /// <summary>
    ///A test for *
    ///</summary>
    [TestMethod()]
    public void op_MultiplyTest()
    {
      Matrix a = new Matrix() { new Vector() { 1, 2, 3 }, new Vector() { 2, 3, 4 }, new Vector() { 3, 4, 5 } };
      Matrix b = new Matrix() { new Vector() { 3, 2, 1 }, new Vector() { 4, 3, 2 }, new Vector() { 5, 4, 3 } };
      Matrix expected = new Matrix() { new Vector() { 26, 20, 14 }, new Vector() { 38, 29, 20 }, new Vector() { 50, 38, 26 } };
      Matrix actual = (a * b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for *
    ///</summary>
    [TestMethod()]
    public void op_Multiply2Test()
    {
      Matrix a = new Matrix() { new Vector() { 1, 2, 3 }, new Vector() { 2, 3, 4 } };
      Matrix b = new Matrix() { new Vector() { 3, 2}, new Vector() { 4, 3}, new Vector() { 5, 4} };
      Matrix expected = new Matrix() { new Vector() { 26, 20 }, new Vector() { 38, 29 } };
      Matrix actual;
      actual = (a * b);
      Assert.IsTrue(expected==actual);
    }

    /// <summary>
    ///A test for Transpose
    ///</summary>
    [TestMethod()]
    public void TransposeTest()
    {
      Matrix target = new Matrix() { new Vector() { 1, 2, 3 }, new Vector() { 4, 5, 6 }};
      Matrix expected = new Matrix() { new Vector() { 1, 4 }, new Vector() { 2, 5 }, new Vector() { 3, 6 } };
      Matrix actual = target.Transpose();
      Assert.AreEqual(expected,actual);
    }

    /// <summary>
    ///A test for Equals
    ///</summary>
    [TestMethod()]
    public void EqualsTest()
    {
      Matrix target = new Matrix {new Vector{1}}; 
      object a = new Matrix {new Vector{2}};
      Assert.IsFalse(target.Equals(a));
      Assert.IsTrue(target.Equals(target));
    }
  }
}
