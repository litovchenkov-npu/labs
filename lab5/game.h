#pragma once

#include <iostream>
#include <ctime>

//���� ������ �����
namespace Game
{
	class GameLogic
	{
	private:
		char _board[9] = { '#', '#', '#',
						   '#', '#', '#',
						   '#', '#', '#' }; //���� �������� ����
		static short int s_moveCount; //�������� ����� ��� �������������� ������� ����� ���
	public:
		//������ get �� set ��� �������� ����
		char* getBoard();
		void setBoard(char newBoard[9]);

		static short int getMoveCount(); //���������� �������� ������� ����� ���
		void updateMoveCount(); //��������� ������� ����� ���
		void drawBoard(char* board); //���������� ��������� �������� ����
		bool checkGameOver(char* board); //�������� ����� �������� �� ��������
		bool checkTie(char* board); //�������� ����� ��躿
	};

	//��������� ������
	class IPlayer
	{
	public:
		//������ get �� set ��� ������� �������
		virtual void setPlayerChar(char player) = 0;
		virtual char getPlayerChar() = 0;

		//��� ������
		virtual void playerMove(char* board, char player) = 0;
	};

	class Player : IPlayer
	{
	private:
		static char _playerChar; //������ ������ �� �������������
	public:
		//������ get �� set ��� ������� ������
		void setPlayerChar(char newPlayerChar) override;
		char getPlayerChar() override;

		//��� ������
		void playerMove(char* board, char player) override;
	};

	class ComputerPlayer : IPlayer
	{
	private:
		static char _computerChar; //������ ����'�������� ������ �� �������������
	public:
		//������ get �� set ��� ������� ����'�������� ������
		void setPlayerChar(char player) override;
		char getPlayerChar() override;

		//��� ����'�������� ������
		void playerMove(char* board, char player) override;
	};
}