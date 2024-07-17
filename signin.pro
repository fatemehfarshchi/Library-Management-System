QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbook.cpp \
    addmember.cpp \
    dashboard.cpp \
    deletebook.cpp \
    deletemember.cpp \
    issuebook.cpp \
    main.cpp \
    returnbook.cpp \
    searchbook.cpp \
    sign_up.cpp \
    signin.cpp

HEADERS += \
    addbook.h \
    addmember.h \
    dashboard.h \
    deletebook.h \
    deletemember.h \
    issuebook.h \
    returnbook.h \
    searchbook.h \
    sign_up.h \
    signin.h

FORMS += \
    addbook.ui \
    addmember.ui \
    dashboard.ui \
    deletebook.ui \
    deletemember.ui \
    issuebook.ui \
    returnbook.ui \
    searchbook.ui \
    sign_up.ui \
    signin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
