#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t, r, c, K;
	int v[300][300], maxlen[300][300];
	cin>>t;
	for (int i=0; i<t; i++){
		cin>>r>>c>>K;
		for (int ii=0;ii<r;ii++)
			for (int jj=0;jj<c;jj++){
				cin>>v[ii][jj];
			}

		for (int i=0; i<r; i++){
			for (int j=0; j<c-1; j++){
				int Min=v[i][j], Max=v[i][j];
				int k;
				for (k=j+1; k<c; k++){
					Max = max(Max, v[i][k]);
					Min = min(Min, v[i][k]);
					if (Max - Min > K){
						k = k-1;
						break;
					}
				}
				if (k>=c) k--;
				maxlen[i][j] = k-j;
				// cout<<k-j<<' ';
			}
			// cout<<endl;
		}

		int ans = r;
		for (int j=0;j<c-1;j++)
			for (int len=1;len<c-j;len++){
				int continuous = 0;
				for (int i=0; i<r; i++){
					if (maxlen[i][j]>=len) continuous++; else{
						
						ans = max(ans, continuous*(len+1));
						continuous = 0;
						// cout<<continuous<<len<<endl;
					}
				}
				ans = max(ans, continuous*(len+1));
			}
		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}
	
	

}