#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf (1LL<<61)
#define len(s) (int)s.size()
#define all(a) a.begin(), a.end()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr <<*it << " = " << a << ",   " << endl;
    err(++it, args...);
}
void solve() {
	int n, k;
	cin >> n >> k;
	std::vector<int> v(n);
	for(auto &i: v) cin >> i;
		std::vector<int> od(n, 0), ev(n, 0);
	if(v[0] % 2 == 0) ev[0]++;
	if(v[0] % 2 == 1) od[0]++;
	for(int i = 1; i < n; ++i){
		if(v[i] % 2 == 0){
			ev[i] += ev[i - 1] + 1;
		}
		else ev[i] =  ev[i - 1];
		
		if(v[i] % 2 == 1){
			od[i] += od[i - 1] + 1;
		}
		else od[i] = od[i - 1];
	}
	int l, r;
	int odds = 0;
	int evens = 0;
	int ans = 0;
	
	auto fact = [&](int x){
		int mul = 1;
		for(int i = 1; i <= x; ++i) mul  = (mul * i) % inf;
			return mul;
	};
	while(k--){
		cin >> l >> r;
		l--;
		r--;
		ans = 0;
		if(l == 0) odds = od[r];
		else 
		odds = od[r] - od[l - 1];
		
		if(l == 0) evens = ev[r];
		else evens = ev[r] - ev[l - 1];
		
		int od_cal = 0;
			int cal  = (odds) * (odds - 1) * (odds - 2);
			cal/=6ll;
			ans += cal;
		int cals = evens * (evens - 1) / 2;
		if(odds) ans += (cals * odds);
		cout << ans << ' ';
		
	}
	cout << '\n';
	
 
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for(int cs = 1; cs <= T; cs++) {
        solve();
    }
    return 0;
 
}
