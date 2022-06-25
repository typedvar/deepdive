// dialgaTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define BOOST_TEST_MODULE treeTest
#include "../../dialga/include/tree.h"
#include "../../dialgaShared/include/dialgaUtils.h"

#include <boost/test/unit_test.hpp>

#include <string>
#include <algorithm>

using intTreeT = dialga::containers::tree<int>;

struct treeFixture
{
    treeFixture()
    {
        BOOST_TEST_MESSAGE("populating tree...");
        const std::string fileName = "../../dialgaShared/data/test00.txt";
        std::vector<int>& input = dialga::utils::fetchTest(fileName);
        for (auto& x : input)
        {
            _root.insert(x);
        }
    }
    intTreeT _root;
    std::string _sep = "-";
};

BOOST_FIXTURE_TEST_CASE(testTreePreOrder, treeFixture)
{
    std::vector<int> cont;
    _root.preOrder(cont);
    BOOST_CHECK("1-2-3-4-5-7-8-9-10-11-12-13-14-15-16" == dialga::utils::vec2Str(cont, _sep));
}

BOOST_FIXTURE_TEST_CASE(testTreePostOrder, treeFixture)
{
    std::vector<int> cont;
    _root.postOrder(cont);
    BOOST_CHECK("16-15-14-13-12-11-10-9-8-7-5-4-3-2-1" == dialga::utils::vec2Str(cont, _sep));
}

BOOST_FIXTURE_TEST_CASE(testTreeInOrder, treeFixture)
{
    std::vector<int> cont;
    _root.inOrder(cont);
    BOOST_CHECK("1-2-3-4-5-7-8-9-10-11-12-13-14-15-16" == dialga::utils::vec2Str(cont, _sep));
}

BOOST_FIXTURE_TEST_CASE(testBalancedTreeInOrder, treeFixture)
{
    std::vector<int> cont;
    intTreeT* balanced = _root.balance();
    if (balanced)
    {
        balanced->inOrder(cont);
        delete balanced;
    }
    BOOST_CHECK("1-2-3-4-5-7-8-9-10-11-12-13-14-15-16" == dialga::utils::vec2Str(cont, _sep));
}

