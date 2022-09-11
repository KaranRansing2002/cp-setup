#include <bits/stdc++.h>
#define enl cout<<"\n"
#define ll long long
#define pb push_back
#define sorta(a) sort(a,a+n)
#define rep(n) for(int i=0;i<n;i++)
#define mpp make_pair
#define umap unordered_map
#define uset unordered_set
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define maxn 1000000008
#define null NULL
#define pii pair<int,int>
#define pll pair<ll,ll>
#define inf INT_MAX
#define all(x) (x).begin(), (x).end()

#define read(a) for(auto &i : a) cin>>i;
using namespace std;


int gpf(ll n) { 
  	map<int,int> mp;
	while (n % 2 == 0) 
	{ 
		mp[2]++;
		n = n/2; 
	} 
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		while (n % i == 0) 
		{ 
			mp[i]++;
			n = n/i; 
		} 
	} 
	if (n > 2) 
		mp[n]++;
	for(auto x : mp)
		cout<<x.first<<" "<<x.second<<'\n';
	enl;
    return mp.size();
} 
ll ncr(ll n, ll r){
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
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

int isprime(ll n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else{
        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }	
    
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
    return ans;
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
bool issubstring(string s, string sb){
	string ss=s.substr(0,sb.length());
	if(ss==sb) return true;
	for(int i=sb.length();i<s.length();i++){
		ss.erase(ss.begin());
		ss.pb(s[i]);
		if(ss==sb){
			//cout<<ss<<"\n"<<sb<<"\n";
			return true;
		}
	}
	return false;

}
ll fact(ll n){
	ll ans=1ll;
	for(ll i=2;i<=n;i++){
		ans=((ans%mod)*(i%mod))%mod;
	}
	return ans;
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
		return r > b.r;////////////////
	}
};
void rev(string &s,int i,int j){
    int n=j-i+1;
    cout<<s<<" ";
    string ss=s;
    for(int k=i;k<(j-i+1)/2;k++)
        swap(ss[k],ss[n-1-k]);
    cout<<ss<<'\n';
    s=ss;
}
////////////////Fenwick tree////
vector<int>fenwick(1000001,0); // make sure to create an arr of n+1 size

void update(int ind,int x,int n){ //make sure to pass the size of arr (n+1)
	int sum=0;
	while(ind<n){
		fenwick[ind]+=x;
		ind+=(ind & -ind);
	}
}

void precomputeFenwick(vector<int> a){
	int n=a.size();
	for(int i=1;i<n;i++)
		update(i,a[i],n);
}
int rangesum(int ind){
	int sum=0;
	while(ind>0){
		sum+=fenwick[ind];
		ind-=(ind & -ind);
	}
	return sum;
}
int fquery(int st,int end){
	return rangesum(end)-rangesum(st-1);
}
/////////////////////////////

int lnds(vector<int> a){  // longest non decreasing subsequence
	int n=a.size();
	vector<int> len;
    for(int i = 0; i < n; i++)
    {
	    auto lb = upper_bound(len.begin(), len.end(), a[i]);
	    if(lb != len.end())
	    {
	        *lb = min(*lb, a[i]);
	    }
	    else
	    {
	        len.push_back(a[i]);
	    }
	}
	for(auto c : len)
		cout<<c<<" ";
	enl;
	return len.size();
}

int calc(string s){
	reverse(all(s));
	int ans=0;
	for(int i=0;i<s.length();i++)
		if(s[i]=='1') ans+=(1<<i); 
	return ans;
}


bool comp(vector<int> v,vector<int>vv){
	if(v.size()==0) return 1;
	for(int i=0;i<min(v.size(),vv.size());i++){
		if(v[i]<vv[i]) return 1;
		else if(vv[i]<v[i]) return 0;
	}
	return v.size()<vv.size();
}

vector<int> an;
void subString(string str, int n)
{
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {   
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point. 
            int j = i + len - 1;  
            string ss="";         
            for (int k = i; k <= j; k++)
                ss.pb(str[k]);
             
            // ans.pb(calc(ss));
        }
    }
}
bool validate(string s){
	set<char> st;
	for(int i=0;i<s.length();i++){
        // cout<<i<<" "<<s[i]<<"\n";
		if(st.count(s[i]))
			return 0;
		int j=i;
		while(s[j]==s[i]){
			st.insert(s[i]);
            j++;
        }
		i=j-1;
	}
	return 1;
}

string ans="IMPOSSIBLE";
int solve(int i,vector<string> &v,string op){
	if(i>=v.size()){
		cout<<op<<'\n';
		if(validate(op)){
			ans=op;
			return 1;
		}
		return 0;
	}
	op+=v[i];
	for(int j=i+1;j<v.size();j++){
		if(i==j) continue;
		if(solve(i+1,v,op+v[j]))
			return 1;
	}
	return 0;
}

bool check(int n){
	string s=to_string(n);
	string ss=s;reverse(all(s));
	return s==ss;
}

int main(){
	multiset<int> ms;
	ms.insert(1);ms.insert(1);ms.insert(1);ms.insert(2);
	for(auto c : ms)
		cout<<c<<" ";
	enl;
	ms.erase(1);
	for(auto c : ms)
		cout<<c<<" ";
	enl;
}
