#include <iostream>
#include <string>
#include <Windows.h>
#include "DynamicStack.h"
#include "HooksValidator.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   


    //Завідомо косячний приклад
    string equationFalse = "([ x-y-z} * [x + 2y) - {z + 4x)]";
    //Вірний приклад
    string equationTrue = "({x-y-z} * [x + 2y] - (z + 4x))";
 
    std::cout << equationFalse << '\n';   
    std::cout << equationTrue << '\n';
    
    
    //Зміна класу для перевірки правильної розстановки дужок у виразі
    hooksValidator s1{ equationTrue };
    hooksValidator s2{ equationFalse };
   
    s1.chechToValid();
    s2.chechToValid();

    //DynamicStack<char, 30> s{ ([x-y-z}*[x+2y)-{z+4x)] };



    return 0;
}
