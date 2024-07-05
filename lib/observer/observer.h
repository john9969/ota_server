#ifndef OBSERVER__H
#define OBSERVER__H
#include <iostream>
#include <list>
#include <mutex>
#include "../tiny-json/tiny-json.h"

class IObserver;

class ISubject {
public:
	virtual uint32_t append(IObserver* observer) = 0;
	virtual uint32_t remove(IObserver* observer) = 0;
	virtual void notifyAll(std::string data, const uint32_t& subId = 0) = 0;
};


class Subject :public ISubject{
private:
	static std::mutex _lock;
	static Subject* _instance;
	std::list<IObserver*> _observers;
public:
	static Subject* getInstance();
	uint32_t append(IObserver* observer)	override;
	uint32_t remove(IObserver* observer) override;
	void notifyAll(std::string data, const uint32_t& subId = 0) override;
};

class IObserver {
public:
	virtual ~IObserver();
	virtual void hasChange(std::string data, const uint32_t& subId) = 0;
};

#endif // !OBSERVER__H