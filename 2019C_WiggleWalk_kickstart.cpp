#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

typedef map<char, pair<int, int>> direct_map; 
direct_map M, cur;

int main(){
	int t;
	int n, r, c, sr, sc, cr, cc;
	string str;
	scanf("%d", &t);
	M['N'] = make_pair(-1, 0);
	M['S'] = make_pair(1, 0);
	M['E'] = make_pair(0, 1);
	M['W'] = make_pair(0, -1);
	for (int i=0; i<t; i++){
		scanf("%d %d %d %d %d\n", &n, &r, &c, &sr, &sc);
		cr = sr; cc = sc;
		getline(cin, str);
		cout<<"Case #"<<(i+1)<<": "; 

		char ch;
		map<pair<int, int>, direct_map> direct_XY;
		map<pair<int, int>, direct_map>::iterator lit, cit;
		
		direct_XY.insert(make_pair(make_pair(sr, sc), M));
		lit = direct_XY.find(make_pair(sr, sc));
		for (int j=0;j<n;j++){
			ch = str[j];
			cit = direct_XY.find(make_pair(cr, cc));
			while (cit != direct_XY.end()){
				cur = cit ->second;
				pair<int, int>rep = cur.find(ch) -> second;

				cr += rep.first;
				cc += rep.second;
				cit = direct_XY.find(make_pair(cr, cc));
				
			}
			direct_XY.insert(make_pair(make_pair(cr, cc), M));
			lit = direct_XY.find(make_pair(sr,sc));
			cur = lit ->second;
			cur.find(ch)->second = make_pair(cr-sr, cc-sc);
			lit->second = cur;
			sr = cr; sc = cc;
			// cout<<cr<<' '<<cc<<endl;
		}
		cout<<cr<<' '<<cc<<endl;
	}
}