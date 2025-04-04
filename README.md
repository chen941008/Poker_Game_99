# Poker_Game_99 👉 [Read this in Mandarin](README.zh-TW.md)

## Overview

Poker_Game_99 is an object-oriented poker game project written in C++ that utilizes CMake for build management and is built using the C++17 standard.

## How to Use

### 1. Clone the Repository
  ```bash
  git clone https://github.com/chen941008/Poker_Game_99
  ```
### 2. Build and Run
Ensure that you have CMake (version 3.28 or later) and a C++17-compliant compiler installed, then follow these steps:
  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ./Poker_Game_99
  ```
## Game Flow
- **Game Initialization:**  Follow the prompts to enter the number of players (2-5), player names, whether they are AI, and the card size.
- **Round Progression:** In each round, players take turns playing and drawing cards. Card effects (e.g., "4", "10", "Q") influence the round score and game state.
- **End Conditions:** When a player is unable to play a card or has run out of cards, the system determines win/loss and accumulates scores according to the game rules.
- **Results Display:** At the end of each round, the system displays the scores and final rankings of all players.
  
![GitHub Views](https://komarev.com/ghpvc/?username=chen941008&repo=Poker_Game_99) 