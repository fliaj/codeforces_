#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int> tp;

deque<tp> bfs;
bool flag[251][251], a[251][251];
int dis[251][251];
int cas, r, c, ans;
const int INF = 1<<16;

bool solve(int K){
	int max1=-INF, max2=-INF, min1=INF, min2=INF;
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++){
			if (dis[i][j]<=K) continue;
			max1 = max(max1, i+j);
			max2 = max(max2, i-j);
			min1 = min(min1, i+j);
			min2 = min(min2, i-j);
		}
	if (min2==INF) return true;
	bool suc = false;
	for (int i=0;i<r;i++)
		for (int j=0;j<c;j++){
			if ((abs(max1-i-j)<=K)&&
				(abs(i+j-min1)<=K)&&
				(abs(i-j-min2)<=K)&&
				(abs(max2-(i-j))<=K))
				suc = true;
		}
	return suc;	
}

int main(){
	char ch;
	scanf("%d", &cas);
	pair<int, int> direc[4] = {make_pair(0,1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
	for (int t=1;t<=cas;t++){
		bfs.clear();
		scanf("%d %d", &r, &c);
		memset(flag, 0, sizeof(flag));
		memset(dis, -1, sizeof(dis));
		memset(a, 0, sizeof(a));
		for (int i=0;i<r;i++){
			ch = getchar();
			for (int j=0;j<c;j++){
				ch = getchar();
				if (ch=='1') {
					a[i][j] = true;
					flag[i][j] = true;
					bfs.push_back(make_tuple(i, j));
					dis[i][j] = 0;
				}
			}
		}
		while (bfs.size()>0){
			int x, y, cnt;
			tp cur = bfs[0];
			bfs.pop_front();
			tie(x, y) = cur;
			
			flag[x][y] = true;
			for (int i=0;i<4;i++){
				int xx = x + direc[i].first, yy=y+direc[i].second;
				if (xx<0||xx>=r||yy<0||yy>=c||dis[xx][yy]>=0) continue;
				bfs.push_back(make_tuple(xx,yy));
				dis[xx][yy] = dis[x][y]+1;
			}
		}
		int bl = 0, br = r+c;
		while (bl!=br){
			int mid = (bl+br)/2;
			if (solve(mid))
				br = mid;
			else bl = mid+1;
		}
		cout<<"Case #"<<t<<": "<<bl<<endl;
	}
}
/*
int a[251][251], im[251][251], dis[251][251];
int main(){
	int cas, r, c, ans;
	char ch;

	scanf("%d", &cas);
	pair<int, int> direc[4] = {make_pair(0,1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
	for (int t=1; t<=cas; t++){
		scanf("%d %d", &r, &c);
		memset(im, 20, sizeof(im));
		memset(dis, 20, sizeof(dis));
		//!!!!!!! special io
		for (int i=0;i<r;i++){
		    ch = getchar();
			for (int j=0;j<c;j++){
				ch = getchar();
				a[i][j] = ch - '0';
			}
		}
		for (int i=0;i<r;i++)
			for (int j=0;j<c;j++){
				if (a[i][j]==0) continue;
				im[i][j] = 0;
				for (int k=0;k<4;k++){
					int x=i, y=j, count=0;
					while (true){
						count++;
						x += direc[k].first;
						y += direc[k].second;
						if (x<0 || x>=r || y<0 || y>=c) break;
						if (a[x][y]==1 || count>im[x][y]) break;
						im[x][y] = min(count, im[x][y]);
					}
				}
			}

		for (int i=0;i<r;i++)
			for (int j=0;j<c;j++){
				//if (a[i][j]==1) continue;
				dis[i][j] = im[i][j];
				if (a[i][j]==1) continue;
				for (int k=0;k<4;k++){
					int x=i, y=j, count=0;
					while (true){
						count++;
						x += direc[k].first;
						y += direc[k].second;
						if (x<0 || x>=r || y<0 || y>=c) break;
						if (count>dis[i][j]) break;
						
						dis[i][j] = min(count+im[x][y], dis[i][j]);
					}
				}
			}
		ans = 1<<20;
		for (int i=0;i<r;i++){
			for (int j=0;j<c;j++){
				if (a[i][j]==1) continue;
				int tans = 0;
				for (int x=0;x<r;x++)
					for (int y=0;y<c;y++){
						if (a[x][y]==1) continue;
						
						tans = max(tans, min(dis[x][y], abs(i-x)+abs(j-y));
 					}
 				ans = min(ans, tans);
			}
		}
		cout<<"Case #"<<t<<": "<< ans << endl;
	}
}
*/