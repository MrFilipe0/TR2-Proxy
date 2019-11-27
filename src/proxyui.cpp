#include "proxyui.h"
#include "ui_proxyui.h"
#include "servidor_proxy.hpp"
#include "requisicao_proxy.hpp"
#include "resposta_proxy.hpp"
#include "funcoes.hpp"
#include "Spider.hpp"


using namespace std;

/*
Liga os pontos da interface QT. Modulo com objetivo de fazer com que os botoes executem 
suas determinadas funcoes. Exemplo: apertar Response, deve iniciar a execucacao da funcao request
   */
proxyui::proxyui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::proxyui)
{
    ui->setupUi(this);
}

proxyui::~proxyui()
{
    delete ui;
}
void proxyui::startInsp(int porta)
{
    server = Servidor_proxy();

    server.start(porta);
        req = server.constroi_requis_cliente();
        ui->te_request->setPlainText(req.c_str());
        Request request = Request(req);

            Functions_aux::escreve_file(req, ".", "request.txt");
            req                    = Functions_aux::le_file("request.txt");
}

void proxyui::spider(char* url)
{
    Spider spider = Spider(url);
    if(spider.eh_valido)
    {
        string aux;
        spider.constroi_arvore(2);
        aux = " ";
        aux += spider.raiz ;

        int numSpacos     = spider.raiz.size()+5;
        set<string> filhos = spider.par[spider.raiz];
        set<string> vistos; // urls ja visitados

        vistos.insert(spider.raiz);

        for(set<string>::iterator it = filhos.begin(); it != filhos.end(); ++it){
            if(vistos.find(*it) == vistos.end())
            {
                vistos.insert(*it);
                aux+= *it +"---> ";

                int numSpacos2        = numSpacos + (*it).size()+5;
                set<string> granfilhos = spider.par[*it];

                for(set<string>::iterator it2 = granfilhos.begin(); it2!=granfilhos.end(); ++it2)
                {
                    aux += *it2 + "\n";
                    for(int k =0; k<numSpacos2; k++)
                        aux =+ " ";
                }
            }
            aux += "\n";
            for(int k =0; k < numSpacos; k++) aux+= " ";
        }
        aux+= "\n";
        ui->te_spider->setPlainText(aux.c_str());
    }
}

void proxyui::on_pb_spidergo_clicked()
{
    QByteArray ba = ui->le_spider->text().toLocal8Bit();
    char *c_str = (char*)ba.data();
    spider(c_str);
}

void proxyui::on_pb_start_clicked()
{
    startInsp(ui->le_port->text().toInt());
}

void proxyui::on_pb_dump_clicked()
{
    QByteArray ba = ui->le_dump->text().toLocal8Bit();
    char *c_str = (char*)ba.data();
    Spider x = Spider(c_str);
    x.dump(2);
}

void proxyui::on_pb_request_clicked()
{
    string           req = server.constroi_requis_cliente();
    ui->te_request->setPlainText(req.c_str());
    Request request = Request(req);
}

void proxyui::on_pb_response_clicked()
{
    reply           = server.faz_requis(req);
    Response response = Response(reply);

    Functions_aux::escreve_file(reply, ".", "response.txt");
    reply = Functions_aux::le_file("response.txt");
    ui->te_response->setPlainText(reply.c_str());
    server.testa_resp_cliente(reply);
}
