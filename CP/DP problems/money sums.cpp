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

int dp[1000005];
int dp1[1000005];

void solve(){

	int n;
	cin >> n;

	vector<int> arr(n);
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> arr[i];
	}
	for(int i = 0 ; i <= n*1000 ; i ++)
	{
		dp[i] = 0;
		dp1[i] = 0;
	}
	
	for(int i = 0 ; i < n ; i ++)
	{
		
		for(int j = 0 ; j <= n*1000 ; j ++)
		{
			dp1[arr[i] + j] |= dp[j];
		}
		dp1[arr[i]] = 1;

		for(int j = 0 ; j <= n*1000 ; j ++)
		{
			dp[j] = dp1[j];
		}
	}
	int len = 0;
	for(int i = 0 ; i <= n*1000 ; i ++)
	{
		len += dp[i];
	}
	cout << len << endl;
	for(int i = 0 ; i <= n*1000 ; i ++)
	{
		if (dp[i])cout << i << " ";
	}
	cout << endl;


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