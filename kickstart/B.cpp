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
		vector<int> T(n, 0);
		for (int i=0; i<n; i++) {
			cin >> A[i];
		}


		for (int j=0; j<n; j++) {
			if (T[j] == 1 || T[j] == -1) continue;
			else if (j+A[j] >= n || j+A[j] < 0) T[j] = 1;
			else if (T[j+A[j]] == -1) T[j] = -1;
			else {
				int i = j;
				//cout << i ;
				T[i] = 2;
				while (i+A[i] < n && i+A[i] >= 0 && T[i+A[i]] == 0) {
					T[i+A[i]] = 2;
					i += A[i];
					//cout << " -> " << i;
				}
				i += A[i];
				//cout << endl;
				int ri = -1;
				if (i >= n || i < 0 || T[i] == 1) {
					ri = 1;
				}
				for (int k=0; k<n; k++) {
					if (T[k] == 2) T[k] = ri;
				}
			}
		}

		int num = count(T.begin(), T.end(), 1); 
		cout << num << endl;
		if (num != 0) {
			for (int i=0; i<n; i++) {
				if (T[i] == 1) cout << i+1 << " ";
			}
			cout << endl;
		}
	}

	return 0;
}