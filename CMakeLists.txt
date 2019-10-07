cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME SuperMarioBros3)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        src/state-machine/state-machine.cpp
        src/state-machine/state-machine.hpp
        src/state-machine/states/state.hpp
        src/state-machine/states/main-menu-state.cpp
        src/state-machine/states/main-menu-state.hpp
        src/presenters/main-menu/main-menu-presenter.hpp
        src/presenters/main-menu/main-menu-submenues.hpp
        src/presenters/main-menu/sfml-main-menu-presenter.cpp
        src/presenters/main-menu/sfml-main-menu-presenter.hpp
        src/exceptions/move-back-exception.cpp
        src/exceptions/move-back-exception.hpp
        src/exceptions/exit-required-exception.cpp
        src/exceptions/exit-required-exception.hpp
        src/state-machine/states/state.cpp
        src/state-machine/states/about-menu-state.cpp
        src/state-machine/states/about-menu-state.hpp
        src/presenters/about-menu/about-menu-presenter.hpp
        src/presenters/credits-menu/credits-menu-presenter.hpp
        src/state-machine/states/credits-menu-state.cpp
        src/state-machine/states/credits-menu-state.hpp
        src/presenters/about-menu/sfml_about_menu_presenter.cpp
        src/presenters/about-menu/sfml_about_menu_presenter.hpp
        src/presenters/factory/presenter-factory.hpp src/presenters/factory/sfml-presenter-factory.cpp src/presenters/factory/sfml-presenter-factory.hpp)

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