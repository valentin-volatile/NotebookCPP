//O(n + mlog m)
const ll INF = 1e15;

struct arista{
	ll next, w;
};

struct nodo{
	ll id, dist;
	bool operator<(nodo p) const { return dist > p.dist; }
};

vll dijkstra(int start, int n, vector<vector<arista>> &g){
	vll dist(n, INF); 
    dist[start] = 0;
    priority_queue<nodo> pq;
	pq.push({start, 0});
	while(pq.size()>0){
		nodo aux = pq.top();
		pq.pop();
		ll cur = aux.id;
		ll d = aux.dist;
		if(dist[cur] < d) continue;
		for(arista u : g[cur]) {
            ll new_d = d + u.w;
            if(new_d < dist[u.next]) {
                dist[u.next] = new_d;
                pq.push({u.next, new_d});
            }
		}
	}
	return dist;
}