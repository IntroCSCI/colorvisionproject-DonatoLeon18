//Author: Donato Leon
#include <iostream>
#include <fstream>

using namespace std;
fstream reader;
string filename="";
string basecolor="";
string s;
size_t hex;
int c;
int n;
char ch;
const string CLEAR_SCREEN = u8"\033[2J\033[1;1H";
int error=0;


int main()

{
  
  do{
    //ask user for Hexadecimal
    cout<<"input 6 character Hexadecimal\n";
    cout<<"include #\n";
    cout<<"use lowercase letters a-f\n";
    cout<<"EX:#xxxxxx\n";

  cin>>basecolor;

//use error variable for while condition to zero each time the loop is restarted
  error=0;
//record string length 
    n = basecolor.length();
    //look for # and record its position
    c= basecolor.find("#");
    
    //check to se if hexadecimal has correct format
    /* if: there is # and its in the correct position then check if each character is 0-9 or a lowercase letter a-f
    else:error
    if:size of string is incorrect then error
    */
      if(c==0){
    for(int i = c+1; i < n; i++) {
    
        char ch = basecolor[i];  //stores each character of string as a char
//use stored characters in for loop to test for invalid characters
 if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f')){
cout<<CLEAR_SCREEN<<"invalid characters"<<endl;
error+=1;
break;
            }
         }
    }
    
    else{cout<<CLEAR_SCREEN<<" # missing or misplaced\n";
    error+=3;
    }
    //check for correct string size
    if(n!=7){error+=4;
    cout<<CLEAR_SCREEN<<"incorrect amount of characters"<<endl;
    }
    
     cin.ignore();
    }while(error>0);
cout<<CLEAR_SCREEN<<"correct input\n"<<basecolor<<endl;

    cout<<"input file name\n";
cin>>filename;
reader.open(filename, ios::out|ios::in);

 if(!reader.is_open()){
 cout << "Could not open " << filename << endl;
 exit(1);
 }

reader<<"body{ color: "<<basecolor<<"}"<<endl;
reader.close();

reader.open(filename,ios::out|ios::in);
string result;
cout<<"\n"<<"succesfully printed to file: ";
 while(!reader.eof()){
getline(reader,result);
cout<<result;
 }
reader.close();
  return 0;
}
