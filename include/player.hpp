#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "operation.hpp"
#include "poker.hpp"
class Player {
   private:
    std::vector<Poker> _hand;
    int _playerSerquence;
    std::string _name;
    int _score;
    bool _isAI;
    bool _isWinOrLose;
    Operation *operation;

   public:
    Player(const std::string &name, Operation *operation);
    Player();
    void setHand(std::vector<Poker> hand);
    void setHand(Poker poker);
    void setScore(int score);
    void setIsAi(bool isAi);
    void setName(std::string name);
    const std::vector<Poker> &getHand() const;
    int getScore() const;
    bool getIsAi() const;
    void printHand();
    void printScore();
    void printIsAi();
    void printPlayer();
    void setPlayerSerquence(int playerSerquence);
    void removeCard(int index);
    void removeCard(const Poker &card);
    void init(const std::string &name, Operation *operation);
    void clear();
    int getPlayerSerquence() const;
    void addScore(int score);
    std::string getName() const;
    bool getIsWinOrLose() const;
    void setIsWinOrLose(bool isWinOrLose);
    Operation *getOperation() const;
};

#endif  // PLAYER_HPP