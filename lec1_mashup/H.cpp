#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int>> A;
	rep(i,0,n) {
		int temp;
		cin >> temp;
		A.push_back(make_pair(i+1,temp));
	}
	sort(A.begin(), A.end(), [](auto &left, auto &right) {
    	return left.second < right.second;
	});


	ll sum = 0;
	int s = 0;
	for (int i=0; i<n-1; i++) {
		sum += A[i].second;
		if (sum < A[i+1].second) {
			s = i+1;
		}
	}

	cout << n-s << endl;
	sort(A.begin()+s, A.end(), [](auto &left, auto &right) {
    	return left.first < right.first;
	});
	for (int i=s; i<n; i++) cout << A[i].first << " ";
	cout << endl;
}

int main() {
	init();
	int t = 1;
	cin >> t;
	while (t-- > 0) {
		solve();
	}
	return 0;
}