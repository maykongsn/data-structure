#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> vet, vector<int> &indexes, int p, int r) {
    if(r > p) {
        int trocas = 0;
        for(int i = p; i <= r-1; i++) {
            if(vet[i] > vet[i+1]) {
                swap(vet[i], vet[i+1]);
                swap(indexes[i], indexes[i+1]);
                trocas++;
            }
        }
        if(trocas > 0) {
            bubbleSort(vet, indexes, p, r-1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vet(n);
    vector<int> indexes(n);
    for(int i = 0; i < n; i++) {
        cin >> vet[i];
        indexes[i] = i;
    }

    bubbleSort(vet, indexes, 0, n-1);
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            cout << indexes[i] << endl;
            break;
        }
        cout << indexes[i] << " ";
    }
}