# Improvekuy
Random project that I found interesting and can help me improve my code

/* 
Nama File : UTS.c
Programmer : Alvin Ilham / 23076027
Tgl. pembuatan : 24 Oktober 2023
Deskripsi :  Program Manajemen Perekrutan Anggota Organisasi BEM Universitas
*/

#include <stdio.h>
#include <string.h>

#define MAX_CALON 10
#define MAX_ANGGOTA_BEM 10

// Variabel global untuk menyimpan data anggota BEM resmi
char namaBEM[MAX_ANGGOTA_BEM][50];
char nomorMahasiswaBEM[MAX_ANGGOTA_BEM][10];
float ipkBEM[MAX_ANGGOTA_BEM];
int komitmenBEM[MAX_ANGGOTA_BEM];
int semesterBEM[MAX_ANGGOTA_BEM];
char alamatEmailBEM[MAX_ANGGOTA_BEM][50];
char alasanBergabungBEM[MAX_ANGGOTA_BEM][100];
char gradeBEM[MAX_ANGGOTA_BEM];

// Variabel global untuk menyimpan data calon anggota
char namaCalon[MAX_CALON][50];
char nomorMahasiswaCalon[MAX_CALON][10];
float ipkCalon[MAX_CALON];
int komitmenCalon[MAX_CALON];
int semesterCalon[MAX_CALON];
char alamatEmailCalon[MAX_CALON][50];
char alasanCalon[MAX_CALON][100];
char gradeCalon[MAX_CALON]; // Deklarasikan variabel gradeCalon sebagai variabel global

int jumlahCalon = 0; // Deklarasikan jumlahCalon sebagai variabel global

void judul() {
    printf("\n===== Manajemen Perekrutan Anggota Organisasi BEM Universitas =====\n");
}

void tampilkanHeaderTabel() {
    printf("%-20s%-20s%-10s%-15s%-10s%-30s%-30s%-20s%-10s\n", "Nama", "Nomor Mahasiswa", 
    "IPK", "Komitmen", "Semester", "Alamat Email", "Alasan Bergabung", "Status", "Nilai");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void input(char nama[], char* nomorMahasiswa, float* ipk, int* komitmen, int* semester, char alamatEmail[], char alasan[]) {
    printf("Masukkan nama calon anggota              		      : ");
    scanf(" %[^\n]", nama);

    printf("Masukkan nomor mahasiswa               	    		   : ");
    scanf("%s", nomorMahasiswa);

    printf("Masukkan IPK calon anggota(0.0 - 4.0)          			: ");
    scanf("%f", ipk);

    printf("Masukkan tingkat komitmen calon anggota(1-10)  			: ");
    scanf("%d", komitmen);

    printf("Masukkan semester yang sedang ditempuh calon anggota sekarang(1-8)	: ");
    scanf("%d", semester);

    getchar();  // Mengonsumsi newline yang masih tersisa di buffer

    printf("Masukkan alamat email                          				: ");
    scanf(" %[^\n]", alamatEmail);

    printf("Masukkan alasan bergabung                      				: ");
    scanf(" %[^\n]", alasan);
}

void menampilkanData(char nama[], char nomorMahasiswa[], float ipk, int komitmen, int semester, char alamatEmail[], 
						char alasan[], char grade) {
    char* status = (grade >= 'A' && grade <= 'D') ? "Lulus" : "Tidak Lulus";
    printf("%-20s%-20s%-10.2f%-15d%-10d%-30s%-30s%-20s%-10c\n", nama, nomorMahasiswa, ipk, komitmen, semester, 
			alamatEmail, alasan, status, grade);
}

char hitungNilai(float ipk, int komitmen, int semester) {
    if (ipk > 4.0 || komitmen > 10 || semester > 8) {
        printf("Error: Data tidak valid (IPK, komitmen, atau semester melebihi batas)\n");
        return 'X';  // Menggunakan nilai 'X' untuk menandakan error
    } else if (ipk >= 4.0 && komitmen >= 9 && semester >= 5) {
        return 'A';
    } else if (ipk >= 3.5 && komitmen >= 8 && semester >= 4) {
        return 'B';
    } else if (ipk >= 3.0 && komitmen >= 7 && semester >= 3) {
        return 'C';
    } else if (ipk >= 2.5 && komitmen >= 6 && semester >= 2) {
        return 'D';
    } else if (ipk >= 2.0 && komitmen >= 4 && semester >= 1) {
        return 'E';
    } else {
        printf("Nilai tidak valid\n");
        return 'F';
    }
}

// Menambahkan fungsi ini untuk menampilkan data anggota BEM resmi
void menampilkanDataBEM(char nama[], char nomorMahasiswa[], float ipk, int komitmen, int semester, char alamatEmail[], 
						char alasan[], char grade) {
    char* status = (grade >= 'A' && grade <= 'D') ? "Lulus" : "Tidak Lulus";
    printf("%-20s%-20s%-10.2f%-15d%-10d%-30s%-30s%-20s%-10c\n", nama, nomorMahasiswa, ipk, komitmen, semester, 
			alamatEmail, alasan, status, grade);
}

// Menambahkan fungsi ini untuk menyimpan data calon anggota ke dalam file
void simpanDataKeFile(char nama[], char nomorMahasiswa[], float ipk, int komitmen, int semester, char alamatEmail[], 
						char alasan[], char grade) {
    char path[] = "calon_anggota.txt";
    FILE *file = fopen(path, "a");

    if (file != NULL) {
        fprintf(file, "Nama              : %s\n", nama);
        fprintf(file, "Nomor Mahasiswa   : %s\n", nomorMahasiswa);
        fprintf(file, "IPK               : %.2f\n", ipk);
        fprintf(file, "Komitmen          : %d\n", komitmen);
        fprintf(file, "Semester          : %d\n", semester);
        fprintf(file, "Alamat Email      : %s\n", alamatEmail);
        fprintf(file, "Alasan Bergabung   : %s\n", alasan);

        // Menentukan status berdasarkan nilai grade
        char* status = (grade >= 'A' && grade <= 'D') ? "Lulus" : "Tidak Lulus";
        fprintf(file, "Nilai             : %c\n", grade);
        fprintf(file, "Status            : %s\n", status);

        fprintf(file, "------------------------------------------------------------\n");
        
        fclose(file);
        printf("Data telah disimpan ke dalam berkas 'calon_anggota.txt'\n");
    } else {
        printf("Gagal membuka berkas untuk penyimpanan data.\n");
        // Handle kesalahan sesuai kebutuhan, misalnya dengan mengembalikan kode kesalahan.
    }
}

void menu(int* pilihan) {
    printf("\nMenu Pilihan : \n");
    printf("1. Input data calon anggota BEM\n");
    printf("2. Menampilkan data calon anggota \n");
    printf("3. Seleksi anggota BEM\n");
    printf("4. Menampilkan data anggota BEM resmi \n");
    printf("5. Keluar\n\n");
    printf("Silakan pilih menu yang diinginkan : \n");
    scanf("%d", pilihan);
}

int main() {
    int pilihan;
    judul();
    
    do {
        menu(&pilihan);

        switch (pilihan) {
            case 1:
                if (jumlahCalon < MAX_CALON) {
                    input(namaCalon[jumlahCalon], nomorMahasiswaCalon[jumlahCalon], &ipkCalon[jumlahCalon],
                          &komitmenCalon[jumlahCalon], &semesterCalon[jumlahCalon],
                          alamatEmailCalon[jumlahCalon], alasanCalon[jumlahCalon]);
                    printf("Data calon anggota telah ditambahkan. \n");
                    gradeCalon[jumlahCalon] = hitungNilai(ipkCalon[jumlahCalon], komitmenCalon[jumlahCalon], 
					semesterCalon[jumlahCalon]);
                    jumlahCalon++;
                } else {
                    printf("Maksimum jumlah calon anggota telah tercapai\n");
                }
                
                char path[] = "calon_anggota.txt";
                FILE *file = fopen(path, "a");
                if (file != NULL) {
                    for (int i = 0; i < jumlahCalon; i++) {
                        fprintf(file, "Nama            : %s\n", namaCalon[i]);
                        fprintf(file, "Nomor Mahasiswa : %s\n", nomorMahasiswaCalon[i]);
                        fprintf(file, "IPK             : %.2f\n", ipkCalon[i]); 
                        fprintf(file, "Komitmen        : %d\n", komitmenCalon[i]);
                        fprintf(file, "Semester        : %d\n", semesterCalon[i]);
                        fprintf(file, "Alamat Email    : %s\n", alamatEmailCalon[i]);
                        fprintf(file, "Alasan Bergabung : %s\n", alasanCalon[i]);
            
                        // Menentukan status berdasarkan nilai grade
                        char* status = (gradeCalon[i] >= 'A' && gradeCalon[i] <= 'D') ? "Lulus" : "Tidak Lulus";
                        fprintf(file, "Nilai           : %c\n", gradeCalon[i]);
                        fprintf(file, "Status          : %s\n", status);
            
                        fprintf(file, "------------------------------------------------------------\n");
                    }
                    fclose(file);
                    printf("Data telah disimpan ke dalam berkas 'calon_anggota.txt'\n");
                } else {
                    printf("Gagal membuka berkas untuk penyimpanan data.\n");
                    // Handle kesalahan sesuai kebutuhan, misalnya dengan mengembalikan kode kesalahan.
                }
                break;

            case 2:
                tampilkanHeaderTabel();
                for (int i = 0; i < jumlahCalon; i++) {
                    menampilkanData(namaCalon[i], nomorMahasiswaCalon[i], ipkCalon[i],
                                    komitmenCalon[i], semesterCalon[i], alamatEmailCalon[i],
                                    alasanCalon[i], gradeCalon[i]);
                }
                break;

            case 3:
                // Proses seleksi anggota BEM
                printf("Proses seleksi anggota BEM...\n");
                for (int i = 0; i < jumlahCalon; i++) {
                    gradeBEM[i] = hitungNilai(ipkCalon[i], komitmenCalon[i], semesterCalon[i]);
                    // Misalnya, anggota yang mendapat nilai A lolos seleksi
                    if (gradeBEM[i] >= 'A' || gradeBEM[i] <='D') {
                        // Menyimpan data anggota BEM resmi
                        strcpy(namaBEM[i], namaCalon[i]);
                        strcpy(nomorMahasiswaBEM[i], nomorMahasiswaCalon[i]);
                        ipkBEM[i] = ipkCalon[i];
                        komitmenBEM[i] = komitmenCalon[i];
                        semesterBEM[i] = semesterCalon[i];
                        strcpy(alamatEmailBEM[i], alamatEmailCalon[i]);
                        strcpy(alasanBergabungBEM[i], alasanCalon[i]);
                    }
                }
                printf("Seleksi anggota BEM selesai.\n");
                break;

            case 4:
                // Menampilkan data anggota BEM resmi yang lulus
                tampilkanHeaderTabel();
                for (int i = 0; i < MAX_ANGGOTA_BEM; i++) {
                    if (nomorMahasiswaBEM[i][0] != '\0' && (gradeBEM[i] >= 'A' && gradeBEM[i] <= 'D')) {
                        menampilkanDataBEM(namaBEM[i], nomorMahasiswaBEM[i], ipkBEM[i],
                                           komitmenBEM[i], semesterBEM[i], alamatEmailBEM[i],
                                           alasanBergabungBEM[i], gradeBEM[i]);
                    }
                }
                break;

            case 5:
                // Menyimpan data calon anggota ke dalam file 
                simpanDataKeFile(namaCalon[jumlahCalon-1], nomorMahasiswaCalon[jumlahCalon-1],
                                 ipkCalon[jumlahCalon-1], komitmenCalon[jumlahCalon-1],
                                 semesterCalon[jumlahCalon-1], alamatEmailCalon[jumlahCalon-1],
                                 alasanCalon[jumlahCalon-1], gradeCalon[jumlahCalon-1]);
                printf("Terima kasih, sampai jumpa pada pendaftaran selanjutnya\n");
                break;

            default:
                printf("Pilihan tidak valid : ");
        }
    } while (pilihan != 5);

    return 0;
}
