/**
    __author__ : srv_twry
**/

#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
/*----------------------------------------------------------------------*/

const int N = 10010, LOG = 15;
int chain_num, chain_head[N], chain_size[N], position_in_base[N], chain_idx[N];
vector <int> adj[N], costs[N], indexx[N];
int depth[N], pa[LOG][N], otherEnd[N], subsize[N];
int baseArray[N], ptr, n;

struct SegmentTreeNode {
	int maxm;

	//assign the leaf with the value.
	void assignLeaf(int value) {
		maxm = value;
	}
	
	//do the merge option here.
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		maxm = max(left.maxm, right.maxm);
	}
	
	//return the output.
	int getValue() {
		return maxm;
	}
};

//T is the input array type and V is the output type.
template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N; // tree size.
	
public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}
	
private:	
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}
	
	int getSegmentTreeSize(int N) {
		return 4*N;	
	}
	
	void update(int stIndex, int lo, int hi, int index, T value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

void reset() {
	ptr = 0; chain_num = 0;
	FOR(i, 0, N) {
		adj[i].clear();
		costs[i].clear();
		indexx[i].clear();
		chain_head[i] = -1;
		FOR(j, 0, LOG) pa[j][i] = -1;
	}
}

void dfs(int curr, int par = -1, int dpth = 0) {
	pa[0][curr] = par;
	depth[curr] = dpth;
	subsize[curr] = 1;
	FOR(i, 0, adj[curr].size()) {
		int nxt = adj[curr][i];
		if(nxt != par) {
			otherEnd[indexx[curr][i]] = nxt;
			dfs(nxt, curr, dpth + 1);
			subsize[curr] += subsize[nxt];
		}
	}
}

void HLD(int curr, int cost, int par = -1) {
	if(chain_head[chain_num] == -1) {
		chain_head[chain_num] = curr;
	}
	chain_idx[curr] = chain_num;
	position_in_base[curr] = ptr;
	baseArray[ptr] = cost;
	ptr++;

	int maxm = -1, best = -1;
	FOR(i, 0, adj[curr].size()) {
		int nxt = adj[curr][i];
		if(nxt != par) {
			if(subsize[nxt] > maxm) {
				maxm = subsize[nxt];
				best = i;
			}
		}
	}

	if(best >= 0) {
		HLD(adj[curr][best], costs[curr][best], curr);
	}

	FOR(i, 0, adj[curr].size()) {
		int nxt = adj[curr][i];
		if(nxt != par && nxt != best) {
			chain_num++;
			HLD(nxt, costs[curr][i], curr);
		}
	}
}

int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LOG; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LOG-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void change(SegmentTree<int, int> &st, int edge, int value) {
	int nxt = otherEnd[edge];
	st.update(position_in_base[nxt], value);
}

int query_up(SegmentTree<int, int> &st, int u, int v) {
	if(u == v) return 0;
	int uchain, vchain = chain_idx[v], ans = -1;

	while(true) {
		uchain = chain_idx[u];
		if(uchain == vchain) {
			if(u == v) break;
			int res = st.getValue(position_in_base[v] + 1, position_in_base[u]);
			ans = max(ans, res);
			break;
		}
		int res = st.getValue(position_in_base[chain_head[uchain]], position_in_base[u]);
		ans = max(ans, res);
		u = chain_head[uchain];
		u = pa[0][u];
	}

	return ans;
}

int query(SegmentTree<int,int> &st, int u, int v) {
	int lc = lca(u, v);
	int a1 = query_up(st, u, lc);
	int a2 = query_up(st, v, lc);
	return max(a1, a2);
}

int main(){
    int t,a,b,c;
	scanf("%d", &t);
	while(t--) {
		reset();
		scanf("%d", &n);
		FOR(i, 1, n) {
			scanf("%d %d %d",&a, &b, &c); a--; b--;

			adj[a].push_back(b);
			costs[a].push_back(c);
			indexx[a].push_back(i-1);

			adj[b].push_back(a);
			costs[b].push_back(c);
			indexx[b].push_back(i-1);
		}

		dfs(0);
		HLD(0, -1);
		SegmentTree<int, int> st(baseArray, ptr);

		FOR(lg, 1, LOG) {
			FOR(i, 0, n) {
				if(pa[lg][i-1] == -1) continue;
				pa[lg][i] = pa[pa[lg][i-1]][i-1];
			}
		}

		char s[100];
		while(true) {
			scanf("%s", s);
			if(s[0]=='D') {
				break;
			}
			scanf("%d %d", &a, &b);
			a--;
			if(s[0] == 'Q') {
				b--;
				printf("%d\n", query(st, a, b));
				// cout<<query(st, a, b)<<endl;
			} else {
				change(st, a, b);
			}
		}
	}

    return 0;
}