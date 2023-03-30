#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: ** 
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Brandon Rasgaitis
// RE:   **
bool word(string s) {
    int state = 0;
    int charpos = 0;
    //replace the following todo the word dfa  
    while (s[charpos] != '\0') {
        switch (state) {
            case 0:
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        state = 1;
                        break;
                    case 'b':
                    case 'g':
                    case 'h':
                    case 'k':
                    case 'm':
                    case 'n':
                    case 'p':
                    case 'r':
                        state = 2;
                        break;
                    case 'c':
                        state = 3;
                        break;
                    case 'd':
                    case 'j':
                    case 'w':
                    case 'y':
                    case 'z':
                        state = 4;
                        break;
                    case 's':
                        state = 5;
                        break;
                    case 't':
                        state = 6;
                        break;
                }
                break;
            case 1:
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1;
                        break;
                    case 'b':
                    case 'g':
                    case 'h':
                    case 'k':
                    case 'm':
                    case 'p':
                    case 'r':
                        state = 2;
                        break;
                    case 'c':
                        state = 3;
                        break;
                    case 'd':
                    case 'j':
                    case 'w':
                    case 'y':
                    case 'z':
                        state = 4;
                        break;
                    case 's':
                        state = 5;
                        break;
                    case 't':
                        state = 6;
                        break;
                    case 'n':
                        state = 7;
                        break;
                }
                break;
            case 2:
                switch (s[charpos]) {
                    case 'y':
                        state = 4;
                        break;
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1;
                        break;
                }
                break;
            case 3:
                switch (s[charpos]) {
                    case 'h':
                        state = 4;
                        break;
                }
                break;
            case 4:
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1;
                        break;
                }
                break;
            case 5:
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1;
                        break;
                    case 'h':
                        state = 4;
                        break;
                    case 's':
                        state = 5;
                        break;
                }
                break;
            case 6:
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1;
                        break;
                    case 's':
                        state = 5;
                        break;
                }
                break;
            case 7:
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1;
                        break;
                    default:
                        break;
                }
        }
        charpos++;
    }
    if (state == 1 || state == 7) return (true);  // end in a final state
    else return (false);
}

// PERIOD DFA 
// Done by: Brandon Rasgaitis
bool period (string s)
{  // complete this **
  int state = 0;
  int charpos = 0;

  while(s[charpos] != '\0'){
    if (state == 0 && (s[charpos] == '.'))
            state = 1;
        else
            return (false);
        charpos++;
  }
  if (state == 1) return (true);
  else return (false);
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: *Sebastian Rojas*

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {WORD1, WORD2, PERIOD, ERROR, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"WORD1", "WORD2", "PERIOD", "ERROR", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM"}; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

//gonna do this later tmrw
string reservedwords[] = {};


// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Sebastian Rojas (just started with grabbing next word with fin)
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.  
	
	fin >> w;
	
  /*  **
  2. Call the token functions (word and period) 
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.

  4. Return the token type & string  (pass by reference)
  */
 return 0; // for testing purposes 
}//the end of scanner



// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
int main()
{
  tokentype thetype;
  string theword; 
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
   while (true)
    {
       scanner(thetype, theword);  // call the scanner which sets
                                   // the arguments  
       if (theword == "eofm") break;  // stop now

       //cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end

