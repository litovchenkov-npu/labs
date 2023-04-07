#include "game.h"

namespace Game
{
    char Player::_playerChar = 'X'; //������ ������ �� �������������
    char ComputerPlayer::_computerChar = 'O'; //������ ����'�������� ������ �� �������������

    //������ get �� set ��� ������� ������ �� ����'�����
    void Player::setPlayerChar(char newPlayerChar)
    {
        _playerChar = newPlayerChar;
    };

    void ComputerPlayer::setPlayerChar(char newComputerChar)
    {
        _computerChar = newComputerChar;
    };

    char Player::getPlayerChar()
    {
        return _playerChar;
    };

    char ComputerPlayer::getPlayerChar()
    {
        return _computerChar;
    };

    //��� ������
    void Player::playerMove(char* board, char player)
    {
        int number;
        do {
            std::cout << "Enter a spot to place a marker (1-9): ";
            std::cin >> number;
            number--;
            if (board[number] == '#') {
                board[number] = player;
                break;
            }
        } while (!number > 0 || !number < 8);
    }

    //��� ����'�������� ������
    void ComputerPlayer::playerMove(char* board, char computer)
    {
        int number;
        srand(time(0));

        while (true) {
            number = rand() % 9;
            if (board[number] == '#') {
                board[number] = computer;
                break;
            }
        }
    }
}