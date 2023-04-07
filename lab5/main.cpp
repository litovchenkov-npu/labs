#include "game.h"

using namespace Game;

int main()
{
    bool running = true; //����� ������ �����

    //��������� ���������� ����� ������� ����� �� �������
    GameLogic game;
    Player player;
    ComputerPlayer computer;

    game.drawBoard(game.getBoard()); //����������� �������� ����

    //������������ ������� ��� ������ �� ����'�����
    player.setPlayerChar('X');
    computer.setPlayerChar('O');

    while (running) {
        //��� ������
        player.playerMove(game.getBoard(), player.getPlayerChar()); //��� ������
        game.updateMoveCount(); //��������� ������� ����� ���� ���� ������
        game.drawBoard(game.getBoard()); //����������� �������� ����
        if (game.checkGameOver(game.getBoard()))
        {
            std::cout << "Game over! Thanks for playing!\n";
            running = false; //���������� ��� �� ����� ������� ��� ��������
            break;
        }
        else if (game.checkTie(game.getBoard()))
        {
            std::cout << "It's a tie!\n";
            running = false; //���������� ��� �� ����� ��躿
            break;
        }

        //��� ����'�����
        computer.playerMove(game.getBoard(), computer.getPlayerChar()); //��� ����'�������� ������
        game.updateMoveCount(); //��������� ������� ����� ���� ���� ����'�������� ������
        game.drawBoard(game.getBoard()); //����������� �������� ����
        if (game.checkGameOver(game.getBoard()))
        {
            std::cout << "Game over! Thanks for playing!\n";
            running = false; //���������� ��� �� ����� ������� ��� ��������
            break;
        }
        else if (game.checkTie(game.getBoard()))
        {
            std::cout << "It's a tie!\n";
            running = false; //���������� ��� �� ����� ��躿
            break;
        }
    }

    std::cout << "The game was ended in " << game.getMoveCount() << " turns.\n";

    return 0;
}