// phi(p^k) = (p^k)-(p^(k-1))
// phi(a*b) = phi(a)*phi(b) con a y b coprimos
// phi(n) = phi(p1^k1) * ... * phi(px^kx)

vi phi; 
void precompute(int n){
    phi.resize(n+1);
    forr(i, 1, n+1) phi[i] = i; 
    forr(i, 2, n+1){
        if(phi[i] != i) continue;
        for(int j = i; j < n+1; j += i) phi[j] -= phi[j]/i;
    }
}

