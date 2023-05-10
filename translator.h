// header file for translator to be implemented with parsor

#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "scanner.h"
#include "parser.h"
#include <string>
#include <map>

extern std::map<std::string, std::string> Lexicon;
extern std::string savedEword;
extern std::ofstream translated_file;

void getEword();
void gen(std::string);


#endif