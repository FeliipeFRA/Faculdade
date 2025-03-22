/*
Exemplo 1
*/

bool exemplo1(vector<int> v, int x){
    int tamanho = v.size(); // O(1) - ignora
    for(int i = 0; i < tamanho; i++){ // O(n)
        if (v[i] == x) return true; // O(1) - ignora
    }
    return false; // O(1) - ignora
} 

// O(n)

/*
Exemplo 2
*/

bool exemplo2(vector<int> v){
    int tamanho = v.size(); // O(1)
    for(int i = 0; i < tamanho; i++){ // O(n)
        for (int j = 0; j < tamanho; j++){ // O(n)
            if (i != j && v[i] == v[j]) // O(1)
                return true; // O(1)
        }
    return false; // O(1)
    }
}
// O(n) * O(n) = O(nˆ2)

/*
Exemplo 3
*/

int exemplo3(vector<int> v){
    int tamanho = v.size();  // O(1) - ignora
    int bla = 0; // O(1)
    for(int i = 0; i < tamanho; i++){ // O(n)
        for (int j = 0; j < tamanho; j++){ // O(n)
            if (v[i] == v[j]) // O(1)
                bla++; // O(1)
        }
    }
    
    // ....

    int ble = 0; // O(1)
    for(int i = 0; i < tamanho; i++){ // O(n)
        if(v[i] == 10) // O(1)
            ble = 2*ble; // O(1)
    }

    // ....

    int bli = 0; // O(1)
    for(int i = 0; i < tamanho; i++){ // O(n)
        if(v[i] == 5) // O(1)
            bli += 5; // O(1)
    }

    return bla+ble+bli; // O(1)
}

// O(n) * O(n) + O(n) + O(n) --> O(nˆ2) + 2*O(n) --> 
// O(nˆ2) + O(n) --> O(nˆ2) 

/*
Exemplo 4
*/

bool exemplo4(vector<int> v, vector<int> w){
    int tamanho = v.size(); // O(1)
    int tamanho2 = w.size(); // O(1)
    for (int i = 0; i < tamanho; i++){ // O(n)
        for (int j = 0; j < tamanho2; j++){ // O(m)
            if (v[i] == v[j]) // O(1)
                return true; // O(1)
        }
    }
    return false; // O(1)
}

// O(n) * O(m)

/*
Exemplo 5
*/

bool exemplo5(vector<int> idades){
    sort(idades.begin(), idades.end()); // O(n log n)
    return idades[0] == idades[1]; // O(1)
}
// O(n log n)

/*
Exemplo 6
*/

bool exemplo6(set<int> s, vector<int> v){
    int tamanho = v.size(); // O(1)
    for (int i = 0; i < tamanho; i++){ // O(n)
        if (s.count(v[i])) // O(n)
            return true; // O(1)
    }
    return false; // O(1)
}
// O(n) * O(n) ---> O(nˆ2)