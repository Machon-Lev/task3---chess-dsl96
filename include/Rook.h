#pragma once

#include"Piece.h"
#include "ChessSquare.h"
#include "DirectionalPiece.h"
#include<vector>

class Rook : public  DirectionalPiece
{	 
	const std::vector< ChessSquare> DIRECTIONS{
	  ChessSquare(0,-1),
	  ChessSquare(0,1),
	  ChessSquare(1,0),
	  ChessSquare(-1,0)
	};

	std::vector<ChessSquare> getDirection()const override
	{	 
		return DIRECTIONS;
	}

public:
	Rook(PLAYER itsPlayer) :DirectionalPiece(itsPlayer) {};


};


