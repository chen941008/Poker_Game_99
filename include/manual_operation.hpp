#ifndef MANUAL_OPERATION_HPP
#define MANUAL_OPERATION_HPP
#include "operation.hpp"
class ManualOperation : public Operation {
   public:
    std::optional<Poker> playCard(int currentPoint, const std::vector<Poker>& hand) override;

   private:
};
#endif  // MANUAL_OPERATION_HPP