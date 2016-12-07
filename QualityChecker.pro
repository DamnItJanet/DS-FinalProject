TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DSString.cpp \
    Nests.cpp \
    FileFormat.cpp \
    SizeFile.cpp \
    NamingConv.cpp

HEADERS += \
    HashTable.h \
    AvlTree.h \
    DSString.h \
    Vector.h \
    Nests.h \
    FileFormat.h \
    NamingConv.h \
    SizeFile.h \
    LinkedList.h \
    Stack.h

QMAKE_CXX=g++-4.9

