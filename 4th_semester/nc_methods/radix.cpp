#include <vector>
#include <cstdio>

namespace radix { 
using std::vector;
typedef struct Node {
  unsigned int data;
  unsigned int next;
  unsigned int child;
};

class Tree {
  vector<char>* data;
  vector<Node>* structure;
  public:
  Tree()
  {
    data = new vector<char>();
	structure = new vector<Node>();
  };
  Tree(unsigned int dataSize, unsigned int structureSize)
  {
    Tree();
	data->reserve(dataSize);
	data->reserve(structureSize);
  };
  ~Tree()
  {
    delete data;
	delete structure;
  };
  serialize(char* dataFilename,char* structureFilename)
  {
    FILE* structureFile = fopen(structureFilename,"wb");
	unsigned int size = (unsigned int)structure->size();
	fwrite(&size,sizeof(unsigned int),1,structureFile);
	if (size!=0) {
	  fwrite(&(structure[0]),sizeof(unsigned int),3*size,structureFile);
	}
    fclose(structureFile);	
	
	FILE* dataFile = fopen(dataFilename,"wb");
	size = (unsigned int)data->size();
	fwrite(&size,sizeof(unsigned int),1,dataFile);
	if (size!=0) {
	  fwrite(&data[0],sizeof(char),size,dataFile);
	}
    fclose(dataFile);	
  };
  deserialize(char* dataFilename,char* structureFilename)
  {
    FILE* structureFile = fopen(structureFilename,"rb");
	unsigned int size;
	fread(&size,sizeof(unsigned int),1,structureFile);
	if (size!=0) {
	  structure->reserve(size);
	  fread(&(structure[i]),sizeof(unsigned int),3*size,structureFile);
	}
    fclose(structureFile);	
	
	FILE* dataFile = fopen(dataFilename,"rb");
	fread(&size,sizeof(unsigned int),1,dataFile);
	if (size!=0) {
	  data->reserve(size);
	  fread(&data[0],sizeof(char),size,dataFile);
	}
    fclose(dataFile);	
  };
  insert()
  {
	Node* pos;
  };
  remove()
  {
  };
  clear()
  {
	  data->clear();
	  structure->clear();
  };
  compact()
  {
  };
  contains()
  {
  };
  set()
  {
  };
  find()
  {
  };
}

}