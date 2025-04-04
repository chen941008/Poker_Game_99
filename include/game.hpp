#ifndef GAME_HPP
#define GAME_HPP
#include <random>

#include "player.hpp"
#include "poker.hpp"
class Game {
   private:
    Game() {}
    std::vector<Player> _players;
    std::vector<Poker> _deck;
    Size _size;
    int _playerNum;
    int _round;
    int _currentPlayer;
    int _currentRoundScore;
    int _winnerCount;
    int _loserCount;
    bool _isReverse;
    void _initGame();
    void _initRound();
    void _initPlayerNum();
    void _applyCardPlayEffect(Poker &poker, Player &player);
    void _initPlayer();
    void _initPlayerSequence();
    void _initPlayerHand();
    void _setBoardScore(int score);
    void _setNextPlayer();
    void _setNextPlayer(int playerNum);
    void _showPlayerSequence();
    int _getWinnerOrLoserPoint(bool isWinner);
    int _getWinnerCount() const;
    int _getLoserCount() const;
    void _setWinnerCount(int winnerCount);
    void _setLoserCount(int loserCount);
    void _addWinnerCount();
    void _addLoserCount();
    bool _isGameOver();
    void _showPlayersPoint();
    void _setSize(Size size);
    void _initSize();
    Size _getSize() const;
    Player &_getCurrentPlayer();
    void _showPlayerRank();
    void _setPlayerNum(int playerNum);
    void _setRound(int round);
    int _getRound() const;

   public:
    // 禁止複製與賦值
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

    // 單例存取方法，使用局部靜態變數確保線程安全
    static Game &getInstance() {
        static Game instance;
        return instance;
    }
    void runGame();
    int getCurrentRoundScore() const;
    int getCurrentPlayer() const;
    int getPlayerNum() const;
};

#endif  // GAME_HPP