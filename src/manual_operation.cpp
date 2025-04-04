#include "manual_operation.hpp"

#include <iostream>
#include <sstream>

#include "game.hpp"  // 為了使用 Game::getInstance()
std::optional<Poker> ManualOperation::playCard(int currentPoint, const std::vector<Poker>& hand) {
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
    if (validCards.empty()) {
        return std::nullopt;  // 沒有可出的牌
    }
    std::cout << "The cards, from left to right, are numbered from 1 to " << hand.size() << ". " << std::endl;
    Poker::printPoker(hand);
    int index = 0;
    while (true) {
        std::cout << "Please select a card to play (1 to " << hand.size() << "): ";
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        if (!(iss >> index)) {
            std::cout << "Invalid input. Please enter a number:" << std::endl;
            continue;
        }
        if (index < 1 || index > hand.size()) {
            std::cout << "Index out of range. Please select a card (1 to " << hand.size() << "): " << std::endl;
            continue;
        }
        if (std::find(validCards.begin(), validCards.end(), hand[index - 1]) == validCards.end()) {
            std::cout << "Selected card is not valid. Please select a valid card: " << std::endl;
            continue;
        }
        break;
    }

    // 當離開迴圈時，index 是合法且對應一張可出的牌
    Poker chosenCard = hand[index - 1];
    return chosenCard;
}