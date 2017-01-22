#include <vector>

#include <cstdio>

using namespace std;

class Vector : public vector<float>
{
};

class Matrix : public vector<Vector*>
{
  public:
  int width,height,cpos;
  Matrix() {}
  Matrix(const Matrix& other){
	this->reserve(other.size());
	for(Matrix::const_iterator it = other.begin() ; it != other.end(); ++it)
	{
	  this->push_back(*it);
	}
	this->width = other.width;
	this->height = other.height;
  }
  ~Matrix()
  {
    for(Matrix::const_iterator it = begin() ; it != end(); ++it)
	{
	  delete (*it);
	}
  }
  void moveToEnd()
  {
    cpos = height;
    for(int column=0;column<width;++column)
	{
	   Vector* positive = new Vector();
	   Vector* negative = new Vector();
	   positive->reserve(height);
	   for(int row =0 ; row<height; ++row)
	   {
	     float el = this->at(row)->at(column);
	     if(el>=0) 
		 {
		   positive->push_back(el);
		 }
		 else
		 {
		   negative->push_back(el);
		 }
	   }
	   if(positive->size()<cpos) {
	     cpos = positive->size();
	   }
	   int row = 0;
	   for(Vector::const_iterator it = positive->begin() ; it != positive->end(); ++it)
	   {
	     (*(this->at(row)))[column]=(*it);
	     ++row;
	   }
	   for(Vector::const_iterator it = negative->begin() ; it != negative->end(); ++it)
	   {
	     (*(this->at(row)))[column]=(*it);
		 ++row;
	   }
	   delete positive;
	   delete negative;
	}
  }
  void readFromFile(char* filename)
  {
	FILE* fid = fopen(filename,"r");
	fscanf(fid,"%i %i",&width,&height);
	reserve(height);
	for(int cheight=0;cheight<height;++cheight)
	{
	  Vector* vecptr = new Vector();
	  push_back(vecptr);
	  vecptr->reserve(width);
	  for(int cwidth=0;cwidth<width;++cwidth)
	  {
		float el;
		fscanf(fid,"%f",&el);
		vecptr->push_back(el);
	  }
	}
	fclose(fid);
  }
  void writeToFile(char* filename)
  { 
  	FILE* fid = fopen(filename,"w");
    fprintf(fid,"%i %i",width,height);
	fputs("\n",fid);
	for(int cheight=0;cheight<height;++cheight) 
	{
	  for(int cwidth=0;cwidth<width;++cwidth) 
	  {
        fprintf(fid,"%f ",this->at(cheight)->at(cwidth));
	  }
	  fputs("\n",fid);
	}
	fputs("\n",fid);
	fclose(fid);
  }
  Vector* findMaximums()
  {
    Vector* maximums = new Vector();
    for(int row=0;row<height;++row)
    {
       Vector* crow = at(row);
       float max = crow->at(0);
       for(int column=1;column<width;++column)
       {
         if (crow->at(column)>max) {
           max = crow->at(column);
         }
       }
       maximums->push_back(max);
    }
    return maximums;
  }
  unsigned int findMinCount(float intervalMin, float intervalMax)
  {
    unsigned int minCount = (unsigned int)-1;
    unsigned int minRow = 0;
    for(int row=0;row<height;++row)
    {
       Vector* crow = at(row);
       unsigned int min = 0;
       for(int column=0;column<width;++column)
       {
         if (((crow->at(column))>=intervalMin) && ((crow->at(column))<=intervalMax)) {
           ++min;
         }
       }
       if (min<minCount) {
         minCount=min;
         minRow=row;
       }
    }
    return minRow+1;
  }
};