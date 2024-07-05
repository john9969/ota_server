#pragma once
#include <string>
#include <list>
class UtProcess
{
private:
	std::string _dirCode;
	std::string _dirFileChange;
	std::string _diffFileChange;
	uint32_t _index;
public:
	void run();
	int32_t getTotalUtNum(const std::string& dirFolderUt,uint32_t& totalUtNum);
	int32_t getContent(
		const std::string& dirFile, 
		const std::string& comment, 
		std::list < std::pair<uint32_t, std::string>>& data);
	int32_t cutFile(const std::string& dirFile, std::string& data);
	int32_t writeFileOutput(const std::string& dirFileChange,
		std::list < std::pair<uint32_t, std::string>>& data);

};

