#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: 26 
//=====================================================

// --------- Two DFAs ---------------------------------

//WORD DFA 
//Done by: Brandon Rasgaitis
//RE:   q0[^ndwxyj], N/A, qsa.*, qy.*, qt.*, qs.*, qc.*, q0.*, q0[^ndwxyj]*q1, qsa.*, q0q1.*, qtqsa.*, q0q1.*, qsqsa.*, qcqsa.*, q0q1.*, q0q1[^c]*, q0q1[^s]*, q0q1[^t]*, q0q1[^bhkmnpr]*,
//      (q0|qy), 0, q0, qc, qs, qt, qy, qy, qsa
//      *Each of these are the regular expressions for our transistion functions from our NFA to DFA diagram  
//@param: s, checks each letter in a given word using switch statements for 7 cases inside a while loop.
bool word(string s) { // check to see if this dfa matches our diagram
    int state = 0;
    int charpos = 0;
    // char lastchar = s[s.length()-1];
    // char firstchar = s[0];
    // if (firstchar == 'O'){
    //     return false;
    // }
    // if (lastchar == '*'){
    //     return false;
    // }
    //replace the following todo the word dfa  
    while (s[charpos] != '\0') {
        switch (state) {
            case 0://q0
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1; //q0q1
                        break;
                    case 'b':
                    case 'g':
                        if (s.substr(charpos, 4) == "give") {
                            return false; // lexical error for "give"
                        } else {
                            state = 2; // Qy
                            break;
                        }
                    case 'h':
                    case 'k':
                    case 'm':
                    case 'n':
                    case 'p':
                    case 'r':
                        state = 2;//Qy
                        break;
                    case 'c':
                        state = 3;//Qc
                        break;
                    case 'd':
                    case 'j':
                    case 'w':
                    case 'y':
                    case 'z':
                        state = 4;//Qsa
                        break;
                    case 's':
                        state = 5;//Qs
                        break;
                    case 't':
                        state = 6;//Qt
                        break;
                    default:
                        return false;
                }
                break;
            case 1: //Q0Qy
                switch (s[charpos]) {
                    case 'a':
                    case 'e':
                    case 'E':
                    case 'i':
                    case 'I':
                    case 'o':
                    case 'u':
                        state = 1;//Q0
                        break;
                    case 'b':
                    case 'g':
                    case 'h':
                    case 'k':
                    case 'm':
                    case 'p':
                    case 'r':
                        state = 2;//Qy
                        break;
                    case 'c':
                        state = 3;//Qc
                        break;
                    case 'd':
                    case 'j':
                    case 'w':
                    case 'y':
                    case 'z':
                        state = 4;//Qsa
                        break;
                    case 's':
                        state = 5;//Qs
                        break;
                    case 't':
                        state = 6;//Qt
                        break;
                    case 'n':
                        state = 7;//Q0Qy
                        break;
                    default:
                        return false;
                }
                break;
            case 2://qy
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
                    default:
                        return false;
                }
                break;
            case 3://Qc
                switch (s[charpos]) {
                    case 'h':
                        state = 4;
                        break;
                    default: 
                        return false;
                }
                break;
            case 4://Qsa
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
                        return false;
                }
                break;
            case 5://Qs
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
                    default:
                        return false;
                }
                break;
            case 6://qt
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
                        state = 5;//Qsa
                        break;
                    default:
                        return false;
                }
                break;
            case 7: //q0q1
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
                    case 'n':
                    case 'p':
                    case 'r':
                        state = 2;//Q0Qy
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
                    default:
                        return false;
                        //break;
                }
            //return false;
            break;
        }
        charpos++;
    }
    if (state == 1 || state == 7) return (true);  // end in a final state
    else return (false);
}
// bool word(string s) {
//     int state = 0;
//     int charpos = 0;

//     while (s[charpos] != '\0') {

//         /************************/
//         /*    State 0 block     */
//         /************************/
//         if (state == 0 &&
//             (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
//              s[charpos] == 'u'))
//             state = 1;
//         else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' ||
//                                 s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
//             state = 2;
//         else if (state == 0 && (s[charpos] == 'c'))
//             state = 3;
//         else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' ||
//                                 s[charpos] == 'z'))
//             state = 4;
//         else if (state == 0 && (s[charpos] == 's'))
//             state = 5;
//         else if (state == 0 && (s[charpos] == 't'))
//             state = 6;

//             /************************/
//             /*    State 1 block     */
//             /************************/
//         else if (state == 1 &&
//                  (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
//                   s[charpos] == 'u'))
//             state = 1;
//         else if (state == 1 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' ||
//                                 s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
//             state = 2;
//         else if (state == 1 && (s[charpos] == 'c'))
//             state = 3;
//         else if (state == 1 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' ||
//                                 s[charpos] == 'z'))
//             state = 4;
//         else if (state == 1 && (s[charpos] == 's'))
//             state = 5;
//         else if (state == 1 && (s[charpos] == 't'))
//             state = 6;
//         else if (state == 1 && (s[charpos] == 'n'))
//             state = 7;

//             /************************/
//             /*    State 2 block     */
//             /************************/
//         else if (state == 2 && (s[charpos] == 'y'))
//             state = 4;
//         else if (state == 2 &&
//                  (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
//                   s[charpos] == 'u'))
//             state = 1;

//             /************************/
//             /*    State 3 block     */
//             /************************/
//         else if (state == 3 && (s[charpos] == 'h'))
//             state = 4;

//             /************************/
//             /*    State 4 block     */
//             /************************/
//         else if (state == 4 &&
//                  (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
//                   s[charpos] == 'u'))
//             state = 1;

//             /************************/
//             /*    State 5 block     */
//             /************************/
//         else if (state == 5 &&
//                  (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
//                   s[charpos] == 'u'))
//             state = 1;
//         else if (state == 5 && (s[charpos] == 'h'))
//             state = 4;

//             /************************/
//             /*    State 6 block     */
//             /************************/
//         else if (state == 6 &&
//                  (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
//                   s[charpos] == 'u'))
//             state = 1;
//         else if (state == 5 && (s[charpos] == 's'))
//             state = 5;

//             /************************/
//             /*    State 7 block     */
//             /************************/
//         else if (state == 7 &&
//                  (s[charpos] == 'a' || tolower(s[charpos]) == 'e' || tolower(s[charpos]) == 'i' || s[charpos] == 'o' ||
//                   s[charpos] == 'u'))
//             state = 1;
//         else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' ||
//                                 s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
//             state = 2;
//         else if (state == 7 && (s[charpos] == 'c'))
//             state = 3;
//         else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'j' || s[charpos] == 'w' || s[charpos] == 'y' ||
//                                 s[charpos] == 'z'))
//             state = 4;
//         else if (state == 7 && (s[charpos] == 's'))
//             state = 5;
//         else if (state == 7 && (s[charpos] == 't'))
//             state = 6;
//         else
//             return (false);
//         charpos++;
//     }//end of while

//     // where did I end up????
//     if (state == 1 || state == 7) return (true);  // end in a final state
//     else return (false);
// }


// PERIOD DFA 
// Done by: Brandon Rasgaitis
// @param: s, reads in a '.' as a string and returns the correct state
bool period (string s)
{  // complete this **
  int state = 0;
  int charpos = 0;

  while(s[charpos] != '\0'){
    if (state == 0 && (s[charpos] == '.'))
            state = 1;
        else
            return (false);
        charpos++; //end of if()
  } // end of while
  if (state == 1) return (true);
  else return (false);
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: *Sebastian Rojas*, Alex Sandoval

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {WORD1, WORD2, PERIOD, ERROR, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {"WORD1", "WORD2", "PERIOD", "ERROR", "VERB", "VERBNEG", "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION", "PRONOUN", "CONNECTOR", "EOFM"}; 

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

//table with string values of the reserved words listed in the prompt
string reservedWord[20][2] = {
        {"masu",         ""},
        {"masen",        ""},
        {"mashita",      ""},
        {"masendeshita", ""},
        {"desu",         ""},
        {"deshita",      ""},
        {"o",            ""},
        {"wa",           ""},
        {"ni",           ""},
        {"watashi",      ""},
        {"anata",        ""},
        {"kare",         ""},
        {"kanojo",       ""},
        {"sore",         ""},
        {"mata",         ""},
        {"soshite",     ""},
        {"shikashi",   ""},
        {"dakara", ""},
        {"eofm", ""}

};

//table for the token types of the reserved words in the prompts
tokentype reservedwordTT[20] = {
        VERB,
        VERBNEG,
        VERBPAST,
        VERBPASTNEG,
        IS,
        WAS,
        OBJECT,
        SUBJECT,
        DESTINATION,
        PRONOUN,
        PRONOUN,
        PRONOUN,
        PRONOUN,
        PRONOUN,
        CONNECTOR,
        CONNECTOR,
        CONNECTOR,
        CONNECTOR,
        EOFM
};

// ------------ Scanner and Driver ----------------------- 

ifstream fin;  // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Sebastian Rojas (just started with grabbing next word with fin), Alex Sandoval
// @param: tt, reads in the token type for a given word
// @param: w, reads in the word for the associated token type
int scanner(tokentype& tt, string& w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.  

  //grabs next word via fin
  fin >> w;
	  
  bool reserve = false;                                                                                                      
        
  //if word is equal to "eofm" - EOFM (end of file marker), terminate                                                                                                          
  if(w == "eofm")
    {
      return EOFM;
    }

   // calling (1/2) token function (period) to check if word is type PERIOD (.)                                                                                   
   if(period(w))
    {
      tt = PERIOD;
    }
  // calling (2/2) token function (word) to check a words token type-(tt) using the table of reserved words                                                                                                         
  else if(word(w))
    {
      //check all words(w) in the reservedword table to set tokentype(tt) in the reservedWordTT table
      for(int i = 0; i < 20; i++)
        {
             if (w == reservedWord[i][0]) {
                tt = reservedwordTT[i];
                reserve = true;
                break;
            }
        }  
    
    //condition statements generated when word(w) is not found as reserved, letting tokentype(tt) be WORD1/WORD2 based on last letter (I/E)                                                                                                          
    if(!reserve)
       {
                                                                                                                                          
         if(w[w.length() - 1] == 'I' || w[w.length() - 1] == 'E')
           {                                                                                                                 
             tt = WORD2; //when last letter in string is I
           }

         else
           {
                                                                                                                               
             tt = WORD1; //when last letter in string is E
            }
        }
  }

  //else statement that generates a lexical error if both DFAs fail, letting tokentype(tt) be type ERROR                                                                                                      
  else
    {
      tt = ERROR;
      cout << "\nLexical error: " << w << " is not a valid token\n";
      //tt = ERROR;
    }

	
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
 return 1; // for testing purposes 
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

       cout << "Type is:" << tokenName[thetype] << endl;
       cout << "Word is:" << theword << endl;   
    }

   cout << "End of file is encountered." << endl;
   fin.close();

}// end

