#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#define pass (void)0

#include <limits>
#include <iostream>
#include <stack>
#include <queue>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <list>
#include <cstring>


int main(int argc, char ** argv) {
	int n;
	std::string command;
	int command_arg;
	std::string work;
	std::cin >> n;
	std::vector <int> year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int j = 0;
	std::vector <std::vector <std::string>> month(year[j]);
	for (int i = 0; i < n; i++) {
		std::cin >> command;
		if (command == "ADD") {
			std::cin >> command_arg >> work;
			month[command_arg - 1].push_back(work);
		}
		if (command == "NEXT") {
			j += 1;
			if (j == 12)  j = 0;
			if (j == 0) {
				month[0] = month[11];
			}
			else {
				if (year[j] > year[j - 1]) {
					month.resize(year[j]);
				}
				else {
					if (year[j - 1] - year[j] == 3) {
						std::vector <std::string> temp1 = month[year[j - 1] - 1];
						std::vector <std::string> temp2 = month[year[j - 1] - 2];
						std::vector <std::string> temp3 = month[year[j - 1] - 3];
						month.resize(year[j]);
						month[year[j] - 1].insert(end(month[year[j] - 1]), begin(temp1), end(temp1));
						month[year[j] - 1].insert(end(month[year[j] - 1]), begin(temp2), end(temp2));
						month[year[j] - 1].insert(end(month[year[j] - 1]), begin(temp3), end(temp3));
					}
					if (year[j - 1] - year[j] == 1) {
						std::vector <std::string> temp1 = month[year[j - 1] - 1];
						month.resize(year[j]);
						month[year[j] - 1].insert(end(month[year[j] - 1]), begin(temp1), end(temp1));
					}
				}
			}
		}
		if (command == "DUMP") {
			std::cin >> command_arg;
			std::cout << month[command_arg - 1].size() << " ";
			for (auto w : month[command_arg - 1]) {
				std::cout << w << " ";
			}
			std::cout << std::endl;
		}
	}
	system("PAUSE");
	return 0;
}
