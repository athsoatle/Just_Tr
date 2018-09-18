#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdio>

using namespace std;

vector < vector <long long int> > main_graph;
vector <bool> used;

void dfs(int index) {
	used[index] = true;
	for (auto i : main_graph[index]) {
		if (!used[i])  dfs(i);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input_trs1.txt", "r", stdin);
	freopen("output_trs2.txt", "w", stdout);
#else
	freopen("input_trs1.txt", "r", stdin);
	freopen("output_trs2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	system("PAUSE");
	return 0;
}