#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QnA.h"
#include "service.h"
#include "Observer.h"

class QnA : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    QnA(Service& serv, User user, QWidget *parent = Q_NULLPTR);
    void populate();
    void connect_signals_and_slots();
    void addAnswer();
    void addQuestion();
    void show_answers_for_clicked_q();

    void update() override;

private:
    Ui::QnAClass ui;
    Service& serv;
    User user;
};
