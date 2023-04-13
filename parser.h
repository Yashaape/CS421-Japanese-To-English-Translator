//header file for parser to be implemented in translator

#ifndef PARSER_H
#define PARSER_H
#include "scanner.h"
#include <string>

extern bool token_available;
extern std::string saved_lexme;
extern tokentype saved_token; 
extern bool error1;
extern bool error2;

bool match(tokentype expected);
void Story();
void S();
void AfterSubject();
void AfterNoun();
void AfterObject();
void Noun();
void Verb();
void Be();
void Tense();
void syntaxerror1(tokentype, std::string);
void syntaxerror2(std::string, std::string);

#endif