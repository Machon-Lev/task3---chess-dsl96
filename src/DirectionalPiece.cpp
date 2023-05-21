
#include"DirectionalPiece.h"
 
bool  DirectionalPiece::CheckIfCanReachToDestination(const ChessLogic& board, ChessSquare pieceLoc, ChessSquare destination)const
{
	if (!board.isValidSquare(destination))
		throw std::invalid_argument("invalid destination pass to rook CheckIfCanReachToDestination");

	ChessSquare nextLoc;
	for (  ChessSquare dir :   this->getDirection())
	{
		nextLoc = pieceLoc;
		nextLoc += dir;

		//while on board
		while (board.isValidSquare(nextLoc))
		{
			if (board.checkNonEmptySquare(nextLoc))
			{
				//if the piece in the way its the same player
				if (board.getPieceAt(nextLoc)->GetPlayer() == this->GetPlayer())
					break;
				else
				{
					if (nextLoc == destination)
						return true;
					break;
				}
			}

			if (nextLoc == destination)
				return true;
			nextLoc += dir;
		}
	}
	return false;
}