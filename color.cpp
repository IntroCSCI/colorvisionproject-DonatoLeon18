#include "color.h"
#include <string>
#include<string.h>
#include <iostream>
using std::string;

using namespace std;
color::color():hex{"00,00,00"}, rgb{0,0,0}, characteristic{""}
{
  
}
void color:: set(string input)
{
  int position;
  char ch;
  char splitHex[2];
   position= input.find("#");
for(int i = position+1; i < 3; i++)
{
  ch = input[i];  
    if ((ch >= '0' || ch <= '9') && (ch >= 'a' || ch <= 'f'))
  {
    splitHex[i-1]=ch;
  }
}
   rgb[0]=convertHex(splitHex);  

for(int i = position+3; i < 5; i++) 
{
  ch = input[i];  
  if ((ch >= '0' || ch <= '9') && (ch >= 'a' || ch <= 'f'))
  {
    splitHex[i-3]=ch;
  }
}
   rgb[1]=convertHex(splitHex);   

for(int i = position+5; i < 7; i++) 
{
  ch = input[i];  
  if ((ch >= '0' || ch <= '9') && (ch >= 'a' || ch <= 'f'))
  {
    splitHex[i-5]=ch;

  }
}
   rgb[2]=convertHex(splitHex); 
   
   value(rgb[0],rgb[1],rgb[2]);
}
  void color:: value(string r, string g, string b)
  {
char ch;
char splithex[2];
     hex[0]=r;
     hex[1]=g;
     hex[2]=b;

     for(int i=0;i<0;i++){
       ch=r[i];
       splithex[i]=ch;
     }
     rgb[0]=convertHex(splithex);

     for(int i=0;i<0;i++){
       ch=g[i];
       splithex[i]=ch;
     }
     rgb[1]=convertHex(splithex);;
     for(int i=0;i<0;i++){
       ch=b[i];
       splithex[i]=ch;
     }
     rgb[2]=convertHex(splithex);;
  } 

void color:: value(int R, int G, int B)
{
  rgb[0]=R;
  rgb[1]=G;
  rgb[2]=B;

  hex[0]=convertDec(R);
  hex[1]=convertDec(G);
  hex[2]=convertDec(B);

if(R>G&&R>B)
  {
   //cout<<"color is red dominant\n";
   characteristic="red";
  } 
  else if(G>R&&G>B)
  {
    //cout<<"color is green dominant\n";
    characteristic="green";
  } 
  else if(B>R&&B>G)
  { 
    //cout<<"color is blue dominant\n";
    characteristic="blue";
  }
  else if(R==G&&G==B)
  {
    //cout<<"color is apart of greyscale\n";
    characteristic="grey";
  } 
  else if(R==G||G==B||R==B)
  {
    //cout<<"the color is blended\n";
    characteristic="blended";
  }
}
string color:: properties()
{
  return characteristic;
}

string color:: hexcode()
{
  string Hexcode="";
  Hexcode = "#";
    Hexcode += hex[0];
    Hexcode += hex[1];
    Hexcode += hex[2];
    
    return Hexcode;
  }

int color:: red()
{
  return rgb[0];
}

int color:: green()
{
  return rgb[1];
}

int color:: blue()
{
  return rgb[2];
}

  int color:: convertHex(char red[])
  {
    int len = strlen(red);
   int base = 1;
   int temp = 0;
   for (int i=len-1; i>=0; i--) 
   {
      if (red[i]>='0' && red[i]<='9') 
      {
         temp += (red[i] - 48)*base;
         base = base * 16;
      }
      else if (red[i]>='a' && red[i]<='f') 
      {
         temp += (red[i] - 87)*base;
         base = base*16;
      }
   } return temp;
  }

  string color:: convertDec(int n)
  {
    {
  string hexadecimal;
  char hex[2];
 int count=0;
 while(n!=0)
 {
   int temp=0;
   temp=n%16;
   
   if(temp<10)
   {
     hex[count]= temp+ 48;
     count++;
   } 
   else
   {
     hex[count]=temp+87;
     count++;
   }
   n=n/16;
 }
  hexadecimal="";
 if(count==2)
 {
   hexadecimal.push_back(hex[1]);
   hexadecimal.push_back(hex[0]);
 }
 else if(count==1)
 {
   hexadecimal="0";
   hexadecimal.push_back(hex[0]);
 }
 else if(count==0)
 {
   hexadecimal="00";
 }
 return hexadecimal;
}
  }
