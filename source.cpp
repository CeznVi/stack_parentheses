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
    string equationFalse = "([ x-y-z } * [x + 2y) - {z + 4x)]";
    //Вірний приклад
    string equationTrue = "({x-y-z } * [x + 2y] - (z + 4x))";
    //Текст в змінній каже сам за себе 
    string theFalsel = "нісенітциця повна";

    std::cout << "Правильний рядок: " << equationTrue << '\n';
    std::cout << "Неправильний рядок: " << equationFalse << '\n';
    std::cout << "Пустий рядок: " << theFalsel << '\n';
    
    
    //Зміна класу для перевірки правильної розстановки дужок у виразі
    hooksValidator s1{ equationTrue };
    hooksValidator s2{ equationFalse };
    hooksValidator s3{ theFalsel };

    s1.chechToValid();
    s2.chechToValid();
    s3.chechToValid();
   



    return 0;
}
