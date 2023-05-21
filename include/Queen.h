#pragma once
#include "DirectionalPiece.h"

class Queen :public DirectionalPiece
{
	const std::vector< ChessSquare> DIRECTIONS{
	  ChessSquare(0,-1),
	  ChessSquare(0,1),
	  ChessSquare(1,0),
	  ChessSquare(-1,0),
	  ChessSquare(1,-1),
	  ChessSquare(1,1),
	  ChessSquare(-1,1),
	  ChessSquare(-1,-1)
	};

	std::vector<ChessSquare> getDirection()const override
	{
		return DIRECTIONS;
	}

public:
	Queen(PLAYER itsPlayer) :DirectionalPiece(itsPlayer) {};
};
