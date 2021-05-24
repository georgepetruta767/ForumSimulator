#include "Observer.h"

void Subject::add_observer(Observer* observer)
{
	this->observers.push_back(observer);
}

void Subject::remove_observer(Observer* obs)
{
	auto it = std::find(observers.begin(), observers.end(), obs);
	if (it != observers.end())
		this->observers.erase(it);
}

void Subject::notify()
{
	for (int i = 0; i < observers.size(); i++)
		observers[i]->update();
}
