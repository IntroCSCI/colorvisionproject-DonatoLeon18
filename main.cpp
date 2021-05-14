//Author: Donato Leon
#include <iostream>
#include <fstream>
#include<string.h>
#include <vector>
#include "color.h"
using namespace std;

int checkHex(string);
//int convertHex(char b[]);
//string convertDec(int n);
//string convertRGB(int R, int G, int B);
void generateColors(int& r, int& g, int& b);

int main()
{
color Color;
fstream reader;
string filename="";
string basecolor="";
const string CLEAR_SCREEN = u8"\033[2J\033[1;1H";
int error=0;
int RGB[3];//array for storing rgb color value
int position;
char ch;//hex characters
char splitHex[2];//array to store hex values for red blue green individually 
int cont;
int R,G,B;
vector <string> theme;
cout<<Color.red();
  do{
      //clears screen and vector data if any
     cout<<CLEAR_SCREEN;
    
      if(theme.size()>0)
      {
      theme.clear();
      }

     do{
     
      //ask user for Hexadecimal
     cout<<"input 6 character Hexadecimal\n";
     cout<<"include #\n";
     cout<<"use lowercase letters a-f\n";
     cout<<"EX:#xxxxxx\n";

     cin>>basecolor;


     error=checkHex(basecolor); //check for correct format of hexadecimal


     //print error message depending on the detected error
     switch(error)
     {
      case 1:
       cout<<CLEAR_SCREEN<<"incorrect amount of characters"<<endl;
       break;
       
       case 2:
       cout<<CLEAR_SCREEN<<"invalid characters"<<endl;
       break;

       case 3:
       cout<<CLEAR_SCREEN<<" # missing or misplaced\n";
       break;
     }

    }while(error>0);

theme.push_back(basecolor);
//confirms correct input
cout<<CLEAR_SCREEN<<"correct input\n"<<basecolor<<endl;
string hold[3];
int counter=0;
   //breaks apart hex number into its RGB components and converts those components into decimal values
  Color.set(basecolor);
 

cout<<"RGB value is: ";
     R=Color.red();
     G=Color.green();
     B=Color.blue();
  cout<< R<<", "<<G<<", "<<B<<endl;

   //checks for properties of color
   if(Color.properties()=="grey"||Color.properties()=="blended"){
     cout<<"color is "<<Color.properties()<<endl;
   }
   else
   {
     cout<<"color is "<<Color.properties()<<" Dominant"<<endl;
   }
 

   //generates new colors from inputed color
   cout<<"new colors to complete theme:"<<endl;

for(int i=0;i<5;i++)
  {
   //changes color into new ones
   generateColors(R,G,B);

   //converts alternate color's RGB value back into hex
   Color.value(R, G, B);
   theme.push_back(Color.hexcode());
   
  }

   //displays the colors that have been generated 
for(int i=0;i<theme.size();i++)
  {
   cout<<theme[i]<<endl;
  }

   //option to keep or delete pallete
   cout<<"do you want to keep this pallete?\n";
   cout<<"enter '1' if you want to keep pallete or enter any key to delete pallete\n";
   cin>>cont;
  if(cont==1)
  {

   //ask user for file to output to
    cout<<"input file name\n";
   cin>>filename;

   //prints alternate colors into css file in css format
    for(int i=0;i<theme.size();i++)
    {
     reader.open(filename, ios::app);
      if(!reader.eof())
      {
       reader<<"body{ color: "<<theme[i]<<"}"<<endl;
      }
      reader.close();
    }
   }
   else
   {
     if(theme.size()==5)
     {
       theme.clear();
     }
     else if(theme.size()>5)
     {
       for(int i=0;i<5;i++)
       {
         theme.pop_back();
       }
     }
   }
   cout<<"generate another theme?"<<endl;
   cout<<"enter '1' to generate another theme or enter any other key to quit"<<endl;
   cin>>cont;
  }while(cont==1);
cout<<CLEAR_SCREEN;

//reads what was outputed to the file
reader.open(filename,ios::out|ios::in);
string result;
cout<<"\n"<<"succesfully printed to file:\n";
 while(!reader.eof())
 {
   getline(reader,result);
   cout<<result<<endl;
 }
reader.close();
  return 0;
}

//function for checking hexadecimal format
int checkHex(string hex)
{

 int c;
 int n;
 char ch;
 int error;
 n = hex.length();
 c= hex.find("#");

 if(n!=7)
  {
    error=1;
  }
 else if(c==0)
 {
   for(int i = c+1; i < n; i++) 
   {
    
     char ch = hex[i];  

     if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f'))
     {

     error=2;
     break;
     }
   }
 }

  else if(c!=0)
  {
   error=3;
  }
    if(!(error>0&&error<=3))
    {
      error=0;
    }
    return error;
}



void generateColors(int& r, int& g, int& b)
{
  
  if(r<215&&r>40)
  {
     r-=40;
  }
  else if(r==255||r>215||r==215)
   {
     r-=40;
   }
   if(g<225&&g>30)
   {
     g-=30;
   }
   else if(g==255||g>215||g==215)
   {
     g-=40;
   }
   if(b<215)
   {
     b+=40;
   }
   else if(b==255||b>235||b==235)
   {
     b-=20;
   }
}