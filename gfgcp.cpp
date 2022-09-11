#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sorta(a) sort(a,a+n)
#define sortv(v) sort(begin(a), end(a))
#define rep(n) for(int i=0;i<n;i++)
#define mpp make_pair
//#define mod 1000000007
#define maxn 1000000008
#define enl cout<<"\n"
#define forr(i,n) for(int i=0;i<n;i++)
#define fio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


using namespace std;

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll inv(ll i){if(i==1) return 1;return (MOD-((MOD/i)*inv(MOD%i))%MOD)%MOD;}
 
 
ll fact[N], invfact[N];
 
ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
 
ll modinv(ll k)
{
	return pow(k, MOD-2, MOD);
}
 
void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}
 
ll nCr(ll x, ll y)
{
	if(y>x)
		return 0;
	ll num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
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

//////////seg tree //////
const int maxn=1e5+7;

int t1[4*maxn],t2[4*maxn];

void buildmin(int a[],int v,int tl,int tr){
	if(tl==tr)
		t1[v]=a[tl];
	else{
		int tm=(tl+tr)/2;
		buildmin(a,v*2,tl,tm);
		buildmin(a,v*2+1,tm+1,tr);
		t1[v]=min(t1[v*2],t1[v*2+1]);
	}
}
void buildmax(int a[],int v,int tl,int tr){
	if(tl==tr)
		t2[v]=a[tr];
	else{
		int tm=(tl+tr)/2;
		buildmax(a,v*2,tl,tm);
		buildmax(a,v*2+1,tm+1,tr);
		t2[v]=max(t2[v*2],t2[v*2+1]);
	}
}

int rangeMin(int v,int tl,int tr,int l,int r){
	if(l>r)
		return INT_MAX;
	if (l == tl && r == tr) {
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return min(rangeMin(v*2, tl, tm, l, min(r, tm)),
    	rangeMin(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int rangeMax(int v,int tl,int tr,int l,int r){
	if(l>r)
		return INT_MIN;
	if (l == tl && r == tr) {
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return max(rangeMax(v*2, tl, tm, l, min(r, tm)),
    	rangeMax(v*2+1, tm+1, tr, max(l, tm+1), r));
}
/////////////////////////////////////////////////

class dsu{
public:
	int *parent; int *rank; int n;
	dsu(int n){
		rank=new int[n];
		parent=new int[n];
		this->n=n;
		makeSet();
	}
	void makeSet(){
		for(int i=0;i<n;i++){
			rank[i]=0;
			parent[i]=i;
		}
		//cout<<"\n";
	}
	int find(int x){
		//cout<<parent[x]<<"\n";
		if(parent[x]==x) return x;
		return parent[x]=find(parent[x]);
	}
	void merge(int x, int y){
		int parentOfx=find(x);
		int parentOfy=find(y);

		if(parentOfx==parentOfy) return;

		if (rank[parentOfx] < rank[parentOfy]) {
			parent[parentOfx] = parentOfy;
		}
		else if (rank[parentOfx] > rank[parentOfy]) {
			parent[parentOfy] = parentOfx;
		}
		else{
			parent[parentOfy]=parentOfx;
			rank[parentOfx]++;
		}
	}

};

int main(){
	fio;
	int t=1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		dsu d(n+1);
		int g=0,b=0;
		map<int,int> mp;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			d.merge(x,y);
			int tt=d.find(x);
			if(!mp.count(tt))
				g++;
			else {
				mp[tt]++;
				if(mp[tt]%2){
					g++;
					b--;
				}
				else{
					b++;
					g--;
				}
			}
			cout<<abs(b-g)<<" ";
		}
	}

}