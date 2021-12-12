#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

// Funtion proto_type declare here
int xvalue(std::string x);
int yvalue(std::string x);

int main()
{
    std::string str, tmp;
    std::vector<std::string> start;
    std::vector<std::vector<std::string>> table;
    std::ifstream file("q3_string_input.txt");
    while (std::getline(file, str))
    {
        start.push_back(str);
    }

    std::ifstream file2("q3_parsing_table.txt"); // input parsing_table modifieded (change:ε->"epsilon")

    while (std::getline(file2, str))
    {
        std::vector<std::string> row;
        std::istringstream iss(str);
        while (iss >> tmp)
            row.push_back(tmp);
        table.push_back(row);
    }
    std::stack<std::string> stk;
    stk.push("$");
    stk.push(start[1]);
    std::string a = start[0];
    std::queue<std::string> input;
    for (int i = 0; i < (int)a.size(); i++)
    {
        std::string b;
        if (a[i] == 'i')
        {
            b += a[i++];
            b += a[i];
        }
        else
        {
            b += a[i];
        }
        input.push(b);
        b = "";
    }

    do
    {
        std::string x = stk.top();
        std::string y = input.front();
        int xv = xvalue(x);
        int yv = yvalue(y);

        if (x == y)
        {
            stk.pop();
            input.pop();
        }
        else if (table[xv][yv] != "epsilon")
        {
            std::cout << stk.top() << " -> " << table[xv][yv] << std::endl;
            stk.pop();
            std::string rule = table[xv][yv];
            for (int i = (int)rule.size() - 1; i >= 0; i--)
            {
                std::string temp;
                if (rule[i] == '\'')
                {
                    i--;
                    temp += rule[i];
                    temp += '\'';
                    stk.push(temp);
                }
                else if (rule[i] == 'd')
                {
                    i--;
                    temp += rule[i];
                    temp += 'd';
                    stk.push(temp);
                }
                else
                {
                    temp += rule[i];
                    stk.push(temp);
                }
                temp = "";
            }
        }
        else
        {
            std::cout << stk.top() << " -> " << table[xv][yv] << std::endl;
            stk.pop();
        }

    }

    while (stk.top() != "$");
    return 0;
}
int xvalue(std::string x)
{
    std::string s[5] = {"E", "E'", "T", "T'", "F"};
    int i;
    for (i = 0; i < 5; i++)
    {
        if (s[i] == x)
            break;
    }
    return i;
}

int yvalue(std::string x)
{
    std::string s[6] = {"id", "+", "*", "(", ")", "$"};
    int i;
    for (i = 0; i < 6; i++)
    {
        if (s[i] == x)
            break;
    }
    return (i + 1);
}
