#ifndef DEALER_HPP
#define DEALER_HPP
#include <random>
#include <vector>

#include "player.hpp"
#include "poker.hpp"
class Dealer {
   private:
    // 私有建構子，使用局部靜態變數實現單例
    Dealer() : gen(rd()) {}

    // 將隨機數生成器改為實例成員
    std::random_device rd;
    std::mt19937 gen;

   public:
    // 單例存取方法，使用局部靜態變數確保線程安全
    static Dealer &getInstance() {
        static Dealer instance;
        return instance;
    }
    // 禁止複製和賦值
    Dealer(const Dealer &) = delete;
    Dealer &operator=(const Dealer &) = delete;
    static void shuffleDeck(std::vector<Poker> &);
    static void deal(std::vector<Player> &, std::vector<Poker> &);
    static std::optional<Poker> dealCard(std::vector<Poker> &deck);
    template <typename T>
    static void removeCard(Player &player, const T &cardOrIndex) {
        try {
            player.removeCard(cardOrIndex);
        } catch (const std::out_of_range &e) {
            std::cerr << "Error removing card from player: " << e.what() << std::endl;
            // 根據需求可以做其他錯誤處理
        }
    }
    static void addToDeck(std::vector<Poker> &deck, Poker poker);
    static void initDeck(std::vector<Poker> &deck, Size size);
};

#endif  // DEALER_HPP