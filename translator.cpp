#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include "scanner.h"
#include "parser.h"
#include "translator.h"
using namespace std;

 
/* INSTRUCTION:  copy your parser.cpp here
      cp ../ParserFiles/parser.cpp .
   Then, insert or append its contents into this file and edit.
   Complete all ** parts.
*/

//=================================================
// File translator.cpp written by Group Number: 26
//=================================================

// ----- Additions to the parser.cpp ---------------------

// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt 
//  Done by: Alex Sandoval 
map<string, string> Lexicon;
string savedEword;

// ** Additions to parser.cpp here:
//  Done by: Brandon Rasgaitis
//    getEword() - using the current saved_lexeme, look up the English word
//                 in Lexicon if it is there -- save the result   
//                 in saved_E_word
void getEword(){
  if(saved_lexme == "watashi"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "anata"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "kare"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "kanojo"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "sore"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "mata"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "soshite"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "shikashi"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "dakara"){
    savedEword = Lexicon[saved_lexme];
  }

  //Nouns:
  else if(saved_lexme == "daigaku"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "kurasu"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "hon"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "tesuto"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "ie"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "isu"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "seito"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "sensei"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "tomodachi"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "jidoosha"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "gyuunyuu"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "biiru"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "choucho"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "ryouri"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "toire"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "gohan"){
    savedEword = Lexicon[saved_lexme];
  }

  //Description:
  else if(saved_lexme == "yasashii"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "muzukashii"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "ureshii"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "shiawase"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "kanashii"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "omoi"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "oishii"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "tennen"){
    savedEword = Lexicon[saved_lexme];
  }

  //Verbs:
  else if(saved_lexme == "nakI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "ikI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "tabE"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "ukE"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "kakI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "yomI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "nomI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "agE"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "moraI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "butsI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "kerI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "shaberI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "yarI"){
    savedEword = Lexicon[saved_lexme];
  }
  else if(saved_lexme == "yorokobI"){
    savedEword = Lexicon[saved_lexme];
  }
  else{
    savedEword = saved_lexme;
  }
}

//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
//  Done by: Brandon Rasgaitis 
void gen(string line_type){
  if(line_type != "TENSE"){
    translated_file << line_type << ": " << savedEword << endl;
  }
  else{
    translated_file << line_type << ": " << tokenName[saved_token] << endl;
  }
}

// ----- Changes to the parser.cpp content ---------------------
// As we are using header files to use various functions and variables from 
// parser.cpp, and scanner.cpp, all changes will be directly in those files.
// To see our original parser.cpp, and scanner.cpp they will be in their 
// respective project folders within empress. 
// ** Comment update: Be sure to put the corresponding grammar 
//    rule with semantic routine calls
//    above each non-terminal function 

// ** Each non-terminal function should be calling
//    getEword and/or gen now.


// ---------------- Driver ---------------------------

string filename;
//extern std::ifstream fin;
ofstream translated_file;
ifstream infile;

// The final test driver to start the translator
// Done by:  Alex Scandoval
int main()
{
  //** opens the lexicon.txt file and reads it into Lexicon
  infile.open("lexicon.txt");
  string JAP, ENG;
  while(infile >> JAP >> ENG){
    Lexicon[JAP] = ENG;
  }
  //** closes lexicon.txt 
  infile.close();

  //Visualizing Lexicon:
  // for (const auto& pair : Lexicon) {
  //   cout << pair.first << ": " << pair.second << endl;
  // }

  //** opens the output file translated.txt
  translated_file.open("translated.txt");
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str());

  //** calls the <story> to start parsing
  Story();
  cout << endl;
  if(error1 == false && error2 == false){
    cout << "succesfully parsed <Story>" << endl;
  }
  //** closes the input file 
  fin.close();
  //** closes traslated.txt
  translated_file.close();
}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions

