#include <bits/stdc++.h>
using namespace std;

int main(){
	int cas, n;
	int sec[105], en[105], lo[105], dp[105][10005];
	cin>>cas;
	for (int t=1; t<=cas; t++){
		memset(dp, 0, sizeof(dp));
		cin>>n;
		for (int i=1; i<=n; i++) cin>>sec[i]>>en[i]>>lo[i];

		for (int i=1;i<=n;i++){
			
			for (int j=1;j<=10000;j++){// time
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				if (j>=sec[i]){
					dp[i][j] = max(dp[i][j], dp[i-1][j-sec[i]]+max(0, en[i]-lo[i]*(j-sec[i])) );
				}
			}
		}
		cout<<"Case #"<<t<<": "<<dp[n][10000]<<endl;
	}
	
	

}
