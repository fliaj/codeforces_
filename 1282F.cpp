#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;
ll eucli(ll n, ll a, ll b, ll c){
	if (n<0) return 0;
	if (n==0) return b / c;
	if (b<0) return eucli(n, a, b+c, c) - (n+1);
	if (a>=c || b>=c) return 
		eucli(n, a%c, b%c, c)+(a/c*n*(n+1)/2)+(b/c*(n+1));
	ll m = (a*n+b)/c;
	return n*m - eucli(m-1, c, c-b-1, a);
}
ll eucli(ll l, ll r, ll a, ll b, ll c){
	return eucli(r, a, b, c) - eucli(l-1, a, b, c);
}
ll exgcd(ll a, ll b, ll &x, ll &y){
	if (!b) {
		x=1;
		y=0;
		return a;
	}
	ll d = exgcd(b, a%b, x, y);
	ll temp = x; x = y; y = temp-(a/b)*y;
	return d;  
}
ll solve(ll p, ll q, ll mod, ll l, ll r){
	//VAR r is not useful here actually
	const ll Inf = 1e18;
	ll x, y;
	ll gcd = exgcd(p, q, x, y);
	if (mod % gcd != 0) return Inf;
	p /= gcd;
	q /= gcd;
	mod /= gcd;
	x *= mod;
	y *= mod;

	x += ((l-x) / q) * q;
	if (x<l) x+= q;
	return x;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		ll a, b, p, q;
		scanf("%I64d %I64d %I64d %I64d", &a, &b, &p, &q);

		p = p % q;
		ll left = 0;
		ll right = q;
		ll mid, l, r;
		while (left<right){
			mid = (left + right) / 2;
			l = q-mid; r = q+mid;
			if (eucli(a, b, 2*p, -l, 2*q)-eucli(a, b, 2*p, -r-1, 2*q)>0){
				right = mid;
			} else left = mid+1;
		}
		// printf("%I64d\n", left);
		ll mod = q - left;
		ll ans = solve(2*p, 2*q, mod, a, b);
		mod = q + left;
		ll new_ans = solve(2*p, 2*q, mod, a, b);
		if (ans > new_ans) ans = new_ans;
		if (q==1) ans = a;
		printf("%I64d\n", ans);
	}
}
//with the help from
//https://blog.bill.moe/bsoj4936-euclidean/   &&
//https://www.cnblogs.com/gczdajuruo/p/11008123.html
/*
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
}*/