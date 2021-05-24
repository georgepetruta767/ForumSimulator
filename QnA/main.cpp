#include "QnA.h"
#include <QtWidgets/QApplication>
#include "service.h"
#include "searchQuestion.h"

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);
    string users_file = "users.txt";
    string answers_file = "answers.txt";
    string questions_file = "questions.txt";
    Service serv(users_file, answers_file, questions_file);

    vector<User> users = serv.get_users();
    searchQuestion* z = new searchQuestion{ serv };
    serv.add_observer(z);
    z->show();
    for (auto user : users)
    {
        QnA* w = new QnA{ serv, user };
        serv.add_observer(w);
        w->show();
    }
    
    return a.exec();
}
