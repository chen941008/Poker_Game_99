#include "poker.hpp"
#define RED "\033[31;1m"
#define DEFAULT "\033[0;1m"
#define WHITE "\033[1;37m"
Poker::Poker(Suit suit, Size size, std::string number, bool isFaceUp)
    : _suit(suit), _size(size), _isFaceUp(isFaceUp), _number(number) {
    setPicture(suit, size, number);
    setBackPattern(size);
}
int Poker::_blank = 1;
void Poker::flipCard() { _isFaceUp = !_isFaceUp; }
void Poker::setSuit(Suit suit) { _suit = suit; }
void Poker::setSize(Size size) { _size = size; }
void Poker::setNumber(std::string number) { _number = number; }
void Poker::setIsFaceUp(bool isFaceUp) { _isFaceUp = isFaceUp; }
void Poker::setBlank(int blank) { _blank = blank; }
int Poker::getBlank() { return _blank; }
std::string Poker::getNumber() const { return _number; }
Suit Poker::getSuit() const { return _suit; }
Size Poker::getSize() const { return _size; }
bool Poker::getIsFaceUp() const { return _isFaceUp; }
void Poker::setPicture(Suit suit, Size size, std::string number) {
    switch (size) {
        case small:
            setSmallPicture(suit, number);
            break;
        case melidem:
            setMelidemPicture(suit, number);
            break;
        case large:
            setLargePicture(suit, number);
            break;
    }
}
void Poker::setBackPattern(Size size) {
    switch (size) {
        case small:
            setSmallBackPattern();
            break;
        case melidem:
            setMelidemBackPattern();
            break;
        case large:
            setLargeBackPattern();
            break;
    }
}
void Poker::setSmallPicture(Suit suit, std::string number) {
    std::string suitStr;
    switch (suit) {
        case spade:
            suitStr = "♠";
            break;
        case heart:
            suitStr = "♥";
            break;
        case diamond:
            suitStr = "♦";
            break;
        case club:
            suitStr = "♣";
            break;
    }
    _picture.push_back("┌───┐");
    (number == "10") ? _picture.push_back("│ T │") : _picture.push_back("│ " + number + " │");
    _picture.push_back("│ " + suitStr + " │");
    _picture.push_back("└───┘");
}
void Poker::setSmallBackPattern() {
    _backPattern.push_back("┌───┐");
    _backPattern.push_back("│***│");
    _backPattern.push_back("│***│");
    _backPattern.push_back("└───┘");
}
void Poker::setMelidemPicture(Suit suit, std::string number) {
    std::string suitStr;
    switch (suit) {
        case spade:
            suitStr = "♠";
            break;
        case heart:
            suitStr = "♥";
            break;
        case diamond:
            suitStr = "♦";
            break;
        case club:
            suitStr = "♣";
            break;
    }
    _picture.push_back("┌───────┐");
    _picture.push_back("│" + suitStr + "      │");
    _picture.push_back("│       │");
    (_number == "10") ? _picture.push_back("│   T   │") : _picture.push_back("│   " + number + "   │");
    _picture.push_back("│       │");
    _picture.push_back("│      " + suitStr + "│");
    _picture.push_back("└───────┘");
}
void Poker::setMelidemBackPattern() {
    _backPattern.push_back("┌───────┐");
    _backPattern.push_back("│░░░░░░░│");
    _backPattern.push_back("│░░░░░░░│");
    _backPattern.push_back("│░░░░░░░│");
    _backPattern.push_back("│░░░░░░░│");
    _backPattern.push_back("│░░░░░░░│");
    _backPattern.push_back("└───────┘");
}
void Poker::setLargePicture(Suit suit, std::string number) {
    switch (suit) {
        case spade:
            _picture.push_back("+---------------+");  // 17 chars wide
            (_number == "10") ? _picture.push_back("|10             |")
                              : _picture.push_back("|" + _number + "              |");
            _picture.push_back("|      ▟█▙      |");
            _picture.push_back("|     ▟███▙     |");
            _picture.push_back("|    ▟█████▙    |");
            _picture.push_back("|   ▟███████▙   |");
            _picture.push_back("|  ▟█████████▙  |");
            _picture.push_back("| ▟███████████▙ |");
            _picture.push_back("|▐█████████████▌|");
            _picture.push_back("|▐█████████████▌|");
            _picture.push_back("|▐█████████████▌|");
            _picture.push_back("|▐█████████████▌|");
            _picture.push_back("|▐█████████████▌|");
            _picture.push_back("| ▜███████████▛ |");
            _picture.push_back("|  ▜█████████▛  |");
            _picture.push_back("|   ▐███████▌   |");
            _picture.push_back("|     ▐███▌     |");
            _picture.push_back("|     ▐███▌     |");
            _picture.push_back("|    ▗█████▖    |");
            _picture.push_back("|   ▟███████▙   |");
            (_number == "10") ? _picture.push_back("|            10|")
                              : _picture.push_back("|              " + _number + "|");
            _picture.push_back("+---------------+");
            break;

        case heart:
            _picture.push_back("+---------------+");
            (_number == "10") ? _picture.push_back("|10             |")
                              : _picture.push_back("|" + _number + "              |");
            _picture.push_back("|               |");
            _picture.push_back("|   ♥♥♥   ♥♥♥   |");
            _picture.push_back("|  ♥♥♥♥♥ ♥♥♥♥♥  |");
            _picture.push_back("| ♥♥♥♥♥♥♥♥♥♥♥♥♥ |");
            _picture.push_back("|♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥|");
            _picture.push_back("|♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥|");
            _picture.push_back("|♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥|");
            _picture.push_back("| ♥♥♥♥♥♥♥♥♥♥♥♥♥ |");
            _picture.push_back("| ♥♥♥♥♥♥♥♥♥♥♥♥♥ |");
            _picture.push_back("|  ♥♥♥♥♥♥♥♥♥♥♥  |");
            _picture.push_back("|  ♥♥♥♥♥♥♥♥♥♥♥  |");
            _picture.push_back("|   ♥♥♥♥♥♥♥♥♥   |");
            _picture.push_back("|   ♥♥♥♥♥♥♥♥♥   |");
            _picture.push_back("|    ♥♥♥♥♥♥♥    |");
            _picture.push_back("|     ♥♥♥♥♥     |");
            _picture.push_back("|     ♥♥♥♥♥     |");
            _picture.push_back("|      ♥♥♥      |");
            _picture.push_back("|       ♥       |");
            (_number == "10") ? _picture.push_back("|             10|")
                              : _picture.push_back("|              " + _number + "|");
            _picture.push_back("+---------------+");
            break;
        case diamond:
            _picture.push_back("+---------------+");
            (_number == "10") ? _picture.push_back("|10             |")
                              : _picture.push_back("|" + _number + "              |");
            _picture.push_back("|               |");
            _picture.push_back("|               |");
            _picture.push_back("|       ✧       |");
            _picture.push_back("|      ✦✧✦      |");
            _picture.push_back("|     ✧✦✧✦✧     |");
            _picture.push_back("|    ✦✧✦✧✦✧✦    |");
            _picture.push_back("|   ✧✦✧✦✧✦✧✦✧   |");
            _picture.push_back("|  ✦✧✦✧✦✧✦✧✦✧✦  |");
            _picture.push_back("| ✧✦✧✦✧✦✧✦✧✦✧✦✧ |");
            _picture.push_back("|✦✧✦✧✦✧✦✧✦✧✦✧✦✧✦|");
            _picture.push_back("| ✧✦✧✦✧✦✧✦✧✦✧✦✧ |");
            _picture.push_back("|  ✦✧✦✧✦✧✦✧✦✧✦  |");
            _picture.push_back("|   ✧✦✧✦✧✦✧✦✧   |");
            _picture.push_back("|    ✦✧✦✧✦✧✦    |");
            _picture.push_back("|     ✧✦✧✦✧     |");
            _picture.push_back("|      ✦✧✦      |");
            _picture.push_back("|       ✧       |");
            _picture.push_back("|               |");
            (_number == "10") ? _picture.push_back("|             10|")
                              : _picture.push_back("|              " + _number + "|");
            _picture.push_back("+---------------+");
            break;
        case club:
            _picture.push_back("+---------------+");
            (_number == "10") ? _picture.push_back("|10             |")
                              : _picture.push_back("|" + _number + "              |");
            _picture.push_back("|       ☘       |");
            _picture.push_back("|      ☘☘☘      |");
            _picture.push_back("|     ☘☘☘☘☘     |");
            _picture.push_back("|    ☘☘☘☘☘☘☘    |");
            _picture.push_back("|   ☘☘     ☘☘   |");
            _picture.push_back("|  ☘☘       ☘☘  |");
            _picture.push_back("| ☘☘         ☘☘ |");
            _picture.push_back("| ☘☘    ☘    ☘☘ |");
            _picture.push_back("| ☘☘   ☘☘☘   ☘☘ |");
            _picture.push_back("| ☘☘  ☘☘☘☘☘  ☘☘ |");
            _picture.push_back("|  ☘☘ ☘☘☘☘☘ ☘☘  |");
            _picture.push_back("|   ☘☘☘☘☘☘☘☘☘   |");
            _picture.push_back("|    ☘☘☘☘☘☘☘    |");
            _picture.push_back("|     ☘☘☘☘☘     |");
            _picture.push_back("|      ☘☘☘      |");
            _picture.push_back("|       ☘       |");
            _picture.push_back("|      ☘☘☘      |");
            _picture.push_back("|     ☘☘☘☘☘     |");
            (_number == "10") ? _picture.push_back("|             10|")
                              : _picture.push_back("|              " + _number + "|");
            _picture.push_back("+---------------+");
            break;
            break;
    }
}
void Poker::setLargeBackPattern() {
    _backPattern.push_back("+---------------+");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("|***************|");
    _backPattern.push_back("+---------------+");
}

void Poker::printPoker(const std::vector<Poker>& pokers) {
    int pokerSize = pokers.size();
    int columns = pokers[0]._picture.size();
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < pokerSize; j++) {
            if (pokers[j]._isFaceUp) {
                if (pokers[j].getSuit() == heart || pokers[j].getSuit() == diamond) {
                    std::cout << RED << pokers[j]._picture[i] << DEFAULT;
                } else {
                    std::cout << WHITE << pokers[j]._picture[i] << DEFAULT;
                }
            } else {
                std::cout << pokers[j]._backPattern[i];
            }
            if (j != pokerSize - 1) {
                for (int k = 0; k < _blank; k++) {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}
void Poker::printPoker(const std::vector<Poker>& pokers, int row) {
    std::vector<Poker> subPokers;
    int pokerSize = pokers.size();
    int groups = (pokerSize + row - 1) / row;  // 確保處理所有牌
    for (int i = 0; i < groups; i++) {
        subPokers.clear();
        for (int j = 0; j < row; j++) {
            if (i * row + j >= pokerSize) break;
            subPokers.push_back(pokers[i * row + j]);
        }
        printPoker(subPokers);
        std::cout << std::endl;
    }
}

void Poker::printPoker(const Poker& poker) {
    if (poker.getIsFaceUp()) {
        if (poker.getSuit() == heart || poker.getSuit() == diamond) {
            std::cout << RED;
        } else {
            std::cout << WHITE;
        }
        for (const auto& line : poker._picture) {
            std::cout << line << std::endl;
        }
    } else {
        for (const auto& line : poker._backPattern) {
            std::cout << line << std::endl;
        }
    }
    std::cout << DEFAULT;
}
int Poker::getCardRank() const {
    if (_number == "A") {
        return 1;
    } else if (_number == "K") {
        return 13;
    } else if (_number == "Q") {
        return 12;
    } else if (_number == "J") {
        return 11;
    } else if (_number == "10") {
        return 10;
    } else {
        return std::stoi(_number);
    }
}