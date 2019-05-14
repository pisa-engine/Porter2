#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Porter2.hpp"

using namespace ::testing;
using namespace ::porter2;

TEST(Porter2Test, TestVerbInIng) {
    Stemmer stemmer;
    auto thestem = stemmer("eating");
    ASSERT_EQ(thestem, "eat");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
