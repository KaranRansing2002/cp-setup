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
#define maxn 1000000008
#define inf INT_MAX
#define null nullptr
#define pii pair<int,int>
#define pll pair<ll,ll>
#define read(a) for(auto &i : a) cin>>i;
#define double long double
using namespace std;

class Contributor
{
public:
	string contributorName;
	int numberOfskills;
	set<pair<string, int>> skillSet;

	Contributor(string name, int skills)
	{
		contributorName = name;
		numberOfskills = skills;
	}
};

class Projects
{
public:
	string projectName;
	int days;
	int Score;
	int bestBeforeDay;
	int roles;

	vector<pair<string, int>> roleSet;    

	Projects(string name, int days, int score, int bbday, int noOfRoles)
	{
		projectName = name;
		this->days = days;
		Score = score;
		bestBeforeDay = bbday;
		roles = noOfRoles;
	}
	bool operator< (Projects projs) const
	{
		if(projs.Score==Score) return projs.bestBeforeDay > bestBeforeDay;
		return projs.Score < Score;
		
	}

};

int main()
{
	fio;
	int  Con, Proj;
	cin >> Con >> Proj;
	int pp=Proj;
	vector<Contributor> vecC;

	map<string,vector<Contributor>> mp;

	while (Con--)
	{
		string name;
		int N;
		cin >> name;
		cin >> N;

		Contributor example(name, N);

		for (auto i = 0; i < N; i++)
		{
			string skill{};
			int level;
			cin >> skill >> level;
			mp[skill].pb(example);
			example.skillSet.insert({ skill, level });
		}
		vecC.push_back(example);
	}

	vector<Projects> vecP;
	
	while (Proj--)
	{
		string name;
		int D, score, bbday, roles;

		cin >> name >> D >> score >> bbday >> roles;

		Projects example(name, D, score, bbday, roles);

		for (auto i = 0; i < roles; i++)
		{
			string Rskill{};
			int level;
			cin >> Rskill >> level;
			example.roleSet.push_back({ Rskill, level });
		}
		vecP.push_back(example);
	}
	sort(vecP.begin(), vecP.end());

	cout<<pp<<'\n';
	for(auto x : vecP){
		cout<<x.projectName<<'\n';
		for(auto c : x.roleSet){
			for(auto tt : mp[c.first]){
				cout<<tt.contributorName<<" ";
			}
		}
		enl;
	}

}
