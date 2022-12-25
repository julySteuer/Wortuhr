#include <unity.h>
#include <ClockControl.h>
#include <Data.h>
#include <Arduino.h>

#define TEST_TIME_PROPERTY(actual, expected) TEST_ASSERT_EQUAL(expected.preNum, actual.preNum); \
                                             TEST_ASSERT_EQUAL(expected.delim, actual.delim); \
                                             TEST_ASSERT_EQUAL(expected.hour, actual.hour);

#define TEST_WORD(actual, expected) TEST_ASSERT_EQUAL(expected.begin, actual.begin); \
                                    TEST_ASSERT_EQUAL(expected.end, actual.end);

void test_clock_parser() {
    ClockControl::t_TimeProperty actual = ClockControl::parseTime(30,12);
    ClockControl::t_TimeProperty expected = {1,ClockControl::Deliminator::Nach,1};
    TEST_TIME_PROPERTY(actual, expected);
}


void test_get_minutes() {
    struct Data::t_Word actual = Data::getMinute(20);
    struct Data::t_Word expected = {24,30};
    TEST_WORD(actual, expected);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_clock_parser);   // Doe not work for namespaces  
    RUN_TEST(test_get_minutes);
}

void loop() {
    
    UNITY_END();
}