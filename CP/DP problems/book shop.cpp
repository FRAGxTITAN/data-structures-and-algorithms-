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


int a[1001];
int b[1001];
int dp[100001][1001];

void solve(){

	int n , m;
	cin >> n >> m;
	rep(0,n,1)
	{
		cin>>a[i];
	}
	rep(0,n,1)
	{
		cin>>b[i];
	}

	for(int y = 0 ; y < 1 ; y ++)
	{
		for(int x = 0 ; x <= m ; x ++)
		{
			if(x - a[y] >= 0)
				dp[x][y] = b[y];
			else
				dp[x][y] = 0;
		}
	}

	for(int y = 1 ; y < n ; y ++)
	{
		for(int x = 0 ; x <= m ; x ++)
		{
			if(x - a[y] >= 0)
				dp[x][y] = max(b[y] + dp[x - a[y]][y-1] , dp[x][y-1]);
			else 
				dp[x][y] = dp[x][y-1];
		}
	}

	 // for(int x = 0 ; x <= m ; x ++)
	 // {
	 // 	for(int y = 0 ; y < n ; y ++)
	 // 	{
	 // 		cout << dp[x][y] << " ";
	 // 	}cout << endl;
	 // }


	cout << dp[m][n-1] << endl;

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