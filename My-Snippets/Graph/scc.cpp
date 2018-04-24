vi dfs_num,s,dfs_low;
bool visited[N];
ll dfsNumberCounter=0;

void scc(ll u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
	
	s.push_back(u);

	visited[u] = 1;
	for (ll j = 0; j < (ll)adjlist[u].size(); j++) {
		ll v = adjlist[u][j];
		if (dfs_num[v] == -1){
			scc(v);	
		}
		
		if (visited[v]){
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
		}
	}
		
	if (dfs_low[u] == dfs_num[u]) {

		while (1) {
			int v = s.back(); s.pop_back(); visited[v] = 0;
			
			//do whatever you want with the scc.
			
			if (u == v) break; 	
		}
		s.clear();	
	} 
}

int main(){

	dfs_num.assign(N, -1);
 	dfs_low.assign(N, 0);
 	memset(visited, false, sizeof(visited));
 	
 	F(i, 0, n){
 		if (dfs_num[i] == -1)
 		{
 			scc(i);
 		}
 	}
}
