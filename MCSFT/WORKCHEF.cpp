/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll L,R,dp[20][1<<10][7][8][9];//index, mask, mod[7,8,9]
int K,n;
string str;

string to__string(ll num){
	stringstream ss;
	ss << num;
	return ss.str();
	}

ll solve(int index, int tight, int mask, int last, int mod7, int mod8, int mod9){
	ll &res = dp[index][mask][mod7][mod8][mod9];
	if(res == -1){
		res = 0;
		if(index == n){
			bool div[10];
			div[1]=1; div[2]=!(mod8%2); div[3]=!(mod9%3); div[4]=!(mod8%4);
			div[5]=!(last%5); div[6]=(div[2]&div[3]); div[7]=!(mod7); div[8]=!(mod8);
			div[9]=!(mod9);
			int kk=0;
			for(int i=1; i<=9; i++){
				if(mask&(1<<i) && div[i])kk++;
				}
			if(kk>=K)res = 1;
			}
		else {
			if(tight){
				for(int i=0; i<=str[index]-'0'; i++){
					if(i==str[index]-'0'){
						res += solve(index+1, 1, mask|(1<<i), i, (10*mod7+i)%7, (10*mod8+i)%8, (10*mod9+i)%9);
						}
					else{
						res += solve(index+1, 0, mask|(1<<i), i, (10*mod7+i)%7, (10*mod8+i)%8, (10*mod9+i)%9);
						}
					}
				}
			else{
				for(int i=0; i<=9; i++){
					res += solve(index+1, 0, mask|(1<<i), i, (10*mod7+i)%7, (10*mod8+i)%8, (10*mod9+i)%9);
					}
				}
			}
		}
	return res;
	}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%d",&L,&R,&K);
		//if(K==0||K==1){
		//	printf("%lld\n",R-L+1);
		//	continue;
		//	}
		if(L==R && K<=1){
			int flag=0;
			while(R>0){
				if((R%10 != 0 && L%(R%10))==0){
					flag=1;break;
					}
				if(R%10 == 0 && R>0)
					while(R%10 == 0 && R>0)
						R /= 10;
				else R /= 10;
				}
			if(flag)printf("1\n");
			else printf("0\n");
			continue;
			}
		ll ans = 0;
		str = to__string(R);
		n = str.length();
		memset(dp,-1,sizeof dp);
		if(R>0)ans += solve(0,1,0,0,0,0,0);
		cout<<ans<<endl;
		--L;
		str = to__string(L);
		n = str.length();
		memset(dp,-1,sizeof dp);
		//if(L+1>1)ans -= 
		cout<<solve(0,1,0,0,0,0,0)<<endl;
		printf("%lld\n",ans);
		}
	cout<<"L="<<L<<" "<<"R="<<R;
	return 0;
	}
*/

/* 
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T abs(T n) { return (n < 0 ? -n : n); }
template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;

i64 base[16][16], X[16], mod;
int d, n;

void mul(i64 a[16][16], i64 b[16][16]) {
	int i, j, k;
	i64 r[16][16];
	for(i = 0; i < d; i++) {
		for(j = 0; j < d; j++) {
			r[i][j] = 0;
			for(k = 0; k < d; k++) {
				r[i][j] += a[i][k]*b[k][j];
				if(r[i][j] >= mod) r[i][j] %= mod;
			}
		}
	}
	CPY(a, r);
}

void pwr(i64 r[16][16], i64 e) {
	i64 b[16][16];
	for(int i = 0; i < d; i++) {
		for(int j = 0; j < d; j++) {
			r[i][j] = 0;
			b[i][j] = base[i][j];
		}
		r[i][i] = 1;
	}


	while(e > 0) {
		if(e & 1) mul(r, b);
		e >>= 1;
		mul(b, b);
	}
}

i64 sum(i64 x) {
	i64 ret = 0;
	if(x <= n) {
		for(int i = 1; i <= x; i++) {
			ret += X[n-i];
			if(ret >= mod) ret %= mod;
		}
	}
	else {
		i64 r[16][16];
		pwr(r, x-n);
		
		for(int i=0; i<n; i++){
for(int j=0; j<n; j++){
	cout<<r[i][j]<<" ";
}cout<<endl;
}
		
		for(int i = 0; i < d; i++) {
			ret += r[n][i] * X[i];
			if(ret >= mod) ret %= mod;
		}
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, i;
	i64 a, b, tot;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		d = n + 1;
		
		X[n] = 0;
		for(i = n - 1; i >= 0; i--) {
			scanf("%lld", &X[i]);
			X[n] += X[i];
		}
		
		CLR(base);
		for(i = 1; i < n; i++) base[i][i-1] = 1;
		for(i = 0; i < n; i++) {
			scanf("%lld", &base[0][i]);
			base[n][i] = base[0][i];
		}
		base[n][n] = 1;
		


		scanf("%lld%lld%lld", &a, &b, &mod);
		tot = ( sum(b) - sum(a - 1) ) % mod;
		if(tot < 0) tot += mod;
		printf("%lldn", tot);
	}
	return 0;
}

*/


/* //this is SPP spoj...

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p,k;
ll b[18],c[18];

void mul1(vector<vector<ll> >&res, vector<vector<ll> >&trans){
	int i,j,kk;
	vector<vector<ll> >temp(k+2);
	for(i=0; i<=k+1; i++)temp[i].resize(k+2);
	for(i=0; i<=k+1; i++)
		for(j=0; j<=k+1; j++)temp[i][j]=0LL;
	for(i=0; i<=k+1; i++){
		for(j=0; j<=k+1; j++){
			for(kk=0; kk<=k+1; kk++){
				temp[i][j] += ((ll)(res[i][kk] * trans[kk][j]))%p;
				temp[i][j] %= p;
				}
			}
		}
	for(i=0; i<=k+1; i++)
		for(j=0; j<=k+1; j++)res[i][j]=temp[i][j];
	}
void mul2(vector<vector<ll> >&trans){
	int i,j,kk;
	vector<vector<ll> >temp(k+2);
	for(i=0; i<=k+1; i++)temp[i].resize(k+2);
	for(i=0; i<=k+1; i++)
		for(j=0; j<=k+1; j++)temp[i][j]=0LL;
	for(i=0; i<=k+1; i++){
		for(j=0; j<=k+1; j++){
			for(kk=0; kk<=k+1; kk++){
				temp[i][j] += ((ll)(trans[i][kk] * trans[kk][j]))%p;
				temp[i][j] %= p;
				}
			}
		}
	for(i=0; i<=k+1; i++)
		for(j=0; j<=k+1; j++)trans[i][j]=temp[i][j];
	}

void matExp(vector<vector<ll> >&trans, int pwr){
	vector<vector<ll> >res(k+2);
	int i,j;
	for(i=0; i<=k+1; i++)res[i].resize(k+2);
	for(i=0; i<=k+1; i++){
		for(j=0; j<=k+1; j++)if(i==j)res[i][j]=1;else res[i][j]=0LL;
		}
	while(pwr>0){
		if(pwr&1){
			mul1(res, trans);
			}
		mul2(trans);
		pwr >>= 1;
		}
	for(i=0; i<=k+1; i++)
		for(j=0; j<=k+1; j++)trans[i][j]=res[i][j];
	}

ll solve(int lmt){
	if(lmt==0)return 0;
	if(lmt<=k){
		ll ans=0LL;
		for(int i=1; i<=lmt; i++){ans += b[k+1-i];ans %= p;}
		return ans%p;
		}
	vector<vector<ll> >trans(k+2);
	int i,j;
	for(i=0; i<=k+1; i++)trans[i].resize(k+2);
	for(i=0; i<=k+1; i++){
		for(j=0; j<=k+1; j++)trans[i][j]=0LL;
		}
	for(i=1; i<=k+1; i++) trans[i][i-1] = 1LL;
	for(i=0; i<=k+1; i++){
		for(j=0; j<=k+1; j++){
			if(i==1 && j>0)trans[i][j]=c[j];
			}
		if(i>0 && i!=(k+1))trans[k+1][i] = c[i];
		}
	trans[k+1][k+1]=1LL;
	//for(int i=0; i<=k+1; i++){
	//	for(int j=0; j<=k+1; j++){
	//		cout<<trans[i][j]<<" ";
	//		}
	//	cout<<endl;}
	matExp(trans,lmt-k);
	
	ll ans=0LL;
	for(i=1; i<=k+1; i++){
		ans += ((ll)(b[i]*trans[k+1][i]))%p;
		ans %= p;
		//cout<<" "<<b[i]<<" * "<<trans[k+1][i]<<endl;
		}
	return ans%p;
	}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int i;
		scanf("%lld",&k);
		b[k+1]=0LL;
		for(i=k; i>0; i--){scanf("%lld",&b[i]);b[k+1]+=b[i];}
		for(i=1; i<=k; i++){scanf("%lld",&c[i]);}
		ll l,r;
		scanf("%lld%lld%lld",&l,&r,&p);
		ll ans1=0LL,ans2=0LL;
		ans1 = (solve(r)+p)%p;
		ans2 = (solve(l-1)+p)%p;
		//cout<<ans1<<" "<<ans2<<endl;
		ans1 = (ans1-ans2)%p;
		if(ans1<0)ans1+=p;
		printf("%lld\n",ans1);
		}
	return 0;
	}
**/


//bitmask :D
/*
#include <bits/stdc++.h>
using namespace std;

const int inf = 1005;
int n,dp[1<<16],baby[16],me[16];

int solve(int mask){
	if(dp[mask]!=-1)return dp[mask];
	int num1 = __builtin_popcount(mask);
	if(num1 > n)return inf;
	if(num1==n)return 0;//found another baby arrangement(it me be correct one)...
	int anss = inf;
	for(int i=0; i<n; i++){
		if((mask & 1<<i) == 0){//empty field...lets put a knight here...
			cout<<" mask="<<mask<<" i="<<i<<" ";
			anss = min(anss, abs(i-num1) + abs(baby[num1]-me[i]) + solve(mask | 1<<i));//moving to nth row fro current row...
			cout<<" anss="<<anss<<endl;
			}
		}
	
	
	2 1 2 --- 1 3 1
	
	1 x x
	x x 2
	3 x x
	
	x 1 x
	2 x x
	x 3 x
	
	1 x x
	x x 2
	3 x x
	
	return dp[mask]=anss;
	}

int main(){
	while(scanf("%d",&n)){
		if(n==0)break;
		memset(dp, -1, sizeof dp);
		for(int i=0; i<n; i++)scanf("%d",&baby[i]);
		for(int i=0; i<n; i++)scanf("%d",&me[i]);
		cout<<solve(0)<<endl;
		}
	}
*/
/*
#include <bits/stdc++.h>
using namespace std;

const int inf = 1005;
int n,dp[1<<16][16],baby[16],me[16];
int solve(int mask, int k){
	if(dp[mask][k]!=-1)return dp[mask][k];
	if(k==0)return 0;//dp[mask][k] = abs((int)log2(mask+1)-1-k) + abs( me[(int)log2(mask+1)-1]-baby[k] );
	int ans = inf;
	for(int i=0; i<k; i++){
		if(mask & (1<<i)){
			ans = min(ans, abs(i-k) + abs(me[i]-baby[k]) + solve(mask&(~(1<<i)), k-1));//remove this bit ie one less baby row and than number of way for k-1 rows...
			}
		}
	return dp[mask][k] = ans;
	}

int main(){
	while(scanf("%d",&n)){
		if(n==0)break;
		memset(dp, -1, sizeof dp);
		for(int i=0; i<n; i++)scanf("%d",&baby[i]);
		for(int i=0; i<n; i++)scanf("%d",&me[i]);
		cout<<solve((1<<n) -1, n)<<endl;
		}
	return 0;
	}
*/

#include <bits/stdc++.h>
using namespace std;

//o x o  - - -   
//x o o  0 - o   
//o x o  - - -   

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>m>>n;
		if(m==3 && n>=3){
			if(n==3)cout<<5<<endl;
			else if(n%3==0)cout<<5*(n/3 -1) + 3<<endl;
			else if(n%3==1)cout<<5*(n/3 -1) + 1<<endl;
			else if(n%3==2)cout<<5*(n/3 -1) + 2<<endl;
			continue;
			}
		if(m>n){int temp = n;n=m;m=temp;}
		cout<<(2*m*(n/6) + m*(n%6==1?1:2))<<endl;
	}
	return 0;
	}
