#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>

std::map<std::string, std::string> translations;
std::vector<std::string> history;

std::set<std::string> make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}

void printDictionary(std::map<std::string, std::string> dictionary)
{
    for (const auto& [key,value]: dictionary)
    {
        std::cout << key << " => " << value << std::endl;
    }
}
bool command_exec(std::istream& input){
    auto command = std::string{};
    auto w1 = std::string{};
    auto w2 = std::string{};

    input >> command;

    if (make_exit_commands().count(command))
    {
        return false;
    }
    else if (command == "add")
    {
        input >> w1;
        input >> w2;
        std::cout << w1 << " => " << w2 << std::endl;
        translations.emplace(w1, w2);
        history.push_back("add " + w1 + " " + w2);
    }
    else if (command == "translate")
    {
        auto line = std::string{};
        auto words = std::stringstream{};

        std::getline(input, line);
        words << line;
        while (!words.eof()){
            auto word = std::string{};
            words >> word;
            if (translations.count(word))
            {
                std::cout << translations[word] << std::endl;
            }
            else
            {
                std::cout << "???" << std::endl;
            }
        }
    }
    else if (command == "print")
    {
        printDictionary(translations);
    }

    else if (command == "save")
    {
        auto name = std::string{};
        input >> name;
        auto file = std::ofstream(name);

        for (const auto& add_command: history){
            file << add_command << "\n";
        }
    }

    else if (command == "clear")
    {
        translations.clear();
        history.clear();
    }

    else if (command == "remove")
    {
        auto word = std::string{};
        input >> word;
        for (auto it = translations.begin(); it != translations.end();)
        {
            if (it->first == word || it->second == word){
                it = translations.erase(it);
            }
            else {
                it++;
            }
        }
    }
    return true;
}

int main()
{
    while (true) {
        if (!command_exec(std::cin)){
            return 0;
        }
    }
    return 0;
}