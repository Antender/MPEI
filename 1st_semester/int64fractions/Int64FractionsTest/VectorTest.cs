using Int64Fractions;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace Int64FractionsTest
{
    
    
    /// <summary>
    ///This is a test class for Vector and is intended
    ///to contain all Vector Unit Tests
    ///</summary>
  [TestClass()]
  public class VectorTest
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
    ///A test for +
    ///</summary>
    [TestMethod()]
    public void op_AdditionTest()
    {
      Vector a = new Vector {1, 2, 3};
      Vector b = new Vector {3, 2, 1};
      Vector expected = new Vector {4, 4, 4}; 
      Vector actual;
      actual = (a + b);
      Assert.AreEqual(expected, actual,expected.ToString()+" "+actual.ToString());
    }

    /// <summary>
    ///A test for /(Vector,Fraction)
    ///</summary>
    [TestMethod()]
    public void op_DivisionTest()
    {
      Vector a = new Vector{new Fraction(105,3),new Fraction(105,5),new Fraction(105,7)};
      Fraction b = new Fraction(105); // TODO: Initialize to an appropriate value
      Vector expected = new Vector{new Fraction(1,3),new Fraction(1,5),new Fraction(1,7)}; // TODO: Initialize to an appropriate value
      Vector actual;
      actual = (a / b);
      Assert.AreEqual(expected, actual,expected.ToString()+" "+actual.ToString());
    }

    /// <summary>
    ///A test for op_Multiply
    ///</summary>
    [TestMethod()]
    public void op_MultiplyTest()
    {
      Vector a = new Vector { new Fraction(1, 3), new Fraction(1, 5), new Fraction(1, 7) }; 
      Vector b = new Vector { new Fraction(3, 1), new Fraction(5, 1), new Fraction(7, 1) }; 
      Fraction expected = new Fraction(3); 
      Fraction actual;
      actual = (a * b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for op_Multiply
    ///</summary>
    [TestMethod()]
    public void op_MultiplyTest1()
    {
      Vector b = new Vector { new Fraction(1, 3), new Fraction(1, 5), new Fraction(1, 7) }; 
      Fraction a = new Fraction(105);
      Vector expected = new Vector { new Fraction(35), new Fraction(21), new Fraction(15) };
      Vector actual;
      actual = (b * a);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for op_Multiply
    ///</summary>
    [TestMethod()]
    public void op_MultiplyTest2()
    {
      Fraction a = new Fraction(105);
      Vector b = new Vector { new Fraction(1, 3), new Fraction(1, 5), new Fraction(1, 7) };
      Vector expected = new Vector { new Fraction(35), new Fraction(21), new Fraction(15) };
      Vector actual;
      actual = (a * b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for op_Subtraction
    ///</summary>
    [TestMethod()]
    public void op_SubtractionTest()
    {
      Vector a = new Vector { new Fraction(35), new Fraction(21), new Fraction(15) };
      Vector b = new Vector { new Fraction(1), new Fraction(1), new Fraction(1) };
      Vector expected = new Vector { new Fraction(34), new Fraction(20), new Fraction(14) };
      Vector actual;
      actual = (a - b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for op_UnaryNegation
    ///</summary>
    [TestMethod()]
    public void op_UnaryNegationTest()
    {
      Vector a = new Vector { new Fraction(35), new Fraction(-21), new Fraction(15) };
      Vector expected = new Vector { new Fraction(-35), new Fraction(21), new Fraction(-15) };
      Vector actual;
      actual = -(a);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for Reduced
    ///</summary>
    [TestMethod()]
    public void SimplifyTest()
    {
      Vector target = new Vector { new Fraction(33, 45), new Fraction(11, 45), new Fraction(11, 75) };
      Vector expected = new Vector { new Fraction(3, 3), new Fraction(1, 3), new Fraction(1, 5) };
      Vector actual;
      actual = target.Simplify();
      Assert.AreEqual(expected, actual);
    }
  }
}
