#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int shmCreate(const char* name, int size)
{
    int fd;
    fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0666);
    if(fd != -1)
    {
        //if(ftruncate(fd, len)!=-1)
        if(ftruncate(fd, size)!=-1)
        {
            printf("Utworzono obszar pamieci dzielonej\n");
            return fd;
        }
        else
        {
            printf("Blad ustalania dlugosci obiektu pamieci dzielonej\n");
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("Blad tworzenia obszaru pamieci dzielonej\n");
        perror("Error");
        exit(EXIT_FAILURE);
    }
}
//Funkcja tworzy pamięć dzieloną o nazwie name i rozmiarze size.
//Funkcja zwraca deskryptor obiektu pamięci dzielonej.
int shmOpen(const char* name)
{
    int fd; 
    fd = shm_open(name, O_RDWR, 0666);
    if(fd != -1)
    {
        printf("Pamiec dzielona otwarta\n");
        return fd;
    }
    else
    {
        printf("Blad otwierania obiektu pamieci dzielonej\n");
        perror("Error");
        exit(EXIT_FAILURE);
    }
}
//Funkcja otwiera obiekt pamięci dzielonej i zwraca jego deskryptor.
void shmRm(const char* name)
{
    int err = shm_unlink(name);
    if(err != -1)
    {
        printf("Usunieto obiekt pamieci dzielonej\n");
    }
    else
    {
        printf("Blad usuwania obiektu pamieci dzielonej\n");
        perror("Error");
        exit(EXIT_FAILURE);
    }
}
//Usuwa obiekt pamięci dzielonej o nazwie name.
char* shmMap(int fd, int size)
{
    char* ptr = (char *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    return ptr;
}
//Odwzorowuje obiekt pamięci dzielonej o deskryptorze fd i rozmiarze size w przestrzeń adresową procesu. 
//Funkcja zwraca adres początku odwzorowanego obszaru pamięci dzielonej.
void shmClose(void *ptr, int fd, int size)
{
    munmap(ptr, size);
    close(fd);
}
//Usuwa odwzorowanie obiektu pamięci dzielonej i zamyka powiązany z nim deskryptor.
int shmSize(int fd)
{
    struct stat st;
    fstat(fd, &st);
    return st.st_size;
}
//Zwraca rozmiar pamięci dzielonej określonej deskryptorem fd. 
//Proszę użyć funkcji systemowej fstat.
void shmInfo(int fd)
{
    struct stat st;
    fstat(fd, &st);
    printf("Access rights: %ui\n", st.st_mode);
    printf("Size: %li\n", st.st_size);
    printf("Owner: %ui", st.st_uid);
}
//Wypisuje informacje o pamięci dzielonej: prawa dostępu, rozmiar, właściciel, etc.
