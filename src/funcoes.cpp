#include "funcoes.hpp"
using namespace std;

vector<string> Functions_aux::separa(string str, const char * limite)
{ // limite eh a variavel que coloca um limite ate onde ira percorrer a string
    vector<string> tokem;
    string os(limite);
    int offset = os.length();

    size_t last_byte = -1*offset;
    size_t achado = str.find(limite, last_byte+offset);
    while(achado < str.length())
    {
        tokem.push_back(str.substr(last_byte+offset, achado - last_byte -offset));
        last_byte = achado;
        achado = str.find(limite, last_byte+offset);
    }
    if((last_byte+offset) < str.length())
        tokem.push_back(str.substr(last_byte+offset, str.length()));

    return tokem;
}
/*separa as strings em tokens, ou seja, filtra apenas as palavras do texto*/
vector<string> Functions_aux::separa_antes(string str, const char * limite)
{
    vector<string> tokem;
    string os(limite);
    int offset = os.length();

    size_t achado = str.find(limite);

    if(achado > (str.length()-offset)){
        tokem.push_back(str);
        tokem.push_back(str);
        return tokem;
    }

    tokem.push_back(str.substr(0, achado));
    tokem.push_back(str.substr(achado+offset, str.length()-offset));

    return tokem;
}

int Functions_aux::escreve_file(string str, const char *path, const char *file)
{

    FILE *f;
    string diretorio("");
    diretorio.append(path); // coloca o caminho do diretorio
    diretorio.append("/");
    diretorio.append(file);
    f = fopen(diretorio.c_str(), "w");
    if(f==NULL)
    {
        printf("ERRO NO PONTEIRO");
        exit(2);
    }
 
    fprintf(f,"%s",str.c_str());
    fclose(f);

    return 0;
}

string Functions_aux::le_file(const char*file)
{

    FILE *f;
    char buffer[64768];
    f = fopen(file, "rb");
    fread (buffer, 1, sizeof(buffer), f);
    fclose(f);

    string res(buffer);
    return res;
}
// faz a troca de uma string com outra string que deseja encontrar 
string Functions_aux::replace(string file, const char*from,const char*to)
{

    string str = file;
    string os(from);
    int size   = os.length();
    int achado = str.find(from);
    while(achado < str.length())
    {
        str.replace(achado, size, to);
        achado = str.find(from);
    }

    return str;
}
