#pragma once
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class User
{
private:
	string name;
public:
	User() : name{""} {};
	User(string name) : name{ name } {}
	string get_name() { return this->name; }

	friend istream& operator>>(istream& reader, User& user);
	friend ostream& operator<<(ostream& reader, const User& user);

};

class Question
{
private:
	int id;
	string text;
	string name;
public:
	Question() : id{ 0 }, text{ "" }, name{ "" } {}
	Question(int id, string text, string name) : id{ id }, text{ text }, name{ name } {}

	friend istream& operator>>(istream& reader, Question& user);
	friend ostream& operator<<(ostream& reader, const Question& user);

	string q_to_string();
	string q_to_string_qt();
	int get_id() { return this->id; }
	string get_text() { return this->text; }
};

class Answer
{
private:
	int id;
	int idq;
	string text;
	string name;
	int nrVotes;
public:
	Answer() : id{ 0 }, idq{ 0 }, text{ "" }, name{ "" }, nrVotes{ 0 } {}
	Answer(int id, int idq, string text, string name, int nrVotes) : id{ id }, idq{ idq }, text{ text }, name{ name }, nrVotes{ nrVotes } {}

	friend istream& operator>>(istream& reader, Answer& user);
	friend ostream& operator<<(ostream& reader, const Answer& user);

	int get_idq() { return this->idq; }
	int get_nrVotes() { return this->nrVotes; }
	string a_to_string();
	string a_to_string_qt();
	string get_name() { return this->name; }
};


