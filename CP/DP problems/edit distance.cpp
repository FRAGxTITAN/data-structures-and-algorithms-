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


string a , b;
int n , m;
lli dp[5005][5005];
lli recur (int x , int y)
{

	if(x>=n || y>=m)
	{
		if(x == n && y == m)return 0;
		return abs(n - x) + abs(m - y);
	}

	if(dp[x][y]!=-1)return dp[x][y];
	if(a[x] == b[y])
	{
		return dp[x][y] = recur(x+1 , y+1);
	}
	else
	{
		/*
			add a character at string a
			add a character at string b
			remove a character at string a
			remove a character at string b
			replace a character at string a
			replace a character at string b
		*/
		return dp[x][y] = min(min(1 + recur(x , y+1) ,1 + recur(x+1, y) ), 1 + recur(x+1, y+1));
	}
	return dp[x][y];
}


void solve(){

	cin >> a >> b;
	n = a.length();
	m = b.length();
	for(int i = 0 ; i<= n ; i ++)
	{
		for(int j = 0 ; j <= m ; j ++)
		{
			dp[i][j] = -1;
		}
	}

	int ans = recur( 0 , 0 );
	cout << ans << endl;

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