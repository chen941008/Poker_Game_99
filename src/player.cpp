#include "player.hpp"

#include <iostream>
#include <vector>

#include "ai_operation.hpp"
#include "poker.hpp"
Player::Player(const std::string& name, Operation* operation) { init(name, operation); }
Player::Player() : _playerSerquence(0), _score(0), _isAI(false), _isWinOrLose(false), operation(nullptr) {}
void Player::setHand(std::vector<Poker> hand) { _hand = hand; }
void Player::setHand(Poker poker) { _hand.push_back(poker); }
void Player::setScore(int score) { _score = score; }
void Player::setIsAi(bool isAi) { _isAI = isAi; }
const std::vector<Poker>& Player::getHand() const { return _hand; }
int Player::getScore() const { return _score; }
bool Player::getIsAi() const { return _isAI; }
void Player::printHand() {
    for (auto i : _hand) {
        Poker::printPoker(i);
    }
}
void Player::printScore() { std::cout << "Score: " << _score << std::endl; }
void Player::printIsAi() { std::cout << "Is AI: " << _isAI << std::endl; }
void Player::printPlayer() {
    printHand();
    printScore();
    printIsAi();
}
void Player::setName(std::string name) { _name = name; }
std::string Player::getName() const { return _name; }
void Player::setPlayerSerquence(int playerSerquence) { _playerSerquence = playerSerquence; }
int Player::getPlayerSerquence() const { return _playerSerquence; }
void Player::removeCard(int index) {
    if (index < 0 || index >= _hand.size()) {
        throw std::out_of_range("Invalid card index.");
    }
    _hand.erase(_hand.begin() + index);
}
void Player::removeCard(const Poker& card) {
    auto it = std::find(_hand.begin(), _hand.end(), card);
    if (it == _hand.end()) {
        throw std::out_of_range("Card not found in hand.");
    }
    _hand.erase(it);
}

void Player::init(const std::string& name, Operation* operation) {
    _name = name;
    this->operation = operation;
    if (operation && typeid(*operation) == typeid(AIOperation)) {
        _isAI = true;
    } else {
        _isAI = false;
    }
    _hand.clear();
    _score = 0;
    _playerSerquence = 0;
    _isWinOrLose = false;
}
void Player::clear() {
    _hand.clear();
    _playerSerquence = 0;
    _isWinOrLose = false;
}
void Player::addScore(int score) { _score += score; }
bool Player::getIsWinOrLose() const { return _isWinOrLose; }
void Player::setIsWinOrLose(bool isWinOrLose) { _isWinOrLose = isWinOrLose; }
Operation* Player::getOperation() const { return operation; }