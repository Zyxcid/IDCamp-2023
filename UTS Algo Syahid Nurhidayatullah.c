//nama programmer : Syahid Nurhidayatullah
//tanggal pembuatan program: 24 Oktober 2023 
/*
deskripsi singkat program:  Manajemen Inventaris Barang di Toko 
Anda adalah seorang pemilik toko yang ingin mengelola inventaris barang di toko Anda. 
Anda perlu mengembangkan program yang memungkinkan Anda untuk 
menginput data barang,
mencari barang berdasarkan kode, 
menjual barang kepada pelanggan, dan 
menghitung stok barang.
*/
//untuk membedakan kode saya dengan yang lain saya menggunakan format -> S26_nama_variabel <- Syahid absen ke-26

#include <stdio.h>

char S26_nama_barang, S26_produsen, S26_kode_barang,

void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        printf("Masukkan nama depan mahasiswa: ");
        gets(namaDepanMahasiswa[jumlahMahasiswa]);
        printf("Masukkan nama belakang mahasiswa: ");
        gets(namaBelakangMahasiswa[jumlahMahasiswa]);
        printf("Masukkan usia mahasiswa: ");
        scanf("%d", &usiaMahasiswa[jumlahMahasiswa]);
        getchar(); // Membersihkan karakter newline dari buffer
        jumlahMahasiswa++;
        printf("Data mahasiswa ditambahkan.\n");
    } else {
        printf("Jumlah maksimum mahasiswa tercapai.\n");
    }
}

void tampilkanMahasiswa() {
    if (jumlahMahasiswa == 0) {
        printf("Belum ada data mahasiswa.\n");
    } else {
        printf("Data Mahasiswa:\n");
        int i;
		for (i = 0; i < jumlahMahasiswa; i++) {
            printf("Nama: %s %s\n", namaDepanMahasiswa[i], namaBelakangMahasiswa[i]);
            printf("Usia: %d\n", usiaMahasiswa[i]);
            printf("--------------\n");
        }
    }
}

void cariMahasiswa() {
    if (jumlahMahasiswa == 0) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    char namaDepanCari[50];
    char namaBelakangCari[50];
    printf("Masukkan nama depan yang akan dicari: ");
    gets(namaDepanCari);
    printf("Masukkan nama belakang yang akan dicari: ");
    gets(namaBelakangCari);

    int i, ditemukan = 0;
    for (i = 0; i < jumlahMahasiswa; i++) {
        if (strcmp(namaDepanCari, namaDepanMahasiswa[i]) == 0 &&
            strcmp(namaBelakangCari, namaBelakangMahasiswa[i]) == 0) {
            printf("Mahasiswa ditemukan:\n");
            printf("Nama: %s %s\n", namaDepanMahasiswa[i], namaBelakangMahasiswa[i]);
            printf("Usia: %d\n", usiaMahasiswa[i]);
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("Mahasiswa dengan nama %s %s tidak ditemukan.\n", namaDepanCari, namaBelakangCari);
    }
}

int main() {
    int pilihan;

    do {
        printf("Menu:\n");
        printf("1. Info Barang\n");
        printf("2. Tambah Barang\n");
        printf("3. Cari Barang\n");
        printf("4. Jual Barang\n");
        printf("5. Cek Stok Barang\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar(); 
        
        switch (pilihan) {
            case 1:
                S26_info_barang();
                break;
            case 2:
                S26_tambah_barang();
                break;
            case 3:
                S26_cari_barang();
                break;
            case 4:
                S26_jual_barang();
                break;
            case 5:
                S26_cek_stok_barang();
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan == 4);

    return 0;
}

