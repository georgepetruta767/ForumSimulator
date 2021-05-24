#pragma once
#include <vector>
using namespace std;

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	vector<Observer*> observers;

public:
	void add_observer(Observer* observer);
	void remove_observer(Observer* obs);
	void notify();

};
