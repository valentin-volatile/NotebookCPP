vi primos, minprime;
void criba(int n){
	minprime.resize(n+1);
	forn(i, n+1) minprime[i] = i;
	forr(i, 2, n+1){
		if(minprime[i] != i) continue;
		primos.pb(i);
		for(ll p = 1ll*i*i; p<n+1; p += i){
			if(minprime[p]==p) minprime[p] = i;
		}
	}
}