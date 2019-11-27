
#include "servidor_proxy.hpp"
#include "requisicao_proxy.hpp"

int serverFd, socketClient, socketServidor;
struct sockaddr_in endereco;
struct sockaddr_in addr_servidor;
struct sockaddr    addr_cliente;
int                addr_tamanho, pega_valor;
int                opt;
char               buff[64768];


void Servidor_proxy::start(int porta)
{
    if(porta == 0)
    {
        porta = 8228; // Por padrao, como especificado no trabalho, Coloca-se a porta 8228 
    }
	addr_tamanho = sizeof(endereco);
	if((serverFd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
  {
      perror("Ocorreu um erro ao criar o socket");
      exit(EXIT_FAILURE);
  }

  endereco.sin_family      = AF_INET;
  endereco.sin_addr.s_addr = INADDR_ANY;
  endereco.sin_port        = htons(porta);

  if(bind(serverFd, (struct sockaddr *)&endereco,sizeof(endereco)) < 0)
  {
        perror("Ocorreu um erro ao fazer o bind");
        exit(EXIT_FAILURE);
  }
  if(listen(serverFd, 5) < 0)
  {
        perror("Ocorreu um erro ao fazer o listen");
        exit(EXIT_FAILURE);
  }
};


std::string Servidor_proxy::constroi_requis_cliente()
{
    using namespace std;
    char buff[542768];

    bzero((char *) &buff, sizeof(buff));

    if((socketClient = accept(serverFd, (struct sockaddr *)&endereco, (socklen_t*)&addr_tamanho)) < 0)
    {
        perror("Ocorreu um erro ao aceitar conexões");
        exit(EXIT_FAILURE);
    }

    cout << "Conexao feita com sucesso!" << endl;
    int num = read(socketClient , buff, sizeof(buff));

    if(num > 0)
		{
        string req(buff);
        Request request = Request(req);
        request.tratar_conexao();
        return request.constroi_requisicao();
    }

    Request request = Request();
    request.procedimento       = "POST";

    return request.constroi_requisicao();
}

std::string Servidor_proxy::faz_requis(std::string req)
{
    using namespace    std;
    struct hostent     *requis_host;
    struct sockaddr_in addr_servidor;
    string             request = req;

    if((socketServidor = socket(AF_INET,SOCK_STREAM,0)) < 0);

    Request reqst = Request(request);
    string host        = reqst.camp["Host:"];
              requis_host = gethostbyname(host.c_str());

    if((requis_host == NULL) || (requis_host->h_addr == NULL))
		{
        std::cout << "Erro ao recuperar informacoes DNS: " <<  host << std::endl;
        exit(1);
    }

    addr_servidor.sin_family = AF_INET;
    addr_servidor.sin_port  = htons(80);

    memcpy(&addr_servidor.sin_addr.s_addr,requis_host->h_addr,sizeof(requis_host->h_addr));

    if(connect(socketServidor,(struct sockaddr *)&addr_servidor,sizeof(addr_servidor)) < 0);

    send(socketServidor, request.c_str(), request.length(), 0);

    char buff[1];
    pega_valor = read(socketServidor, &buff, sizeof(buff));
    string reply(buff);
    pega_valor = read(socketServidor, &buff, sizeof(buff));

		while(pega_valor > 0)
		{
        reply.append(buff);
        pega_valor = read(socketServidor, &buff, sizeof(buff));  
    }
    return reply;
}

void Servidor_proxy::testa_resp_cliente(std::string reply)
{
    if(send(socketClient, reply.c_str(), reply.length(), 0) < 0)
		{
        perror("Ocorreu um erro ao responder o browser");
        exit(EXIT_FAILURE);
    }
    close(socketClient);
}
