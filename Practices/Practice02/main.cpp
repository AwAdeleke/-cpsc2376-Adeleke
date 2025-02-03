#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename, const int content) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
        std::cout << "Initializing account with" << content << std::endl;
    }
    else {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
}
void checkFile(const std::string& filename)
{
    std::ifstream inFile(filename);
   
    if (!inFile.is_open()) 
    {
        std::cerr << "Failed to open file for reading." << std::endl;
        return;
    }
    inFile.close();
   
}
void simpleRead(const std::string& filename) {
    std::ifstream inFile(filename);
    int num{};
    while (inFile >> num) {
        std::cout << "Your current balance is $" << num <<  std::endl;
    }
    inFile.close();
}

void addNum(const std::string& filename)
{
    std::ifstream inFile(filename);
    std::cout << "how do you want to deposit: " << std::endl;
    int deposit{};
    int num{};
    std::cin >> deposit;
    while (inFile >> num)
    {
        int addition{ deposit + num };
        std::cout << "Deposit successful" << "  Your new balance is: $" << deposit + num << std::endl;
    }
    inFile.close();
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << deposit+num;
        outFile.close();
        
    }
    
}
void withDraw(const std::string& filename)
{
    std::ifstream inFile(filename);
    std::cout << "Enter withdrawal amount" << std:: endl;
    int money{};
    int num{};
    std::cin >> money;
    while (inFile >> num) 
    {
        if (num < money)
        {
            std::cout << "Error: Insufficient funds." << " Your balance is $" << num << std::endl;
        }
        else
        {
            std::cout << "Withdrawal successful" << " Your new balance is $" << num - money << std::endl;
        }
    }
    inFile.close();
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile <<  num - money;
        outFile.close();

    }
}

int main()
{
  
   
    std::cout << "Welcome to Your Bank Account!" << std::endl;
    std::cout << "if you want to start with one hundred input 1" << std::endl;
    int put{};
        std::cin >> put;
        if (put == 1) {
             writeToFile("account_balance.txt", 100);
        }
    checkFile("account_balance.txt");

    std::cout << "Menu:\n"
        << "1. Check Balance\n"
        << "2. Deposit Money\n"
        << "3. Withdraw Money\n"
        << "4. Exit\n"
        << std::endl;

    int choice{};
    std::cout << "Enter your number choice:" << std::endl;
    std::cin >> choice;
    if (choice == 1) 
    {
        simpleRead("account_balance.txt");
    }
    else if (choice == 2)
    {
        
        addNum("account_balance.txt");

    }
    else if (choice == 3)
    {
        withDraw("account_balance.txt");
    }
    else
    {
        return 0;
    }
}