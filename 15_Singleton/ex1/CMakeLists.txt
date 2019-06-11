# CMakeList.txt : CMakeProject1 の CMake プロジェクト。ソースを含めて、次を定義します:
# プロジェクト専用ロジックはこちらです。
#
cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME "15_Singleton_ex1")

project(${PROJECT_NAME})

# ソースをこのプロジェクトの実行可能ファイルに追加します。
add_executable (${PROJECT_NAME} "main.cpp" "main.h" "singleton.h" "singleton.cpp")

# TODO: テストを追加し、必要な場合は、ターゲットをインストールします。
