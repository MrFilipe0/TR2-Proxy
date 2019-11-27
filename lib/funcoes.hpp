#ifndef STR_FUN_H
#define STR_FUN_H

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

//classe criada para auxiliar na manipulação de strings:
using namespace std;
class Functions_aux{

public:

static  vector< string> separa( string, const char*);
static  vector< string> separa_antes( string, const char*);
static int   escreve_file( string str, const char *caminho,const char *arquivo);
static  string  le_file(const char*arquivo);
static  string  replace( string,const char*,const char*);

};
#endif