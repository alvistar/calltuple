#include <tuple>
#include "google/gtest/include/gtest/gtest.h"
#include "../call_tuple.h"

void dummy(int first, int second) {

}

int add (int first, int second) {
    return first+second;
}

std::string capitalize (std::string str) {
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);
    return str;
}

TEST(CallTuple, TwoParamsRet) {
    auto t = std::make_tuple (4,5);
    auto res = call(add, t);
    ASSERT_EQ(res,9);
}

TEST(CallTuple, OneParamRet) {
    auto t = std::make_tuple ("blue");
    auto res = call(capitalize, t);
    ASSERT_EQ(res,"BLUE");
}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}