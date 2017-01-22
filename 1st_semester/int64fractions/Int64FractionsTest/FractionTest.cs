using Int64Fractions;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace Int64FractionsTest
{
    
    
    /// <summary>
    ///This is a test class for Fraction and is intended
    ///to contain all Fraction Unit Tests
    ///</summary>
  [TestClass()]
  public class FractionTest
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
    ///A test for -(unary)
    ///</summary>
    [TestMethod()]
    public void op_UnaryNegationTest()
    {
      Fraction a = new Fraction(5,2); 
      Fraction expected = new Fraction(-5,2); 
      Fraction actual;
      actual = -(a);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for -
    ///</summary>
    [TestMethod()]
    public void op_SubtractionTest()
    {
      Fraction a = new Fraction(3,5); 
      Fraction b = new Fraction(7,11); 
      Fraction expected = new Fraction(-2,55); 
      Fraction actual;
      actual = (a - b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for *
    ///</summary>
    [TestMethod()]
    public void op_MultiplyTest()
    {
      Fraction a = new Fraction(3,5); 
      Fraction b = new Fraction(7,11); 
      Fraction expected = new Fraction(21,55); 
      Fraction actual;
      actual = (a * b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for /
    ///</summary>
    [TestMethod()]
    public void op_DivisionTest()
    {
      Fraction a = new Fraction(5,11); 
      Fraction b = new Fraction(5,11); 
      Fraction expected = new Fraction(55,55); 
      Fraction actual;
      actual = (a / b);
      Assert.AreEqual(expected, actual);
    }

    /// <summary>
    ///A test for +
    ///</summary>
    [TestMethod()]
    public void op_AdditionTest()
    {
      Fraction a = new Fraction(3,5); 
      Fraction b = new Fraction(7,11); 
      Fraction expected = new Fraction(68,55);
      Fraction actual;
      actual = (a + b);
      Assert.AreEqual(expected, actual, expected.ToString() + " " + actual.ToString());
    }

    /// <summary>
    ///A test for Reduced
    ///</summary>
    [TestMethod()]
    public void ReducedTest()
    {
      Fraction target = new Fraction(-88,-55);
      Fraction expected = new Fraction(8,5);
      Fraction actual = target.Reduced();
      Assert.AreEqual<Fraction>(expected, actual,expected.ToString()+" "+actual.ToString());
    }
  }
}
