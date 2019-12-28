#include<iostream>
using namespace std;
enum PlayerTurn{FIRST_PLAYER=1,SECOND_PLAYER=2};
enum GameStatus{DRAW,WIN,IN_PROGRESS};
class GameBoard
{private:
	char data[3][3];
	GameStatus gameStatus;
	int validMovesCount = 0;
public:
	GameBoard();
	void displayBoard();
	void markBoard(char pos , char playSymbol);
	bool isValidPosition(char pos);
	bool isAlreadyMarked(char pos);
	bool isWin();
	int getValidMovesCount();
	GameStatus getGameStatus();
	void setGameStatus(GameStatus gs);
};