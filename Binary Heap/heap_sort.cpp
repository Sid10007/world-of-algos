#include<bits/stdc++.h>
#include"heap_sort.h"

int main() {
	vector<int> arr;

	long n;
	cin >> n;

	for(long i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	heap_sort(arr, n);

	for(auto val: arr)
		cout << val << "  ";
	cout << "\n";

	return 0;
}

