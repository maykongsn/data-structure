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

int repeated(vector<int> vet, int size) {
    vector<int> num;
    for(int i = 0; i < size; i++) {
        if(vet[i] == vet[i+1]) {
            num.push_back(vet[i]);
        }
    }

    return num.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> vet(n);

    for(int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    selectionSort(vet, 0, n-1);
    cout << repeated(vet, n) << endl;
}