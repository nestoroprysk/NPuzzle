#include "Parser.hpp"
#include "State.hpp"
#include "Utils.hpp"
#include "MatrixRepository.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char const** argv)
{
    try
    {
        if (argc == 1)
            throw std::invalid_argument("At least one argument expected");
        for (auto i = 1; i < argc; ++i)
        {
            const auto file_name = Utils::getFileInBuildDirFullName(argv[i]);
            std::ifstream f(file_name);
            if (!f)
                throw std::invalid_argument("Usage: ./Sortedness [any number of file names]\n"
                    "(every file should reside in the Build directory)");
            std::string query((std::istreambuf_iterator<char>(f)),
                             std::istreambuf_iterator<char>());
            const auto m = Parser::parse(query);
            const auto s = State(m);
            std::cout << MatrixRepository::getSortedness(s.getId()) << std::endl;
        }
    }
    catch (std::exception const& e)
    {
        std::cout << e.what()  << std::endl;
    }
}
