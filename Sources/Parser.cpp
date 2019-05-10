#include "Parser.hpp"
#include "Utils.hpp"
#include <sstream>
#include <unordered_set>

namespace {

static constexpr auto g_n_position = 0;
static constexpr auto g_comment = '#';
static constexpr auto g_map_size_lower_limit = 3;
static constexpr auto g_map_size_upper_limit = 64;

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

auto split(std::string const& i_str) -> std::vector<std::size_t>
{
    std::stringstream ss(i_str);
    std::size_t n;
    std::vector<std::size_t> result;
    while (ss >> n)
        result.push_back(n);
    return result;
}

auto tryGetPureLines(const std::string& i_content) -> std::vector<std::string>
{
    std::vector<std::string> result;
    auto ss = std::stringstream(i_content);
    for (std::string s; std::getline(ss, s);)
        if (!isComment(s) && !isEmpty(s))
            result.push_back(std::move(s));
    if (result.empty())
        throw std::invalid_argument("Content cannot be empty");
    return result;
}

std::size_t tryGetN(std::string const& i_str)
{
    const auto result = std::atoi(i_str.c_str());
    if (result < g_map_size_lower_limit || result > g_map_size_upper_limit)
        throw std::invalid_argument("Number indicating the number of should be within the range [3, 64] "
            "(got " + std::to_string(result) + ")");
    return result;
}

auto validate(SquareMatrix::SquareArray&& i_array, std::size_t const i_n) -> SquareMatrix::SquareArray
{
    if (i_array.size() != i_n)
        throw std::logic_error(std::string("N and parsed matrix side len mismatch: [") +
            std::to_string(i_n) + "," + std::to_string(i_array.size()) + "]");
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
    const auto lines = tryGetPureLines(i_content);
    SquareMatrix::SquareArray result;
    for(auto it = std::begin(lines) + 1; it != lines.cend(); ++it)
        result.push_back(split(*it));
    const auto n = tryGetN(lines[g_n_position]);
    return validate(std::move(result), n);
}
