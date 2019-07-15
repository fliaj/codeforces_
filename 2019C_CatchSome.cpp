#include <bits/stdc++.h>

using namespace std;
int main(){
	int T, N, K;
	vector<int> a[1001];//extend this array larger;
	int dp[1000][100], dp2[1000][100];
	int p[1000];
	cin>>T;
	for (int i=0; i<T; i++){
		memset(dp, 20, sizeof(dp));
		memset(dp2, 20, sizeof(dp2));
		cin>>N>>K;
		for (int j=0; j<1001; j++) a[j].clear();
		for (int j=0; j<N; j++) cin>>p[j];
		for (int j=0; j<N; j++){
			int temp;
			cin>>temp; temp--;
			a[temp].push_back(p[j]);
		}
		for (int j=0; j<1001; j++) sort(a[j].begin(),a[j].end());
	
		/*for (int i=0; i<4; i++){
			for (int j=0; j<a[i].size();j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}*/
		dp[0][0] = 0;
		dp2[0][0] = 0;
		for (int itr=0; itr<a[0].size(); itr++){
			if (itr>=K-1) dp[0][itr+1] = a[0][itr];
			else dp[0][itr+1] = a[0][itr] * 2;
			dp2[0][itr+1] = a[0][itr];
		}
		for (int j=1;j<1000;j++){
			// int cumu = 0;
			dp[j][0] = 0;
			dp2[j][0] = 0;
			for (int k=1;k<=K;k++){
				dp2[j][k] = dp2[j-1][k];
				dp[j][k] = dp[j-1][k];
				
				for (int itr=0;itr<a[j].size();itr++){
					if (itr>=k) break;
					//int cost;
					// if (k==K) {
					// 	cost = min(dp[j-1][k-itr] + a[j][itr], dp2[j-1][k-itr] + 2*a[j][itr]);
					// }
					// else 
					//cost = dp[j-1][k-itr-1] + 2*a[j][itr];
					dp2[j][k] = min(dp2[j][k], dp[j-1][k-itr-1]+a[j][itr]);
					dp2[j][k] = min(dp2[j][k], dp2[j-1][k-itr-1]+2*a[j][itr]);
					dp[j][k] = min(dp[j][k], dp[j-1][k-itr-1] + 2*a[j][itr]);
				}
			}
		}
		/*for (int itr=0; itr<6; itr++){
			for (int j=0; j<=6; j++){
				cout<<dp[itr][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
		for (int itr=0; itr<6; itr++){
			for (int j=0; j<=6; j++){
				cout<<dp2[itr][j]<<' ';
			}
			cout<<endl;
		}*/
		cout<<"Case #"<<(i+1)<<": "<<min(dp[999][K],dp2[999][K])<<endl;
	}
}