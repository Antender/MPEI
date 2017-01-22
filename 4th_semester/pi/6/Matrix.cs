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

    public float[,] FindMaximums()
    {
        float[,] maximums = new float[height,1];
        for(int row=0;row<height;++row)
        {
            float max = data[row,0];
            for(int column=1;column<width;++column)
            {
                if (data[row,column]>max) 
                {
                    max = data[row,column];
                }
            }
            maximums[row,0] = max;
        }
        return maximums;
    }
    public int findMinCount(float intervalMin, float intervalMax)
    {
        int minCount = -1;
        int minRow = -1;
        for(int row=0;row<height;++row)
        {
            int min = 0;
            for(int column=0;column<width;++column)
            {
                if ((data[row,column]>=intervalMin) && (data[row,column]<=intervalMax)) {
                ++min;
            }
        }
		  if (minCount == -1)
		  {
			  minCount = min;
		  }
		  else if (min<minCount) {
            minCount=min;
            minRow=row;
        }
    }
	 if (minRow == -1)
	 {
		 minRow = 0;
	 }
    return minRow+1;
  }
}