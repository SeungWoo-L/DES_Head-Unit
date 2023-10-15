cmake_minimum_required(VERSION 3.14)

project(DES_Project3_IC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package(...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    qml.qrc
)

# Add resource files
set(RESOURCE_FILES
    images/battery.png
)

# CMake에서 .qrc 파일을 자동으로 처리하기 위한 설정
qt_add_resources(QRC_FILES qml.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DES_Project3_IC
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${QRC_FILES}  # 추가된 부분: .qrc 파일 포함
    )
else()
    if(ANDROID)
        add_library(DES_Project3_IC SHARED
            ${PROJECT_SOURCES}
            ${QRC_FILES}  # 추가된 부분: .qrc 파일 포함
        )
    else()
        add_executable(DES_Project3_IC
            ${PROJECT_SOURCES}
            ${QRC_FILES}  # 추가된 부분: .qrc 파일 포함
        )
    endif()
endif()

target_compile_definitions(DES_Project3_IC
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)
target_link_libraries(DES_Project3_IC
    PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
)

set_target_properties(DES_Project3_IC PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(DES_Project3_IC)
    qt_finalize_executable(DES_Project3_IC)
endif()

foreach(RESOURCE ${RESOURCE_FILES})
    configure_file(${RESOURCE} ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach()
