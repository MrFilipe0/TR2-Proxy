#include "Response.hpp"
#include "Functions_aux.hpp"
using namespace std;

Response::Response(std::string stringResponse)
{
    vector<string> string_separada = Functions_aux::separa(stringResponse, "\r\n\r\n");

    if(string_separada.size() < 2)
        string_separada = Functions_aux::separa_antes(stringResponse, "\n\n");

    string header = string_separada[0];
	  data   = string_separada[1];
	  vector<string> linhas_separadas  = Functions_aux::separa(header, "\r\n");
	  string primeiraLinha   = linhas_separadas[0];
	  vector<string> tokem_primeira    = Functions_aux::separa_antes(primeiraLinha, " ");
    
    versao = tokem_primeira[0];
    estado_codigo  = tokem_primeira[1];
    vector<string> temp;

    for(int i = 1; i < linhas_separadas.size(); i++)
    {
         temp = Functions_aux::separa_antes(linhas_separadas[i], " ");
         camp[temp[0]] = temp[1];
    }
};

Response::Response(){};

std::string Response::constroi_resposta()
{
    using  namespace std;
    string Response("");

    Response.append(versao);
    Response.append(" ");
    Response.append(estado_codigo);
    Response.append("\r\n");

    camp["Length:"] = to_string(data.length());

    for (std::map<string,string>::iterator it=camp.begin(); it != camp.end(); ++it)
    {
        Response.append(it->first);
        Response.append(" ");
        Response.append(it->second);
        Response.append("\r\n");
    }
    Response.append("\r\n");
    Response.append(data);
    Response.append("\r\n");
    return Response;
}


void Response::mostra()
{
    cout << "Status: " << estado_codigo << endl;
    cout << "Versao: " << versao << endl;

    for(map<string, string>::iterator it = camp.begin(); it != camp.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
    cout << "dado: " << endl << data <<endl;
}
