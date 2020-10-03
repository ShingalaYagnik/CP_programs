#include<bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define what(x) cout<<#x<<" is "<<x<<endl;
using namespace std;


template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

ll powmod(ll a,ll b,ll mod) {
    ll res=1;a%=mod;
    //assert(b>=0);
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;a=a*a%mod;
    }
    return res;
}
int n,q;
set<int> s;
multiset<int> delta;
vector<int> vp;
void solve(){
	cin>>n>>q;
	delta.insert(0);
	vp.resize(n);
	for(int i=0;i<n;i++){
		cin>>vp[i];
		s.insert(vp[i]);
	}
	sort(all(vp));
	for(int i=1;i<n;i++){
		delta.insert(vp[i]-vp[i-1]);
	}
	if(vp[0]==vp[n-1]){
		cout<<0<<'\n';
	}else{
		cout<<vp[n-1]-vp[0]-*delta.rbegin()<<'\n';
	}
	while(q--){
		int type,x;
		cin>>type>>x;
		if(type){
			auto it=s.lower_bound(x);
			if(it==s.end()){
			//	s.insert(x);
				if(s.size()>0){
					it--;
					delta.insert(x-*it);
				}
				delta.insert(0);
			}else{
				if(it==s.begin()){
					delta.insert(*it-x);
				}else{
					auto it2=it;
					it--;
					auto temp = delta.lower_bound(*it2-*it);
					if(*it2!=*it)
					delta.erase(temp);
					delta.insert(x-*it);
					delta.insert(*it2-x);
				}
			}
				s.insert(x);
		}else{
			s.erase(x);
			auto it=s.lower_bound(x);
			if(it==s.end()){
				if(s.size()>0){
					it--;
					if(x!=*it){
						auto temp=delta.lower_bound(x-*it);
						delta.erase(temp);
					}
				}
			}else{
				if(it==s.begin()){
					if(*it!=x){
						auto temp=delta.lower_bound(*it-x);
						delta.erase(temp);
					}
				}else{
					auto it2=it;
					it--;
					auto temp = delta.lower_bound(x-*it);
					if(x!=*it)
					delta.erase(temp);
					temp=delta.lower_bound(*it2-x);
					if(*it2!=x)
					delta.erase(temp);
					delta.insert(*it2-*it);
				}
			}
		}
		debug(s);
		debug(delta);
		if(s.size())
		cout<<*s.rbegin()-*s.begin()-*delta.rbegin()<<'\n';
		else
			cout<<-*delta.rbegin()<<'\n';
	}

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int tc=1;
    // cin>>tc;
    while(tc--)solve();
}
