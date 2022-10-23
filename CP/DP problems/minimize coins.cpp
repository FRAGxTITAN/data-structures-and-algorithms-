#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<lli> vl;
typedef pair<lli,lli> pll;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define repr(a , b , c) for(int i = a ; i>b ; i-=c)
#define rep(a , b , c) for(int i = a ; i<b ; i+=c)
#define print(a) for(auto x:a) cout<<x<<" ";cout<<endl;
#define sq(a) (a)*(a)


void solve(){

	int n , x;
	cin >> n >> x;
	vi a(n);
	rep(0,n,1)
	{
		cin>>a[i];
	}

	lli dp[x+1];
	for(int i = 0 ; i <= x ; i ++) dp[i] = INT_MAX;
	// assuming that initially no.of ways to choose sum is infinity
	dp[0] = 0;
	
	for(int i = 1 ; i <= x ; i ++)
	{
		lli prev = INT_MAX;
		for(int j = 0 ; j < n ; j ++)
		{
			if(i - a[j] >=0)
				prev = min(prev , dp[i - a[j]]);
		}
		dp[i] = 1 + prev;
	}
	if(dp[x] >= INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dp[x] << endl;
	}
}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	//int t;cin>>t; while(t--)
    
    solve();
	
	return 0;
}
