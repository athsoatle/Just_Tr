#include <iostream>
#include <vector>

template <typename T, typename U>
class Pair {
public:
	Pair() {}
	Pair(T first, U second) :
		first_(first), second_(second) {}
private:
	T first_;
	U second_;
};

template<typename Iterator>
struct IteratorRange {
	Iterator Begin() {
		return first;
	}
	Iterator End() {
		return last;
	}
	Iterator first;
	Iterator last;
};

template <typename T>
IteratorRange <typename std::vector <T>::iterator> Head(std::vector <T>& v, size_t top) {
	return {
	v.begin(), next(v.begin(), std::min(top , v.size()))
	};
}

template<typename T>
size_t RangeSize(IteratorRange<T> r) {
	return r.end() − r.begin();
}

template <typename T> struct Widget {
	Widget(T value);
};
Widget w_int(5);


int main() {
	Pair <bool, int> pr;
	return 0;
}
