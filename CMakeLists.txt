cmake_minimum_required(VERSION 3.21)

project(PurpleNavigator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(PurpleNavigator
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
    src/pages/OverviewPage.cpp
    src/pages/OverviewPage.h
    src/pages/DetailsPage.cpp
    src/pages/DetailsPage.h
    src/pages/SettingsPage.cpp
    src/pages/SettingsPage.h
)

target_link_libraries(PurpleNavigator PRIVATE Qt6::Widgets)

target_include_directories(PurpleNavigator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(PurpleNavigator PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS PurpleNavigator
    BUNDLE DESTINATION .
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES LICENSE DESTINATION share/doc/PurpleNavigator)

include(InstallRequiredSystemLibraries)

if(WIN32)
    set(CPACK_GENERATOR "ZIP")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop;ZIP")
else()
    set(CPACK_GENERATOR "TGZ;ZIP")
endif()

set(CPACK_PACKAGE_NAME "PurpleNavigator")
set(CPACK_PACKAGE_VENDOR "PurpleNavigator")
set(CPACK_PACKAGE_CONTACT "")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A Qt Widgets navigation shell with stacked views")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_FILE_NAME "PurpleNavigator-${PROJECT_VERSION}-${CMAKE_SYSTEM_NAME}")

include(CPack)