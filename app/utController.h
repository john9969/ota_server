#pragma once
#include "../lib/observer/observer.h"
#include "ut_process/utProcess.h"
#include <thread>
#include <mutex>
#include <iostream>
#define MAXIMUM_THREAD 10
class UtController :
    public IObserver
{
public:
    
    void run();
    static UtController* getInstance();
    void hasChange(std::string data, const uint32_t& subId) override;
private:
    std::mutex _lock;
    std::list <std::thread> _listUtProcess;
    uint8_t _numThreadRuning;
    static UtController* _instance;
};

