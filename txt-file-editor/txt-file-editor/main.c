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

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}