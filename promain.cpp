#include <bits/stdc++.h>

using namespace std:

#define lli unsigned long long int
#define REP(i,n) for(int i=0;i<n;i++)

#define MAX 300010
#define MOD 998244353
#define lli long long int

lli kaijo[MAX];
lli finv[MAX];
lli inv[MAX];

void calcKaijo(){

	REP(i,MAX){
		if(i==0 || i==1){
			kaijo[i]=1;
			finv[i]=1;
			inv[i]=1;
		}

		else {
			kaijo[i] = kaijo[i-1]*i;
			kaijo[i] %= MOD;
			inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
			finv[i] = finv[i-1]*inv[i] % MOD;
		}
	}
}

lli nCr(lli n,lli r){
	if(n<r)return 0;
	if(n<0 || r<0)return 0;
	return kaijo[n]*(finv[r]*finv[n-r]%MOD)%MOD;
}

int main(){
	lli n,a,b,k;
	cin>>n>>a>>b>>k;

	lli ans=0;

	calcKaijo();
	//aの個数を決める
	REP(red,n){
		if( (k-a*red)%b !=0){
			continue;
		}
		lli green = (k-a*red)/b;
		if(a*red + b*green == k){
			ans += (nCr(n,red)*nCr(n,green));
			ans %= MOD;
		}
	}
	cout<<ans<<endl;
}

