#pragma once

#include"Piece.h"

class Knight : public Piece
{

	const ChessSquare  MOVES[8] = {
			 ChessSquare(1, 2),
			 ChessSquare(1, -2),
			 ChessSquare(-1, 2),
			 ChessSquare(-1, -2),
			 ChessSquare(2, 1),
			 ChessSquare(2, -1),
			 ChessSquare(-2 ,1),
			 ChessSquare(-2, -1)
	};

public:

	Knight(PLAYER itsPlayer) :Piece(itsPlayer) {};

	bool CheckIfCanReachToDestination(const ChessLogic& board, ChessSquare pieceLoc, ChessSquare destination) const override;
	
	bool isKing()const override
	{
		return false;
	}

};
