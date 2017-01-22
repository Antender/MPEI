//$/t:library
using System;
using System.Collections.Generic;

public class Matrix
{
	public int width,height,maxpos;
	public float[,] data;
	public Matrix(int w, int h)
	{
		width = w;
		height = h;
		data = new float[w,h];
	}
	public void moveToEnd()
   {
	   maxpos = height;
		for (int column = 0; column < width; ++column)
		{
			List<float> positive = new List<float>();
			List<float> negative = new List<float>();
	   
			for(int row = 0 ; row < height; ++row)
			{
				float el = data[row,column];
				if(el>=0) 
				{
					positive.Add(el);
				} 
				else 
				{
					negative.Add(el);
				}
			}
			if (positive.Count<maxpos)
			{
				maxpos = positive.Count;
			}
			int crow = 0;
			foreach (var posnum in positive)
			{
				data[crow,column]=posnum;
				++crow;
			}
			foreach (var negnum in negative)
			{
				data[crow,column]=negnum;
				++crow;
			}
		}
		var temp = new float[maxpos,width];
		for (int row = 0; row<width; row++)
		{
			for (int column = 0; column<maxpos; column++)
			{
				temp[column,row] = data[column,row];
			}
		}
		data = temp;
		height = maxpos;
	}
}