#pragma once

#include "SquareMatrix.hpp"

#include <map>

namespace Utils {

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

    inline auto& getMatrixRepository()
    {
        static std::map<State::Id, SquareMatrix> g_state_id_to_matrix;
        return g_state_id_to_matrix;
    }

    inline auto& getIdCounter()
    {
        static std::size_t g_id_counter = 0;
        return g_id_counter;
    }

} // namespace Utils
