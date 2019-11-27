#include "analises.hpp"
#include "Spider.hpp"
#include "servidor_proxy.hpp"
#include "requisicao_proxy.hpp"
#include "resposta_proxy.hpp"
#include "analises.hpp"
using namespace std;

/*
Cria as arvores de links. Pega todos os link referenciados no site, construindo uma arvore.
É possivel fazer o dump do browser tambem.
*/

Spider::Spider(string url)
{
	string pega_url       = url;
	vector<string> resultado = Functions_aux::separa(pega_url, "//");

	if(resultado.size() == 2)
	{
		if(resultado[0] != "http:")
		{
		 eh_valido = false;
		 return;
		}

		pega_url = resultado[1];
	}
	if(resultado.size() > 2)
	{
	 	eh_valido = false;
	 	return;
	}

	if(pega_url.find('/')!=0 && pega_url.find('/') < pega_url.length())
	{
		vector<string> resultado2 = Functions_aux::separa_antes(pega_url, "/");
		if(host.length() == 0)
		{
			host = resultado2[0];
		}else
		{
			eh_valido = false;
			return;
		}
		raiz = "/";
		raiz.append(resultado2[1]);
	}else if(pega_url.find('/') > pega_url.length())
	{
		raiz = "/";
		host = pega_url;
	}else
	{
		eh_valido = false;
		return;
	}
	eh_valido = true;
};

bool Spider::avaliar_url(string url)
{
	if(url.size() == 0)
		return false;

	string pega_url       = url;
	vector<string> resultado = Functions_aux::separa(pega_url, "//");

	if(resultado.size() == 2)
	{
		if(resultado[0] != "http:")
			return false;
		pega_url = resultado[1];
	}

	if(resultado.size() > 2)
		return false;


	if(pega_url.find('/') != 0)
	{
		vector<string> resultado2 = Functions_aux::separa(pega_url, "/");

		if(host.length() == 0)
		{
			return false;
		}else
		{
			if(host != resultado2[0])
				return false;
		}
	}
	return true;
}

string Spider::parsing_url(string url)
{
	string parsed("");
	string pega_url       = url;
	vector<string> resultado = Functions_aux::separa(pega_url, "//");

	if(resultado.size() == 2)
		pega_url = resultado[1];

	if(pega_url.find('/') != 0)
	{
		vector<string> resultado2 = Functions_aux::separa_antes(pega_url, "/");
		parsed                 = "/";
		parsed.append(resultado2[1]);
	}else
	{
		parsed = pega_url;
	}

	if(parsed.find("?") < parsed.length())
	{
		int ask = parsed.find("?");
		parsed  = parsed.substr(0,ask);
	}

	if(parsed != url)
		nomes[parsed] = url;

	return parsed;
}

void Spider::constroi_arvore(int niveis)
{
	int i = niveis;
	urls_vistas.clear();
	par.clear();
	html.clear();

	if(!eh_valido)
		return;


	Servidor_proxy proxy   = Servidor_proxy();
	Request request = Request();
	request.tratar_conexao();
	set<string> requis_dest;
	requis_dest.insert(raiz);

	do
	{
		set<string> nextRequest;

		for (std::set<string>::iterator url=requis_dest.begin(); url != requis_dest.end(); ++url)
		{
			if(urls_vistas.find(*url) == urls_vistas.end())
			{
				urls_vistas.insert(*url);
				request.url             = *url;
				request.camp["Host:"] = host;


				string reply           = proxy.faz_requis(request.constroi_requisicao());
				Response response = Response(reply);

				if(response.estado_codigo == "200 OK")
				{
					html[*url]           = response.dado;
					set<string> todosUrl = Parser::analisa_url(response.dado.c_str());
					set<string> url_local;

					for (std::set<string>::iterator it = todosUrl.begin(); it != todosUrl.end(); ++it)
					{
				        if(this->avaliar_url(*it))
				        	url_local.insert(this->parsing_url(*it));

		     		}
				    par[*url] = url_local;
				    for (std::set<string>::iterator it=url_local.begin(); it != url_local.end(); ++it)
				        nextRequest.insert(*it);
				}
			}
		}
		requis_dest = nextRequest;
	 	i--;
	}while(i>=0);
}

std::string Spider::url_nome_arquivo(std::string url_in)
{

	string nomeArquivo("");
	string url = url_in;
	string slash("-");
	vector<string> splitted = Functions_aux::separa(url, "/");
	if(splitted.size()==1 && splitted[0].length()==0)
	{
		nomeArquivo = "root.html";
		return nomeArquivo;
	}
	for(int i = 0; i < splitted.size(); i++)
			nomeArquivo.append(splitted[i]);

	if(nomeArquivo.find(".") > nomeArquivo.length())
		nomeArquivo.append(".html");
	else if(nomeArquivo.find("?") < nomeArquivo.length()){
		int ask  = nomeArquivo.find("?");
		nomeArquivo = nomeArquivo.substr(0,ask);
	}
	return nomeArquivo;
}

void Spider::dump(int niveis)
{
	this->constroi_arvore(niveis);
	set<string> traduzir = urls_vistas;

	mapa_dicionario[raiz] = "index.html";
	traduzir.erase(raiz);

	for(set<string>::iterator it = traduzir.begin(); it != traduzir.end(); ++it)
		mapa_dicionario[*it]=Spider::url_nome_arquivo(*it);

	for(std::map<string,string>::iterator it = html.begin(); it != html.end(); ++it)
    	for(std::map<string,string>::iterator dt = mapa_dicionario.begin(); dt != mapa_dicionario.end(); ++dt)
			{
    		it->second = Functions_aux::replace(it->second,"\'","\"");
    		string from("\"");from.append(dt->first.c_str());from.append("\"");
    		string to("\"");to.append(dt->second.c_str());to.append("\"");
    		it->second = Functions_aux::replace(it->second,from.c_str(),to.c_str());

    		if(nomes.find(dt->second) != nomes.end())
				{
    			string from("\"");from.append(nomes[dt->second].c_str());from.append("\"");
    			string to("\"");to.append(dt->second.c_str());to.append("\"");
    			it->second = Functions_aux::replace(it->second,from.c_str(),to.c_str());
    		}
    }

  string command("rm -rf ");
  command.append(host);
	system(command.c_str());
  command.assign("mkdir ");
  command.append(host);
	system(command.c_str());

   for(std::map<string,string>::iterator it = html.begin(); it != html.end(); ++it)
	{
		cout << "Salvando arquivo: " << mapa_dicionario[it->first] << endl;
    Functions_aux::escreve_file(it->second, host.c_str(), mapa_dicionario[it->first].c_str());
  }
  cout << "Arquivos salvos no diretorio " << host << endl;
  cout << "O arquivo \"index.html\" eh a raiz." << endl;
}

void Spider::mostra_arvore(int niveis)
{

	if(niveis==0)
	{
		cout << "Arvore de urls:"<<endl<<endl;
		cout << raiz << "---> ";

		int qtd_espacos     = raiz.size()+5;
		set<string> nos_filhos = par[raiz];
		for(set<string>::iterator it = nos_filhos.begin(); it != nos_filhos.end(); ++it)
		{
			cout << *it << endl;
			for(int s =0; s < qtd_espacos; s++)
				cout << " ";

		}
		cout << endl;
	}
	else if(niveis == 1)
	{
		cout << "Arvore de urls:"<<endl<<endl;
		cout << raiz << "---> ";

		int qtd_espacos     = raiz.size()+5;
		set<string> nos_filhos = par[raiz];
		set<string> visitado;

		visitado.insert(raiz);

		for(set<string>::iterator it = nos_filhos.begin(); it != nos_filhos.end(); ++it){
			if(visitado.find(*it) == visitado.end())
			{
				visitado.insert(*it);
				cout << *it << "---> ";

				int qtd_espacos2        = qtd_espacos + (*it).size()+5;
				set<string> granfilhos = par[*it];

				for(set<string>::iterator it2 = granfilhos.begin(); it2!=granfilhos.end(); ++it2)
				{
					cout << *it2 << endl;
					for(int k =0; k<qtd_espacos2; k++)
						cout << " ";
				}
			}
			cout << endl;
			for(int k =0; k < qtd_espacos; k++) cout << " ";
		}
		cout << endl;
	}else
	{
		cout << "Erro: arvore muito grande." << endl;
	}
}
