#include <iostream>
#include <vector>
using namespace std;

void show(vector<string> mat) {
    for(int i = 0; i < mat.size(); i++) {
        cout << mat[i] << endl;
    }
}

void tocar_fogo(vector<string> &mat, int l, int c) {
    int nl = mat.size();
    int nc = mat[0].size();

    if((l < 0) || (c < 0) || (l >= nl) || (c >= nc)) {
        return;
    }

    if(mat[l][c] == '#') {
        mat[l][c] = 'o';
        tocar_fogo(mat, l + 1, c);
        tocar_fogo(mat, l - 1, c);
        tocar_fogo(mat, l, c + 1);
        tocar_fogo(mat, l, c - 1);
    } else {
        return;
    }
}

int main() {
    int nl = 0, nc = 0, l = 0, c = 0;
    cin >> nl >> nc >> l >> c;
    vector<string> mat;
    for(int i = 0; i < nl; i++) {
        string line;
        cin >> line;
        mat.push_back(line);
    }
    tocar_fogo(mat, l, c);
    show(mat);
}