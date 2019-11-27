cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME SuperMarioBros3)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/main.cpp
        src/state-machine/StateMachine.cpp
        src/state-machine/StateMachine.hpp
        src/state-machine/states/State.hpp
        src/state-machine/states/main-menu/MainMenuState.cpp
        src/state-machine/states/main-menu/MainMenuState.hpp
        src/views/main-menu/MainMenuView.hpp
        src/views/main-menu/MainMenuSubmenues.hpp
        src/views/main-menu/SfmlMainMenuView.cpp
        src/views/main-menu/SfmlMainMenuView.hpp
        src/exceptions/MoveBackException.cpp
        src/exceptions/MoveBackException.hpp
        src/exceptions/ExitReqiredException.cpp
        src/exceptions/ExitReqiredException.hpp
        src/state-machine/states/State.cpp
        src/state-machine/states/about-menu/AboutMenuState.cpp
        src/state-machine/states/about-menu/AboutMenuState.hpp
        src/views/about-menu/AboutMenuView.hpp
        src/views/credits-menu/CreditsMenuView.hpp
        src/state-machine/states/credits/CreditsMenuState.cpp
        src/state-machine/states/credits/CreditsMenuState.hpp
        src/views/about-menu/SfmlAboutMenuView.cpp
        src/views/about-menu/SfmlAboutMenuView.hpp
        src/views/factory/ViewFactory.hpp
        src/views/factory/SfmlViewFactory.cpp
        src/views/factory/SfmlViewFactory.hpp
        src/resource-loader/SfmlResourceLoader.cpp
        src/resource-loader/SfmlResourceLoader.hpp
        src/views/credits-menu/SfmlCreditsMenuView.cpp
        src/views/credits-menu/SfmlCreditsMenuView.hpp
        src/game/sfml-super-mario/Animation.cpp
        src/game/sfml-super-mario/Animation.hpp
        src/game/sfml-super-mario/Game.cpp
        src/game/sfml-super-mario/Game.hpp
        src/game/sfml-super-mario/GameObject.cpp
        src/game/sfml-super-mario/GameObject.hpp
        src/game/sfml-super-mario/GameObjectManager.cpp
        src/game/sfml-super-mario/GameObjectManager.hpp
        src/game/sfml-super-mario/Player.cpp
        src/game/sfml-super-mario/Player.hpp
        src/sfml-provider/SfmlProvider.cpp
        src/sfml-provider/SfmlProvider.hpp
        src/state-machine/states/game-state/GameState.cpp
        src/state-machine/states/game-state/GameState.hpp
        src/game/sfml-super-mario/Camera.cpp
        src/game/sfml-super-mario/Camera.hpp
        )

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/cpp/SFML_2_4_2)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()