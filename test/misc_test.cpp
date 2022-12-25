#include <unity.h>
#include <Storage.h>
// Danger Zone !!!

#define TEST_CREDENTIALS(actual, expected) TEST_ASSERT_EQUAL_STRING(actual.username.c_str(), expected.username.c_str()); \
                                           TEST_ASSERT_EQUAL_STRING(actual.password.c_str(), expected.password.c_str());

void setUp() {
    Storage::storeCredentials({"Hello", "World"});
}

void test_storage_io() {
    Storage::t_Crendentials actual = Storage::readCredentials();
    Storage::t_Crendentials expected = {"Hello", "World"};
    TEST_CREDENTIALS(actual, expected);
}

void test_storage_creds_are_there() {
    bool actual = Storage::credentialsSet();
    TEST_ASSERT_TRUE(actual);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_storage_creds_are_there);
    RUN_TEST(test_storage_io);
}

void loop() {
    UNITY_END();
}