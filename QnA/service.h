#pragma once
#include "domain.h"
#include <algorithm>
#include "Observer.h"

class Service: public Subject
{
private:
	vector<User> users;
	vector<Answer> answers;
	vector<Question> questions;
	string users_file;
	string answers_file;
	string questions_file;

public:
	Service(string users_file, string answers_file, string questions_file) : users_file{ users_file }, answers_file{ answers_file }, questions_file{ questions_file } {this->read(); }
	void read();
	void write();

	vector<User> get_users() { return this->users; }
	vector<Answer> get_answers() { return this->answers; }
	vector<Question> get_sorted_questions();
	Question get_matched_question(string match);
	vector<Answer> get_3answers(Question q);
	vector<Answer> get_allAnswers(Question q);
	void addQuestion(string text, string name);
	void addAnswer(int idq, string text, string name);
};

