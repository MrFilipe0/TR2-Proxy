#include "analises.hpp"
/*
std :: regex_token_iterator é um ForwardIterator somente leitura que acessa as correspondências
 individuais de cada correspondência de uma expressão regular dentro da sequência de caracteres subjacente.
 Também pode ser usado para acessar as partes da sequência que não foram correspondidas pela expressão 
 regular especificada (por exemplo, como um tokenizador).
*/

/*
pega funcao hmtl , url , src
*/
std::set<std::string> Parser::analisa_url(const char *body)
{
    using       namespace std;
    string      str(body);
    set<string> urls;
    try // verifica erro na referencia
    {
        regex r("href=\"(.*?)\"", regex_constants::icase);
        urls = {sregex_token_iterator(str.begin(), str.end(), r, 1), sregex_token_iterator{}};
    }catch (...){;
    }
    return urls;
}

std::string Parser::analisa_html(const char *data)
{
    using  namespace std;
    string str(data);
    int    origem = str.find("<!DOCTYPE");

    if(origem > str.length())
       int origem =str.find("<html");

    int dest = str.find("</html>");

    if(origem>=str.length())
        return str;

    if(dest>=str.length())
        return str.substr(origem, str.length()-origem);

    return str.substr(origem, dest-origem+7);
}

// procura pelo diretorio
std::set<std::string> Parser::analisa_emissor(const char *body)
{
    using namespace std;
    string          str(body);
    set<string>     sources;
    try
    {
        regex r("src=\"(.*?)\"", regex_constants::icase);
        sources = {sregex_token_iterator(str.begin(), str.end(), r, 1), sregex_token_iterator{}};
    }catch(...){;
    }
    return sources;
}

// busca pela o endereco do site (url)
std::set<std::string> Parser::analisa_import(const char *body)
{
    using namespace std;
    string          str(body);
    set<string>     imports;
    try
    {
        regex r("url(\"(.*?)\"", regex_constants::icase);
        imports = {sregex_token_iterator(str.begin(), str.end(), r, 1), sregex_token_iterator{}};
    }catch(...){;
    }
    return imports;
}
