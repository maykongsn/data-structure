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

void frequency(vector<int> vet, int size) {
    int cont = 1;
    int max = 0;
    int num = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(vet[i] == vet[j]) {
                cont++;
            } else {
                break;
            }
        }
        if(cont > max) {
            max = cont;
            num = vet[i];
        }
        cont = 1;
    }

    cout << num << " " << max << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> vet(n);

    for(int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    selectionSort(vet, 0, n-1);
    frequency(vet, n);
}