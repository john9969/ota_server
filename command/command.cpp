#include "command.h"
#include <algorithm>
#include <cctype>
#include <chrono>
void Command::run() {
	
	std::lock_guard<std::mutex> lock(_lock);
	if (!isAvailable(_dataInput)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		return;
	}
	if (!parse(_dataInput)) {
		std::cout << "wrong form" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		return;
	}
	//find and process command

}
//{"control": 1, "create_file": 1 }

//createfile()
uint32_t Command::parse(const std::string& data) {
	std::string command = "";
	if (getValueText(data, "command", command) <= 0) {
		std::cout << "can not find comamnd in data" << std::endl;
		return -1;
	}
	if (command == "read_ut") {
		std::string output = "";
		if (getValueText(data, "comment", output) >0)
			notifyAll(output, CommandModuleFindChangeComment);
		if (getValueText(data, "dirCode", output) > 0)
			notifyAll(output, CommandModuleFindChangeDirCode);
		if (getValueText(data, "dirFileChange", output) > 0)
			notifyAll(output, CommandModuleFindChangeDirFileChange);
		return 1;
	}
	else if (command == "update_status") {

	}
	return 0;
}
bool Command::isAvailable(std::string& data) {
	if (std::getline(std::cin, data)) {
		auto it = data.begin();
		while (it != data.end() && (std::isspace(*it) || *it == '\n' || *it == '\r')) {
			it++;
		}
		return true;
	}
	return false;
}
int32_t Command::getValueText(std::string data, std::string key, std::string& value) {
	return 0;
}
int32_t Command::getValueInterger(std::string data, std::string key, int& value) {
	return 0;
}
