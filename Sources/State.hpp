#pragma once

#include "Move.hpp"
#include "SquareMatrix.hpp"
#include <vector>
#include <optional>
#include <list>

class State
{
public:
    using Id = std::size_t;
    using MaybePredecessor = std::shared_ptr<State>;
    State(SquareMatrix const& i_matrix);
    State(State const& i_other);
    auto getAllNeighbours() const -> std::vector<State>;
    State getNeighbour(Move i_move) const;
    bool isSolution() const;
    void setPredecessor(State const&) const;
    auto getPredecessor() const -> MaybePredecessor;
    SquareMatrix const& getMatrix() const;
    Id getId() const;
private:
    mutable MaybePredecessor m_opt_predecessor;
    std::size_t m_id = -1;
};

namespace StateUtils {

    std::size_t sortedness(State const& i_state);

} // namespace StateUtils
