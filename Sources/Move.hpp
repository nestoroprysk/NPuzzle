#pragma once

#include <unordered_set>

class SquareMatrix;

enum class Move { Left, Right, Up, Down };

namespace MoveUtils {

auto possibleMoves(SquareMatrix const& i_state) -> std::unordered_set<Move>;
bool isValid(SquareMatrix const& i_state, Move i_move);
SquareMatrix move(SquareMatrix const& i_state, Move i_move);
Move inferMove(SquareMatrix const& i_from, SquareMatrix const& i_to);

} // namespace MoveUtils
