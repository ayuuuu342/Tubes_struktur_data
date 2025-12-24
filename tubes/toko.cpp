#include "toko.h"

Node::Node(int h, string nama, string m, int stok, string w) {
    harga = h;
    namaBarang = nama;
    merk = m;
    sisaStok = stok;

    warna[0] = w;
    jumlahWarna = 1;

    left = NULL;
    right = NULL;
}


TokoAlatTulis::TokoAlatTulis() {
    root = NULL;
}

void TokoAlatTulis::inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        cout << "\n=========================\n";
        cout << "Harga: Rp " << node->harga << endl;
        cout << "Nama: " << node->namaBarang << endl;
        cout << "Merk: " << node->merk << endl;
        cout << "Stok: " << node->sisaStok << endl;
        cout << "Warna: ";
        for (int i = 0; i < node->jumlahWarna; i++) {
            cout << node->warna[i];
            if (i < node->jumlahWarna - 1) cout << ", ";
        }
        cout << endl;
        inorder(node->right);
    }
}

Node* TokoAlatTulis::search(Node* node, int harga) {
    if (node == NULL || node->harga == harga) {
        return node;
    }
    
    if (harga < node->harga) {
        return search(node->left, harga);
    }
    
    return search(node->right, harga);
}

Node* TokoAlatTulis::insert(Node* node, int harga, string nama, string merk, int stok, string warna) {
    if (node == NULL) {
        return new Node(harga, nama, merk, stok, warna);
    }

    if (harga < node->harga) {
        node->left = insert(node->left, harga, nama, merk, stok, warna);
    } else if (harga > node->harga) {
        node->right = insert(node->right, harga, nama, merk, stok, warna);
    }

    return node;
}
void TokoAlatTulis::tambahBarang(int harga, string nama, string merk, int stok, string warna) {
    root = insert(root, harga, nama, merk, stok, warna);
    cout << "Barang berhasil ditambahkan!\n";
}

void TokoAlatTulis::tampilkanSemua() {
    cout << "\n===== DAFTAR BARANG =====";
    inorder(root);
    cout << "\n=========================\n";
}

void TokoAlatTulis::cariBarang(int harga) {
    Node* hasil = search(root, harga);
    if (hasil != NULL) {
        cout << "\nBarang ditemukan!\n";
        cout << "Harga: Rp " << hasil->harga << endl;
        cout << "Nama: " << hasil->namaBarang << endl;
        cout << "Merk: " << hasil->merk << endl;
        cout << "Stok: " << hasil->sisaStok << endl;
        cout << "Warna: ";
        for (int i = 0; i < hasil->jumlahWarna; i++) {
            cout << hasil->warna[i];
            if (i < hasil->jumlahWarna - 1) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "\nBarang tidak ditemukan!\n";
    }
}

// DATA DUMMY WOY
void TokoAlatTulis::isiDataDummy() {
    root = insert(root, 5000, "Pulpen Gel", "Pilot", 150, "Hitam");
    root = insert(root, 2500, "Pensil 2B", "Faber Castell", 200, "Biru");
    root = insert(root, 8000, "Spidol Whiteboard", "Snowman", 80, "Merah");
    root = insert(root, 1500, "Penghapus", "Steadtler", 300, "Hijau");
    root = insert(root, 12000, "Buku Tulis", "Sinar Dunia", 120, "Putih");
    root = insert(root, 3500, "Penggaris 30cm", "Butterfly", 100, "Ungu");
    root = insert(root, 15000, "Kertas HVS A4", "Paperline", 50, "Putih");
    root = insert(root, 7000, "Lem Cair", "UHU", 60, "Merah");
    root = insert(root, 4000, "Correction Tape", "Kenko", 90, "Biru");
    root = insert(root, 10000, "Stabilo Highlighter", "Stabilo Boss", 75, "Kuning");
    cout << "Data dummy ditambahkan\n";
}
