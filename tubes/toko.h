#ifndef TOKO_H_INCLUDED
#define TOKO_H_INCLUDED

#include <iostream>
using namespace std;

struct Node {
    int harga;
    string namaBarang;
    string merk;
    int sisaStok;
    string warna[10];
    int jumlahWarna;
    Node* left;
    Node* right;
    
    Node(int h, string nama, string m, int stok);
};

class TokoAlatTulis {
private:
    Node* root;
    Node* insert(Node* node, int harga, string nama, string merk, int stok);
    void inorder(Node* node);
    Node* search(Node* node, int harga);
    
public:
    TokoAlatTulis();  
    void tambahBarang(int harga, string nama, string merk, int stok);
    void tambahWarna(int harga, string warna);
    void tampilkanSemua();
    void cariBarang(int harga);
    void isiDataDummy();
};

#endif