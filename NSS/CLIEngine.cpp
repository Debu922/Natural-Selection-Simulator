#include "CLIEngine.h"

#include <iostream>
#include <string>
#include <sstream>

bool verifyUserAction(std::string input);

std::string fetchLine(std::string message = "")
{
    if (message != "")
        std::cout << message << "\n";
    for (std::string line; std::cout << "NSS > " && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == "exit")
            {
                if (verifyUserAction("termination?"))
                    exit(-1);
                else
                    continue;
            }
            if (line == "?")
            {
                std::cout << message << "\n";
                continue;
            }
            return line;
        }
    }
    return "";
}

bool verifyUserAction(std::string input)
{
    std::cout << "Accept " << input << " (y/n)\n";
    char x = fetchLine()[0];
    while (x != 'y' && x != 'Y' && x != 'n' && x != 'N')
    {
        std::cout << "Please enter valid char.\n";
        x = fetchLine()[0];
    }
    if (x == 'y' || x == 'Y')
        return true;
    else
        return false;

}

void CLIEngine::process(std::string l)
{
    //std::cout<<l<<"\n";
    if (l == "exit")
    {
        flag = false;
    }
    if (l == "start")
    {
        std::cout << "Starting the simulator.\n";
        //main
    }
    else;
}

int CLIEngine::getUserInputI(std::string message)
{
    bool flag = false;
    int x;
    while (!flag)
    {
        std::istringstream temp(fetchLine(message));
        temp >> x;
        flag = verifyUserAction(std::to_string(x));
    }
    return x;
}
double CLIEngine::getUserInputD(std::string message)
{
    bool flag = false;
    double x;
    while (!flag)
    {
        std::istringstream temp(fetchLine(message));
        temp >> x;
        flag = verifyUserAction(std::to_string(x));
    }
    return x;
}

char CLIEngine::getUserInputC(std::string message)
{
    return 0;
}
