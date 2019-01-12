#ifndef HEAP_SORT
#define HEAP_SORT

#define AND &&
#define OR ||

using namespace std;


int left_child(long index) {
	return 2 * index + 1;
}


int right_child(long index) {
	return 2 * index + 2;
}


int parent(long index) {
	return (index - 1) / 2;
}

void heapify(vector<int> &arr, long index, long max_size) {
	long left = left_child(index), right = right_child(index), largest;
	
	if(left < max_size AND arr[left] >= arr[index]) 
		largest = left;
	else
		largest = index;

	if(right < max_size AND arr[right] >= arr[largest])
		largest = right;

	if(largest != index) {
		int temp = arr[largest];
		arr[largest] = arr[index];
		arr[index] = temp;

		heapify(arr, largest, max_size);
	}
}


void build_heap(vector<int> &arr, long max_size) {
	for(long i = max_size / 2; i >= 0; i--) 
		heapify(arr, i, max_size);
}


void heap_sort(vector<int> &arr, long max_size) {
	build_heap(arr, max_size);
	long n = max_size;

	for(long i = n - 1; i > 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		heapify(arr, 0, i);
	}
}


#endif