# #####################################################################
# trab2FT qmake
# #####################################################################
QT += core \
    gui

# app indica ao qmake que estamos montando uma aplicacão
TEMPLATE = app

# Diretórios onde estarão outros arquivos do projeto
DEPENDPATH += src
INCLUDEPATH += .
INCLUDEPATH += src

# Pasta onde os arquivos temporarios de compilacao ficaram armazenados
OBJECTS_DIR = tmp
MOC_DIR = tmp
RCC_DIR = tmp

# Diretorio onde os arquivos executaveis serao gerados
DESTDIR = bin

# Indica ao qmake que vamos utilizar a biblioteca qt
# com os modulos core e gui (que sao os que utilizaremos)
CONFIG += qt

# Indica se deve criar um makefile com suporte aos simbolos de debug ou nao
CONFIG += debug

# CONFIG += release
# #DEFINES += QT_NO_DEBUG_OUTPUT
# #DEFINES += QT_NO_WARNING_OUTPUT
# Habilitando os warnings do compilador no makefile.
CONFIG += warn_on

# Se estivermos em uma plataforma Windows
win32 { 
    # Se estiver em modo debug, incluimos as bibliotecas de console para podermos
    # utilizar funcoes de debug como a qDebug():
    # http://doc.qtsoftware.com/4.5/qtglobal.html#qDebug
    debug:CONFIG += console
    
    # Então configura de acordo.
    CONFIG += windows
}

# # Windows common build here
# Se estivermos em ambiente unix
unix:CONFIG += x11

# Versao do trab2FT =]
VERSION = 0.0.1

# Nome do executavel criado
TARGET = trab2FT

# # ADICIONEM OS ARQUIVOS AQUI ##
# Arquivos .h
HEADERS += src/Trab2FT.h \
    src/HalfEdge.h \
    src/Face.h \
    src/Vertex.h \
    src/Interface.h \
    src/PlyParser.h \
    src/KDTree.h
HEADERS += src/MainWindow.h
HEADERS += src/RenderPanel.h
HEADERS += src/Render.h
HEADERS += src/CommandQueue.h

# Arquivos .cpp
SOURCES += src/Trab2FT.cpp \
    src/HalfEdge.cpp \
    src/Face.cpp \
    src/Vertex.cpp \
    src/Interface.cpp \
    src/PlyParser.cpp \
    src/KDTree.cpp
SOURCES += src/MainWindow.cpp
SOURCES += src/RenderPanel.cpp
SOURCES += src/Render.cpp
SOURCES += src/CommandQueue.cpp

# Arquivos dos resources (imagens por exemplo) do jogo
RESOURCES += trab2FT.qrc
