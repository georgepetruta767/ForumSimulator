#include "domain.h"

istream& operator>>(std::istream& reader, User& user)
{
    string line;
    getline(reader, line);
    if (line.empty())
        return reader;

    user.name = line;
    return reader;
}

std::ostream& operator<<(std::ostream& writer, const User& user) 
{
    writer << user.name << "\n";
    return writer;
}

istream& operator>>(istream& reader, Question& question)
{
    string line;
    getline(reader, line);
    if (line.empty())
        return reader;

    stringstream stream(line);
    string id, text, name;
    getline(stream, id, ',');
    getline(stream, text, ',');
    getline(stream, name, ',');

    question.id = stoi(id);
    question.text = text;
    question.name = name;

    return reader;
}

ostream& operator<<(ostream& writer, const Question& q)
{
    writer << q.id << "," << q.text << "," << q.name << "\n";
    return writer;
}

istream& operator>>(istream& reader, Answer& answer)
{
    string line;
    getline(reader, line);
    if (line.empty())
        return reader;

    stringstream stream(line);
    string id, idq, text, name, nrVotes;
    getline(stream, id, ',');
    getline(stream, idq, ',');
    getline(stream, text, ',');
    getline(stream, name, ',');
    getline(stream, nrVotes, ',');

    answer.id = stoi(id);
    answer.idq = stoi(idq);
    answer.text = text;
    answer.name = name;
    answer.nrVotes = stoi(nrVotes);

    return reader;
}

ostream& operator<<(ostream& writer, const Answer& a)
{
    writer << a.id << "," << a.idq << "," << a.text << "," << a.name << ","<< a.nrVotes<< "\n";
    return writer;
}

string Question::q_to_string()
{   
    string to_return="";
    to_return += to_string(this->id) + " - ";
    to_return += this->text + " - ";
    to_return += this->name;
    return to_return;
}

string Question::q_to_string_qt()
{
    string to_return = "Q:";
    to_return += this->text + "  Posted by:";
    to_return += this->name;
    return to_return;
}

string Answer::a_to_string()
{
    string to_return = "";
    to_return += to_string(this->id) + " - ";
    to_return += to_string(this->idq) + " - ";
    to_return += this->text + " - ";
    to_return += this->name + " - ";
    to_return += to_string(this->nrVotes);
    return to_return;
}

string Answer::a_to_string_qt() {
    string to_return = "A:";
    to_return += this->text + "  Posted by:";
    to_return += this->name + "  Nr.of votes:";
    to_return += to_string(this->nrVotes);
    return to_return;
}
