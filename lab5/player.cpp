#include "game.h"

namespace Game
{
    char Player::_playerChar = 'X'; //символ гравця за замовчуванням
    char ComputerPlayer::_computerChar = 'O'; //символ комп'ютерного гравця за замовчуванням

    //методи get та set для символів гравця та комп'ютера
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

    //хід гравця
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

    //хід комп'ютерного гравця
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