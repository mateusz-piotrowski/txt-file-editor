//
//  main.c
//  txt-file-editor
//
//  Created by Mateusz Piotrowski on 11/11/18.
//  Copyright © 2018 Mateusz Piotrowski. All rights reserved.
//

#include <stdio.h>

struct record
{
    int id_operator;
    char name_operator;
    int id_product;
    char name_product;
};

struct record data;


void start() {
    printf("\n Program starting\n");
    printf("\n\n [press any key to continue...]\n");
    
    getchar();
    
    system("clear");
}

void menu() {
    system("clear");
    
    printf("Menu:\n");
    printf(" 1. Display database from file. [char by char]\n");
    printf(" 2. Display database from file [line number]\n");
    printf(" 3. Write data to database\n");
    printf(" 0. Exit program\n");
    printf(" \n Your choise:  ");
}

void read_data_char_by_char()
{
    FILE *fp;
    if ((fp=fopen("database.txt", "r"))==NULL) {
        printf("I can't open database file.\n");
        exit(1);
    }
    
    int symbols;
    
    system("clear");
    
    printf("\n Database file:\n");
    
    symbols = getc(fp);
    
    while(symbols != EOF) {
        printf( "%c", symbols );
        symbols = getc(fp);
    }
    
    fclose(fp);
    
    printf("%s", "\n [ press any key...]\n");
    
    getchar();
}

void read_data_by_line(void)
{
    FILE *fp;
    if ((fp=fopen("database.txt", "r"))==NULL) {
        printf("I can't open database file.\n");
        exit(1);
    }
    
    system("clear");
    
    int symbols = 0;
    int lines = 0;
    
    while(symbols != EOF) {
        symbols = getc(fp);
        
        if (symbols == '\n') {
            lines = lines+1;
        }
    }
    
    printf("\n Database file: \n");
    printf("\nLP   Data: \n\n");
    
    int i = 1;
    const int max_n = 300;
    //const int lines = 5;
    char caption[max_n];
    char *result;
    /*
     rewind(fp);
     czytnik = getc(fp);
     while ( czytnik != '#' )
     {
     czytnik == id_operatoratora;
     printf("%d", id_operatoratora );
     //symbols = getc(fp);
     }
     */
    int tmp = 0;
    tmp = lines;
    
    rewind(fp);
    
    for (i = 1; i <= tmp; i++)
    {
        result = fgets(caption, max_n, fp);
        //fgets(caption, max_n, fp);
        lines++;
        
        if (result != 0) {
            printf("%d    %s", i, caption);
            if (feof (fp)) {
                printf ("\n %d End of file \n", i);
            }
        }
        else {
            printf ("\n%d read error\n", i);
        }
    }
    
    printf("\n Number of rows in database file --> %d \n", lines);
    
    fclose(fp);
    
    printf("%s", "\n [press any key...] \n");
    
    getchar();
    getchar();
    
    system("clear");
    menu();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
