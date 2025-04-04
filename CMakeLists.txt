cmake_minimum_required(VERSION 3.28)
project(Poker_Game_99)

# 指定 C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# (可選) 產生 compile_commands.json，方便編輯器取得正確的 include path 設定
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 搜集 src 資料夾裡所有的 .cpp 檔案
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# 排除掉 main.cpp（如果你想單獨管理它的話）
list(FILTER SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# 建立可執行檔，並把 main.cpp 加入
add_executable(Poker_Game_99 "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# 將其餘 .cpp 檔案加入 Reg_hw2 target
target_sources(Poker_Game_99 PRIVATE ${SOURCES})

# 指定 include 目錄，這裡假設 include 資料夾位於 Regular_class 下
target_include_directories(Poker_Game_99 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
