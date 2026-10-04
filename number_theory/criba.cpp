vi primos, minprime; //2e5 ~18.000 | 1e6 ~79.000
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

vector<pii> factorize(int x){
    vector<pii> fac;
    while(x > 1){
        int p = minprime[x];
        int cant = 0;
        while(x % p == 0) {
            cant++;
            x /= p;
        }
        fac.pb({p, cant});
    }
    return fac;
}