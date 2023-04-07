#include "game.h"

using namespace Game;

int main()
{
    bool running = true; //умова роботи циклу

    //створенн€ екземпл€р≥в клас≥в ≥гровох лог≥ки та гравц≥в
    GameLogic game;
    Player player;
    ComputerPlayer computer;

    game.drawBoard(game.getBoard()); //в≥дображенн€ ≥грового пол€

    //встановленн€ символ≥в дл€ гравц€ та комп'ютера
    player.setPlayerChar('X');
    computer.setPlayerChar('O');

    while (running) {
        //х≥д гравц€
        player.playerMove(game.getBoard(), player.getPlayerChar()); //х≥д гравц€
        game.updateMoveCount(); //оновленн€ к≥льеост≥ крок≥в п≥сл€ ходу гравц€
        game.drawBoard(game.getBoard()); //в≥дображенн€ ≥грового пол€
        if (game.checkGameOver(game.getBoard()))
        {
            std::cout << "Game over! Thanks for playing!\n";
            running = false; //припиненн€ гри за умови виграшу або програшу
            break;
        }
        else if (game.checkTie(game.getBoard()))
        {
            std::cout << "It's a tie!\n";
            running = false; //припиненн€ гри за умови н≥чиЇњ
            break;
        }

        //х≥д комп'ютера
        computer.playerMove(game.getBoard(), computer.getPlayerChar()); //х≥д комп'ютерного гравц€
        game.updateMoveCount(); //оновленн€ к≥льеост≥ крок≥в п≥сл€ ходу комп'ютерного гравц€
        game.drawBoard(game.getBoard()); //в≥дображенн€ ≥грового пол€
        if (game.checkGameOver(game.getBoard()))
        {
            std::cout << "Game over! Thanks for playing!\n";
            running = false; //припиненн€ гри за умови виграшу або програшу
            break;
        }
        else if (game.checkTie(game.getBoard()))
        {
            std::cout << "It's a tie!\n";
            running = false; //припиненн€ гри за умови н≥чиЇњ
            break;
        }
    }

    std::cout << "The game was ended in " << game.getMoveCount() << " turns.\n";

    return 0;
}