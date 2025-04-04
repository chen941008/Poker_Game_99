# 99 Rules

## Game Setup
1. Each player starts with 0 points.
2. The game supports 2 to 5 players. Except for one designated player, all other players are controlled by the computer.
3. Each player starts with 5 cards in hand.

## Scoring
- **Spades A**: Resets the score to zero.
- **A**: Adds 1 point.
- **2**: Adds 2 points.
- **3**: Adds 3 points.
- **4**: Reverse Card  
  - In a four-player game, this card reverses the turn order from ascending to descending.  
  - In two- or three-player games, it is treated as adding 4 points.
- **5**: Designated Card  
  - The player who plays this card can choose the next player to take a turn. If a computer plays this card, the next player is chosen randomly.
- **6**: Adds 6 points.
- **7**: Adds 7 points.
- **8**: Adds 8 points.
- **9**: Adds 9 points.
- **10**: Can either add 10 points or subtract 10 points.
- **J**: Skip Turn (the player does not play this round).
- **Q**: Can either add 20 points or subtract 20 points.
- **K**: Sets the current score directly to 99.

## Game Flow
1. **Determining the Play Order**  
   - At the beginning of each round, each player draws one card from a deck of 52 cards to determine the play order.  
   - The player with the higher card value plays first; if the values are the same, the suits are ranked (Spades > Hearts > Diamonds > Clubs).  
   - The results of the draw determine the turn order (the higher the card, the earlier the turn).

2. **Dealing Cards**  
   - After determining the play order, the drawn cards are returned to the deck, which is then shuffled and each player is dealt 5 cards.

3. **Playing Cards**  
   - Players take turns playing cards according to the established order, with the effects of the played cards updating the current score.

4. **Drawing Cards**  
   - After playing a card, each player draws one card from the deck to maintain a hand of 5 cards.  
   - If the deck runs out of cards, the game continues using the remaining cards in hand.

5. **Winning Condition**  
   - When a player plays all of their cards and the current score is less than 99, that player wins the round and earns points based on the total number of players (e.g., in a four-player game, the first winner receives 4 points, the second receives 3 points, etc.).

6. **Elimination Rule**  
   - If, during their turn, a player's remaining hand combined with the current score exceeds 99 and they cannot play a special card (Spades A, 4, 5, 10, J, Q, or K), that player is eliminated.  
   - The order of elimination determines the points assigned (the first eliminated receives 1 point, the second receives 2 points, etc.).

7. **Remaining Points**  
   - Players who neither win nor are eliminated in a round receive the remaining points.  
   - For example, in a game with four players, if player A wins first (earning 4 points), player B is the first eliminated (earning 1 point), and player C wins second (earning 3 points), then the remaining player D receives 2 points.

8. **Score Tally and Final Ranking**  
   - At the end of each round, the scores of all players are tallied.  
   - After all rounds are completed, the final rankings are determined based on the cumulative scores and announced.
