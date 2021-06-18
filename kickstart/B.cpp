#include <bits/stdc++.h>
using namespace std;

#define N 1000001

typedef long long ll;
typedef vector<int> vi;

int traverse(vector<int>& A, vector<int>& T, int i, int n) {
	if (i >= n || i < 0) {
		return 1;
	}
	else if (T[i] == 1) {
		return 1;
	}
	else if (T[i] == -1 || T[i] == 2) {
		return -1;
	}
	else {
		T[i] = 2;
		T[i] = traverse(A,T,i+A[i],n);
		return T[i];
	}
}

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vi A(n);
		vi T(n,0);
		for (int i=0; i<n; i++) {
			cin >> A[i];
		}
		for (int i=0; i<n; i++) {
			traverse(A,T,i,n);
		}

		vi idxs;
		for (int i=0; i<n; i++) {
			if (T[i] == 1) idxs.push_back(i+1);
		}
		cout << idxs.size() << endl;
		for (int k : idxs) cout << k << " ";
		cout << endl;
	}

	return 0;
}