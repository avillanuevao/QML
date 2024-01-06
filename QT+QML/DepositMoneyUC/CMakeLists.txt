cmake_minimum_required(VERSION 3.14)

project(DepositMoneyUC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)


file(GLOB_RECURSE UTILS
    ${PROJECT_SOURCE_DIR}/utils/*.hpp  #Variable
    ${PROJECT_SOURCE_DIR}/utils/*.cpp)

file(GLOB_RECURSE VIEW
    ${PROJECT_SOURCE_DIR}/view/*.hpp  #Variable
    ${PROJECT_SOURCE_DIR}/view/*.cpp)

file(GLOB_RECURSE MODEL
    ${PROJECT_SOURCE_DIR}/model/*.hpp  #Variable
    ${PROJECT_SOURCE_DIR}/model/*.cpp)

file(GLOB_RECURSE CONTROLLER
    ${PROJECT_SOURCE_DIR}/controller/*.hpp  #Variable
    ${PROJECT_SOURCE_DIR}/controller/*.cpp)

set(PROJECT_SOURCES
        ${UTILS}    #Tomar Valor Variable
        ${VIEW}
        ${MODEL}
        ${CONTROLLER}
        main.cpp
        qml.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DepositMoneyUC
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DepositMoneyUC APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DepositMoneyUC SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DepositMoneyUC
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(DepositMoneyUC
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(DepositMoneyUC
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

set_target_properties(DepositMoneyUC PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(DepositMoneyUC)
    qt_finalize_executable(DepositMoneyUC)
endif()
