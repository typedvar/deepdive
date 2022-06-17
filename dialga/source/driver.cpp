#include <iostream>
#include <vector>
#include <algorithm>

#include <tree.h>
#include "../../dialgaShared/include/dialgaUtils.h"

using intTreeT = dialga::tree<int>;

int main()
{
	intTreeT root;
	int nums[] = {1, 7, 2, 4, 5};
	const size_t numEls = sizeof(nums) / sizeof(int);
	
	std::for_each(nums, nums + numEls, [&](int x) {
		root.insert(x);
		});

	std::string out;
	std::vector<int> cont1;
	root.preOrder(cont1);
	std::cout << "Pre-order - " << dialgaUtils::vec2Str(cont1) << std::endl;

	std::vector<int> cont2;
	root.postOrder(cont2);
	std::cout << "Post-order - " << dialgaUtils::vec2Str(cont2) << std::endl;

	std::vector<int> cont3;
	root.inOrder(cont3);
	std::cout << "In-order - " << dialgaUtils::vec2Str(cont3) << std::endl;

	return 0;
}

