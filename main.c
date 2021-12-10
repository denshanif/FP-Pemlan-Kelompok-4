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
    int i, menu;1

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

void urutNamaAscen()
{
    int i, j, minimum;

    // Looping selection sort
    for (i = 0; i < (z - 1); i++)
    {
        minimum = i;

        // Looping pengurutan nilai
        for (j = i + 1; j < z; j++)
        {
            if (strcmp(data[j].nama, data[minimum].nama) < 0)
            {
                minimum = j;
            }
            if (minimum != i)
            {
                tukar = data[minimum];
                data[minimum] = data[i];
                data[i] = tukar;
            }
        }
    }

    for (i = 0; i < z; i++)
    {
        printf("Nama Barang : %s\n\n", data[i].nama);

        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Harga Barang : %d\n\n", data[i].harga);
    }
}

void urutNamaDescen()
{
    int i, j, minimum;

    // Looping selection sort
    for (i = 0; i < (z - 1); i++)
    {
        minimum = i;

        // Looping pengurutan nilai
        for (j = i + 1; j < z; j++)
        {
            if (strcmp(data[j].nama, data[minimum].nama) > 0)
            {
                minimum = j;
            }
            if (minimum != i)
            {
                tukar = data[minimum];
                data[minimum] = data[i];
                data[i] = tukar;
            }
        }
    }

    for (i = 0; i < z; i++)
    {
        printf("Nama Barang : %s\n\n", data[i].nama);

        printf("Kode Barang : %d\n", data[i].kode);
        printf("Kategori Barang : %s\n", data[i].kategori);
        printf("Harga Barang : %d\n\n", data[i].harga);
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

    printf("1. TAMPILKAN NAMA BARANG URUT ASCENDING\n");
    printf("2. TAMPILKAN NAMA BARANG URUT DESCENDING\n");
    printf("3. KEMBALI KE MENU UTAMA\n");

    printf("Masukkan pilihan anda: ");
    scanf("%d", &menu);

    printf("\n");

    // Switch case pemilihan menu
    switch (menu)
    {
    case 1:
        urutNamaAscen();
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    case 2:
        urutNamaDescen();
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
    // printf("2. TAMPILKAN DATA BARANG URUT SESUAI HARGA BARANG\n");
    printf("2. KEMBALI KE MENU UTAMA\n");

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
    /*
                case 2:
                    tampilHarga();
                    printf("\n");
                    printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
                    getch();
                    goto up;
                */
    case 2:
        break;
    default:
        printf("Maaf, input yang anda masukkan salah/invalid");
        printf("\n");
        printf("Tekan enter untuk kembali ke menu sebelumnya.\n");
        getch();
        goto up;
    }
}