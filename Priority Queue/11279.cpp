#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

// 연습용 priority_queue 쓰면 더 쉬움
void insert(int x) {
	heap.push_back(x);		// x를 추가하고
	int i = heap.size() - 1;	// 배열 크기
	int p = (i - 1) / 2;	// 부모 인덱스

	while (i > 0) {
		if (heap[p] < heap[i]) {	// 부모가 자식보다 작으면
			swap(heap[p], heap[i]);	// 교체하기
			i = p;					// 부모 위치로 갱신하기
			p = (i - 1) / 2;		// 갱신한 위치의 부모 인덱스
		}
		else break;
	}
}

int pop() {
	int root = heap[0];
	heap[0] = heap.back();	// 제일 뒤에 있는 거
	heap.pop_back();		// 제일 뒤에 있는 걸 제거함

	int i = 0;
	while (1) {
		int left = i * 2 + 1;
		int right = i * 2 + 2;

		if (left >= heap.size()) break;		// 자식이 없음

		else if (left < heap.size() && right >= heap.size()) {	// 자식이 왼쪽만 있음
			if (heap[i] < heap[left]) {	// 자식이 더 큼
				swap(heap[i], heap[left]);
				i = left;
			}
			else break;
		}
		else if (right < heap.size()) {			// 자식 둘 다 있음
			if (heap[left] < heap[right]) {		// 오른쪽이 왼쪽보다 더 크고
				if (heap[i] < heap[right]) {	// 오른쪽이 부모보다 큼
					swap(heap[i], heap[right]);
					i = right;
				}
				else break;
			}
			else {								// 왼쪽이 오른쪽보다 더 크고
				if (heap[i] < heap[left]) {		// 왼쪽이 부모보다 큼
					swap(heap[i], heap[left]);
					i = left;
				}
				else break;
			}
		}
	}
	return root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num != 0) {
			insert(num);
		}
		else {
			if (heap.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pop() << '\n';
			}
		}
	}
}

