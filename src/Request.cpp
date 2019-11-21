#include "Request.hpp"
#include "Functions_aux.hpp"

using namespace std;


Request::Request(std::string requestString)
{
    vector<string> requis_separada = Functions_aux::separa(requestString, "\r\n\r\n");
    string header  = requis_separada[0];

    if(requis_separada.size()>1)
        body = requis_separada[1];

    vector<string> linhas  = Functions_aux::separa(header, "\r\n");
    string primeiraLinha = linhas[0];
    vector<string> tokem_primeira = Functions_aux::separa(primeiraLinha, " ");

    procedimento = tokem_primeira[0];
    url    = tokem_primeira[1];
    versao = tokem_primeira[2];

    vector<string> aux;

    for( int i = 1; i<linhas.size(); i++)
    {
         aux = Functions_aux::separa_antes(linhas[i], " ");
         camp[aux[0]] = aux[1];
    }
};

Request::Request()
{
    procedimento = "GET";
    versao = "HTTP/1.1";
    url    = "";
    body  = "";
};

std::string Request::constroi_requisicao()
{
    using namespace std;
    string Request("");

    Request.append(procedimento);
    Request.append(" ");
    Request.append(url);
    Request.append(" ");
    Request.append(versao);
    Request.append("\r\n");

    for (std::map<string,string>::iterator it=camp.begin(); it!=camp.end(); ++it)
    {
        Request.append(it->first);
        Request.append(" ");
        Request.append(it->second);
        Request.append("\r\n");
    }
    Request.append("\r\n");
    Request.append(body);

    return Request;
}

void Request::mostra()
{
    cout << "metodo: " << procedimento << endl;
    cout << "versao: " << versao << endl;
    cout << "url: " << url << endl;

    for(map<string, string>::iterator it = camp.begin(); it!=camp.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << "corpo: " << body << endl<<endl;

}

void Request::tratar_conexao()
{
    camp["Connection:"]      = "close";
    camp["Accept-Encoding:"] = "identity";
}

bool Request::analisa_metodo()
{
    if( procedimento != "GET") return false;
    return true;
}
