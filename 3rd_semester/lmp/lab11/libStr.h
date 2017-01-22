#include <cstdio>
#include <cstdlib>
#include "libStrExc"

class String {
  uint32_t length;
  char * data;
  friend char * strConcat(char* first, int firstLength, char * second, int secondLength);
  friend char * strExclude(char * needle, char * haystack);
  public:
    String(char const * proto);
    String(String proto, uint32_t len);
    ~String();
    float toFloat();
    static String fromFloat(float proto);
    String operator=(String const &proto);
    char operator[](int index);
    String operator+(String const &other);
    String operator+=(char symbol);
    String operator-(String const &other);
    bool operator==(String const &other);
    bool operator!=(String const &other);
    bool operator<=(String const &other);
    bool operator>=(String const &other);
    bool operator<(String const &other);
    bool operator>(String const &other);
    float operator(float)();
};