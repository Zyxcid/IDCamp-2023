//Nama programmer : Syahid Nurhidayatullah
//Tanggal pembuatan program: 24-26 Oktober 2023 
/*
Deskripsi singkat program:  Manajemen Inventaris Barang di Toko 
Program ini memungkinkan Anda untuk:
menginput data barang,
mencari barang berdasarkan kode & nama, 
menjual barang kepada pelanggan, dan
menghitung stok barang.
*/
//	Untuk membedakan kode saya dengan yang lain saya menggunakan format -> S26_nama_variabel <- Syahid absen ke-26

#include <stdio.h>

//   Konstanta
#define S26_max_barang 99

// variabel untuk menyimpan data barang
char S26_nama_barang[S26_max_barang][39], S26_produsen[S26_max_barang][39], S26_kode_barang[S26_max_barang][39];
int S26_tahun_pembuatan[S26_max_barang], S26_harga[S26_max_barang];

// boolean untuk menentukan tersedia atau tidaknya barang, berisi nilai 1 atau 0
int S26_tersedia[S26_max_barang];

// variabel untuk menyimpan data penjualan
char S26_nama_pelanggan[S26_max_barang][39];
int S26_tanggal[S26_max_barang], S26_bulan[S26_max_barang], S26_tahun[S26_max_barang];

// variabel untuk menghitung total jumlah barang
int S26_jumlah_barang = 0;

void S26_judul(char nama[]) {
	printf("\n~~~~~~~~~~~~ Selamat Datang %s di Program Inventaris Toko ~~~~~~~~~~~~\n", nama);
}

void S26_info_barang() {
	if (S26_jumlah_barang == 0) {
        printf("Belum ada barang\n");
        return;
    }	
	int i;
	for (i = 0; i < S26_jumlah_barang; i++) {
		if (S26_jumlah_barang != 0 && S26_tersedia[i] == 1) {
			printf("---------------------\n");
    		printf(">> Informasi barang <<\n");
            printf("Nama barang: %s\n", S26_nama_barang[i]);
            printf("Status barang: Tersedia\n");
            printf("produsen: %s\n", S26_produsen[i]);
            printf("Tahun pembuatan: %d\n", S26_tahun_pembuatan[i]);
            printf("Kode barang: %s\n", S26_kode_barang[i]);
            printf("Harga barang: Rp.%d\n", S26_harga[i]);
            printf("---------------------\n");
        }
        else {
        	printf("---------------------\n");
    		printf(">> Informasi barang <<\n");
            printf("Nama barang: %s\n", S26_nama_barang[i]);
            printf("Status barang: Tidak tersedia\n");
            printf("Nama pelanggan: %s\n", S26_nama_pelanggan[i]);
            printf("Tanggal penjualan: %d-%d-%d\n", S26_tanggal[i], S26_bulan[i], S26_tahun[i]);
            printf("Harga barang: Rp.%d\n", S26_harga[i]);
            printf("---------------------\n");
		}
    }
}

void S26_tambah_barang() {
	//o	Informasi barang (nama barang, produsen, tahun pembuatan, kode barang, dan harga).
    if (S26_jumlah_barang < S26_max_barang) {
        printf("Masukkan nama barang: ");
        gets(S26_nama_barang[S26_jumlah_barang]);
        printf("Masukkan produsen barang: ");
        gets(S26_produsen[S26_jumlah_barang]);
        printf("Masukkan tahun pembuatan: ");
        scanf("%d", &S26_tahun_pembuatan[S26_jumlah_barang]);
        printf("Masukkan kode barang: ");
        scanf("%s", &S26_kode_barang[S26_jumlah_barang]);
        printf("Masukkan harga barang: ");
        scanf("%d", &S26_harga[S26_jumlah_barang]);
        getchar();
        S26_tersedia[S26_jumlah_barang] = 1;
        S26_jumlah_barang++;
        printf("Informasi barang ditambahkan\n");
    } 
	else {
        printf("Jumlah maksimum mahasiswa tercapai\n");
    }
}

void S26_cari_barang() {
	char S26_cari_barang[39];
	
    if (S26_jumlah_barang != 0) {
    	printf("Cari berdasar nama atau kode barang: ");
    	gets(S26_cari_barang);
    	
    	int i, ditemukan = 0;
		for (i = 0; i < S26_jumlah_barang; i++) {
	        if (strcmp(S26_cari_barang, S26_nama_barang[i]) == 0 ||
				strcmp(S26_cari_barang, S26_kode_barang[i]) == 0) {
				printf("---------------------\n");
				printf("--> Barang ditemukan <--\n");
				printf("Nama barang: %s\n", S26_nama_barang[i]);
	            printf("Produsen: %s\n", S26_produsen[i]);
	            printf("Tahun pembuatan: %d\n", S26_tahun_pembuatan[i]);
	            printf("Kode barang: %s\n", S26_kode_barang[i]);
	            printf("Harga barang: Rp.%d\n", S26_harga[i]);
	            printf("---------------------\n");
	            ditemukan = 1;
				break;
			}
		}
		
		if (!ditemukan) {
			printf("--> Barang tidak ditemukan <--\n");
		}
	}	
    else {
    	printf("Belum ada barang\n");
        return;
	}
}

void S26_jual_barang() {
    char S26_jual_barang[39];

    if (S26_jumlah_barang != 0) {
	    printf("Masukkan nama barang yang akan dijual: ");
		gets(S26_jual_barang);
		
		int i, ditemukan = 0;
		for (i = 0; i < S26_jumlah_barang; i++) {
	        if (strcmp(S26_jual_barang, S26_nama_barang[i]) == 0 ||
				strcmp(S26_jual_barang, S26_kode_barang[i]) == 0) {
				printf("--> Barang ditemukan <--\n");
				printf("Nama barang: %s\n", S26_nama_barang[i]);
			    printf("Produsen: %s\n", S26_produsen[i]);
	            printf("Tahun pembuatan: %d\n", S26_tahun_pembuatan[i]);
	            printf("Kode barang: %s\n", S26_kode_barang[i]);
	            printf("Harga barang: Rp.%d\n", S26_harga[i]);
				ditemukan = 1;
	            
	            char jual;
	            printf("\nYakin ingin menjual barang? (ketik Y untuk ya T untuk tidak): ");
	            scanf("%c", &jual);
	            switch (jual) {
	            	case 'Y':
	            		printf("Barang dijual dengan harga: Rp.%d\n", S26_harga[i]);
	            		printf("Masukkan nama pelanggan: ");
	            		scanf("%s", &S26_nama_pelanggan[i]);
	            		printf("Masukkan tanggal saat ini (angka)\n");
	            		printf("Tanggal: ");
	        		    scanf("%d", &S26_tanggal[i]);
	            		printf("Bulan: ");
	        		    scanf("%d", &S26_bulan[i]);
	            		printf("Tahun: ");
			            scanf("%d", &S26_tahun[i]);
	            		S26_tersedia[i] = 0;
	            		break;
	            	case 'T':
	            		printf("Kembali ke menu\n");
	            		break;
		            default:
	    	    	    printf("Pilihan tidak valid\n Kembali ke menu\n");
	    		}
			}
        }
        
		if (!ditemukan) {
        	printf("--> %s tidak ditemukan <--\n", S26_jual_barang);			
		}	
	}
    else {
        printf("Belum ada barang\n");
        return;
    }
}

S26_cek_stok_barang() {
	printf("-- Barang di inventaris saat ini: %d --\n", S26_jumlah_barang);	
}

int main() {
    int pilihan;
    char nama_user[39];
    printf("Masukkan nama user: ");
    scanf("%s", &nama_user);
    S26_judul(nama_user);
	
	do {
        printf("\n >> Menu << \n");
        printf("1. Info Barang\n");
        printf("2. Tambah Barang\n");
        printf("3. Cari Barang\n");
        printf("4. Jual Barang\n");
        printf("5. Cek Stok Barang\n");
        printf("9. Keluar\n");
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
            case 9:
                printf("Keluar dari program\n");
                break;
            default:
                printf("Pilihan tidak valid\n");
        }
    } while (pilihan != 9);

    return 0;
}
