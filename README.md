# Donato Leon

Theme completer



### v0.2 Updates

creates color pallete based off input color

### v1.0 Updates

creates a color pallete suitable for red and green color weakness


## Developer

Donato Leon

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
1.user inputs a 6 decimal hexadecimal value with a #
   ex:#xxxxxx
2. program checks for every combination of error
3.program prints out the rgb color value of the user input
   ex:
      RGB value is: xx, xx, xx,
4.program prints out characteristics of the color
   ex: "color is blue dominant"
5.program prints out the generated Theme
   ex: 
      #xxxxxx
      #xxxxxx
      #xxxxxx
      #xxxxxx
      #xxxxxx
      #xxxxxx
6.program asks the user if they wish to  keep or discard generated theme.
7. program propmts user to choose  to either create another theme or quit

theme.css already comes with a list of colors best suited for people with protanopia colorblindness originating from the hex colors #eeffdd and #ffeedd

```

## C++ Guide

### Variables and Data Types
string 
this variable type is like an array of characters put together as a single object

this program mainly uses them to keep track of user Decisions

ex:
string basecolor(takes hexidecimal )
string filename(takes filename)
string cont(takes user decision)

int
this variable type is used to store whole numbers which can have a range of uses. 

this program uses these variables for different operations which range from recording the size of a string, vector, or array to recording the position of a character within a string or keeping track of errors detected in a user input.

ex:
int position (records position of the # in a string)

int error (given a value based on the error type so the program knows which message to print out)

char
this type of variable is used to hold a single character

for this program they are used to for things such as
comparing characters of eachother or breaking up a hex number to be converted to rgb value

ex:
char ch (checks the string uses only numbers 0-9 and lowercase letters a-f)

constant string was also used to store a clear screen command
const string CLEAR_SCREEN = u8"\033[2J\033[1;1H";



### Console Input and Output

before a user inputs anything theres always a prompt beforehand that gives directions to the user. 
console outputs only neccesary information and confirmations.

### Decisions

if, if else, else, and switches were used in the proccess of deciding what was wrong with the user input and what the issue was.
the if, if else, and else statements were what checked for user errors and gave outputs to be used as inputs for the switch statement to determine what error message to print

### Iteration

do while and for loops were used in the in the process of checking errors as well. for loop checked each character in a string to determine if it was a valid input. the do while was used to restart the input and checking proccess of the program each time an error was found

### File Input and Output

program takes in the file name entered by user and opens the entered file. if the file cannot be opened or is found then it exits the program. if found the program writes a simple css statement using the users hexadecimal input and closes it. then the program reopens the file to start back from the beginning and reads the file back to the user to confirm what it has printed

### Arrays/Vectors

Arrays keep a static size that cannot be increased or decreased when defined. arrays in this program are used for storing components of an RGB or Hexadecimal color value. these RGB and Hexadecimal components keep a consistent format which makes using arrays an effective option.

Vectors can be defined with with things stored inside them but unlike an array it can increase or decrease as much as it needs to throughout the program which made it a great choice for storing the generated list of colors in the program because the user is given an option to delete palletes or generate as many as they want so its important to use a vector in this case as it can satisfy this these conditions

### Functions
This program has 5 functions that serve their own unique functions

1. int checkHex(string);
this function takes in a hexadecimal number asa string and checks its format to determine wether or not it is a 6 character hexadecimal with lowercase letters. the string is passed by value so the original string stays the same. the function returns an int value that tells us the type of error that has been found

2. int convertHex(char b[]);
this function takes in an array of two characters from a hexadecimal to convert it into its decimal form. the array is oassed by value and the function returns the decimal value as an integer.

3. string convertDec(int n);
this function converts a decimal value into a two character hexadecimal. it takes in a integer value and returns a string.
the integer is passed by value so the original variable is left unchanged by the function

this function does not appear in int main but appears in our next function

4. string convertRGB(int R, int G, int B);
this function takes components of an RGB color value and converts it back into a 6 character Hexadecimal color value. it takes in the RGB components as integers and returns our hexadecimal as a string

5. void generateColors(int& r, int& g, int& b);
this function takes in RGB components as integers and either increases or decreased each component by certain values to creat new colors. this fuction is differetn from the rst because it does not return anything but affects our paraneters as they are passed by reference meaning the origina copies of the variable are changed.

### Classes

the color class was added to the algorithm to represent the user provided color as an object that held information such as its rgb value, hexadecimal value, and its characteristics as it relates to colorblindness( EX: if a color is red dominant)
