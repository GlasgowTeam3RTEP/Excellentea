#include "WebThread.h"
#include "LCD.h"
#include <iostream>
#include <chrono>
#include <thread>

WebThread::WebThread() { }

void WebThread::run() {
	
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
}

