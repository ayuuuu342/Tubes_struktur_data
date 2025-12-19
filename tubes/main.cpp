#include "toko.h"

int main() {
    TokoAlatTulis toko;
    int pilihan, harga, stok;
    string nama, merk, warna;
    
    // BUAT ISI DATA DUMMY OTOMATIS
    toko.isiDataDummy();
    
    do {
        cout << "\n=== TOKO ALAT TULIS & FOTOKOPI ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tambah Warna ke Barang\n";
        cout << "3. Tampilkan Semua Barang\n";
        cout << "4. Cari Barang\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                cout << "Harga: ";
                cin >> harga;
                cin.ignore();
                cout << "Nama Barang: ";
                getline(cin, nama);
                cout << "Merk: ";
                getline(cin, merk);
                cout << "Stok: ";
                cin >> stok;
                toko.tambahBarang(harga, nama, merk, stok);
                break;
            case 2:
                cout << "Harga Barang: ";
                cin >> harga;
                cin.ignore();
                cout << "Warna: ";
                getline(cin, warna);
                toko.tambahWarna(harga, warna);
                break;
            case 3:
                toko.tampilkanSemua();
                break;
            case 4:
                cout << "Harga Barang: ";
                cin >> harga;
                toko.cariBarang(harga);
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 0);
    
    return 0;
}