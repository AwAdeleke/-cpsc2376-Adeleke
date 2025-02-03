#include <iostream>
#include <vector>


void printByReference(std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers.at(i) << std::endl;
    }
}



int main()
{
    std::vector <int> myVector{ 2, 4, 6, 7 };
    printByReference(myVector);

    int option{};

    std::cout
        << "Pick a option by inputing the number beside the option\n"
        << "\tAdd a Number to the Printed Value on above Option 1\n";
    std::cin >> option;
    if (option == 1)
    {
        std::cout << "What the number you will like to add\n";
        int num{};
        std::cin >> num;
        myVector.push_back(num);
    }
    std::cout << "To print the new numbers 1" << std::endl;
    int input{};
    std::cin >> input;
    if (input == 1) {
        printByReference(myVector);
    }
    int sum{ 0 };
    for (int i = 0; i < myVector.size(); i++)
    {
        sum += myVector.at(i);
    }
    std::cout << "\nSum of all numbers: " << sum << std::endl;

    std::cout << "Pick a number to multiple with value in system" << std::endl;
    int x{};
    std::cin >> x;
    for (int i = 0; i < myVector.size(); i++)
    {
        myVector.at(i) *= x;

    }

    printByReference(myVector);



