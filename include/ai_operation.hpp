#ifndef AI_OPERATION_HPP
#define AI_OPERATION_HPP
#include "operation.hpp"
class AIOperation : public Operation {
   public:
    std::optional<Poker> playCard(int currentPoint, const std::vector<Poker>& hand) override;

   private:
};

#endif  // AI_OPERATION_HPP