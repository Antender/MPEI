String::String(char const * proto) {
  if (proto!=NULL) {
    length = strlen(proto);
    data = (char*)malloc(length+1);
    if (data==NULL) {
      throw stringTooLongEx;
    }
    strcpy(data,proto);
  } else {
    length = 0;
    data = (char *) malloc(1);
    *(data) = 0;
  }
}

String::String(String proto, uint32_t len) {
  if (proto.length<len) {
    throw stringTooLongEx;
  }
  length = len;
  data = (char*)malloc (len+1);
  if (data==NULL) {
    throw stringTooLongEx;
  }
  for (int i=0;i<len;++i) {
    data[i] = proto.data[i];
  }
  data[len] = 0;
}

String::~String() {
  free(data);
}

float String::toFloat() {
  return atof(data);
}

String String::fromFloat(float proto) {
  char * fromFloatBuffer = (char*) malloc(80);
  sprintf(fromFloatBuffer,"%f",proto);
  String result = *(new String(fromFloatBuffer));
  free(fromFloatBuffer);
  return result;
}

String String::operator=(String const &proto) {
  if (this != &proto) {
    delete(data);
    length = proto.length;
    data = (char *) malloc(length+1);
    if (data==NULL) {
      throw stringTooLongEx;
    }
    strcpy(data,proto.data);
  }
  return *(this);
}

char String::operator[](int index) {
  if ((index>=length) || (index<0)) {
    throw stringIndexOutOfRangeEx;
  }
  return data[index];
}

String String::operator+(String const &other) {
  return new String(strConcat(data,other.data,length,other.length));
}

String String::operator+=(char symbol) {
  data[length]=symbol;
  ++length;
  realloc(data,length);
  if (data==NULL) {
    throw stringTooLongEx;
  }
  data[length]=0;
  return *(this);
}

String String::operator-(String const &other) {
  char * buffer = (char*) malloc(length+1);
  if (buffer==NULL) {
    throw stringTooLongEx;
  }
  return new String(strExclude(other.data,strcpy(buffer,data)));;
}

bool String::operator==(String const &other) {
  return strcmp(data,other.data) == 0;
}

bool String::operator!=(String const &other) {
  return strcmp(data,other.data) != 0;
}

bool String::operator<=(String const &other) {
  return !(strcmp(data,other.data) > 0);
}

bool String::operator>=(String const &other) {
  return !(strcmp(data,other.data) < 0);
}

bool String::operator<(String const &other) {
  return strcmp(data,other.data) < 0;
}

bool String::operator>(String const &other) {
  return strcmp(data,other.data) > 0;
}

float String::operator(float)() {
  return toFloat();
}

char * strConcat(char* first, char * second, int firstLength, int secondLength) {
  return strcat(strcpy((char*) malloc (firstLength+secondLength+1),first),second);
}

char * strExclude(char * needle, char * haystack) {
  char * cursym = haystack;
  char * cmpsym = needle;
  char * writesym = haystack;
  while (*(cursym)!=0) {
    if (*(cursym)==*(cmpsym)) {
      ++cursym;
    } else {
      if (*cmpsym==0) {
        writesym-=other.length;
      }
      cmpsym=other.data;
    }
    *(writesym)=*(cursym);
    ++writesym;
    ++cursym;
  }
  *(writesym) = 0;
  return realloc(haystack,strlen(haystack)+1);
}