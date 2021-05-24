#include "searchQuestion.h"

searchQuestion::searchQuestion(Service& serv, QWidget* parent) : serv{ serv }, QWidget(parent)
{
	ui.setupUi(this);
	connect_signals_and_slots();
}

void searchQuestion::connect_signals_and_slots()
{
	connect(ui.lineEdit, &QLineEdit::textChanged, this, &searchQuestion::show_matches);
}

void searchQuestion::show_matches()
{	
	this->ui.listWidget->clear();
	string to_search = this->ui.lineEdit->text().toStdString();
	Question q = this->serv.get_matched_question(to_search);
	this->ui.listWidget->addItem(QString::fromStdString(q.q_to_string()));

	for (auto a : this->serv.get_3answers(q))
		this->ui.listWidget->addItem(QString::fromStdString("      " + a.a_to_string()));
}

void searchQuestion::update()
{
	show_matches();
}
