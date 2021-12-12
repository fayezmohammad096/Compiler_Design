#include <bits/stdc++.h>

int main()
{
    std::ifstream file("input.txt"); 
    std::string str;                 

    while (getline(file, str))
    {
        std::string datatype; 
        int paramCount = 1;

        if (str.find('{') != std::string::npos)
        {
            std::stringstream sso(str);
            sso >> datatype;
            

            for (int i = datatype.size() + 1; i < str.find('('); i++)
            {
                std::cout << str[i];
            }

            for (int i = datatype.size() + 1; i < str.find('{'); i++)
            {
                if (str[i] == ',')
                {
                    paramCount++;
                }
              

                if (str[i] == ')' && str[i - 1] == '(')
                {
                    std::cout << "()";
                    paramCount = 0;
                    break;
                }
            }

            std::cout << " : " << paramCount << " parameter(s)." << std::endl;
        }
    }

    return 0;
}