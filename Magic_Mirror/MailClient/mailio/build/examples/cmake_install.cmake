# Install script for directory: /home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_folders" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_folders")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_folders"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/imap_folders")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/imap_folders")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_folders" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_folders")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_folders")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_remove_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_remove_msg")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_remove_msg"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/imap_remove_msg")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/imap_remove_msg")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_remove_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_remove_msg")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/imap_remove_msg")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_search" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_search")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_search"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/imaps_search")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/imaps_search")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_search" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_search")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_search")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_stat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_stat")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_stat"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/imaps_stat")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/imaps_stat")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_stat" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_stat")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/imaps_stat")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3_remove_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3_remove_msg")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3_remove_msg"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/pop3_remove_msg")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/pop3_remove_msg")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3_remove_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3_remove_msg")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3_remove_msg")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_attachment" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_attachment")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_attachment"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/pop3s_attachment")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/pop3s_attachment")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_attachment" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_attachment")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_attachment")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_fetch_one" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_fetch_one")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_fetch_one"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/pop3s_fetch_one")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/pop3s_fetch_one")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_fetch_one" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_fetch_one")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/pop3s_fetch_one")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtp_utf8_qp_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtp_utf8_qp_msg")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtp_utf8_qp_msg"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/smtp_utf8_qp_msg")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/smtp_utf8_qp_msg")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtp_utf8_qp_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtp_utf8_qp_msg")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtp_utf8_qp_msg")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_attachment" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_attachment")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_attachment"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/smtps_attachment")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/smtps_attachment")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_attachment" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_attachment")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_attachment")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_simple_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_simple_msg")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_simple_msg"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/share/mailio/examples/smtps_simple_msg")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/usr/local/share/mailio/examples" TYPE EXECUTABLE FILES "/home/nolan/CLionProjects/Magic Mirror/Magic_Mirror/MailClient/mailio/build/examples/smtps_simple_msg")
  if(EXISTS "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_simple_msg" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_simple_msg")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/local/share/mailio/examples/smtps_simple_msg")
    endif()
  endif()
endif()

