#ifndef HTTP_REQ_H
#define HTTP_REQ_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string.h>

//classe para manipular as mensagens de requests no servidor proxy:
using namespace std;
class Request{

public:
	Request( string);
	Request();

	 map< string,  string> camp;
	 string body;
	 string procedimento;
	 string url;
	 string versao;

	//verifica se o metodo é GET:
	bool analisa_metodo();

	//acrescenta "close" e "identity" nos campos corretos da mensagem:
	void tratar_conexao();

	//mostra os atributos:
	void mostra();

	//monta o request:
	 string constroi_requisicao();
};
#endif
