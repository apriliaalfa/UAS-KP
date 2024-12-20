#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Fungsi untuk mengecek pengguna berdasarkan ID
void cekpengguna(char* ID) {
    char line[100], kategorinamafile[20];
    char kategoripengguna[10];
    char cocok[50] = "Tidak Ditemukan";
    char IDpengguna[20], nama[50];
    FILE *file;

    // Deteksi tipe ID (Dosen atau Mahasiswa)
    if (strncmp(ID, "00", 2) == 0) {
        strcpy(kategorinamafile, "dosen.txt");
        strcpy(kategoripengguna, "Dosen");
    } else if (ID[0] == 'L') {
        strcpy(kategorinamafile, "mahasiswa.txt");
        strcpy(kategoripengguna, "Mahasiswa");
    } else {
        printf("Format ID tidak valid.\n");
        return;
    }

    //Buka file sesuai tipe
    file = fopen(kategorinamafile, "r");
    if (file == NULL) {
        printf("File %s tidak ditemukan.\n", kategorinamafile);
        return;
    }

    //Cari ID dalam file
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^|]| %[^\n]", IDpengguna, nama); // Pisahkan ID dan Nama
        if (strcmp(IDpengguna, ID) == 0) {
            strcpy(cocok, nama);
            break;
        }
    }
    fclose(file);

    // Tampilkan hasil
    if (strcmp(cocok, "Tidak Ditemukan") == 0) {
        printf("ID tidak ditemukan dalam data %s.\n", kategoripengguna);
    } else {
        printf("Kategori: %s\n", kategoripengguna);
        printf("Nama: %s\n", cocok);
        printf("ID: %s\n", ID);
    }
}

int main() {
    char ID[30];

    printf("Masukkan ID (NIDN untuk Dosen || NIM untuk Mahasiswa): ");
    scanf("%s", ID);

    cekpengguna(ID);

    return 0;
}
///////
