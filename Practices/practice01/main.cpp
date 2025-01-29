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
    else
    {

    }



}