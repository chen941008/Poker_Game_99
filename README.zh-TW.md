# Poker_Game_99 👉 [用英文閱讀](README.md)

## 專案概述

這是一個以 C++ 撰寫的物件導向撲克牌遊戲專案，採用 CMake 來管理編譯流程，並設定使用 C++17 標準。

## 如何使用

### 1. Clone 專案
  ```bash
  git clone https://github.com/chen941008/Poker_Game_99
  ```
### 2. 編譯與執行
請確保已安裝 CMake（版本 3.28 或更高）以及支援 C++17 的編譯器，然後依照以下步驟操作：
  ```bash
  mkdir build
  cd build
  cmake ..
  make
  ./Poker_Game_99
  ```
## 遊戲流程
- **遊戲初始化：** 根據提示依次輸入玩家數量（2-5 人）、玩家姓名、是否為 AI 以及卡牌大小。
- **回合進行：** 每回合中，玩家依序出牌與抽牌，牌面效果（例如「4」、「10」、「Q」等）會影響回合分數與遊戲狀態。
- **結束條件：** 當玩家無法出牌或手牌用盡時，系統依照遊戲規則決定勝負並累計得分。
- **結果展示：** 回合結束後，系統會顯示各玩家的得分與最終排名。
  
![GitHub Views](https://komarev.com/ghpvc/?username=chen941008&repo=Poker_Game_99) 