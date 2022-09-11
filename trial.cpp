#include <bits/stdc++.h>
#define enl cout<<"\n"
#define ll long long
#define pb push_back
#define sorta(a) sort(a,a+n)
#define all(x) (x).begin(), (x).end()
#define mpp make_pair
#define umap unordered_map
#define uset unordered_set
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define maxn 1000000008
#define null NULL
#define pii pair<int,int>
#define pll pair<ll,ll>
#define read(a) for(auto &i : a) cin>>i;
using namespace std;


int gpf(ll n) { 
  	set<int> s;
	while (n % 2 == 0) 
	{ 
		s.insert(2);
		n = n/2; 
	} 
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		while (n % i == 0) 
		{ 
			s.insert(i);
			n = n/i; 
		} 
	} 
	if (n > 2) 
		s.insert(n);
	for(auto x : s)
		cout<<x<<" ";
	enl;
    return s.size();
} 
ll ncr(int n, int r){
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r; 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

ll gcd(ll a,ll b){
    if(b==0) return a; 
    return gcd(b,a%b);
}
ll lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}

string bin(ll n){
	string s="";
	while(n>0){
		s+=to_string(n%2);
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
int power(int a, int b, int m)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;;
}

ll round(ll a,ll b){
    if(a%b==0) return a/b;
    return(a/b)+1;
}

bool isp (ll x) // is power of two func
{ 
	return x && (!(x&(x-1))); 
} 
ll roundn(ll x,ll n){
	ll next = pow(n, ceil(log(x)/log(n)));
	if(next==x)return next;
	return next;
}
ll pw(ll x,ll n){
    return ceil(log(x)/log(n));
}

vector<bool> prime(1000001,1);
void sieve()
{
    int n=1000001;
    prime[1]=0;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
struct seg {
	int l, r, id;
	bool operator< (seg b) const {
		if (l != b.l) {
			return l < b.l;
		}
		return r > b.r;
	}
};
vector<int> z_function(string s) { 
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// int dp[1000][1000]={-1};
int solve(int n,int wt[],int val[],int cap){
    if(n==0)
        return 0;

    if(cap>=wt[n-1]){
        int letehai=solve(n-1,wt,val,cap-wt[n-1])+val[n-1];
        int nhiletehai=solve(n-1,wt,val,cap);
        return max(letehai,nhiletehai);
    }
    return solve(n-1,wt,val,cap);
}


int main(){
	fio;
	int t=1;
	// cin>>t;
	while(t--){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> p;
        p.push({5,4});
        p.push({4,5});
        cout<<p.top().first<<" "<<p.top().second<<'\n';
	}

}

