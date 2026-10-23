#include <iostream>
#include "Student.h"

int main()
{
    std::cout << "Hello, OOP!" << std::endl;
    Student student("Thomas", "Edison");
    std::cout << "Student " << student.firstName
              << " " << student.lastName << std::endl;
    return 0;
}//
// Created by i9824 on 23.10.2026.
//
