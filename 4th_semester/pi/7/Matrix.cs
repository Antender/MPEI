//$/t:library
using System;
using System.Collections.Generic;

public struct OddEvenResult
{
    public OddEvenResult(int o, int e)
    {
        odd = o;
        even = e;
    }
    public int odd;
    public int even;
}

public class Matrix
{
	public int width,height,maxpos;
	public int[,] data;
	public Matrix(int w, int h)
	{
		width = w;
		height = h;
		data = new int[w,h];
	}

    public OddEvenResult FindOddEven()
    {
        int odd = 0;
        int even = 0;
        for(int row=0;row<height;++row)
        {
            for(int column=0;column<width;++column)
            {
                if (data[row,column]%2==0) 
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
        }
        return new OddEvenResult(odd,even);
    }
    public float[,] FindSubzeroes()
    {
        float[,] subzeroes = new float[1,width];
        for(int column=0;column<width;++column)
        {
            for(int row=0;row<height;++row)
            {
                if (data[row,column]<0) 
                {
                    subzeroes[0,column] = data[row,column];
                    break;
                }
            }
            
        }
        return subzeroes;
    }
}