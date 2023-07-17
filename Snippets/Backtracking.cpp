#include <iostream>
#include <string>

/*
* Generate all combinations (binary) by a given length
*/
void printAllBin(int len);
void printAllBinHelper(std::string str, int len);

void printAllBin(int len)
{
    for(int i = 1; i <= len; i++)
    {
        printAllBinHelper("", i);
    }
}

void printAllBinHelper(std::string str, int len)
{
    if(str.length() == len)
    {
        std::cout << str << std::endl;
        return;
    }
    std::string opt1 = str + "1";
    std::string opt2 = str + "0";
    printAllBinHelper(opt1, len);
    printAllBinHelper(opt2, len);

}

/*
* Generate all combination (USC) given a length
*/
void printAllUSC(int len);
void printAllUSCHelp(std::string str, int len, std::string& choice);

void printAllUSC(int len)
{
    std::string choice = "USC";
    printAllUSCHelp("", len, choice);
}

void printAllUSCHelp(std::string str, int len, std::string& option)
{
    if(len == str.length())
    {
        std::cout << str << std::endl;
        return;
    }
    //! for-loop loop through choices
    for(char c : option)
    {
        printAllUSCHelp(str + c, len, option);
    }
}

/*
* Generate all combination (USC) with two U in a row
*/
void printUSCRes(int len);
void printUSCResHelp(std::string str, int len, std::string& choice);

void printUSCRes(int len)
{
    std::string choice = "USC";
    printUSCResHelp("", len, choice);
}

void printUSCResHelp(std::string str, int len, std::string& choice)
{
    if(str.length() == len)
    {
        std::cout << str << std::endl;
        return;
    }
    for(char c : choice)
    {
        if(!(c == 'U' && str[str.length()-1] == 'U'))
        {

        }
        else
        {
            printUSCResHelp(str + c, len, choice);
        }
    }
}

/************************main function for compilation*****************************/
int main()
{
    //printAllBin(3);
    // printALLUSC(3);
    //printUSCRes(3);

    return 0;
}