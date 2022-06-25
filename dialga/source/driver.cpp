#include <iostream>
#include <vector>
#include <algorithm>

#include <tree.h>
#include "../../dialgaShared/include/dialgaUtils.h"

using intTreeT = dialga::containers::tree<int>;

int main()
{
    intTreeT root;

    const std::string fileName = "../../dialgaShared/data/test00.txt";
    std::vector<int>& input = dialga::utils::fetchTest(fileName);
    for (auto& x : input)
    {
        root.insert(x);
    }

    int treeIndentPerLevel = 2;

    std::cout << "Tree - " << std::endl << root.toString(treeIndentPerLevel) << std::endl;

    std::string sep = "-";
    std::vector<int> cont1;
    root.preOrder(cont1);
    std::cout << "Pre-order - " << dialga::utils::vec2Str(cont1, sep) << std::endl;

    std::vector<int> cont2;
    root.postOrder(cont2);
    std::cout << "Post-order - " << dialga::utils::vec2Str(cont2, sep) << std::endl;

    std::vector<int> cont3;
    root.inOrder(cont3);
    std::cout << "In-order - " << dialga::utils::vec2Str(cont3, sep) << std::endl;

    intTreeT* balanced = root.balance();
    if (balanced)
    {
        std::cout << "Balanced tree - " << std::endl << balanced->toString(treeIndentPerLevel) << std::endl;
    }

    return 0;
}

