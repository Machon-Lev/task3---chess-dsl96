
#include "ChessLogic.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"

ChessLogic::ChessLogic(string strBoard) : currPlayer(WHITE)
{
	this->initBoardFromStr(strBoard);
}

void ChessLogic::initBoardFromStr(string strBoard)
{
	if (strBoard.size() != BOARD_SIZE * BOARD_SIZE)
		throw std::invalid_argument("Invalid argument strBoard most be in the same size of board");

	int strBoardIdx = 0;

	for (int row = 0; row < BOARD_SIZE; ++row)
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			board[row][col] = getPieceByChar(strBoard[strBoardIdx++]);

		}
}

unique_ptr<Piece> ChessLogic::getPieceByChar(char ch)
{


	unique_ptr<Piece> uPtr;

	PLAYER piecePlayer = std::islower(ch) ? BLACK : WHITE;

	ch = std::tolower(ch);

	switch (ch)
	{
	case 'r':
		uPtr = std::make_unique<Rook>(piecePlayer);
		break;

	case 'k':
		uPtr = std::make_unique<King>(piecePlayer);
		break;

	case 'b':
		uPtr = std::make_unique<Bishop>(piecePlayer);
		break;

	case 'q':
		uPtr = std::make_unique<Queen>(piecePlayer);
		break;

	case 'n':
		uPtr = std::make_unique<Knight>(piecePlayer);
		break;
	}

	return std::move(uPtr);
}


ChessSquare ChessLogic::getSquareFromStr(char charRow, char charCol)
{
	charRow = std::tolower(charRow);
	int row = int(charRow - 'a');
	int col = int(charCol - '1');

	return ChessSquare(row, col);
}

bool ChessLogic::checkNonEmptySquare(ChessSquare square) const
{
	return  getPieceAt(square) != nullptr;
}

bool ChessLogic::checkPieceItsBelongToCurrentPlayer(ChessSquare square)
{
	if (!checkNonEmptySquare(square))
		throw std::invalid_argument("empty square pass to checkPieceItsBelongToCurrentPlayer");

	return getPieceAt(square)->GetPlayer() == this->getPlayerTurn();

}

const Piece* ChessLogic::getPieceAt(ChessSquare square) const
{
	return  board[square.row][square.col].get();
}


STATUS ChessLogic::CheckMove(string strMove)
{
	ChessSquare startSquare = getSquareFromStr(strMove[0], strMove[1]);
	ChessSquare endSquare = getSquareFromStr(strMove[2], strMove[3]);


	if (!checkNonEmptySquare(startSquare))
		return NO_PIECE;


	if (!checkPieceItsBelongToCurrentPlayer(startSquare))
		return NOT_YOUR_PIECE;

	if (getPieceAt(endSquare) != nullptr && checkIfBelongTheSamePlayer(*getPieceAt(startSquare), *getPieceAt(endSquare)))
		return DISTENETION_NOT_FREE;

	if (!getPieceAt(startSquare)->CheckIfCanReachToDestination(*this, startSquare, endSquare))
		return INVALID_MOVE;

	unique_ptr<Piece> removedPiece = std::move(board[endSquare.row][endSquare.col]);
	movePiece(startSquare, endSquare);

	if (this->checkIfInCheck(getPlayerTurn()))
	{
		//undo move
		movePiece(endSquare, startSquare);
		board[endSquare.row][endSquare.col] = std::move(removedPiece);

		return MOVE_MAKE_SELF_CHECK;
	}

	switchPlayer();
	if (this->checkIfInCheck(getPlayerTurn()))
		return MOVE_MAKE_CHECK;

	return VALID_MOVE;
}

bool ChessLogic::isValidSquare(ChessSquare square)const
{
	return square.row < BOARD_SIZE && square.row >= 0 && square.col < BOARD_SIZE && square.col >= 0;
}

bool ChessLogic::checkIfBelongTheSamePlayer(const Piece& p1, const Piece& p2)
{
	return  p1.GetPlayer() == p2.GetPlayer();
}


void ChessLogic::movePiece(ChessSquare from, ChessSquare to)
{
	board[to.row][to.col] = std::move(board[from.row][from.col]);
	board[from.row][from.col] = nullptr;
}


ChessSquare ChessLogic::findKingSquare(PLAYER player) const
{
	ChessSquare currSruare;
	const Piece* currPiece;
	for (int row = 0; row < BOARD_SIZE; ++row)
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			currSruare.col = col;
			currSruare.row = row;

			if (this->checkNonEmptySquare(currSruare))
			{
				currPiece = this->getPieceAt(currSruare);
				if (currPiece->GetPlayer() == player && currPiece->isKing())
					return currSruare;
			}
		}

	return ChessSquare(-1, -1);
}


bool ChessLogic::checkIfInCheck(PLAYER player) const
{
	ChessSquare kingSquare = this->findKingSquare(player);

	// for debug in tests board not most include king
	if (kingSquare == ChessSquare(-1, -1))
	{
		return false;
	}

	ChessSquare currSquare;
	const Piece* currPiece;
	for (int row = 0; row < BOARD_SIZE; ++row)
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			currSquare.col = col;
			currSquare.row = row;

			if (this->checkNonEmptySquare(currSquare))
			{
				currPiece = this->getPieceAt(currSquare);
				if (currPiece->GetPlayer() != player && currPiece->CheckIfCanReachToDestination(*this, currSquare, kingSquare))
					return true;
			}
		}
	return false;
}