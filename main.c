#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data_barang
{
    char nama[25], kategori[25];
    int harga, kode;
} tukar;

int z = 0;

typedef struct data_barang barang;

barang data['0'];

FILE *file_data;

void tampilBarang();

int main()
{
    int i, menu;

    char kembali;

    file_data = fopen("Data.txt", "r");

    while (!feof(file_data))
    {
        fscanf(file_data, "\nKode : %d\nKategori : %s\nNama Barang : %s\nHarga : %d", &data[z].kode, &data[z].kategori, &data[z].nama, &data[z].harga);
        z++;
    }

    do
    {
        system("cls");
        printf("===================================================\n");
        printf("========== PROGRAM MANAJEMEN SUPERMARKET ==========\n");
        printf("===================================================\n");

        printf("\n=== SILAHKAN PILIH MENU YANG DI BAWAH INI ===\n");
        printf("1. MENAMPILKAN SEMUA DATA BARANG\n");
        printf("2. KELUAR PROGRAM\n");

        printf("Masukkan pilihan anda: ");
        scanf("%d", &menu);

        printf("\n");

        // Switch case untuk masing-masing menu
        switch (menu)
        {
        case 1:
            tampilBarang();
            printf("\n");
            break;
        case 2:
            exit(0);
        default:
            printf("Maaf, input yang anda masukkan salah/invalid");
            printf("\n");
            break;
        }
        printf("\n");

        // Pilihan kembali ke menu utama
        printf("Ingin kembali ke menu utama? (Y/T): ");
        scanf("%c", &kembali);
        scanf("%c", &kembali);
    } while (kembali == 'y' || kembali == 'Y');

    fclose(file_data);

    return 0;
}

void listNama()
{
    int i;
    for (i = 0; i < z; i++)
    {
        printf("Nama Barang : %s\n\n", data[i].nama);

        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Harga Barang : %d\n\n", data[i].harga);
    }
}

void urutNamaAscen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (strcmp(data[j].nama, data[j-1].nama) < 0) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void urutNamaDescen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (strcmp(data[j].nama, data[j-1].nama) > 0) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void tampilNama()
{
    int menu;

// Menu
up:
    system("cls");
    printf("================= Menampilkan Data Barang Menurut Nama Barang ===================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

    printf("1. TAMPILKAN NAMA BARANG URUT ASCENDING (A-Z).\n");
    printf("2. TAMPILKAN NAMA BARANG URUT DESCENDING (Z-A).\n");
    printf("3. KEMBALI KE MENU UTAMA\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        urutNamaAscen();
        listNama();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutNamaDescen();
        listNama();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}

void listHarga()
{
    int i;
    for (i = 0; i < z; i++)
    {
        printf("Harga Barang : %d\n\n", data[i].harga);

        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Nama Barang : %s\n\n", data[i].nama);
    }
}

void urutHargaAscen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (data[j].harga < data[j-1].harga) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void urutHargaDescen()
{
    int i, j;

	// Looping bubble sort
	for (i = z - 1; i > 0; i--) {
		for (j = z - 1; j >= z - i; j--) {
			if (data[j].harga > data[j-1].harga) {
				tukar = data[j];
				data[j] = data[j-1];
				data[j-1] = tukar;
			}
		}
	}
}

void tampilHarga()
{
    int menu;

// Menu
up:
    system("cls");
    printf("================ Menampilkan Data Barang Menurut Harga Barang ===================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

    printf("1. TAMPILKAN HARGA BARANG URUT ASCENDING (Murah - Mahal)\n");
    printf("2. TAMPILKAN HARGA BARANG URUT DESCENDING (Mahal - Murah)\n");
    printf("3. KEMBALI KE MENU UTAMA\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        urutHargaAscen();
        listHarga();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutHargaDescen();
        listHarga();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}

void tampilBarang()
{
    int menu;

// Menu
up:
    system("cls");
    printf("=========================== Menampilkan Data Barang =============================\n\n");
    printf("\n======================= SILAHKAN PILIH OPSI DI BAWAH INI ======================\n");

    printf("1. TAMPILKAN DATA BARANG URUT SESUAI NAMA BARANG\n");
    printf("2. TAMPILKAN DATA BARANG URUT SESUAI HARGA BARANG\n");
    printf("3. KEMBALI KE MENU UTAMA\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        tampilNama();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        tampilHarga();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 3:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid.");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}
