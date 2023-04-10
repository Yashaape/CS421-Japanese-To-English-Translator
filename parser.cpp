#include<iostream>
#include<fstream>
#include<string>
#include "scanner.h"
using namespace std;

/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.  
  e.g. You can copy scanner.cpp here by:
          cp ../ScannerFiles/scanner.cpp .  
       and then append the two files into one: 
          cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: **
//=================================================
//extern enum tokentype;


// ----- Four Utility Functions and Globals -----------------------------------
//Global Variable:

extern string reservedWords;
extern tokentype reservedWordsType;
extern string tokenName;
bool token_available;
string saved_lexme;
tokentype saved_token; 
bool error1 = false;
bool error2 = false;


// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: **
// Done by: ** 
void syntaxerror1(string s, tokentype token){

}
// Type of error: **
// Done by: ** 
void syntaxerror2(string s){

}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: **
// Done by: Brandon Rasgaitis
tokentype next_token(){
   if(!token_available){
      scanner(saved_token, saved_lexme);
      token_available = true;

      if(saved_token == ERROR){
         syntaxerror1(saved_lexme, saved_token);
      }
      token_available = true;
   }
   return saved_token;
}

// Purpose: **
// Done by: Brandon Rasgaitis
bool match(tokentype expected){
   if(next_token() != expected){
      syntaxerror2(saved_lexme); //not sure if saved_token should also be passed in as a parameter
      return false; // no match, error
   }
   else{ // match has occured 
      token_available = false; //eat up the token
      return true;   // say there was a match
   }
}

// ----- RDP functions - one per non-term -------------------

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

// Grammar: **
// Done by: **

string filename;
ifstream fin;
//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by:  **
int main()
{
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  //** closes the input file 

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
