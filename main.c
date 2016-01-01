#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio_ext.h>

struct record
{
    int id_operator;
    char name_operator;
    int id_product;
    char name_product;
};

struct record data;

void start()
{
    printf("\n Program starting\n");
    printf("\n\n [press any key to continue...]\n");
    getchar();
    system("clear");
}

void menu()
{
    system("clear");

    printf("       Menu:\n");
    printf(" 1. Display database from file. [char by char]\n");
    printf(" 2. Display database from file [line number]\n");
    printf(" 3. Write data to database\n");
    printf(" 0. Exit program\n");
    printf(" \n Your choise:  ");
}

void read_data_char_by_char()
{
    FILE *fp;
    if ((fp=fopen("database.txt", "r"))==NULL)
    {
        printf("I can't open database file.\n");
        exit(1);
    }

    int symbols;

    system("clear");

    printf("\n Database file:\n");

    symbols = getc(fp);

    while(symbols != EOF)
    {
        printf( "%c", symbols );
        symbols = getc(fp);
    }

    fclose(fp);

    printf("%s", "\n [ press any key...]\n");

    getchar();
}

int main(void)
{
    printf("Hello World\n");
    return 0;
}
