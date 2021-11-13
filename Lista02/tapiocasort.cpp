#include <iostream>
#include <vector>
using namespace std;

void flip(vector<int> &vet, int r) {
    for(int i = 0, j = r; i < j; i++, j--) {
        swap(vet[i], vet[j]);
    }
}

int maior(vector<int> vet, int r) {
    int index = 0;
    for(int i = 0; i <= r; i++) {
        if(vet[i] > vet[index]) {
            index = i;
        }
    }
    return index;
}

bool isOrdered(vector<int> vet) {
    for(int i = 0; i < vet.size()-1; i++) {
        if(vet[i] > vet[i+1]) {
            return false;
        }
    }
    return true;
}

void tapioca(vector<int> vet) {
    int index;
    int size = vet.size();
    vector<int> temp;
    for(int i = size-1; i > 0; i--) {
        int index = maior(vet, i);
        if(index < i) {
            if(index == 0) {
                flip(vet, i);
                temp.push_back(size-i);
            } else {
                flip(vet, index);
                flip(vet, i);
                temp.push_back(size-index);
                temp.push_back(size-i);
            }
        }

        if(isOrdered(vet)) {
            for(int i = 0; i < temp.size(); i++) {
                cout << temp[i] << " ";
            }
            cout << "0" << endl;
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> vet(n);

    for(int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    
    tapioca(vet);
}