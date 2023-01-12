#include <iostream>
#include <string>

int main() {
    std::cout << "What's your name? " << std::endl;
    
    auto var = std::string {};
    std::cin >> var;

    std::cout << "Hello " << var << "!" << std::endl;
    return 0;
}