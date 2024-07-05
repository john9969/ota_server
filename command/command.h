#ifndef COMMANND__H
#define COMMAND__H

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

#include "../lib/observer/observer.h"
#define MAXIMUM_FW_INFO 20
typedef const uint32_t CommandModule;
CommandModule CommandModuleFindChange = 0;
CommandModule CommandModuleFindChangeDirCode = 1;
CommandModule CommandModuleFindChangeComment = 2;
CommandModule CommandModuleFindChangeDirFileChange = 3;
CommandModule CommandModuleShowStatus = 1;
class Command :public Subject{
public:

	uint32_t parse(const std::string& data);
	bool isAvailable(std::string& data);
	void run();
private:
	int32_t getValueText(std::string data, std::string key, std::string& value);
	int32_t getValueInterger(std::string data, std::string key, int& value);
	std::string _dataInput;
	
	bool hasNewData;
	std::mutex _lock;
};

#endif // !COMMANND__H
