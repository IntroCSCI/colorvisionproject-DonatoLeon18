//Author: Donato Leon
#include <iostream>
#include <fstream>
#include<string.h>
#include <vector>
using namespace std;
fstream reader;
string filename="";
string basecolor="";

const string CLEAR_SCREEN = u8"\033[2J\033[1;1H";
int error=0;
int checkHex(string);
int convertHex(char b[]);
string convertDec(int n);
string convertRGB(int R, int G, int B);
void generateColors(int& r, int& g, int& b);
int RGB[3];//array for storing rgb color value
int position;
char ch;//hex characters
char splitHex[2];//array to store hex values for red blue green individually 
int cont;
vector <string> theme;

int main()

{

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
//confirms cirrect input
cout<<CLEAR_SCREEN<<"correct input\n"<<basecolor<<endl;

   //breaks apart hex number into its RGB components and converts those components into decimal values
    position= basecolor.find("#");
for(int i = position+1; i < 3; i++)
{
  ch = basecolor[i];  
    if ((ch >= '0' || ch <= '9') && (ch >= 'a' || ch <= 'f'))
  {
    splitHex[i-1]=ch;
  }
}
   RGB[0]=convertHex(splitHex);  

for(int i = position+3; i < 5; i++) 
{
  ch = basecolor[i];  
  if ((ch >= '0' || ch <= '9') && (ch >= 'a' || ch <= 'f'))
  {
    splitHex[i-3]=ch;
  }
}
   RGB[1]=convertHex(splitHex);   

for(int i = position+5; i < 7; i++) 
{
  ch = basecolor[i];  
  if ((ch >= '0' || ch <= '9') && (ch >= 'a' || ch <= 'f'))
  {
    splitHex[i-5]=ch;

  }
}
   RGB[2]=convertHex(splitHex); 

cout<<"RGB value is: ";

  for(int i=0;i<3;i++)
  {
    cout<<RGB[i]<<", ";
  } 
   cout<<endl;

   //checks for properties of color
  if(RGB[0]>RGB[1]&&RGB[0]>RGB[2])
  {
   cout<<"color is red dominant\n";
  } 
  else if(RGB[1]>RGB[0]&&RGB[1]>RGB[2])
  {
    cout<<"color is green dominant\n";
  } 
  else if(RGB[2]>RGB[0]&&RGB[2]>RGB[1])
  { 
    cout<<"color is blue dominant\n";
  }
  else if(RGB[0]==RGB[1]&&RGB[1]==RGB[2])
  {
    cout<<"color is apart of greyscale\n";
  } 
  if(RGB[0]==RGB[1]||RGB[1]==RGB[2]||RGB[0]==RGB[2])
  {
    cout<<"the color is blended\n";
  }

   //generates new colors from inputed color
   cout<<"new colors to complete theme:"<<endl;

for(int i=0;i<5;i++)
  {
   //changes color into new ones
   generateColors(RGB[0],RGB[1],RGB[2]);

   //converts alternate color's RGB value back into hex
   basecolor=convertRGB(RGB[0],RGB[1],RGB[2]);
   theme.push_back(basecolor);
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

//function thatconverts hexadecimal value into decimal value
int convertHex(char red[])
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
   }return temp;
} 

//function that converts decimal to hexadecimal
string convertDec(int n)
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

//function that converts RGB color value to hexadecimal color format
string convertRGB(int R, int G, int B)
{
  string hexCode;
  if ((R>=0&&R<=255)&&(G>=0&&G<=255)&&(B>=0&&B<=255)) 
  {
  
    hexCode = "#";
    hexCode += convertDec(R);
    hexCode += convertDec(G);
    hexCode += convertDec(B);
  }

 return hexCode;
}
void generateColors(int& r, int& g, int& b)
{
  if(RGB[0]<225&&RGB[0]>30)
  {
     RGB[0]-=30;
  }
  else if(RGB[0]==255||RGB[0]>235||RGB[0]==235)
  {
     RGB[0]-=20;
   }
   if(RGB[1]<225)
   {
     RGB[1]+=30;
   }
   else if(RGB[1]==255||RGB[1]>235||RGB[1]==235)
   {
     RGB[1]-=40;
   }
   if(RGB[2]<225)
   {
     RGB[2]+=30;
   }
   else if(RGB[2]==255||RGB[2]>235||RGB[2]==235)
   {
     RGB[2]-=40;
   }
}
 


         