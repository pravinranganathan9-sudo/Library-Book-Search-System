#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[60];
    char author[60];
} Book;

typedef struct Node {
    Book book;
    struct Node *left, *right;
} Node;

Node *createNode(Book b) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\n"); exit(1); }
    n->book = b; n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, Book b) {
    if (root == NULL) return createNode(b);
    if (b.id < root->book.id) root->left = insert(root->left, b);
    else if (b.id > root->book.id) root->right = insert(root->right, b);
    else printf("Book ID %d already exists; duplicate ignored.\n", b.id);
    return root;
}

Node *search(Node *root, int id, int *comparisons) {
    while (root != NULL) {
        (*comparisons)++;
        if (id == root->book.id) return root;
        root = (id < root->book.id) ? root->left : root->right;
    }
    return NULL;
}

int height(Node *root) {
    if (!root) return 0;
    int lh = height(root->left), rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%-6d %-28s %s\n", root->book.id, root->book.name, root->book.author);
    inorder(root->right);
}

void freeTree(Node *root) {
    if (!root) return;
    freeTree(root->left); freeTree(root->right); free(root);
}

int main(void) {
    Book data[30] = {
        {101,"C Programming","Dennis Ritchie"},
        {105,"Data Structures","Mark Allen"},
        {110,"Operating Systems","Galvin"},
        {115,"Computer Networks","Tanenbaum"},
        {120,"DBMS","Navathe"},
        {125,"Java Programming","Herbert Schildt"},
        {130,"Python Basics","Mark Lutz"},
        {135,"Computer Architecture","Morris Mano"},
        {140,"Software Engineering","Pressman"},
        {145,"Algorithms","Cormen"},
        {150,"Web Technology","Jon Duckett"},
        {155,"Artificial Intelligence","Russell"},
        {160,"Machine Learning","Tom Mitchell"},
        {165,"Cyber Security","William Stallings"},
        {170,"Cloud Computing","Rajkumar Buyya"},
        {175,"Data Mining","Han"},
        {180,"Compiler Design","Aho"},
        {185,"Computer Graphics","Hearn"},
        {190,"Digital Electronics","Morris Mano"},
        {195,"Discrete Mathematics","Rosen"},
        {200,"Linux Basics","Brian Ward"},
        {205,"Database Systems","Elmasri"},
        {210,"C++ Programming","Bjarne Stroustrup"},
        {215,"Android Development","Reto Meier"},
        {220,"Networking Basics","Kurose"},
        {225,"Information Security","Whitman"},
        {230,"Numerical Methods","Chapra"},
        {235,"Theory of Computation","Sipser"},
        {240,"Data Analytics","Foster Provost"},
        {245,"Mobile Computing","Jochen Schiller"}
    };
    Node *root = NULL;
    for (int i=0; i<30; i++) root = insert(root, data[i]);

    int choice, id;
    do {
        printf("\n=== LIBRARY BOOK SEARCH: BST ===\n");
        printf("1 Search  2 Display (inorder)  3 Height  4 Insert  5 Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            int c=0; printf("Book ID: "); scanf("%d", &id);
            Node *found = search(root, id, &c);
            if (found) printf("FOUND: %d | %s | %s\n", found->book.id, found->book.name, found->book.author);
            else printf("NOT FOUND: %d\n", id);
            printf("Search key comparisons: %d\n", c);
        } else if (choice == 2) {
            printf("Book ID  Book Name                    Author\n"); inorder(root);
        } else if (choice == 3) {
            printf("BST height (measured in nodes): %d\n", height(root));
        } else if (choice == 4) {
            Book b; printf("New Book ID: "); scanf("%d", &b.id);
            printf("Book name: "); scanf(" %59[^\n]", b.name);
            printf("Author: "); scanf(" %59[^\n]", b.author);
            int before=height(root); root=insert(root,b);
            printf("Insertion processed. Height before=%d, after=%d\n", before, height(root));
        } else if (choice != 5) printf("Invalid choice.\n");
    } while (choice != 5);
    freeTree(root);
    return 0;
}
