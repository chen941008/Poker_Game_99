#include "dealer.hpp"

#include <algorithm>
void Dealer::shuffleDeck(std::vector<Poker>& deck) {
    Dealer& dealer = Dealer::getInstance();  // 取得單例實例
    std::shuffle(deck.begin(), deck.end(), dealer.gen);
}
void Dealer::deal(std::vector<Player>& players, std::vector<Poker>& deck) {
    for (auto& player : players) {
        player.setHand(deck.back());
        deck.pop_back();
    }
}

std::optional<Poker> Dealer::dealCard(std::vector<Poker>& deck) {
    if (!deck.empty()) {
        Poker card = deck.back();
        deck.pop_back();
        return card;
    }
    return std::nullopt;  // 如果牌堆空了，返回 nullopt
}
void Dealer::initDeck(std::vector<Poker>& deck, Size size) {
    deck.clear();
    deck.reserve(52);  // 預先分配 52 個位置，避免多次分配記憶體
    Poker::setBlank(0);
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 0) {
                deck.push_back(Poker(static_cast<Suit>(j), size, "A", true));
            } else if (i == 10) {
                deck.push_back(Poker(static_cast<Suit>(j), size, "J", true));
            } else if (i == 11) {
                deck.push_back(Poker(static_cast<Suit>(j), size, "Q", true));
            } else if (i == 12) {
                deck.push_back(Poker(static_cast<Suit>(j), size, "K", true));
            } else {
                deck.push_back(Poker(static_cast<Suit>(j), size, std::to_string(i + 1), true));
            }
        }
    }
}
void Dealer::addToDeck(std::vector<Poker>& deck, Poker poker) { deck.push_back(poker); }