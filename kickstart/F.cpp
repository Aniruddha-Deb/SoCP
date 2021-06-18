#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;

int main() {
	int n, k;
	cin >> n >> k;
	vector<bool> students(n,false);

	ll ans = 1;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		if (temp) students[i] = true;
	}
	int num = count(students.begin(), students.end(), true);

	int ssum = 0;
	int ns = 0;
	for (int i=0; i<n; i++) {
		if (ssum % k == 0 && ssum != 0 && ssum != num) {
			while (i < n && !students[i]) {
				ns++;
				i++;
			}
			ns++;
			ans = ((ans%MOD)*(ns%MOD))%MOD;
			ns = 0;
		}
		if (students[i]) {
			ssum++;
		}
	}

	cout << ans << endl;

	return 0;
}