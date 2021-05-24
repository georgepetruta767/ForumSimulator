#include "QnA.h"

QnA::QnA(Service& serv, User user, QWidget* parent) : serv{ serv }, user{ user }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(user.get_name()));
    populate();
    connect_signals_and_slots();
}

void QnA::populate()
{
    this->ui.listQuestions->clear();

    for (auto q : this->serv.get_sorted_questions())
        this->ui.listQuestions->addItem(QString::fromStdString(q.q_to_string_qt()));
}

void QnA::connect_signals_and_slots()
{
    connect(ui.questionButton, &QPushButton::clicked, this, &QnA::addQuestion);
    connect(ui.answerButton, &QPushButton::clicked, this, &QnA::addAnswer);
    connect(this->ui.listQuestions, &QListWidget::itemSelectionChanged, this, [this]() {this->show_answers_for_clicked_q(); });
}

void QnA::addAnswer()
{
    int index = ui.listQuestions->currentIndex().row();
    string text = this->ui.lineEdit->text().toStdString();
    Question q = this->serv.get_sorted_questions()[index];
    this->serv.addAnswer(q.get_id(), text, this->user.get_name());
    this->populate();
}

void QnA::addQuestion()
{
    string text = this->ui.addQ_lineEdit->text().toStdString();
    this->serv.addQuestion(text, this->user.get_name());
    this->populate();
}

void QnA::show_answers_for_clicked_q()
{   
    this->ui.answersList->clear();
    int index = ui.listQuestions->currentIndex().row();
    Question q = this->serv.get_sorted_questions()[index];
    int i = 0;
    for (auto a : this->serv.get_allAnswers(q))
    {
        this->ui.answersList->addItem(QString::fromStdString(a.a_to_string_qt()));
        if (a.get_name() == this->user.get_name())
            this->ui.answersList->item(i)->setBackgroundColor(QColor(Qt::yellow));
        i++;
    }
}

void QnA::update()
{
    this->populate();
}

