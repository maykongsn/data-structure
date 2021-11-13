#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &vet, int p, int r) {
    if(p < r) {
        int min = p;
        for(int k = p+1; k <= r; k++) {
            if(vet[k] < vet[min])
                min = k;
        }
        swap(vet[p], vet[min]);
        selectionSort(vet, p+1, r);
    }
}

bool savePatient(vector<int> vac, vector<int> pac) {
    for(int i = 0; i < vac.size(); i++) {
        if(vac[i] < pac[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> vac(n);
    vector<int> pac(n);

    for(int i = 0; i < n; i++) {
        cin >> vac[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> pac[i];
    }

    selectionSort(vac, 0, n-1);
    selectionSort(pac, 0, n-1);

    cout << (savePatient(vac, pac) ? "Yes" : "No") << endl;
}