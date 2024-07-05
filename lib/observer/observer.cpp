#include "observer.h"

uint32_t Subject::append(IObserver* observer) {
	bool chk = false;
	if (!observer) return -1;
	std::lock_guard<std::mutex> lock(_lock);
	for (auto it : _observers) {
		if (it != observer) continue;
		chk = true;
		break;
	}
	if (!chk) return 0;
	_observers.push_back(observer);
	return 1;
}

uint32_t Subject::remove(IObserver* observer) {
	if (!observer) return -1;
	std::lock_guard<std::mutex> lock(_lock);
	if (_observers.empty()) return 0;
	auto it = std::find(_observers.begin(), _observers.end(), observer);
	if (it == _observers.end()) return 0;
	_observers.erase(it);
	return 1;
}

void Subject::notifyAll(std::string data, const uint32_t & subId) {
	auto it = _observers.begin();
	while (it != _observers.end())
	{
		(*it)->hasChange(data, subId);
		it++;
	}
	
}

Subject* Subject::getInstance() {
	std::lock_guard<std::mutex> lock(_lock);
	if (!_instance) {
		_instance = new Subject();
	}
	return _instance;
}

void IObserver::hasChange(std::string data, const uint32_t& subId) {
	std::cout << "IObserver do nothing" << std::endl;
}
IObserver::~IObserver() {

}
Subject* Subject::_instance = nullptr;
std::mutex Subject::_lock;