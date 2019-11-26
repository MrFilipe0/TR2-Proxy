#ifndef SPIDER_H
#define SPIDER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <set>

using namespace std;


//classe para realizar o spider:
using namespace std;
class Spider{

public:
	Spider( string);

	string host; 
	string raiz;
	bool eh_valido;							
	map< string,  string> nomes;
	map< string,  string> html;
	set< string> urls_vistas; // guarda as urls ja visitadas
	map< string,  string> mapa_dicionario;
	map< string,  set< string> > par;

	bool        avaliar_url( string url);

	 string parsing_url( string url);
	 string url_nome_arquivo( string url);

	//monta a arvore de referencias:
	void constroi_arvore(int);

	//mostra a arvore:
	void mostra_arvore(int);

	//realiza o dump:
	void dump(int);
};
#endif
