#pragma once
#include "Piece.h"
#include<vector>

class DirectionalPiece : public Piece
{

public:

	virtual std::vector<ChessSquare> getDirection()const = 0;	 
	
	DirectionalPiece(PLAYER itsPlayer) :Piece(itsPlayer) {};
	
	bool CheckIfCanReachToDestination(const ChessLogic& board, ChessSquare pieceLoc, ChessSquare destination)const override;
};
