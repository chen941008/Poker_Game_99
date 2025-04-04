#include "ai_operation.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "game.hpp"  // 為了使用 Game::getInstance()
#include "poker.hpp"

std::optional<Poker> AIOperation::playCard(int currentPoint, const std::vector<Poker>& hand) {
    // 定義需要檢查 currentPoint 的數字牌候選（例如 "2", "3", "6", "7", "8", "9"）
    const std::vector<std::string> numericCandidates = {"A", "2", "3", "6", "7", "8", "9"};
    std::vector<Poker> validCards;

    // 掃描手牌，找出所有屬於數字牌候選且 currentPoint + 牌值 <= 99 的牌
    // 對 "4" 做特殊處理：
    //   - 如果玩家數不為 4，則 "4" 當作一般牌 (視同數字牌)，加入考慮範圍
    //   - 如果玩家數為 4，則 "4" 不納入數字牌候選，視為功能牌
    int playerCount = Game::getInstance().getPlayerNum();
    for (const auto& card : hand) {
        std::string num = card.getNumber();
        // 如果是 "4"，根據玩家數做處理
        if (num == "4") {
            if (playerCount != 4) {
                // 當玩家數不為 4，"4" 視為一般牌，其牌值為 4
                int cardValue = card.getCardRank();  // 這裡預期 card.getCardRank() 會返回 4
                if (currentPoint + cardValue <= 99) {
                    validCards.push_back(card);
                }
            }
            // 若玩家數為 4，則略過 "4" 的數字候選（待後續作為功能牌處理）
            continue;
        }
        if (num == "A" && card.getSuit() != spade) {
            int cardValue = card.getCardRank();  // 這裡預期 card.getCardRank() 會返回 4
            if (currentPoint + cardValue <= 99) {
                validCards.push_back(card);
            }
        }
        // 對其他數字牌候選進行判斷
        if (std::find(numericCandidates.begin(), numericCandidates.end(), num) != numericCandidates.end()) {
            int cardValue = card.getCardRank();
            if (currentPoint + cardValue <= 99) {
                validCards.push_back(card);
            }
        }
    }
    // 否則，沒有可出數字牌，選擇功能牌（包括 "4" 當作功能牌的情況）
    const Poker* chosenFunctionCard = nullptr;
    for (const auto& card : hand) {
        std::string num = card.getNumber();
        // 如果是 "4"，只有在玩家數為 4時才視為功能牌
        if (num == "4" && playerCount != 4) {
            continue;  // 跳過不當作功能牌
        }
        // 如果該牌不屬於數字牌候選（numericCandidates），則視為功能牌
        if (std::find(numericCandidates.begin(), numericCandidates.end(), num) == numericCandidates.end()) {
            validCards.push_back(card);
        }
    }
    // 如果手牌非空但上述邏輯都未選中，保險起見回傳第一張牌
    if (validCards.empty() && !hand.empty()) {
        return std::nullopt;
    }
    // If there are valid cards to play, select one randomly
    if (!validCards.empty()) {
        // Initialize random seed
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, validCards.size() - 1);

        // Select a random card
        int randomIndex = distrib(gen);
        return validCards[randomIndex];
    }
    // 如手牌真空，拋出例外
    throw std::runtime_error("AI's hand is empty!");
}
