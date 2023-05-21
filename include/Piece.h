#pragma once
#include<vector>
#include "Enums.h"
#include"ChessSquare.h"
#include"ChessLogic.h"
#include <iostream>

using std::vector;


class ChessLogic;

class Piece {

private:
	PLAYER itsPlayer;

public:
	
	explicit Piece(PLAYER itsPlayer) :itsPlayer(itsPlayer) {};
	
	~Piece()
	{
		std::cout << "in dtor";
	}

	PLAYER GetPlayer() const { return itsPlayer; };

	virtual bool CheckIfCanReachToDestination(const ChessLogic& board, ChessSquare pieceLoc, ChessSquare destination)const = 0;
	
	virtual bool isKing()const
	{
		return false;
	}
};



