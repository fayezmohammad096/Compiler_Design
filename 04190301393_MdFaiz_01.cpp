#include <bits/stdc++.h> //included all headerfile into a file
//#include <string.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include<fstream>

using namespace std;

int isKeyword(std::string temp)
{

    std::string keyInput[32] = {"auto", "break", "case", "char", "const", "continue", "default",
                                "do", "double", "else", "enum", "extern", "float", "for", "goto",
                                "if", "int", "long", "register", "return", "short", "signed",
                                "sizeof", "static", "struct", "switch", "typedef", "union",
                                "unsigned", "void", "volatile", "while"};

    int result = 0;

    for (int i = 0; i < 32; i++)
    {
        if (keyInput[i] == temp)
        {
            result = 1;
        }
    }

    return result;
}

int main()
{
    char ch, s_temp[15], b[30], logical_op[] = "<>", math_op[] = "+-*/=", numeric[] = "0123456789.", other[] = ",;\(){}[]'':";

    //geting infromation from txt file used reading mode
    ifstream My_file;
    My_file.open("mid_input_01.txt");

    int i, j = 0, kw = 0, idtfr = 0, log_op = 0, ma_op = 0, numc_op = 0, other_op = 0, aaa = 0, Value[1000] = {0};

    vector<string> keyOutput; // vector <datatype> vec_name;
    vector<char> idOutput;
    vector<char> logOpOutput;
    vector<char> mathOpOutput;
    vector<string> numValuesOutput;
    vector<char> othersOutput;

    if (!My_file.is_open())
    {
        cout << "Cant't open file !" << endl;
        exit(0);
    }

    while (!My_file.eof())
    {
        ch = My_file.get();
        for (i = 0; i < 12; ++i)
        {
            if (ch == other[i])
            {
                int aa = ch;
                if (Value[aa] != 1)
                {
                    othersOutput.push_back(ch);
                    Value[aa] = 1;
                    ++other_op;
                }
            }
        }

        for (i = 0; i < 5; ++i)
        {
            if (ch == math_op[i])
            {
                int aa = ch;
                if (Value[aa] != 1)
                {
                    mathOpOutput.push_back(ch);
                    Value[aa] = 1;
                    ++ma_op;
                }
            }
        }
        for (i = 0; i < 2; ++i)
        {
            if (ch == logical_op[i])
            {
                int aa = ch;
                if (Value[aa] != 1)
                {
                    logOpOutput.push_back(ch);
                    Value[aa] = 1;
                    ++log_op;
                }
            }
        }
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.' || ch == ' ' || ch == '\n' || ch == ';')
        {

            if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == '.')
                b[aaa++] = ch;
            if ((ch == ' ' || ch == '\n' || ch == ';') && (aaa != 0))
            {
                b[aaa] = '\0';
                aaa = 0;
                char array[30];
                strcpy(array, b);
                numValuesOutput.push_back(array);
                ++numc_op;
            }
        }

        if (isalnum(ch))
        {
            s_temp[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
        {
            s_temp[j] = '\0';
            j = 0;

            if (isKeyword(s_temp) == 1)
            {

                keyOutput.push_back(s_temp);
                ++kw;
            }
            else
            {

                if (s_temp[0] >= 97 && s_temp[0] <= 122)
                {
                    if (Value[s_temp[0] - 'a'] != 1)
                    {
                        idOutput.push_back(s_temp[0]);
                        ++idtfr;
                        Value[s_temp[0] - 'a'] = 1;
                    }
                }
            }
        }
    }

    My_file.close(); //close file
    //printing scope start...

    int count_k = 0, count_i = 0, count_m = 0, count_l = 0, count_n = 0, count_o = 0;
    cout << "Keywords + Identifiers : ";
    for (int f = 0; f < kw; ++f)
    {
        if (f == kw - 1)
        {

            count_k++;
        }
        else
        {

            count_k++;
        }
    }

    for (int f = 0; f < idtfr; ++f)
    {
        if (f == idtfr - 1)
        {

            count_i++;
        }
        else
        {

            count_i++;
        }
    }
    cout << count_k << " + " << count_i << endl;

    cout << "Math + Logical Operators : ";

    for (int f = 0; f < ma_op; ++f)
    {
        if (f == ma_op - 1)
        {

            count_m++;
        }
        else
        {

            count_m++;
        }
    }

    for (int f = 0; f < log_op; ++f)
    {
        if (f == log_op - 1)
        {

            count_l++;
        }
        else
        {

            count_l++;
        }
    }
    cout << count_m << " + " << count_l << endl;

    cout << "Numerical + Others Values : ";

    for (int f = 0; f < numc_op; ++f)
    {
        if (f == numc_op - 1)
        {

            count_n++;
        }
        else
        {

            count_n++;
        }
    }
    cout << "Others: ";
    for (int f = 0; f < other_op; ++f)
    {
        if (f == other_op - 1)
        {

            count_o++;
        }
        else
        {

            count_o++;
        }
    }
    cout << count_n << " + " << count_o << endl;

    return 0;
}
