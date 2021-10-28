#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void print(vector<int> vet, int pos) {
    cout << vet[pos] << " ";
    pos++;
    if (vet.size() == pos)
        return;
    print(vet, pos);
}

void printInvert(vector<int> vet, int pos) {
    cout << vet[pos] << " ";
    pos--;
    if(pos < 0)
        return;
    printInvert(vet, pos);
}

int sum(vector<int> vet, int size) {
    if(size == 1) {
        return vet[0];
    } else {
        return vet[size - 1] + sum(vet, size - 1);
    }
}

int mult(vector<int> vet, int size) {
    if(size == 1) {
        return vet[0];
    } else {
        return vet[size - 1] * mult(vet, size - 1);
    }
}

int min(vector<int> vet, int pos, int value) {
    if(vet.size() == pos) {
        return vet[value];
    } else if (vet[pos] < vet[value]) {
        value = pos;
        return min(vet, pos + 1, value);
    }
    return min(vet, pos + 1, value);
}

void invert(vector<int> vet, int ini, int end) {
    if(ini >= end) {
        print(vet, 0);
        return;
    }

    int temp = vet[ini];
    vet[ini] = vet[end];
    vet[end] = temp;

    invert(vet, ini + 1, end - 1);
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while(ss >> value)
        vet.push_back(value);
    cout << "vet : [ ";
    print(vet, 0);
    cout << "]" << endl << "rvet: [ ";
    printInvert(vet, vet.size() - 1);
    cout << "]" << endl;
    cout << "sum : " << sum(vet, vet.size()) << endl;
    cout << "mult: " << mult(vet, vet.size()) << endl;
    cout << "min : " << min(vet, 0, 0) << endl;
    cout << "inv : [ ";
    invert(vet, 0, vet.size() - 1);
    cout << "]" << endl;
}
