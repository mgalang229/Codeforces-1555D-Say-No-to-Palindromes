#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int pref[6][n+1];
    pref[0][0] = 0;
    char pattern[] = "abc";
    int cur = 0;
    do {
        for (int i = 0; i < n; i++) {
            pref[cur][i+1] = pref[cur][i] + (s[i] != pattern[i%3]);
        }
        cur++;
    } while (next_permutation(pattern, pattern + 3));
    while (m--) {
        int l, r;
        cin >> l >> r;
        int ans = n;
        for (int i = 0; i < 6; i++) {
            ans = min(ans, pref[i][r] - pref[i][l-1]);
        }
        cout << ans << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
// 	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}


