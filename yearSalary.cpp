// Copyright (c) 2021 Alexander Matheson All rights reserved.
//
// Created by: Alexander matheson
// Created on: Dec 9 2021
// This program gets the user to input their
// yearly salary and years of service.
// It then determines if the user should get a bonus.
// If the user gets a bonus, the program will calculate the bonus.
#include <iostream>
#include <iomanip>
#include <string>


// set constants
const int SERVICE = 5;
const float INCREASE = 0.05;
const char YES = 'y';


// declare variables
int extraYears;
int years;
float salaryExtra;
float salary;
char answer;


void input() {
    // variables
    std::string salaryString;
    std::string yearsString;
    // input
    std::cout << "What is your current yearly salary: $";
    std::cin >> salaryString;
    // error checking
    try {
        salary = std::stoi(salaryString);
    } catch (std::invalid_argument) {
        std::cout << "Must be a number \n";
        return input();
    }
    std::cout << "Enter your current years of service: ";
    std::cin >> yearsString;
    // error checking
    try {
        years = std::stoi(yearsString);
    } catch (std::invalid_argument) {
        std::cout << "Must be a number \n";
        return input();
    }
    std::cout << "" << std::endl;
}


void calculate() {
    // process
    salaryExtra = salary * INCREASE;
    salary = salary + salaryExtra;

    // output
    std::cout << "Your bonus is $" << std::fixed << std::setprecision(2)
    << salaryExtra << ".\n";
    std::cout << "Your new salary is $" << std::fixed << std::setprecision(2)
    << salary << ".\n";
    std::cout << "\n";
}


void moreYears() {
    // process
    extraYears = SERVICE + 1 - years;

    // output
    std::cout << "You do not have enough years of service";
    std::cout << " to receive a bonus.\n";

    if (extraYears == 1) {
        std::cout << "You need " << extraYears << " more year.\n";
    } else {
        std::cout << "You need " << extraYears << " more years.\n";
    }
}


int main() {
    // loop
    do {
    // input
    input();

    // process
    if (years > SERVICE) {
        calculate();
    } else {
        moreYears();
    }

    // loop
    std::cout << "Is there someone else who would like to try? (y/n) ";
    std::cin >> answer;
    std::cout << "\n";
       } while (answer == YES);
    // end
    std::cout << "Goodbye.";
}
