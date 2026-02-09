#include <iostream>
#define SIZE 1000000
using namespace std;

int arr[SIZE];

void merge(int a[], int m, int middle, int n) {
	int i = m, j = middle + 1, k = m;
	while (i <= middle && j <= n) {
		if (a[i] <= a[j])
			arr[k++] = a[i++];
		else arr[k++] = a[j++];
	}
	if (i > middle)
		for (int t = j; t <= n; t++, k++)
			arr[k] = a[t];
	else
		for (int t = i; t <= middle; t++, k++)
			arr[k] = a[t];

	for (int t = m; t <= n; t++)
		a[t] = arr[t];
}

void mergeSort(int a[], int m, int n) {
	int middle;
	if (m < n) {
		middle = (m + n) / 2;
		mergeSort(a, m, middle);		// 앞 쪽 분할
		mergeSort(a, middle + 1, n);	// 뒷 쪽 분할
		merge(a, m, middle, n);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int* list = new int[n];
	for (int i = 0; i < n; i++)
		cin >> list[i];

	mergeSort(list, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << list[i] << '\n';

}