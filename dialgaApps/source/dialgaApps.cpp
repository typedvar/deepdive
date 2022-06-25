// dialgaApps.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author: avi

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[])
{
    std::vector<int> input;
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
        {
            input.push_back(std::stoi(argv[i]));
        }
    }

    for (const int& i : input)
    {
        std::cout << i << std::endl;
    }
    return 0;
}

// end of file
