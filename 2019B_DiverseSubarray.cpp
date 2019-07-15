#include <bits/stdc++.h>
using namespace std;

int main(){
	int cas, n, s, ans;
	cin>>cas;

	int a[100001];
	
	for (int t=1; t<=cas; t++){
		cin>>n>>s;
		for (int i=0;i<n;i++) cin>>a[i];

		cout<<"Case #"<<t<<": "<< ans<< endl;
			
	}
}
/*
int main(){
	int cas, n, s, ans, jet;
	int a[100001];
	int buc[100001];
	int lst[100001];
	cin>>cas;
	for (int t=1; t<=cas; t++){
		cin>>n>>s;
		for (int i=0;i<n;i++) cin>>a[i];
		ans = 1;
		for (int i=0;i<n-1;i++){
			if (i+ans>=n) break;
			memset(buc, 0, sizeof(buc));
			buc[a[i]] = 1;
			int cans = 1;
			for (int j=i + ans; j<n;j++){
				buc[a[j]] += 1;
				if (buc[a[j]] == s+1) {
					cans -= s;
				} else if (buc[a[j]] < s+1) cans++;
				if (cans>ans){
					ans = cans;

				}
			}
		}
		cout<<"Case #"<<t<<": "<< ans<< endl;
	}
}*/