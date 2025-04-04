#ifndef POKER_HPP
#define POKER_HPP
#include <iostream>
#include <string>
#include <vector>

enum Suit { spade, heart, diamond, club };
enum Size { small, melidem, large };
class Poker {
   private:
    Suit _suit;
    Size _size;
    static int _blank;
    bool _isFaceUp;
    std::string _number;
    std::vector<std::string> _picture;
    std::vector<std::string> _backPattern;
    void setPicture(Suit suit, Size size, std::string number);
    void setBackPattern(Size size);
    void setLargePicture(Suit suit, std::string number);
    void setMelidemPicture(Suit suit, std::string number);
    void setSmallPicture(Suit suit, std::string number);
    void setLargeBackPattern();
    void setMelidemBackPattern();
    void setSmallBackPattern();

   public:
    Poker(Suit suit, Size size, std::string number, bool isFaceUp);
    static void printPoker(const std::vector<Poker> &pokers);
    static void printPoker(const std::vector<Poker> &pokers, int row);
    static void printPoker(const Poker &poker);
    void flipCard();

    /**************setter**************/
    void setSuit(Suit suit);
    void setSize(Size size);
    void setNumber(std::string number);
    void setIsFaceUp(bool isFaceUp);
    static void setBlank(int blank);
    /**************getter**************/
    Suit getSuit() const;
    Size getSize() const;
    std::string getNumber() const;
    bool getIsFaceUp() const;
    static int getBlank();
    int getCardRank() const;
};
// 在 Poker.hpp 的末尾或 class 定義外部
inline bool operator==(const Poker &lhs, const Poker &rhs) {
    return lhs.getSuit() == rhs.getSuit() && lhs.getSize() == rhs.getSize() && lhs.getNumber() == rhs.getNumber();
}

inline bool operator!=(const Poker &lhs, const Poker &rhs) { return !(lhs == rhs); }

#endif  // OKER_HPP