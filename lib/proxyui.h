#ifndef PROXYUI_H
#define PROXYUI_H

#include <QMainWindow>
#include "servidor_proxy.hpp"

namespace Ui {
class proxyui;
}

class proxyui : public QMainWindow
{
    Q_OBJECT

public:
    explicit proxyui(QWidget *parent = 0);
    ~proxyui();

private slots:
    void on_pb_spidergo_clicked();

    void on_pb_start_clicked();

    void on_pb_dump_clicked();

    void on_pb_request_clicked();

    void on_pb_response_clicked();

private:
    Ui::proxyui *ui;
    void startInsp(int);
        void spider(char*);
        Servidor_proxy server;
        std::string           req;
        std::string           reply;
};

#endif // PROXYUI_H