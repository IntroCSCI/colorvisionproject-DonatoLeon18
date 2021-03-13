# !!!Donato Leon!!!

#Theme completer

!!!!!!

### v0.2 Updates

*Coming soon*

### v1.0 Updates

*Coming soon*


## Developer

!!!Donato Leon!!!

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
3.user inputs file to copy hexadecimal value to
4.program prints to css file in the correct format

```

## C++ Guide

### Variables and Data Types
strings used for user input
ex:
string basecolor(takes hexidecimal )
string filename(takes filename)

integers used to check or mark errors in the users format by comparing size of the input and position of the #
ex:
int c (records position of the # in a string)
int n (records the size of the string)
int error (given a value based on the error type so the program knows which message to print out)

characters used to compare each number and letter in a string following a # to chech for invalid numbers or symbols
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

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
