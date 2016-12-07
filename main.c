#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define NAME_OPERATOR 50
#define NAME_PRODUCT 50

struct record
{
    char id_operator[4];
    char id_product[4];
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

  system("clear");

  printf("\n Zawartosc pliku database.txt\n");

  int symbols;
  int sign;
  int lines = 0;

  FILE *fp;
  if ((fp=fopen("database.txt", "r")) == NULL)
  {
      printf("I can't open file for read-only\n");
      exit(1);
  }

  printf("\n");

  while( symbols != EOF )
  {
      printf( "%c", symbols );
      symbols = getc(fp);
  }

  getchar();
  getchar();

  fclose(fp);
  system("clear");
  menu();
}

void read_data_by_line()
{
    FILE *fp;
    if ((fp=fopen("database.txt", "r"))==NULL)
    {
        printf("I can't open database file.\n");
        exit(1);
    }

    system("clear");

    int choises = 0;
    int lines = 0;

    while(choises != EOF)
    {
        choises = getc(fp);
        if (choises == '\n')
            lines = lines+1;
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
            czytnik == data.data.id_operatoratora;
            printf("%d", data.data.id_operatoratora );
            //choises = getc(fp);
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

        if (result != 0)
        {
            printf("%d    %s", i, caption);
            if (feof (fp))
            {
                printf ("\n %d End of file \n", i);
            }
        }
        else
            printf ("\n%d read error\n", i);
    }

    printf("\n Number of rows in database file --> %d \n", lines);

    fclose(fp);

    printf("%s", "\n [press any key...] \n");

    getchar();
    getchar();

    system("clear");
    menu();
}

void delete_enter(char *input)
{
  int size = sizeof(input);
  for (int i = 0; i < size; i++)
  {
    if (input[i] == '\n')
    {
      input[i] = '#';
    }
  }
}

int write_to_file()
{
    system("clear");

    FILE *fp;
    if ((fp=fopen("database.txt", "a+")) == NULL)
    {
        printf("I can't open database file.\n");
        exit(1);
    }

  char *name_operator = malloc(NAME_OPERATOR);
    if (name_operator == NULL)
    {
      printf ("No memory\n");
      return 1;
    }

  char *name_product = malloc(NAME_PRODUCT);
    if (name_product == NULL)
    {
      printf ("No memory\n");
      return 1;
    }

  printf("Insert id of operator:\n");
  fgets(data.id_operator, sizeof(data.id_operator), stdin);

  if ((strlen(data.id_operator)>0) && (data.id_operator[strlen(data.id_operator) - 1] == '\n'))
      data.id_operator[strlen(data.id_operator) - 1] = '#';

  printf("Insert name of operator:\n");
  fgets(name_operator, NAME_OPERATOR, stdin);

  if ((strlen(name_operator)>0) && (name_operator[strlen(name_operator) - 1] == '\n'))
      name_operator[strlen(name_operator) - 1] = '#';

  printf("Insert id of product:\n");
  fgets(data.id_product, sizeof(data.id_product), stdin);

  if ((strlen(data.id_product)>0) && (data.id_product[strlen(data.id_product) - 1] == '\n'))
      data.id_product[strlen(data.id_product) - 1] = '#';

  printf("Insert name of product:\n");
  fgets(name_product, NAME_PRODUCT, stdin);

  if ((strlen(name_product)>0) && (name_product[strlen(name_product) - 1] == '\n'))
      name_product[strlen(name_product) - 1] = '#';

  //  printf("\n");

  //  printf("%s", data.data.id_operator);
  //  printf("%s", name_operator);
  //  printf("%c", '#');
  //  printf("%s", data.data.data.id_product);
  //  printf("%s", name_product);
  //  printf("%c", '#');

  //  printf("\n\n");

    fprintf(fp, "%s", data.id_operator);
    fprintf(fp, "%s", name_operator);
    fprintf(fp, "%s", data.id_product);
    fprintf(fp, "%s", name_product);
    fprintf(fp, "%c", '\n');

    free(name_operator);
    free(name_product);
    fclose(fp);
    printf("\n   Inserted data was saved.\n\n   [Press any key...]");
    fgetc(stdin);
    system("clear");
    menu();
    return 0;
}

void end_program()
{
    system("clear");
    printf("\n Program was closed...\n");
    printf("\n   [press any key to exit...]\n");
}

int main()
{

    start();

    menu();

     int choise;
    //  atoi(choise);

    do
    {
      // choise = fgetc(stdin);
        // fgets(choise, sizeof(choise), stdin);
        // choise = fgetc(stdin);
        scanf("%d", &choise);

        switch (choise)
        {
          case 0:
            end_program();
            return 0;
          case 1:
            read_data_char_by_char();
            break;
            //return 0;
          case 2:
            read_data_by_line();
            break;
          //  return 0;
          case 3:
            write_to_file();
              break;
          //  return 0;
          default:
            printf("Access Denied");
            printf("\n [press any key...]\n");
            menu();
            break;
          //  return 0;
        }
    }

    while (choise != 0);

    return 0;
}
