// dialgaTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define BOOST_TEST_MODULE treeTest
#include "../../dialga/include/tree.h"
#include "../../dialgaShared/include/dialgaUtils.h"

#include <boost/test/unit_test.hpp>

#include <string>
#include <algorithm>

using intTreeT = dialga::tree<int>;

struct treeFixture
{
    treeFixture()
    {
        BOOST_TEST_MESSAGE("populating tree...");
        int nums[] = { 1, 7, 2, 4, 5 };
        const size_t numEls = sizeof(nums) / sizeof(int);

        std::for_each(nums, nums + numEls, [&](int x) {
            _root.insert(x);
            });
    }
    intTreeT _root;
};

BOOST_FIXTURE_TEST_CASE(testTreePreOrder, treeFixture)
{
    std::vector<int> cont;
    _root.preOrder(cont);
    BOOST_CHECK("1x72x4x5xxx" == dialgaUtils::vec2Str(cont));
}

BOOST_FIXTURE_TEST_CASE(testTreePostOrder, treeFixture)
{
    std::vector<int> cont;
    _root.postOrder(cont);
    BOOST_CHECK("xxxxx542x71" == dialgaUtils::vec2Str(cont));
}

BOOST_FIXTURE_TEST_CASE(testTreeInOrder, treeFixture)
{
    std::vector<int> cont;
    _root.inOrder(cont);
    BOOST_CHECK("x1x2x4x5x7x" == dialgaUtils::vec2Str(cont));
}

