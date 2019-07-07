#include <bits/stdc++.h>
using namespace std;

int main(){
	int cas;
	int N, Q;
	string str;
	cin>>cas;
	int sum[26][10001];
	for (int t=1; t<=cas; t++){
		memset(sum, 0, sizeof(sum));
		cin>>N>>Q;
		char ch = getchar();
		getline(cin, str);
		for (int i=1; i<=N; i++) 
			for (int j=0;j<26;j++)
				if (j == str[i-1] - 'A')
					sum[j][i] = sum[j][i-1] + 1;
				else
					sum[j][i] = sum[j][i-1];

		int ans = 0;
		int l, r, odd;
		for (int i=0;i<Q;i++){
			cin>>l>>r;
			odd = 0;
			for (int j=0;j<26;j++)
				if ((sum[j][r]-sum[j][l-1])%2==1) odd++;
			if (odd<=1) ans++;
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;

	}
}