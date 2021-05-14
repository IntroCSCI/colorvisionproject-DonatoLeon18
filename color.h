#ifndef COLOR_H
#define COLOR_H
#include <string>
#include <vector>
#include<string.h>
using std::string;
using std::vector;
using namespace std;
class color
{
  private:
string characteristic;
string hex[3];
int rgb[3];


  public:
  void value(string r, string g, string b);
  void value(int R, int G, int B);
  string convertDec(int n);
  int convertHex(char red[]);
  int red();
  int blue();
  int green();
  string hexcode();
  string properties();
  void set(string input);
  
  color();

  
};
#endif