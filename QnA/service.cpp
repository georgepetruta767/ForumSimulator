#include "service.h"

void Service::read()
{
	ifstream users_file{ this->users_file };
	User user;
	while (users_file >> user)
		this->users.push_back(user);

	ifstream answers_fin{ this->answers_file };
	Answer answer;
	while (answers_fin >> answer)
		this->answers.push_back(answer);

	ifstream questions_fin{ this->questions_file };
	Question question;
	while (questions_fin >> question)
		this->questions.push_back(question);

	users_file.close();
	answers_fin.close();
	questions_fin.close();
}

void Service::write()
{
	ofstream questions_fout{ questions_file };
	ofstream answers_fout{ answers_file };
	for (auto q : questions)
		questions_fout << q;
	for (auto a : answers)
		answers_fout << a;
	questions_fout.close();
	answers_fout.close();
}

vector<Question> Service::get_sorted_questions()
{
	vector<int> nrAnswers;
	for (auto q : this->questions)
		nrAnswers.push_back(0);
	
	int i = 0;
	for (auto q : this->questions)
	{	
		for (auto a: this->answers)
			if(a.get_idq() == q.get_id())
				nrAnswers[i]++;
		i++;
	}

	for (int i = 0; i < this->questions.size() - 1; i++)
		for (int j = i + 1; j < this->questions.size(); j++)
			if (nrAnswers[j] > nrAnswers[i])
				swap(questions[i], questions[j]);

	return this->questions;
		
}

Question Service::get_matched_question(string match)
{
	vector<Question> list;
	int max_count = 0;
	Question result{};

	for (auto& q : this->questions)
	{	
		int count_match_parts = 0;
		int min;
		if (q.get_text().size() < match.size())
			min = q.get_text().size();
		else
			min = match.size();
		for (int i = 0; i < min; i++)
		{
			if (q.get_text()[i] == match[i])
				count_match_parts++;
			if (count_match_parts > max_count)
			{
				max_count = count_match_parts;
				result = q;
			}
		}
	}

	return result;
}

vector<Answer> Service::get_3answers(Question q)
{
	vector<Answer> list;
	for (auto a : this->answers)
		if (a.get_idq() == q.get_id())
			list.push_back(a);
	sort(list.begin(), list.end(), [](Answer a1, Answer a2) { return a1.get_nrVotes() > a2.get_nrVotes(); });
	if(list.size() > 3)
		list.erase(list.begin() + 3, list.end());
	return list;
}

vector<Answer> Service::get_allAnswers(Question q)
{
	vector<Answer> list;
	for (auto a : this->answers)
		if (a.get_idq() == q.get_id())
			list.push_back(a);
	return list;
}

void Service::addQuestion(string text, string name)
{
	Question q{ int(this->questions.size()+1), text, name };
	this->questions.push_back(q);
	notify();
	write();
}

void Service::addAnswer(int idq, string text, string name)
{
	Answer a{ int(this->answers.size()+1), idq, text, name, 0};
	this->answers.push_back(a);
	notify();
	write();
}
