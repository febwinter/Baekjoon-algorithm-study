#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


using namespace std;

int n;
long long sum;
int temp[4];
vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;

vector<int> AB;
vector<int> CD;

pair<vector<int>::iterator, vector<int>::iterator> range;
vector<int>::iterator sumTest;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	// 입력

	for (int i = 0; i < n; i++) {
		cin >> temp[0] >> temp[1] >> temp[2] >> temp[3];
		A.emplace_back(temp[0]);
		B.emplace_back(temp[1]);
		C.emplace_back(temp[2]);
		D.emplace_back(temp[3]);
	}

	// A+B
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.emplace_back((A[i] + B[j]) * -1);
		}
	}
	// C+D
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			CD.emplace_back(C[i] + D[j]);
		}
	}

	// 이진탐색 위해 sorting
	sort(CD.begin(), CD.end());
	// 이진탐색 및 갯수 합산
	for (int i = 0; i < AB.size(); i++) {

		range = equal_range(CD.begin(), CD.end(), AB[i]);
		// iterator 변환
		sum += distance(CD.begin(), range.second) - distance(CD.begin(), range.first);
	}

	cout << sum;
	return 0;
}