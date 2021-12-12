#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cmath>
#include <regex>



int main()
{
    double f_init = 1.00, f_out1 = 0, f_out2 = 0, f_out3 = 0;
    std::ifstream file("input.txt");
    std::string s;
    while (std::getline(file, s))
    {
        std::vector<std::string> split;
        std::string str_word;
        std::stringstream stringstream_input(s);

        while (std::getline(stringstream_input, str_word, ' '))// --A--B--
        {
            split.push_back(str_word);
            
        }

        if (split[1] == "/")
        {
            if (std::regex_match(split[0], std::regex("[0-9]+")) && std::regex_match(split[2], std::regex("[0-9]+")))
            {
                int num1, num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out3 = (num1 / num2) * f_out2;
                std::cout << "Initial : " << num1 / num2 << ". Final : " << f_out3;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+")) && std::regex_match(split[2], std::regex("[0-9]+.[0-9]*")))
            {
                int num1;
                double num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                
                f_out3 = (num1 / num2) * f_out2;
                std::cout << "Initial : " << num1 / num2 << ". Final : " <<f_out3;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+.[0-9]*")) && std::regex_match(split[2], std::regex("[0-9]+.[0-9]*")))
            {
                double num1, num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out3 = (num1 / num2) * f_out2;
                std::cout << "Initial : " << num1 / num2 << ". Final : " << f_out3;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+.[0-9]*")) && std::regex_match(split[2], std::regex("[0-9]+")))
            {
                double num1;//6.2
                int num2;//3
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
               
                f_out3 = num1/num2 *f_out2;
                std::cout << "Initial : " << num1 / num2 << ". Final : " <<f_out3<<std::endl;
               
            }
        }

        if (split[1] == "*")
        {
            if (std::regex_match(split[0], std::regex("[0-9]+")) && std::regex_match(split[2], std::regex("[0-9]+")))
            {
                int num1, num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out2 = num1 * num2 * f_out1;
                std::cout << "Initial : " << num1 * num2 << ". Final : " << f_out2 << std::endl;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+")) && std::regex_match(split[2], std::regex("[0-9]+.[0-9]*")))
            {
                int num1;
                double num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out2 = num1 * num2 * f_out1;
                std::cout << "Initial : " << num1 * num2 << ". Final : " << f_out2 << std::endl;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+.[0-9]*")) && std::regex_match(split[2], std::regex("[0-9]+.[0-9]*")))
            {
                double num1, num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out2 = num1 * num2 * f_out1;
                std::cout << "Initial : " << num1 * num2 << ". Final : " << f_out2 << std::endl;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+.[0-9]*")) && std::regex_match(split[2], std::regex("[0-9]+")))
            {
                double num1;
                int num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out2 = num1 * num2 * f_out1;
                std::cout << "Initial : " << num1 * num2 << ". Final : " << f_out2 << std::endl;
            }
        }

        if (split[1] == "+")
        {

            if (std::regex_match(split[0], std::regex("[0-9]+")) && std::regex_match(split[2], std::regex("[0-9]+")))
            {
                int num1, num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out1 = (num1 + num2) * f_init;
                std::cout << "Initial : " << (num1 + num2) << ". Final : " << f_out1 << std::endl;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+")) && std::regex_match(split[2], std::regex("[0-9]+.[0-9]*")))
            {
                int num1;
                double num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out1 = (num1 + num2) * f_init;
                std::cout << "Initial : " << (num1 + num2) << ". Final : " << f_out1 << std::endl;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+.[0-9]*")) && std::regex_match(split[2], std::regex("[0-9]+.[0-9]*")))
            {
                double num1, num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out1 = (num1 + num2) * f_init;
                std::cout << "Initial : " << (num1 + num2) << ". Final : " << f_out1 << std::endl;
            }

            if (std::regex_match(split[0], std::regex("[0-9]+.[0-9]*")) && std::regex_match(split[2], std::regex("[0-9]+")))
            {
                double num1;
                int num2;
                std::stringstream number1(split[0]);
                number1 >> num1;
                std::stringstream number2(split[2]);
                number2 >> num2;
                f_out1 = (num1 + num2) * f_init;
                std::cout << "Initial : " << (num1 + num2) << ". Final : " << f_out1 << std::endl;
            }
        }

        
    }

    return 0;
}
