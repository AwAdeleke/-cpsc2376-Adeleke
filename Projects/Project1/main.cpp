#include <iostream>
#include <vector>
#include <stdexcept>

enum class Cell { BLANK, B, W };

std::vector<std::vector<Cell>> makeBoard( int size = 8)
{
	std::vector<std::vector<Cell>> board(size, std::vector <Cell> (size, Cell::BLANK));
	
	return board;
}

void printBoard(std::vector<std::vector<Cell>> board)
{
	auto size = board.size();
	for (auto row : board)
	{
		for (auto elem : row)
		{
			if (elem == Cell::B)
			{
				std::cout << " B ";
			}
			else
			{
				std::cout << " - ";
			}

		}
	std::cout << '\n';
	}
}

Cell getCurrentplayer(const  std::vector<std::vector<Cell>>& board)
{
	int count{ 0 };
	for (auto row : board)
	{
		for (auto elem : row)
		{

			if (elem != Cell::BLANK)
			{
				count++;
			}
			if (count % 2 == 0)
			{
				return Cell::B;
			}
			else
			{
				return Cell::W;
			}
		}
	}
	
}

bool play(std::vector < std::vector<Cell>> & board, int row, int col, int token )
{
		
	
	/*Cell token = getCurrentplayer(board);*/
	auto height = board.size();
	if (height == 0) throw std::invalid_argument("Height of the board can not be Zero");

	auto width = board.at(0).size();
}


int main()
{
	auto board = makeBoard();
	
	
	int turn{0};
	while (true)
	{
		printBoard(board);
		if (getCurrentplayer(board) == Cell::B)
		{
			std::cout << "Player X's turn\n";
		}
		else
		{
			std::cout << "player O's turn\n";
		}
		int token{ turn % 2 + 1 };
		std::cout << "Player" << token<< "'s turn!\n";

		int row;
		std::cout << "Enter your row";
		std::cin >> row;
		std::cout << "Enter your column";
		int col;
		std::cin >> col;

		bool playWorked{ play(board, row, col};
		if (!playWorked)
		{
			std::cout << "bad moves\n";
		}
		else
		{
			turn++; 
		}
		turn++;
	}
	

	
}