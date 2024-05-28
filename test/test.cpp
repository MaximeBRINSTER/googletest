#include <gtest/gtest.h>
#include "PrintTask.h"

using namespace std;

TEST(PrintTaskTest, ExecutePrintsMessage) {
    string expected_message = "Hello World!";
    testing::internal::CaptureStdout();
    PrintTask task(expected_message);
    task.execute();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, expected_message + "\n");
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
