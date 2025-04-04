#ifndef OPERATION_HPP
#define OPERATION_HPP
#include <optional>
#include <vector>

#include "poker.hpp"

class Operation {
   public:
    virtual ~Operation() {}
    virtual std::optional<Poker> playCard(int currentPoint, const std::vector<Poker>& hand) = 0;
};

#endif  // OPERATION_HPP
