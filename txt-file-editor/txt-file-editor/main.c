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

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
