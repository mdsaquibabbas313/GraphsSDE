#include<bits/stdc++.h>
using namespace std;

class DisjoinSet {
	vector<int> rank,parent,size;
public:
	DisjoinSet(int n) {
		rank.resize(n+1 , 0);
		parent.resize(n+1);
		size.resize(n+1);
		for(int i = 0 ; i<=n ; i++) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	int findPar(int node) {
		if(node == parent[node]) {
			return node;
		}

		return parent[node] = findPar(parent[node]);
	}
	void unionByRank(int u , int v) {
		int ulp_u = findPar(u);
		int ulp_v = findPar(v);
		if(ulp_u == ulp_v) return ; // same component

		if(rank[ulp_u] < rank[ulp_v]) {
			parent[ulp_u] = ulp_v;
		}

		else if(rank[ulp_v] < rank[ulp_u]) {
			parent[ulp_v] = ulp_u;
		}

		else{
			//same
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}

	}
	// Union By Size
	void unionBySize(int u , int v) {
		int ulp_u = findPar(u);
		int ulp_v = findPar(v);
		if(ulp_u == ulp_v) return ; // same component

		if(size[ulp_u] < size[ulp_v]) {
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_v];
		}

		else {
			parent[ulp_v] = ulp_u;
			size[ulp_v] += size[ulp_v];
		}
		

	}
};
int main() {

	DisjoinSet ds(7);

	/*ds.unionByRank(1,2);
	ds.unionByRank(2,3);
	ds.unionByRank(4,5);
	ds.unionByRank(6,7);
	ds.unionByRank(5,6);
	// check 3 & 7 before union same par or not
	if(ds.findPar(3) == ds.findPar(7)) {
		cout << "Same\n";
	}
	else {
		cout << "Not Same\n";
	}
	ds.unionByRank(3,7);

	if(ds.findPar(3) == ds.findPar(7)) {
		cout << "Same\n";
	}
	else {
		cout << "Not Same\n";
	}
	// ds.unionByRank(1,2);*/

	ds.unionBySize(1,2);
	ds.unionBySize(2,3);
	ds.unionBySize(4,5);
	ds.unionBySize(6,7);
	ds.unionBySize(5,6);
	// check 3 & 7 before union same par or not
	if(ds.findPar(3) == ds.findPar(7)) {
		cout << "Same\n";
	}
	else {
		cout << "Not Same\n";
	}
	ds.unionBySize(3,7);

	if(ds.findPar(3) == ds.findPar(7)) {
		cout << "Same\n";
	}
	else {
		cout << "Not Same\n";
	}


    return 0;
}