#include<iostream>
using namespace std;

class Logger {
public:
	static Logger* get_instance() {
		if (instance == nullptr) {
			instance = new Logger;
			return instance;
		}
		return instance;
	}

	void log_validation() {
		cout << "log instance created, validation successful" << endl;
	}

private:
	static Logger* instance;
	Logger() {}
	// copy constructor 
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
};

Logger* Logger::instance = nullptr;

int main() {
	Logger* logger1 = Logger::get_instance();
	logger1->log_validation();
	Logger* logger2 = Logger::get_instance();
	Logger* logger3 = Logger::get_instance();
	if (logger1 == logger2 && logger2 == logger3) {
		cout << "all the logger objects are same" << endl;
	}
	else {
		cout << "logger objects are different" << endl;
	}
	return 0;
}
