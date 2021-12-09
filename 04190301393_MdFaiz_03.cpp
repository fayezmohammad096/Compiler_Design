
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

int main()
{

    std::ifstream file("mid_input_03.txt");

    std::string strRegEx;
    std::getline(file, strRegEx);
    stringstream temporary_RegEx(strRegEx);

    int numberOfRegEx = 0;
    temporary_RegEx >> numberOfRegEx;
    std::string arrayREx[numberOfRegEx];

    int i = 0;
    while (i < numberOfRegEx)
    {

        std::string temporary_RegEx;
        std::getline(file, temporary_RegEx);
        arrayREx[i] = temporary_RegEx;

        i++;
    }

    // Handling the Input Lines

    std::string strInputLine;
    std::getline(file, strInputLine);
    stringstream temporary_InputLine(strInputLine);

    int numberOfInputLine = 0;
    temporary_InputLine >> numberOfInputLine;
    std::string arrayInputLine[numberOfInputLine];

    for (int i = 0; i < numberOfInputLine; ++i)
    {
        std::string temporary_InputLine;
        std::getline(file, temporary_InputLine);
        arrayInputLine[i] = temporary_InputLine;
    }

    for (int i = 0; i < numberOfInputLine; ++i)//5
    {
        int flag = 0;

        for (int j = 0; j < numberOfRegEx; ++j)//3
        {
            if (regex_match(arrayInputLine[i], regex(arrayREx[j])))
            {
                flag++;
                cout << arrayREx[j] << "  Matched  " << flag << " string(s)." << endl;
            }
        }
    }
}
