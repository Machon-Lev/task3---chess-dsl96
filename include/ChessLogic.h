#pragma once
#include <string>
#include <memory>
#include "Enums.h"
#include"Piece.h"
using std::string;
using std::unique_ptr;

class Piece;

class ChessLogic
{

private:

	static const int BOARD_SIZE = 8;

	unique_ptr<Piece> board[BOARD_SIZE][BOARD_SIZE];

	PLAYER currPlayer;

	void initBoardFromStr(string strBoard);

	unique_ptr<Piece> getPieceByChar(char ch);

	PLAYER getPlayerTurn()
	{
		return this->currPlayer;
	}

	/// <summary>
	/// get square in board in chars   
	/// </summary>
	/// <param name="charRow"> row{'A' 'B ... 'H'} non case sensitive </param>
	/// <param name="charCol">col{'1' '2' ... '8'}</param>
	/// <returns>instance of chessSquare represente that square</returns>
	ChessSquare getSquareFromStr(char charRow, char charCol);

	
	bool checkPieceItsBelongToCurrentPlayer(ChessSquare square);

	void movePiece(ChessSquare from, ChessSquare to);

	bool checkIfBelongTheSamePlayer(const Piece& p1, const Piece& p2);

	void switchPlayer() 
	{
		this->currPlayer = otherPlayer(this->currPlayer);
	}

	ChessSquare findKingSquare(PLAYER player)const;

	bool checkIfInCheck(PLAYER player)const;

	
public:

	ChessLogic(string strBoard);

	STATUS CheckMove(string strMove);

	const Piece* getPieceAt(ChessSquare square) const;

	PLAYER otherPlayer(PLAYER player)
	{
		return player == BLACK ? WHITE : BLACK;
	}

	bool isValidSquare(ChessSquare square) const;

	bool checkNonEmptySquare(ChessSquare square) const;


};
