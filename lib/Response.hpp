#ifndef HTTP_RESP_H
#define HTTP_RESP_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string.h>

//classe para manipular as mensagens de resposta no servidor proxy:
using namespace std;
class Response{

public:
	Response( string);
	Response();

	 string versao;
	 string data;
	 string estado_codigo;
	 map< string,  string> camp; // string separa em varios campos

	//mostra os atributos:
	void mostra();
	
	//monta a  mensagem de resposta :
	 string constroi_resposta();
};
#endif