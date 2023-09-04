#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(int arr[], int N, int i)
{
	int largest = i;        // Initialize largest as root
	int l = 2 * i + 1;
	int r = 2 * i + 2;
    
    // If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;
    
    // If right child is larger than largest so far
	if (r < N && arr[r] > arr[largest])
		largest = r;
    
    // If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);
        
        // Recursively heapify the affected sub-tree
		heapify(arr, N, largest);
	}
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int N)
{
    // Index of last non-leaf node
	int startIdx = (N / 2) - 1;
	
	// Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, N, i);
	}
}

void printHeap(int arr[], int N)
{
	cout << "Array representation of Heap is:\n";

	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

	int N = 11;

	buildHeap(arr, N);
	printHeap(arr, N);

	return 0;
}
