#include <cstring>
#include "HashMap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <ctime>

int main(int argc, char* argv[]) {
	int start_s = clock();
	int arrSize;
	if (argc == 1) {
		std::cout << "Enter array size : ";
		std::cin >> arrSize;
		start_s = clock();
	}
	else {
		arrSize = atoi(argv[1]);
	}
	printf("Using %d as the arraySize.\n", arrSize);
	HashMap* hm = new HashMap(arrSize);
	unsigned int collissionCounts = 0;

	std::ifstream in("dictionary.txt");

	if (!in) {
		std::cout << "Cannot open input file.\n";
		return 1;
	}

	char str[20];
	while (in) {
		in.getline(str, 20);
		collissionCounts += hm->addNode(str);
	}

	std::cout << collissionCounts << " collisions" << std::endl;
	delete hm;
	in.close();
	int stop_s = clock();
	std::cout << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << std::endl;
	return 0;
}
