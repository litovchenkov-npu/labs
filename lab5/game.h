#pragma once

#include <iostream>
#include <ctime>

//клас ≥гровоњ лог≥ки
namespace Game
{
	class GameLogic
	{
	private:
		char _board[9] = { '#', '#', '#',
						   '#', '#', '#',
						   '#', '#', '#' }; //опис ≥грового пол€
		static short int s_moveCount; //статична зм≥нна дл€ в≥дсл≥дковуванн€ к≥лькост≥ крок≥в гри
	public:
		//методи get та set дл€ ≥грового пол€
		char* getBoard();
		void setBoard(char newBoard[9]);

		static short int getMoveCount(); //поверненн€ значенн€ к≥лькост≥ крок≥в гри
		void updateMoveCount(); //зб≥льшенн€ к≥лькост≥ крок≥в гри
		void drawBoard(char* board); //построкове виведенн€ ≥грового пол€
		bool checkGameOver(char* board); //перев≥рка умови перемоги чи програшу
		bool checkTie(char* board); //перев≥рка умови н≥чиЇњ
	};

	//≥нтерфейс гравц€
	class IPlayer
	{
	public:
		//методи get та set дл€ символ≥в гравц≥в
		virtual void setPlayerChar(char player) = 0;
		virtual char getPlayerChar() = 0;

		//х≥д гравц€
		virtual void playerMove(char* board, char player) = 0;
	};

	class Player : IPlayer
	{
	private:
		static char _playerChar; //символ гравц€ за замовчуванн€м
	public:
		//методи get та set дл€ символу гравц€
		void setPlayerChar(char newPlayerChar) override;
		char getPlayerChar() override;

		//х≥д гравц€
		void playerMove(char* board, char player) override;
	};

	class ComputerPlayer : IPlayer
	{
	private:
		static char _computerChar; //символ комп'ютерного гравц€ за замовчуванн€м
	public:
		//методи get та set дл€ символу комп'ютерного гравц€
		void setPlayerChar(char player) override;
		char getPlayerChar() override;

		//х≥д комп'ютерного гравц€
		void playerMove(char* board, char player) override;
	};
}