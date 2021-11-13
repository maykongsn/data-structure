#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int bubblesort(vector<int> vet) {
    int count = 0;
    int n = vet.size();
    bool swapped = true;

    while(swapped != false) {
        swapped = false;
        count++;
        for(int i = 0; i < n-1; i++) {
            if(vet[i] > vet[i+1]) {
                swap(vet[i], vet[i+1]);
                swapped = true;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> vet(n);

    for(int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    cout << bubblesort(vet) << endl;
}