#include <stdio.h>
#include <stdlib.h>
#define SIZE 20


struct symbol{
int x;
int y;
char face;
};


char world[SIZE+1][SIZE+1];
struct symbol all_symbols[SIZE*SIZE];
int population = 0;


void create_borders();
void print_world();
void add_symbol_to_symbols(struct symbol);
void update_world();




int main()
{
    for(int i=2; i<10; i++){
        struct symbol a = {5+i, 5+i, 'o'};
        all_symbols[i] = a;
        population++;
    }

    update_world();
    print_world();

}

void create_borders(){
    for (int i=0; i<=SIZE; i++){
        world[0][i] = '#';
        world[SIZE][i] = '#';
        world[i][0] = '#';
        world[i][SIZE] = '#';
    }
}

\
void print_world(){
    system("cls");
    for(int i=0; i<=SIZE; i++){
        for(int j=0; j<=SIZE; j++) putchar(world[i][j]);
        printf("\n");
    }
}

void update_world(){
    for(int i=1; i<=SIZE; i++){
        for(int j=1; j<=SIZE; j++){
            world[i][j] = ' ';
        }
    }
    create_borders();
    for(int i=0; i<population; i++) world[all_symbols[i].x][all_symbols[i].y] = all_symbols[i].face;
}
