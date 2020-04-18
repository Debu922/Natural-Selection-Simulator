#pragma once
#include <string>
class CLIEngine
{
private:
protected:
	bool flag;
public:
	void start();
	void end();
	void process(std::string);
	int getUserInputI(std::string);
	double getUserInputD(std::string);
	char getUserInputC(std::string);
};

