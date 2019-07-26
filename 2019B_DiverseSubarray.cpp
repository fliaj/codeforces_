#include <bits/stdc++.h>
using namespace std;
const int maxnode = 100001;

int _sum, _min, _max, op, qL, qR, v;

struct SegmentTree {
  int sumv[maxnode], minv[maxnode], maxv[maxnode], addv[maxnode];
  void clear(){
  	// memset(maxv, 0, sizeof(maxv));
  	// memset(addv, 0, sizeof(addv));
  	for (int i=0;i<maxnode;i++) maxv[i] = addv[i] =sumv[v]= 0;
  }
  // 维护信息
  void maintain(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    sumv[o] = minv[o] = maxv[o] = 0;
    if(R > L) {
      sumv[o] = sumv[lc] + sumv[rc];
      minv[o] = min(minv[lc], minv[rc]);
      maxv[o] = max(maxv[lc], maxv[rc]);
    }
    if(addv[o]) { minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o] * (R-L+1); }
  }

  void update(int o, int L, int R) {
    int lc = o*2, rc = o*2+1;
    if(qL <= L && qR >= R) { // 递归边界
      addv[o] += v; // 累加边界的add值
    } else {
      int M = L + (R-L)/2;
      if(qL <= M) update(lc, L, M);
      if(qR > M) update(rc, M+1, R);
    }
    maintain(o, L, R); // 递归结束前重新计算本结点的附加信息
  }

  void query(int o, int L, int R, int add) {
    if(qL <= L && qR >= R) { // 递归边界：用边界区间的附加信息更新答案
      _sum += sumv[o] + add * (R-L+1);
      _min = min(_min, minv[o] + add);
      _max = max(_max, maxv[o] + add);
    } else { // 递归统计，累加参数add
      int M = L + (R-L)/2;
      if(qL <= M) query(o*2, L, M, add + addv[o]);
      if(qR > M) query(o*2+1, M+1, R, add + addv[o]);
    }
  }
};

int main(){
	int cas, n, s, ans;
	int flag[maxnode], a[maxnode], b[maxnode];
	deque<int> buc[maxnode];
	SegmentTree tree;
	
	cin>>cas;	
	for (int t=1; t<=cas; t++){
		//memset(&tree, 0, sizeof(tree));
		tree.clear();
		
		memset(flag, 0, sizeof(flag));
		cin>>n>>s;
		for (int i=1;i<=n;i++) {
			cin>>b[i];
			buc[b[i]].push_back(i);
		}

		ans = 1;
		a[0] = 0;
		for (int i=1; i<=n;i++){
			flag[b[i]] ++;
			if (flag[b[i]]<s+1) a[i] = a[i-1]+1;
			else a[i] = a[i-1];
			
			if (flag[b[i]] == s+1) a[i] -= s;
			ans = max(ans, a[i]);

			//seg init
			op = 1;
			qL = qR = i;
			v = a[i];
			tree.update(1, 1, n);
		}
		//Segment Tree
		for (int i=2; i<n; i++){
			qL = i;
			v = -1;

			if (buc[b[i-1]].size()==1){
				qR = n;
				tree.update(1, 1, n);
			} else {
				qR = buc[b[i-1]][1]-1;
				tree.update(1, 1, n);
			}


			if (buc[b[i-1]].size()>s){
				v = s;
				qL = buc[b[i-1]][s];
				if (buc[b[i-1]].size()>s+1)
					qR = buc[b[i-1]][s+1]-1;
				else qR = n;
				tree.update(1, 1, n);
			}

			buc[b[i-1]].pop_front();

			//query
			qL = i; qR = n; _max = 0;
			tree.query(1, 1, n, 0);

			ans = max(_max, ans);
			// cout<<ans<<endl;
		}

		cout<<"Case #"<<t<<": "<< ans<< endl;
	}


}
