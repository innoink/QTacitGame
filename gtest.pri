GTEST_PATH = c:/prog/gtest-1.7.0

isEmpty(GTEST_PATH) {
}
else {
        INCLUDEPATH += $$GTEST_PATH/include

        win32-msvc2015 {
            LIBS += -L$$GTEST_PATH/build/Debug
        } else {
            LIBS += -L$$GTEST_PATH/lib/.libs
        }
}

LIBS += -lgtest
