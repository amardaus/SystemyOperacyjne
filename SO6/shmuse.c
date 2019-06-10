/*
 * ./shmuse.x c size - Tworzy segment pamięci dzielonej o rozmiarze size bajtów.
./shmuse.x d size - Usuwa segment pamięci dzielonej
./shmuse.x r - Wypisuje zawartość pamięci dzielonej na standardowe wyjście.
./shmuse.x w < input.txt - Kopiuje zawartość standardowego wejścia do pamięci dzielonej. Sprawdzić rozmiar segmentu.
./shmuse.x i - Wypisuje informacje o pamięci dzielonej.
./shmuse.x - Wypisuje informacje o użyciu tego programu.*/

#include "shmem.h"

const char* name = "/cokolwiek";

int main(int argc, char* argv[])
{
    if(argc == 0)
    {
        printf("c [size] - tworzy segment pamieci dzielonej o rozmiarze size\n");
        printf("d - usuwa segment pamieci dzielonej\n");
        printf("w < input.txt - kopiuje zawartość standardowego wejścia do pamięci dzielonej. Sprawdzić rozmiar segmentu\n");
        printf("i - wypisuje informacje o pamięci dzielonej.\n");
        return 0;
    }
    int l = argv[1];
    if(l == 'c' && argc == 2)
    {
        int s = argv[2];
        shmCreate(name, s);
        return 0;
    }
    if(l == 'd')
    {
        shmRm(name);
        return 0;
    }
    if(l == 'w')
    {
        //tu dopisac ten znaczek i input <
        int addr = shmOpen(name);
        strcpy(addr, "text");
        return 0;
    }
    if(l == 'i')
    {
        shmInfo(name);
        return 0;
    }

}
