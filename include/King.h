#pragma once

#include"Piece.h"

class King : public Piece
{

	const ChessSquare  MOVES[8] = {
			 ChessSquare(0,-1),
			 ChessSquare(0,1),
			 ChessSquare(1,0),
			 ChessSquare(-1,0),
			 ChessSquare(-1,-1),
			 ChessSquare(1,1),
			 ChessSquare(-1,1),
			 ChessSquare(1,-1)
	};

public:

	King(PLAYER itsPlayer) :Piece(itsPlayer) {};

	bool CheckIfCanReachToDestination(const ChessLogic& board, ChessSquare pieceLoc, ChessSquare destination) const override;
	
	bool isKing()const override
	{
		return true;
	}

};


