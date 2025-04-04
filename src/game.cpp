#include "game.hpp"

#include <algorithm>
#include <limits>
#include <sstream>

#include "ai_operation.hpp"
#include "dealer.hpp"
#include "iostream"
#include "manual_operation.hpp"
#include "operation.hpp"
#include "player.hpp"

void Game::_setPlayerNum(int playerNum) { _playerNum = playerNum; }
void Game::_setRound(int round) { _round = round; }
int Game::getPlayerNum() const { return _playerNum; }
int Game::_getRound() const { return _round; }
int Game::getCurrentPlayer() const { return _currentPlayer; }
int Game::getCurrentRoundScore() const { return _currentRoundScore; }
void Game::_initGame() {
    _initPlayerNum();
    _initPlayer();
    _initSize();
}

void Game::_initPlayerNum() {
    std::cout << "Enter the number of players (2-5): ";
    int playerNum;
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (!(iss >> playerNum)) {
            std::cout << "Invalid input. Please enter a number between 2 and 5: ";
            continue;
        }
        if (playerNum >= 2 && playerNum <= 5) {
            break;
        }
        std::cout << "Invalid number of players. Please enter a number between 2 and 5: ";
    }
    _setPlayerNum(playerNum);
}
void Game::_setBoardScore(int score) {
    if (score < 0) score = 0;
    _currentRoundScore = score;
}

void Game::_applyCardPlayEffect(Poker &poker, Player &player) {
    if (poker.getSuit() == spade && poker.getNumber() == "A") {
        _setBoardScore(0);
    } else if (poker.getNumber() == "4" && getPlayerNum() == 4) {
        _isReverse = !_isReverse;
    } else if (poker.getNumber() == "5") {
        _showPlayerSequence();
        if (player.getIsAi()) {
            int nextPlayer = rand() % getPlayerNum() + 1;  // Random number from 1 to _playerNum
            _setNextPlayer(nextPlayer);
            std::cout << "The AI chooses next player: " << nextPlayer << std::endl;
        } else {
            int nextPlayer = 0;
            std::string input;
            std::cout << "Please choose the next player (1-" << getPlayerNum() << "): " << std::endl;
            while (true) {
                std::cout << "Please enter your choice: ";
                std::getline(std::cin, input);
                std::istringstream iss(input);
                if (!(iss >> nextPlayer)) {
                    std::cout << "Invalid input. Please enter a number between 1 and " << getPlayerNum() << ": "
                              << std::endl;
                    continue;
                }
                if (nextPlayer < 1 || nextPlayer > getPlayerNum()) {
                    std::cout << "Index out of range. Please enter a number between 1 and " << getPlayerNum() << ": "
                              << std::endl;
                    continue;
                }
                if (_players[nextPlayer - 1].getIsWinOrLose()) {
                    std::cout << "That player is already eliminated. Please choose a different player: " << std::endl;
                    continue;
                }
                break;
            }

            _setNextPlayer(nextPlayer);
        }
    } else if (poker.getNumber() == "10") {
        if (player.getIsAi()) {
            if (getCurrentRoundScore() <= 89) {
                std::cout << "The AI chooses +10." << std::endl;
                _setBoardScore(getCurrentRoundScore() + 10);
            } else {
                std::cout << "The AI chooses -10." << std::endl;
                _setBoardScore(getCurrentRoundScore() - 10);
            }
        } else {
            std::cout << "Would you like to add 10 or subtract 10? (Enter 1 to add, 2 to subtract): " << std::endl;
            int choice = 0;
            while (true) {
                std::cout << "Please enter your choice: ";
                std::string input;
                std::getline(std::cin, input);
                if (input.empty()) {
                    std::cout << "No input detected. Please try again. " << std::endl;
                    continue;
                }
                std::istringstream iss(input);
                if (!(iss >> choice)) {
                    std::cout << "Invalid input. Please enter a number 1 to add, 2 to subtract: " << std::endl;
                    continue;
                }
                if (choice != 1 && choice != 2) {
                    std::cout << "Invalid input. Please enter 1 to add or 2 to subtract: " << std::endl;
                    continue;
                }
                if (choice == 1 && getCurrentRoundScore() > 89) {
                    std::cout << "The current score is too high to add 10; please choose 2 to subtract 10. "
                              << std::endl;
                    continue;
                }
                break;
            }
            if (choice == 1) {
                _setBoardScore(getCurrentRoundScore() + 10);
            } else {
                _setBoardScore(getCurrentRoundScore() - 10);
            }
        }
    } else if (poker.getNumber() == "J") {
        // do nothing
    } else if (poker.getNumber() == "Q") {
        if (player.getIsAi()) {
            if (getCurrentRoundScore() <= 79) {
                std::cout << "The AI chooses +20." << std::endl;
                _setBoardScore(getCurrentRoundScore() + 20);
            } else {
                std::cout << "The AI chooses -20." << std::endl;
                _setBoardScore(getCurrentRoundScore() - 20);
            }
        } else {
            std::cout << "Would you like to add 20 or subtract 20? (Enter 1 to add, 2 to subtract): " << std::endl;
            int choice;
            std::string input;
            while (true) {
                std::cout << "Please enter your choice: ";
                std::getline(std::cin, input);  // 讀取整行輸入
                std::istringstream iss(input);
                if (!(iss >> choice)) {
                    std::cout << "Invalid input. ";
                    continue;
                }
                // 檢查輸入是否合法：必須是 1 或 2，且如果選擇 1，當前分數必須不超過 79
                if ((choice != 1 && choice != 2) || (choice == 1 && getCurrentRoundScore() > 79)) {
                    if (choice != 1 && choice != 2) {
                        std::cout << "Invalid input. Please enter 1 to add or 2 to subtract: " << std::endl;
                    } else if (choice == 1 && getCurrentRoundScore() > 79) {
                        std::cout << "The current score is too high to add 20; please choose 2 to subtract 20."
                                  << std::endl;
                    }
                    continue;
                }
                break;  // 輸入合法時跳出迴圈
            }
            if (choice == 1) {
                _setBoardScore(getCurrentRoundScore() + 20);
            } else {
                _setBoardScore(getCurrentRoundScore() - 20);
            }
        }
    } else if (poker.getNumber() == "K") {
        _setBoardScore(99);
    } else if (poker.getNumber() == "A") {
        _setBoardScore(getCurrentRoundScore() + 1);
    } else {
        _setBoardScore(getCurrentRoundScore() + std::stoi(poker.getNumber()));
    }
}
void Game::_setNextPlayer() {
    if (_isReverse) {
        // 將 1-based 轉成 0-based：_currentPlayer - 1，
        // 減 1，再加上 _playerNum 防止負值，
        // 取模後再轉回 1-based（+1）
        _currentPlayer = (((_currentPlayer - 1 - 1 + getPlayerNum()) % getPlayerNum()) + 1);
    } else {
        // 將 1-based 轉成 0-based，加 1 後取模，再轉回 1-based
        _currentPlayer = (((_currentPlayer - 1 + 1) % getPlayerNum()) + 1);
    }
}

void Game::_setNextPlayer(int playerNum) { _currentPlayer = playerNum; }
void Game::_initRound() {
    for (auto &player : _players) {
        player.clear();
    }
    Dealer::initDeck(_deck, _getSize());  // 初始化牌堆
    Dealer::shuffleDeck(_deck);           // 洗牌
    _initPlayerSequence();                // 初始化玩家順序
    Dealer::shuffleDeck(_deck);           // 洗牌
    _initPlayerHand();                    // 發牌
    _setBoardScore(0);                    // 初始化分數
    _setWinnerCount(0);                   // 初始化贏家數量
    _setLoserCount(0);                    // 初始化輸家數量
}
void Game::_initPlayer() {
    _players.clear();
    _players.resize(_playerNum);  // 為 _playerNum 個元素分配空間
    for (int i = 0; i < _playerNum; i++) {
        std::cout << "Enter player " << i + 1 << "'s name: ";
        std::string name;
        std::getline(std::cin, name);
        std::cout << "Is player " << i + 1 << " an AI? (1 for yes, 0 for no): ";
        int isAi;
        while (true) {
            std::string input;
            std::getline(std::cin, input);  // 讀取整行輸入
            std::istringstream iss(input);
            if (!(iss >> isAi)) {
                std::cout << "Invalid input. Please enter a number (1 for yes, 0 for no): ";
                continue;
            }
            if (isAi == 1 || isAi == 0) {
                break;  // 輸入合法就跳出迴圈
            } else {
                std::cout << "Invalid choice. Please enter 1 for yes or 0 for no: ";
            }
        }
        _players[i].init(name, isAi == 1 ? static_cast<Operation *>(new AIOperation())
                                         : static_cast<Operation *>(new ManualOperation()));
    }
}

void Game::_initPlayerSequence() {
    _currentPlayer = 1;             // 初始化當前玩家
    Dealer::deal(_players, _deck);  // 每個人抽一張牌
    for (int i = 0; i < _playerNum; i++) {
        std::cout << "Player " << _players[i].getName() << "'s hand: " << std::endl;
        _players[i].printHand();
        Dealer::addToDeck(_deck, _players[i].getHand().back());
    }
    std::sort(_players.begin(), _players.end(), [](const Player &a, const Player &b) {
        auto handA = a.getHand();  // handA 為臨時變數，但它持有了整個 vector 的複製
        auto handB = b.getHand();
        if (handA.empty() || handB.empty()) {
            // 根據需求處理空手牌情況
            return false;
        }
        const Poker &cardA = handA.front();
        const Poker &cardB = handB.front();
        int rankA = cardA.getCardRank();
        int rankB = cardB.getCardRank();
        if (rankA == rankB) {
            return cardA.getSuit() < cardB.getSuit();
        }
        return rankA > rankB;
    });
    for (int i = 0; i < _playerNum; i++) {
        _players[i].removeCard(_players[i].getHand().back());
        _players[i].setPlayerSerquence(i + 1);
    }
    _showPlayerSequence();
}
void Game::_initPlayerHand() {
    for (int i = 0; i < 5; i++) {
        Dealer::deal(_players, _deck);
    }
}

void Game::runGame() {
    std::cout << "Game started! " << std::endl;
    _initGame();
    std::cout << "Game initialized! " << std::endl;
    std::string input;
    int round = 0;
    std::cout << "How many rounds do you want to play? " << std::endl;
    while (true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (iss >> round) {
            // 可選：檢查 round 是否大於0
            if (round > 0) {
                break;
            } else {
                std::cout << "Please enter a positive number: ";
            }
        } else {
            std::cout << "Invalid input. Please enter a number: ";
        }
    }
    _setRound(round);
    for (int i = 0; i < round; i++) {
        std::cout << "Round " << i + 1 << " started!" << std::endl;
        _initRound();
        while (!_isGameOver()) {
            std::cout << "******************************************" << std::endl;
            Player &currentPlayer = _getCurrentPlayer();
            if (currentPlayer.getHand().empty() || _getWinnerCount() + _getLoserCount() + 1 == getPlayerNum()) {
                if (currentPlayer.getHand().empty()) {
                    std::cout << "Player " << currentPlayer.getName() << " has no cards left. " << std::endl;
                }
                std::cout << "Player " << currentPlayer.getName() << "has finished the round. " << std::endl;
                currentPlayer.setIsWinOrLose(true);
                currentPlayer.addScore(_getWinnerOrLoserPoint(true));
                _addWinnerCount();
                continue;
            }
            std::cout << "Current round score: " << getCurrentRoundScore() << std::endl;
            std::cout << "Current player: " << currentPlayer.getName() << std::endl;
            if (currentPlayer.getOperation() == nullptr) {
                throw std::runtime_error("Operation pointer is null for player " + currentPlayer.getName());
            }
            std::optional<Poker> cardOpt =
                currentPlayer.getOperation()->playCard(getCurrentRoundScore(), currentPlayer.getHand());
            if (!cardOpt) {
                std::cout << "No valid card to play. Player " << currentPlayer.getName() << " is eliminated. "
                          << std::endl;
                currentPlayer.setIsWinOrLose(true);
                currentPlayer.addScore(_getWinnerOrLoserPoint(false));
                _addLoserCount();
                continue;
            }
            Poker poker = *cardOpt;  // 取出值
            currentPlayer.removeCard(poker);
            std::cout << "Player " << currentPlayer.getName() << " plays: " << std::endl;
            Poker::printPoker(poker);
            _applyCardPlayEffect(poker, currentPlayer);
            std::optional<Poker> dealCard = Dealer::dealCard(_deck);
            if (dealCard) {
                currentPlayer.setHand(*dealCard);
                std::cout << "Player " << currentPlayer.getName() << " draws a card: " << std::endl;
                if (!currentPlayer.getIsAi()) {
                    Poker::printPoker(*dealCard);
                } else {
                    Poker poker = *dealCard;
                    poker.flipCard();
                    Poker::printPoker(poker);
                }
            }
            if (currentPlayer.getPlayerSerquence() == getCurrentPlayer()) {
                _setNextPlayer();
            }
        }
        std::cout << "******************************************" << std::endl;
        _showPlayersPoint();
    }
    _showPlayerRank();
    std::cout << "Game over!" << std::endl;
}
void Game::_showPlayerSequence() {
    std::cout << "Player sequence: " << std::endl;
    for (int i = 0; i < _playerNum; i++) {
        if (_players[i].getIsWinOrLose() == true) {
            continue;
        }
        std::cout << "Player " << _players[i].getName() << " is in position " << _players[i].getPlayerSerquence()
                  << std::endl;
    }
}
void Game::_setWinnerCount(int winnerCount) { _winnerCount = winnerCount; }
void Game::_setLoserCount(int loserCount) { _loserCount = loserCount; }
int Game::_getWinnerCount() const { return _winnerCount; }
int Game::_getLoserCount() const { return _loserCount; }
void Game::_addWinnerCount() { _winnerCount++; }
void Game::_addLoserCount() { _loserCount++; }
int Game::_getWinnerOrLoserPoint(bool isWinner) {
    if (isWinner) {
        return getPlayerNum() - _getWinnerCount();
    }
    return _getLoserCount() + 1;
}
bool Game::_isGameOver() {
    if (_getWinnerCount() + _getLoserCount() == getPlayerNum()) {
        return true;
    }
    return false;
}
Player &Game::_getCurrentPlayer() {
    if (_currentPlayer < 1 || _currentPlayer > _playerNum) {
        throw std::out_of_range("Invalid player number.");
    }
    while (_players[_currentPlayer - 1].getIsWinOrLose() == true) {
        _setNextPlayer();
    }
    return _players[_currentPlayer - 1];
}
void Game::_showPlayersPoint() {
    std::cout << "Players' points: " << std::endl;
    std::sort(_players.begin(), _players.end(),
              [](const Player &a, const Player &b) { return a.getScore() > b.getScore(); });
    for (auto &player : _players) {
        std::cout << "Player " << player.getName() << " scored " << player.getScore() << " points. " << std::endl;
    }
    std::cout << "******************************************" << std::endl;
}
void Game::_setSize(Size size) { _size = size; }
Size Game::_getSize() const { return _size; }
void Game::_initSize() {
    int size = 0;
    std::string input;
    std::cout << "Select card size: 1 for small, 2 for medium, 3 for large. " << std::endl;
    while (true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (!(iss >> size)) {
            std::cout << "Invalid input. Please enter a number: ";
            continue;
        }
        if (size < 1 || size > 3) {
            std::cout << "Invalid choice. Please enter 1 for small, 2 for medium, or 3 for large: ";
            continue;
        }
        break;
    }
    _setSize(static_cast<Size>(size - 1));
}
void Game::_showPlayerRank() {
    std::cout << "Players' rank:" << std::endl;

    // 將玩家按照分數從高到低排序
    std::sort(_players.begin(), _players.end(),
              [](const Player &a, const Player &b) { return a.getScore() > b.getScore(); });

    if (_players.empty()) {
        std::cout << "No players available. " << std::endl;
        return;
    }

    int rank = 1;  // 第一名
    std::cout << "Player " << _players[0].getName() << " ranks " << rank << " with " << _players[0].getScore()
              << " points. " << std::endl;

    // 從第二位開始遍歷
    for (int i = 1; i < _players.size(); i++) {
        // 如果當前玩家的分數與前一位相同，排名保持不變；否則排名更新為 i+1
        if (_players[i].getScore() != _players[i - 1].getScore()) {
            rank = i + 1;
        }
        std::cout << "Player " << _players[i].getName() << " ranks " << rank << " with " << _players[i].getScore()
                  << " points. " << std::endl;
    }

    std::cout << "******************************************" << std::endl;
}
