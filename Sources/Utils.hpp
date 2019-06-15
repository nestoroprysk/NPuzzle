#pragma once

#include "SquareMatrix.hpp"
#include "State.hpp"

#include <map>
#include <string>

namespace Utils {

static constexpr auto g_moving_point = 0;

class ScopedCaller
{
public:
    ScopedCaller(std::function<void()> i_f)
        : m_f(std::move(i_f))
    {
        if (!noexcept(i_f))
            throw std::logic_error("noexcept function expected");
    }
    ~ScopedCaller()
    {
        m_f();
    }
private:
    std::function<void()> m_f;
};

inline std::string getBuildDirPath()
{
    return PATH_TO_BUILD_DIR;
}

inline auto& getIdCounter()
{
    static std::size_t g_id_counter = 0;
    return g_id_counter;
}

inline std::string getFileInBuildDirFullName(std::string const& i_name)
{
    return getBuildDirPath() + '/' + i_name;
}

} // namespace Utils
