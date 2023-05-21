#pragma once

#include "DirectionalPiece.h"


class Bishop :public DirectionalPiece
{
	const std::vector< ChessSquare> DIRECTIONS
	{
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
	Bishop(PLAYER itsPlayer) :DirectionalPiece(itsPlayer) {};
};
