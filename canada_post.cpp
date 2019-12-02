// Copyright (c) 2019 Joseph Palermo All rights reserved.
//
// Created by: Joseph Palermo
// Created on: November 2019
// This program prints a Canada Post mailing address

#include <iostream>
#include <string>

std::string MailingAddress(std::string userName,
                      std::string userAddress,
                      std::string userCity,
                      std::string userProvince,
                      std::string userPostalCode,
                      std::string userApartmentNumber = "") {
    // this function puts the credentials into proper format

    // variables
    std::string postAddress;

    // process
    if (userApartmentNumber.size() != 0) {
        postAddress = userName + "\n" + userApartmentNumber + \
                      + "-" + userAddress + "\n" + userCity \
                      + " " + userProvince + "  " + userPostalCode;
    } else {
        postAddress = userName + "\n" + userAddress + "\n" + \
                      userCity + " " + userProvince + \
                      "  " + userPostalCode;
    }
    return postAddress;
}

int main() {
    // this function gets all mailing credentials and outputs them

    // variables
    std::string userName;
    std::string userAddress;
    std::string question;
    std::string userCity;
    std::string userProvince;
    std::string userPostalCode;
    std::string userAddy;
    std::string userApartmentNumber = "";

    // input
    std::cout << "Enter your full name:" << std::endl;
    std::getline(std::cin, userName);
    std::cout << "Enter your address:"
              << std::endl;
    std::getline(std::cin, userAddress);
    std::cout << "Do you live in an apartment (y/n):" << std::endl;
    std::getline(std::cin, question);
    if (question == "y" || question == "yes") {
        std::cout << "Enter your apartment number:" << std::endl;
        std::getline(std::cin, userApartmentNumber);
    }
    std::cout << "Enter your city:" << std::endl;
    std::getline(std::cin, userCity);
    std::cout << "Enter your abbreviated province or territory:"
              << std::endl;
    std::getline(std::cin, userProvince);
    std::cout << "Enter your postal code:" << std::endl;
    std::getline(std::cin, userPostalCode);;

    // process
    if (userApartmentNumber != "") {
        userAddy = MailingAddress(userName, userAddress, userCity,
                              userProvince, userPostalCode,
                              userApartmentNumber);
    } else {
        userAddy = MailingAddress(userName, userAddress, userCity,
                              userProvince, userPostalCode);
    }

    // output, addy means exact address
    std::cout << "" << std::endl;
    std::cout << userAddy << std::endl;
}
