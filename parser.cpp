#include<iostream>
#include<fstream>
#include<string>
#include "scanner.h"
#include "parser.h"
#include "translator.h"
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
// File parser.cpp written by Group Number: 26
//=================================================
//extern enum tokentype;


// ----- Four Utility Functions and Globals -----------------------------------
//Global Variable:

bool token_available;
string saved_lexme;
tokentype saved_token; 
bool error1 = false;
bool error2 = false;

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  

// Type of error: Expected Token but found "token" instead
// Done by: Brandon Rasgaitis 
void syntaxerror1(tokentype token, string s){
   cout << "SYNTAX ERROR: Expected " << tokenName[token] << " but found " << s << endl;
   error1 = true;
   exit(1);
}
// Type of error: Unexpected Token 
// Done by: Brandon Rasgaitis 
void syntaxerror2(string sl, string func){ //note: in other functions such as AfterNoun() type in "AfterNoun()" as parameter
   cout << "SYNTAX ERROR: unexpected " << sl << " found in parser function " << func << endl;
   error2 = true;
   exit(1);
}

// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme

// Purpose: Used to look ahead one token to see what the scanner would return next. Decides production rules.
// Done by: Alex Sandoval
tokentype next_token(){
   if(!token_available){
      scanner(saved_token, saved_lexme);
      token_available = true;
      cout << "Scanner called using word: " << saved_lexme << endl;
      if(saved_token == ERROR){
         //syntaxerror1(saved_token, saved_lexme);
         return saved_token;
      }
   }
   return saved_token;
}

// Purpose: Used to get the next scanner token. If token matches, match succeeds, other wise perform Syntax error handling 
// Done by: Alex Sandoval
bool match(tokentype expected){
   if(next_token() != expected){
      //syntaxerror2(saved_lexme, tokenName[expected]); //not sure if saved_token should also be passed in as a parameter
      syntaxerror1(expected, saved_lexme);
      scanner(saved_token, saved_lexme);
      return match(saved_token); // no match, error
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
// Note: each terminal function might need to be renamed based on left factoring submission
// Original Grammar: <s> ::= [CONNECTOR] <noun> SUBJECT <after subject>
// Done by: Sebastian Rojas, Brandon Rasgaitis

// Updated Grammar:
// Done by: Sebastian Rojas
void S(){
   cout << endl;
   cout << "Processing <S()>" << endl;
   if(next_token() == CONNECTOR){
      match(CONNECTOR);
      cout << "Matched: " << tokenName[CONNECTOR] << endl;
      getEword();
      gen(tokenName[CONNECTOR]);
   }
   Noun();
   getEword();
   match(SUBJECT);
   gen("Actor");
   cout << "Matched: " << tokenName[SUBJECT] << endl;
   AfterSubject();
}

// Grammar:
// Done by: Brandon Rasgaitis

// Updated Grammar:
// Done by: Sebastian Rojas
void Story(){ //statement_list() from notes 
   cout << endl;
   cout << "Processing <Story()>" << endl;
   S();
   while(next_token() != EOFM){
      switch(next_token()){
         case CONNECTOR:
         case WORD1:
         case PRONOUN: 
            S();
            break;
         default: 
            return;
      }
   }
}
// Grammar: <after subject> ::= <verb> <tense> PERIOD | <noun> <after noun>
// Done by: Brandon Rasgaitis

// Updated Grammar:
// Done by: Sebastian Rojas
void AfterSubject(){
   cout << endl;
   cout << "Processing <AfterSubject()>" << endl;
   switch(next_token()){
      case WORD2: 
         Verb();
         getEword();
         gen("ACTION"); 
         Tense(); 
         gen("TENSE");
         match(PERIOD); 
         cout << "Matched: "<< tokenName[PERIOD] << endl;
         break;
      case WORD1: 
         Noun(); 
         getEword();
         AfterNoun();
         break;
      case PRONOUN: 
         Noun(); 
         getEword();
         AfterNoun();
         break;
      default: 
         syntaxerror2(saved_lexme, "<After Subject>");
   }
}
// Grammar: <after noun> ::= <be> PERIOD | DESTINATION <verb> <tense> PERIOD| OBJECT <after object>
// Done by: Brandon Rasgaitis

// Updated Grammar:
// Done by: Sebastian Rojas
void AfterNoun(){
   cout << endl;
   cout << "Processing <AfterNoun()>" << endl;
   switch (next_token()){
      case IS:
      case WAS: 
         Be(); 
         gen("DESCRIPTION");
         gen("TENSE");
         match(PERIOD); 
         cout << "Matched: "<< tokenName[PERIOD] << endl; 
         break;
      case DESTINATION: 
         match(DESTINATION); 
         cout << "Matched: " << tokenName[DESTINATION] << endl;
         gen("TO");
         Verb(); 
         getEword();
         gen("ACTION");
         Tense();
         gen("TENSE"); 
         match(PERIOD); 
         cout << "Matched: "<< tokenName[PERIOD] << endl; 
         break;
      case OBJECT: 
         match(OBJECT); 
         cout << "Matched: " <<  tokenName[OBJECT] << endl; 
         gen("OBJECT");
         AfterObject(); 
         break;
      default: 
         syntaxerror2(saved_lexme, "<After Noun>");
   }
}

// Grammar: <after object> ::= <verb> <tense> PERIOD | <noun> DESTINATION <verb> <tense> PERIOD
// Done by: Sebastian Rojas

// Updated Grammar:
// Done by: Sebastian Rojas
void AfterObject(){
   cout << endl;
   cout << "Processing <AfterObject()>" << endl;
   switch(next_token()){
      case WORD2: 
         Verb(); 
         getEword();
         gen("ACTION");
         Tense(); 
         gen("TENSE");
         match(PERIOD); 
         cout << "Matched: "<< tokenName[PERIOD] << endl;
         break;
      case WORD1:
      case PRONOUN: 
         Noun(); 
         getEword();
         match(DESTINATION); 
         cout << "Matched: " << tokenName[DESTINATION] << endl; 
         gen("TO");
         Verb(); 
         getEword();
         gen("ACTION");
         Tense(); 
         gen("TENSE");
         match(PERIOD); 
         cout << "Matched: "<< tokenName[PERIOD] << endl; 
         break;
      default: 
         syntaxerror2(saved_lexme, "<After Object>");
   }
}

// Grammar: <noun>  ::= WORD1 | PRONOUN
// Done by: Sebastian Rojas

// Updated Grammar:
// Done by: Sebastian Rojas
void Noun(){
   cout << endl;
   cout << "Processing <Noun()>" << endl;
   switch(next_token()){
   case WORD1: 
      match(WORD1); 
      cout << "Matched: " << tokenName[WORD1] << endl;
      break;
   case PRONOUN: 
      match(PRONOUN); 
      cout << "Matched: " << tokenName[PRONOUN] << endl;
      break;
   default: syntaxerror2(saved_lexme, "<Noun>");
   }
}

// Grammar: <verb>  ::= WORD2
// Done by: Sebastian Rojas
void Verb(){
   cout << endl;
   cout << "Processing <Verb()>" << endl;
   match(WORD2);
   cout << "Matched: " << tokenName[WORD2] << endl;
}

// Grammar: <be>  ::= IS | WAS
// Done by: Sebastian Rojas

// Updated Grammar:
// Done by: Sebastian Rojas
void Be(){
   cout << endl;
   cout << "Processing <Be()>" << endl;
   switch(next_token()){
      case IS: 
         match(IS); 
         cout << "Matched: " << tokenName[IS] << endl;
         break;
      case WAS: 
         match(WAS); 
         cout << "Matched: " << tokenName[WAS] << endl;
         break;
      default: 
         syntaxerror2(saved_lexme, "Be");
   }
}

// Grammar: <tense>  ::= VERBPAST  | VERBPASTNEG | VERB | VERBNEG 
// Done by: Sebastian Rojas
void Tense(){
   cout << endl;
   cout << "Processing <Tense()>" << endl;
   switch(next_token()){
   case VERBPAST: 
      match(VERBPAST); 
      cout << "Matched: " << tokenName[VERBPAST] << endl;
      break;
   case VERBPASTNEG: 
      match(VERBPASTNEG); 
      cout << "Matched: " << tokenName[VERBPASTNEG] << endl;
      break;
   case VERB: 
      match(VERB); 
      cout << "Matched: " << tokenName[VERB] << endl;
      break;
   case VERBNEG: 
      match(VERBNEG); 
      cout << "Matched: " << tokenName[VERBNEG] << endl;
      break;
   default: 
      syntaxerror2(saved_lexme, "<Tense>");
   }
}
//----------- Driver ---------------------------
//string filename;
//extern ifstream fin;

// The new test driver to start the parser
// Done by:  Sebastian Rojas
// int main(){
//    cout << "Enter the input file name: ";
//    cin >> filename;
//    fin.open(filename.c_str());

//    //** calls the <story> to start parsing
//    Story();
//    cout << endl;
//    if(error1 == false && error2 == false){
//       cout << "succesfully parsed <Story>" << endl;
//    }
//    //** closes the input file 
//    fin.close();
//    return 0;
// }// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions
