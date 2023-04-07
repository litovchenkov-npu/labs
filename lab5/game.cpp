#include "game.h"

namespace Game
{
    short int GameLogic::s_moveCount = 0;

    //построкове виведення ігрового поля
    void GameLogic::drawBoard(char* board)
    {
        std::cout << '\n'
            << board[0] << ' ' << board[1] << ' ' << board[2] << '\n'
            << board[3] << ' ' << board[4] << ' ' << board[5] << '\n'
            << board[6] << ' ' << board[7] << ' ' << board[8] << '\n'
            << '\n';
    };

    //перевірка умови перемоги чи програшу
    //почергово перевіряється кожен рядок, стовбець та діагональ
    bool GameLogic::checkGameOver(char* board)
    {
        bool endGame = false; //результат закінчення гри

        //переірка виграшу по вертикалі
        if ((board[0] != '#') && (board[0] == board[1]) && (board[1] == board[2]) ||
            (board[3] != '#') && (board[3] == board[4]) && (board[4] == board[5]) ||
            (board[6] != '#') && (board[6] == board[7]) && (board[7] == board[8]))
        {
            endGame = true;
        }
        //перевірка виграшу по горизонталі
        else if ((board[0] != '#') && (board[0] == board[3]) && (board[3] == board[6]) ||
            (board[1] != '#') && (board[1] == board[4]) && (board[4] == board[7]) ||
            (board[2] != '#') && (board[2] == board[5]) && (board[5] == board[8]))
        {
            endGame = true;
        }
        //перевірка виграшу по діагоналі
        else if ((board[0] != '#') && (board[0] == board[4]) && (board[4] == board[8]) ||
            (board[2] != '#') && (board[2] == board[4]) && (board[4] == board[6]))
        {
            endGame = true;
        }
        else {
            endGame = false;
        }

        return endGame;
    }

    //перевірка умови нічиєї
    bool GameLogic::checkTie(char* board)
    {
        for (int i = 0; i < 9; i++) {
            if (board[i] == '#') {
                return false; //якщо на дошці присутні пусті клітини, повертається false
            }
        }
        return true; //якщо на дошці немає пустих клітин, повертажться true
    }

    //методи get та set для ігрового поля
    char* GameLogic::getBoard()
    {
        return _board;
    }

    void GameLogic::setBoard(char newBoard[9])
    {
        memcpy(_board, newBoard, sizeof(char) * 9);
    }

    //збільшення кількості кроків гри
    void GameLogic::updateMoveCount()
    {
        s_moveCount++;
    };

    short int GameLogic::getMoveCount()
    {
        return s_moveCount;
    };
}