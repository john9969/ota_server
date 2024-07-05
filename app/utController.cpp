#include "utController.h"
UtController* UtController::getInstance() {

}
void UtController::run() {
{
	std::lock_guard<std::mutex> lock(_lock);
	if (_numThreadRuning > 0 && _numThreadRuning < MAXIMUM_THREAD) {
		std::unique_ptr<UtProcess> it = std::make_unique<UtProcess>();
		std::thread p_thread = std::thread(it);
		_listUtProcess.push_back(p_thread);
		_numThreadRuning--;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}