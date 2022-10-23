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

/*
	given N
	prints all numbers 0 to 2^N-1 in gray code format
	1 <= N <= 16;
*/

void solve(){

	int n;
	cin >> n;
	for(int i = 0 ; i < pow(2 , n) ; i ++)
	{
		int num = i;
		int ans = num&(1<<(n-1));
		ans = ans>>(n-1);

		for(int u = 0 ; u < n-1 ; u ++)
		{
			int d = ((num&(1<<(n-u-1)))>>(n-u-1))^((num&(1<<(n-u-2)))>>(n-u-2));
			ans = ans<<1;
			ans += d; 
		}
		// ans in decimal format
		// convert into binary format
		
		for(int i = 0 ; i < n ; i ++)
		{
			cout << ((ans&(1<<(n-i-1)))>>(n-i-1));
		}cout<<endl;
	}


}
int main(){

	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r" , stdin);
		freopen("output.txt", "w" , stdout);
	#endif

    solve();
	
	return 0;
}
