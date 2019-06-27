#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;
ll eucli(ll n, ll a, ll b, llc){
	if (b<0) return eucli(n, a, b+c, c) - (n+1);
}
ll eucli(ll l, r, a, b, c){
	return eucli(r, a, b, c) - eucli(l-1, a, b, c);
}
int main(){
	int n;
	
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		ll a, b, p, q;
		scanf("%I64d %I64d %I64d %I64d", &a, &b, &p, &q);
		p = p % q;

		ll start = 2 * p * (a % (2 * q)) ;
		start = start % (2 * q);
		ll gap = start;
		ll ans=a;
		for (int j=1; j<=b-a; j++){
			start += 2 * p;
			if (start >= 2* q) start -= 2*q;
			long long cur_gap = abs(start - q);
			if (cur_gap < gap){
				gap = cur_gap;
				ans = j + a;
			}
		}
		//if (ans==959 && a!=473) printf("%d %d %d %d ", a, b, p, q);
		printf("%I64d\n", ans);

	}
}