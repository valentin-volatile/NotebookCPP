// O(V+E)
// usage: dfs(raiz, -1, grafo);
// en es_art true si el nodo es punto de articulacion
// si no me aseguran que sea conexo, tirar dfs en todos los nodos no vistos

vi tin, low;
vb visto, es_art;


int timer = 0;
void dfs(int cur, int prev, vector<vi> &grafo){
	tin[cur] = low[cur] = timer++;
	visto[cur] = true;
	
	int hijos = 0;
	for(int prox : grafo[cur]){
		if(prox == prev) continue;
		if(visto[prox]) low[cur] = min(low[cur], tin[prox]);
		else{
			hijos++;
			dfs(prox, cur, grafo);
			low[cur] = min(low[cur], low[prox]);
			if(low[prox] >= tin[cur] and prev != -1) es_art[cur] = true;
		}
	}
	
	if(prev == -1 and hijos>1) es_art[cur] = true;
}