
#include "Knight.h"

bool Knight::CheckIfCanReachToDestination(const ChessLogic& board, ChessSquare pieceLoc, ChessSquare destination)const
{
	if (!board.isValidSquare(destination))
		throw std::invalid_argument("invalid destination pass to knight CheckIfCanReachToDestination");

	ChessSquare currSquar;
	for (auto move : MOVES)
	{
		currSquar = pieceLoc;
		currSquar += move;

		if (currSquar == destination)
		{
			if (!board.checkNonEmptySquare(currSquar) || board.getPieceAt(currSquar)->GetPlayer() != this->GetPlayer())
				return true;

			return false;
		}

	}
	return false;
}