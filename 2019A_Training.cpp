#include <bits/stdc++.h>
using namespace std;

int main(){
	int cas, ans, n, p, temp, cans;
	deque<int> s;

	cin>>cas;
	for (int t=1; t<=cas; t++){
		ans = 0;
		cin>>n>>p;

		for (int i=1;i<=n;i++){
			cin>>temp;
			s.push_back(temp);
		}
		sort(s.begin(), s.end());

		for (int i=0;i<p-1;i++) ans += s[p-1] - s[i];
		cans = ans;

		int i = p;
		while (i<n){
			cans -= (s[i-1] - s[i-p]);
			cans += (p-1) * (s[i]-s[i-1]);
			i++;
			ans = min(ans, cans);
			cout<<cans<<endl;
		} 	
		/*while (s.size()>p){
			cans -= (s[p-1]-s[0]);
			s.pop_front();
			cans += (p-1) * (s[p-1] - s[p-2]);
			ans = min(ans, cans); 
		}*/

 		cout<<"Case #"<<t<<": "<< ans<< endl;
	}
}