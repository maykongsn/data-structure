#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;

int calc(int** mat, int i, int j, int size) { 
    if(i == size) {
        return mat[i][j];
    } else {
        mat[i][j] = calc(mat, i+1, j, size) + calc(mat, i+1, j+1, size);
        return mat[i][j];
    }
}

int main() {
    string line;
    int k = 0;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value)
        vet.push_back(value);
    
    int** mat = (int**) malloc(vet.size() * sizeof(int**));
    for(int i = 0; i < vet.size(); i++) {
        mat[i] = (int *) malloc (vet.size() * sizeof(int));
    }

    for(int i = 0; i < vet.size(); i++) {
        for(int j = 0; j < vet.size(); j++) {
            if(i == vet.size() - 1) {
                mat[i][j] = vet[k];
                k++;
            } else {
                mat[i][j] = 0;
            }
        }
    }

    calc(mat, 0, 0, vet.size()-1);
    for(int i = 0; i < vet.size(); i++) {
        cout << "[ ";
        for(int j = 0; j < vet.size(); j++) {
            if(mat[i][j] != 0) {
                cout << mat[i][j] << " ";
            }
        }
        cout << "]" << endl;
        
    }
    
    free(mat);
}