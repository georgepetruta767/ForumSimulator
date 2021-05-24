#pragma once

#include <QWidget>
#include "ui_searchQuestion.h"
#include "service.h"

class searchQuestion : public QWidget, public Observer
{
	Q_OBJECT

public:
	searchQuestion(Service& serv, QWidget *parent = Q_NULLPTR);
	~searchQuestion() {}
	void connect_signals_and_slots();
	void show_matches();

	void update();

private:
	Ui::searchQuestion ui;
	Service& serv;
};
