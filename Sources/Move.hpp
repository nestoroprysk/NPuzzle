#pragma once

class SquareMatrix;

enum class Move { Left, Right, Up, Down };

namespace MoveUtils {

bool isValid(SquareMatrix const& i_state, Move i_move);
void move(SquareMatrix& io_state, Move i_move);

} // namespace MoveUtils
