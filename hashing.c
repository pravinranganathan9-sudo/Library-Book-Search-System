#include <stdio.h>
#include <string.h>

#define SIZE 40
typedef struct {
    int id;
    char name[60], author[60];
    int occupied;
} BookSlot;

BookSlot table[SIZE];
int totalCollisions=0;

void initialize(void) {
    for(int i=0;i<SIZE;i++) table[i].occupied=0;
}
int hashFunction(int id) { return id % SIZE; }

/* Counts one collision each time insertion encounters an occupied slot. */
int insert(BookSlot b) {
    int index=hashFunction(b.id), start=index;
    do {
        if(!table[index].occupied) {
            table[index]=b; table[index].occupied=1;
            return 1;
        }
        if(table[index].id==b.id) {
            printf("Duplicate Book ID %d; insertion rejected.\n",b.id);
            return 0;
        }
        totalCollisions++;
        index=(index+1)%SIZE;
    } while(index!=start);
    printf("Hash table is full.\n"); return 0;
}

void searchBook(int id) {
    int index=hashFunction(id), probes=0, start=index;
    do {
        probes++;
        if(!table[index].occupied) {
            printf("NOT FOUND: %d\nSearch probes: %d\n",id,probes);
            return;
        }
        if(table[index].id==id) {
            printf("FOUND: %d | %s | %s\nSearch probes: %d\n",
                   table[index].id,table[index].name,table[index].author,probes);
            return;
        }
        index=(index+1)%SIZE;
    } while(index!=start);
    printf("NOT FOUND: %d\nSearch probes: %d\n",id,probes);
}
void display(void) {
    printf("Index  BookID  Book Name                    Author\n");
    for(int i=0;i<SIZE;i++) if(table[i].occupied)
        printf("%-6d %-7d %-28s %s\n",i,table[i].id,table[i].name,table[i].author);
}

int main(void) {
    BookSlot data[30]={
        {101,"C Programming","Dennis Ritchie",1},{105,"Data Structures","Mark Allen",1},
        {110,"Operating Systems","Galvin",1},{115,"Computer Networks","Tanenbaum",1},
        {120,"DBMS","Navathe",1},{125,"Java Programming","Herbert Schildt",1},
        {130,"Python Basics","Mark Lutz",1},{135,"Computer Architecture","Morris Mano",1},
        {140,"Software Engineering","Pressman",1},{145,"Algorithms","Cormen",1},
        {150,"Web Technology","Jon Duckett",1},{155,"Artificial Intelligence","Russell",1},
        {160,"Machine Learning","Tom Mitchell",1},{165,"Cyber Security","William Stallings",1},
        {170,"Cloud Computing","Rajkumar Buyya",1},{175,"Data Mining","Han",1},
        {180,"Compiler Design","Aho",1},{185,"Computer Graphics","Hearn",1},
        {190,"Digital Electronics","Morris Mano",1},{195,"Discrete Mathematics","Rosen",1},
        {200,"Linux Basics","Brian Ward",1},{205,"Database Systems","Elmasri",1},
        {210,"C++ Programming","Bjarne Stroustrup",1},{215,"Android Development","Reto Meier",1},
        {220,"Networking Basics","Kurose",1},{225,"Information Security","Whitman",1},
        {230,"Numerical Methods","Chapra",1},{235,"Theory of Computation","Sipser",1},
        {240,"Data Analytics","Foster Provost",1},{245,"Mobile Computing","Jochen Schiller",1}
    };
    initialize();
    for(int i=0;i<30;i++) insert(data[i]);
    printf("Initial dataset loaded: 30 books\n");
    printf("Initial insertion collisions: %d\n",totalCollisions);
    int choice,id;
    do {
        printf("\n=== LIBRARY BOOK SEARCH: HASHING ===\n");
        printf("1 Search  2 Display  3 Show collisions  4 Insert  5 Exit\nChoice: ");
        if(scanf("%d",&choice)!=1) break;
        if(choice==1) { printf("Book ID: "); scanf("%d",&id); searchBook(id); }
        else if(choice==2) display();
        else if(choice==3) printf("Insertion collisions so far: %d\n",totalCollisions);
        else if(choice==4) {
            BookSlot b; b.occupied=1;
            printf("New Book ID: "); scanf("%d",&b.id);
            printf("Book name: "); scanf(" %59[^\n]",b.name);
            printf("Author: "); scanf(" %59[^\n]",b.author);
            if(insert(b)) printf("Book inserted successfully. Total collisions now: %d\n",totalCollisions);
        } else if(choice!=5) printf("Invalid choice.\n");
    } while(choice!=5);
    return 0;
}
