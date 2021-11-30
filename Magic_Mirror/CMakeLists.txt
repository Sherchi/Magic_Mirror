cmake_minimum_required(VERSION 3.20)
project(Magic_Mirror)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#Boost config
set(BOOST_ROOT "C++_Libraries/Boost/boost_1_61_0")
find_package(Boost 1.57.0)
find_package(Boost COMPONENTS system filesystem regex REQUIRED)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

find_package(OpenSSL REQUIRED)

#QT config
set(Qt5_DIR "/usr/lib/x86_64-linux-gnu")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)

add_executable(Magic_Mirror Magic_Mirror/Bootstrapper/main.cpp Magic_Mirror/Bootstrapper/MainWindow.cpp Magic_Mirror/Bootstrapper/MainWindow.h
        Magic_Mirror/News/APIRequest.h Magic_Mirror/News/APIRequest.cpp Magic_Mirror/News/articleData.h Magic_Mirror/News/articleData.cpp Magic_Mirror/News/imgDownloader.h
        Magic_Mirror/News/imgDownloader.cpp
        Magic_Mirror/Weather/getWeather.h Magic_Mirror/Weather/getWeather.cpp Magic_Mirror/Webcam/Camera.cpp Magic_Mirror/Webcam/Camera.h
        Magic_Mirror/Webcam/Camera.h Magic_Mirror/Webcam/Camera.cpp
        Magic_Mirror/Date_and_Time/clock.h Magic_Mirror/Date_and_Time/clock.cpp
        Magic_Mirror/User_System/User.h Magic_Mirror/User_System/User.cpp Magic_Mirror/User_System/UserSystem.h Magic_Mirror/User_System/UserSystem.cpp
        Magic_Mirror/Utils/ClickableLabel.cpp Magic_Mirror/Utils/ClickableLabel.h
        Magic_Mirror/User_System/LoginPopupWidget/LoginPopup.cpp Magic_Mirror/User_System/LoginPopupWidget/LoginPopup.h
        Magic_Mirror/User_System/AdminAccountInfoWidget/AdminAccountInfo.cpp Magic_Mirror/User_System/AdminAccountInfoWidget/AdminAccountInfo.h
        Magic_Mirror/Date_and_Time/ClockWidget/ClockWidget.cpp Magic_Mirror/Date_and_Time/ClockWidget/ClockWidget.h
        Magic_Mirror/Date_and_Time/CalendarWidget/calendarWidget.cpp Magic_Mirror/Date_and_Time/CalendarWidget/calendarWidget.h
        Magic_Mirror/Date_and_Time/CalendarWidget/event.cpp Magic_Mirror/Date_and_Time/CalendarWidget/event.h
        Magic_Mirror/News/NewsWidget/NewsWidget.cpp Magic_Mirror/News/NewsWidget/NewsWidget.h
        Magic_Mirror/Weather/WeatherWidget/WeatherWidget.cpp Magic_Mirror/Weather/WeatherWidget/WeatherWidget.h
        Magic_Mirror/User_System/UserSystemWidget/UserSystemWidget.cpp Magic_Mirror/User_System/UserSystemWidget/UserSystemWidget.h
        Magic_Mirror/User_System/UserAccountInfoWidget/UserAccountInfo.cpp Magic_Mirror/User_System/UserAccountInfoWidget/UserAccountInfo.h
        Magic_Mirror/User_System/CreateUserWidget/CreateUser.cpp Magic_Mirror/User_System/CreateUserWidget/CreateUser.h
        Magic_Mirror/Date_and_Time/AddEventWidget/AddEvent.cpp Magic_Mirror/Date_and_Time/AddEventWidget/AddEvent.h
        Magic_Mirror/MailClient/Email.h Magic_Mirror/MailClient/Email.cpp Magic_Mirror/MailClient/Inbox.h Magic_Mirror/MailClient/Inbox.cpp
        Magic_Mirror/MailClient/MailClient.h Magic_Mirror/MailClient/MailClient.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(Magic_Mirror Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}
        ${Boose_REGEX_LIBRARY} jsoncpp Threads::Threads ${CMAKE_CURRENT_SOURCE_DIR}/Magic_Mirror/MailClient/mailio/build/libmailio.a OpenSSL::SSL Boost::regex)
