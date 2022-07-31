#include <iostream>
#include <string>
#include <Windows.h>
#include "DynamicStack.h"
#include "HooksValidator.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    hooksValidator s1;

    string equationFalse = "([ x-y-z} * [x + 2y) - {z + 4x)]";
    string equationTrue = "({x-y-z} * [x + 2y] - (z + 4x))";
    std::cout << equationFalse << '\n';
    std::cout << equationTrue << '\n';
 
    s1.takeInput(equationFalse);


    //DynamicStack<char, 30> s{ ([x-y-z}*[x+2y)-{z+4x)] };



    return 0;
}
