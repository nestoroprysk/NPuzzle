#pragma once

#include "SquareMatrix.hpp"
#include "State.hpp"

#include <map>

class MatrixRepository
{
public:
    using Sortedness = std::size_t;
    static void add(State::Id const i_id, SquareMatrix const& i_matrix);
    static SquareMatrix& getMatrix(State::Id const i_id);
    static Sortedness getSortedness(State::Id const i_id);
    static void flush();
private:
    static std::map<State::Id, SquareMatrix>& getMatrixRepository();
    static std::map<State::Id, MatrixRepository::Sortedness>& getSortednessRepository();
};
