#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Porter2/Porter2.hpp"

using namespace ::testing;
using namespace ::stem;

TEST(Porter2Test, TestVerbInIng) {
    Porter2 stemmer;
    auto thestem = stemmer.stem("eating");
    ASSERT_EQ(thestem, "eat");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}