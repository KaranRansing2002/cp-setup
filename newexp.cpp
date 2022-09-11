#include <bits/stdc++.h>
#define enl cout<<"\n"
#define ll long long
#define pb push_back
#define sorta(a) sort(a,a+n)
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define md 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define inf INT_MAX
#define null nullptr
#define pii pair<int,int>
#define pll pair<ll,ll>
#define read(a) for(auto &i : a) cin>>i;
#define double long double
#define int ll

using namespace std;

int dp[2001][3];
int check(int cur,int l,int r,string &s,char lc){
	if(r-l==1){
		if(s[r]==s[l])
			return -1;
		return cur;
	}
	int res1=check(!cur,l+1,r,s,s[l]),res2=check(!cur,0,r-1,s);
	cout<<l<<" "<<r<<" "<<cur<<" "<<res1<<" "<<res2<<'\n';
	if(res1==1 or res2==1)
		return 1;
	else if (res1==-1 and )
	else 
		return 0;
}

void solve(int tc){
	int n;
	string s;
	cin>>s;
	n=s.length();
	cout<<check(0,0,n-1,s)<<'\n';
}

int32_t main()
{
	fio;
 	int t=1;
 	cin>>t;
 	for(int tt=1;tt<=t;tt++){
 		solve(tt);
 	}
}
