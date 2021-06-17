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
		int no, ne;
		no = ne = 0;
		for (int i = 0; i<n; i++) {
			int temp;
			cin >> temp;
			if (temp%2 == 0) ne++;
			else no++;
		}

		cout << ((long long)no)*(no-1)/2 + ((long long)ne)*(ne-1)/2 << endl;

	}

	return 0;
}