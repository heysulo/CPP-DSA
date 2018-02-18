#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {
	DynamicArray<int> x(5, 3);
	x[2] = 2;
	x[3] = 3;
	x[4] = 4;
	x[5] = 5;
	x[6] = 6; // requires scaling
	x[5] = 55;
	x[12] = 12; // requires scaling
	x[13] = 13;
	x[14] = 14;
	printf("%d %d %d\n", x[2], x[6], x[14]);
	return 0;
}
