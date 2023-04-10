// scanner.cpp function to be used with parser


#ifndef SCANNER_H
#define SCANNER_H
#include <string>
enum tokentype {WORD1, WORD2, PERIOD, ERROR, VERB, VERBNEG, VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION, PRONOUN, CONNECTOR, EOFM};


bool word(std::string s);
bool period(std::string s);
int scanner(tokentype& tt, std::string& w);

#endif //TOKENTYPE_H