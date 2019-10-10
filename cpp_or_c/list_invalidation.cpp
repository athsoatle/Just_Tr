#include "test_runner.h"
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>


int main() {
	std::list<int> a = { 1, 2, 3, 4, 5, 6 };
	std::list<int>::iterator it = a.begin();
	std::advance(it, 2);// points at 3
	std::list<int>::iterator itt = a.begin();
	std::advance(itt, 4);//points at 5
	std::list<int> b;
	b.splice(b.begin(), a, a.begin(), it);
	/*std::cout << "b : \n";
	for (const auto& item : b) {
		std::cout << item << " ";
	}
	std::cout << "\n";
	std::cout << "a : \n";
	for (const auto& item : a) {
		std::cout << item << " ";
	}
	std::cout << "\n";*/
	b.insert(b.end(), *itt);
	b.splice(b.end(), a, std::next(it), itt);
	b.insert(b.end(), *it);
	b.splice(b.end(), a, std::next(itt), a.end());
	for (const auto& item : b) {
		std::cout << item << " ";
	}
	std::cout << "\n";
	std::cout << "a : \n";
	for (const auto& item : a) {
		std::cout << item << " ";
	}
	std::cout << "\n";
	std::cout << "It =" << *it << "itt = " << *itt << "\n";
	//true
	/*const auto iterator2_next = next(iterator2);
	lst.splice(iterator1, lst, iterator2);
	lst.splice(iterator2_next, lst, iterator1);*/
	return 0;
}
