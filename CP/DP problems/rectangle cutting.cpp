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


int dp[505][505];

int recur(int a , int b)
{
	if(a == b) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	
	int ans = INT_MAX;

	for(int i = 1 ; i<= a-1 ; i++)
	{
		ans = min(ans , 1 + recur(i,b) + recur(a-i,b));
	}
	for(int i = 1 ; i<= b-1 ; i++)
	{
		ans = min(ans , 1 + recur(a,i) + recur(a,b-i));
	}
	dp[a][b] = ans;
	return ans;
}

void solve(){

	int a , b;
	cin >> a >> b;
	int ans = recur(a , b);
	cout << ans << endl;
}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

	//int t;cin>>t; while(t--)
    for(int i = 0 ; i <= 504 ; i ++)
    {
    	for(int j = 0 ; j <= 504 ; j ++)
    	{
    		dp[i][j] = -1;
    	}
    }
    solve();
	
	return 0;
}