project(KEcm)
cmake_minimum_required(VERSION 2.6)

SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTXML TRUE)

find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)

#add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})

include_directories( ${QT_INCLUDES}  ${KDE4_INCLUDES}  ${CMAKE_CURRENT_BINARY_DIR} /usr/include/qt4/qtsoap)

#include_directories(/usr/include/qt4/qtsoap)
#include_directories()
#include_directories(/usr/include/qt4/QtNetwork)	
#include_directories(/usr/include/qt4/QtXml)
#add_subdirectory(lib)

set(KEcm_SRCS KEcmConfigure.cpp KEcm.cpp main.cpp)

kde4_add_kcfg_files(KEcm_SRCS GENERATE_MOC KEcmSettings.kcfgc)
kde4_add_ui_files(KEcm_SRCS conexao.ui)

qt4_automoc(${KEcm_SRCS})

add_executable(KEcm ${KEcm_SRCS})

target_link_libraries(KEcm  ${KDE4_KDEUI_LIBS} 
${QT_QTCORE_LIBRARY} 
${QT_QTGUI_LIBRARY} 
${QT_QTXML_LIBRARY} 
${QT_QTNETWORK_LIBRARY} 
/home/cassio/projects/KEcm/lib/libQtSoap.so)

install(TARGETS KEcm RUNTIME DESTINATION bin)
install(FILES kecmsettings.kcfg DESTINATION ${KCFG_INSTALL_DIR})
