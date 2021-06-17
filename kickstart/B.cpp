#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vi A(n);
		for (int i=0; i<n; i++) cin >> A[i];

		vector<int> T(n, 0);
		for (int j=0; j<n; j++) {
			if (T[j] == 1 || T[j] == -1) continue;
			else if (j+A[j] >= n || j+A[j] < 0) T[j] == 1;
			else if (T[j+A[j]] == -1) T[j] == -1;
			else {
				while (T[j+A[j]] != 1 || )
					// TODO finish code of this (somewhat recursion based?)
			}
		}
	}

	return 0;
}