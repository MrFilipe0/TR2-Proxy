#ifndef HTML_PRS_H
#define HTML_PRS_H
#include <regex>
#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include <set>
using namespace std;
//classe responsavel por verificar as informações das mensagens trocadas entre servidor e cliente:

class Parser{
// analisa = verifica 
public:
	static  set< string> analisa_emissor(const char*);
	static  set< string> analisa_url   (const char*);
	static  set< string> analisa_import(const char*);
	static  string analisa_html  (const char*);
};
#endif
