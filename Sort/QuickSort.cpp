#include <iostream>
#include <vector>
using namespace std;

int partition(int a[], int begin, int end, int size) {
	int L = begin, R = end, temp;
	int pivot = (L + R) / 2;

	while (L < R) {
		while ((L < R) && (a[L] < a[pivot])) L++;
		while ((L < R) && (a[R] >= a[pivot])) R--;
		if (L < R) {
			swap(a[L], a[R]);
			if (L == pivot)
				pivot = R;
		}
	}
	swap(a[pivot], a[R]);
	return R;
}

void QuickSort(int a[], int begin, int end, int size) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end, size);
		QuickSort(a, begin, p - 1, size);
		QuickSort(a, p + 1, end, size);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	QuickSort(arr, 0, n - 1, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;

}