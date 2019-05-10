#include "Parser.hpp"
#include <sstream>
#include <unordered_set>

namespace {

static constexpr auto g_moving_point = 0;
static constexpr auto g_comment = '#';

bool isEmpty(std::string const& i_str)
{
    for (auto ch : i_str)
        if (!std::isspace(ch))
            return false;
    return true;
}

bool isComment(std::string const& i_str)
{
    for (auto ch : i_str)
        if (!std::isspace(ch))
            return ch == g_comment;
    return false;
}

std::size_t getN(std::stringstream& i_ss)
{
    std::size_t result = 0;
    if (std::string s; std::getline(i_ss, s))
        return std::stoi(s);
    throw std::logic_error("N expected");
}

auto split(std::string const& i_str) -> std::vector<std::size_t>
{
    std::stringstream ss(i_str);
    std::size_t n;
    std::vector<std::size_t> result;
    while (ss >> n)
        result.push_back(n);
    return result;
}

void skipComment(std::stringstream& i_ss)
{
    for (std::string s; std::getline(i_ss, s);)
    {
        if (isEmpty(s))
            continue;
        if (!isComment(s))
            throw std::logic_error("Comment expected");
        break;
    }
}


auto preprocess(SquareMatrix::SquareArray&& i_array) -> SquareMatrix::SquareArray
{
    for (auto& row : i_array)
    {
        for (auto& n : row)
        {
            if (n == g_moving_point)
            {
                n = i_array.size() * i_array.size();
                return i_array;
            }
        }
    }
    throw std::logic_error("Validation failed: no zero found");
}

auto validate(SquareMatrix::SquareArray&& i_array) -> SquareMatrix::SquareArray
{
    const auto height = i_array.size();
    if (height == 0)
        throw std::logic_error("Invalid empty SquareMatrix");
    const auto width = i_array[0].size();
    if (height != width)
        throw std::logic_error("Square matrix expected");
    if (height < 3)
        throw std::logic_error("N must be at least 3");
    for (auto const& row : i_array)
        if (row.size() != width)
            throw std::logic_error("Invalid SquareMatrix with wariable row size");
    std::unordered_set<std::size_t> s;
    for (auto const& row : i_array)
        for (auto const n : row)
            if (!s.insert(n).second)
                throw std::runtime_error("All the elements in a matrix should be unique");
    for (auto n = 0; n < s.size(); ++n)
        if (s.find(n) == s.end())
            throw std::runtime_error("A range of numbers [0..n*n) is expected");
    return i_array;
}

} // namespace anonymous

SquareMatrix Parser::parse(std::string const& i_content)
{
    std::stringstream ss(i_content);

    skipComment(ss);

    auto const n = getN(ss);

    SquareMatrix::SquareArray result;
    
    for (std::string s; std::getline(ss, s);)
        if (!isEmpty(s))
            result.push_back(split(s));

    if (result.size() != n)
        throw std::logic_error(std::string("N and parsed matrix side len mismatch: [") +
            std::to_string(n) + "," + std::to_string(result.size()) + "]");

    return preprocess(validate(std::move(result)));
}
