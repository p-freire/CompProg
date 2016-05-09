// Gramática original:
// E -> E '+' E | E '-' E | E '*' E | E '/' E | E '%' E | E '^' E | (' E ')' | I
// I -> [0..9] | [0..9] I
//
// Removendo ambiguidade:
// E -> E '+' T | E '-' T | T
// T -> T '*' F | T '/' F | T '%' F | F
// F -> F '^' G | G
// G -> '(' E ')' | I
// I -> [a..zA..Z0..9] | [a..zA..Z0..9] I
//
// Removendo recursão à esquerda:
// E  -> T | T E1
// E1 -> '+' T | '-' T | '+' T E1 | '-' T E1
// T  -> F | F T1
// T1 -> '*' F | '/' F | '%' F | '*' F T1 | '/' F T1 | '%' F T1
// F -> G | G F1
// F1 -> '^' G | '^' G F1
// G  -> '(' E ')' | I
// I -> [a..zA..Z0..9] | [a..zA..Z0..9] I

#include <stdio.h>
#include <stdlib.h>

// Conforme a definição recursiva de árvore
struct tree
{
    char info[100]; // Número ou operador
    struct tree *left, *right; // Filhos
};

// Remove espaços em branco de uma string
void trim(char *str);

// Funções de árvore
void new_tree(struct tree **t);
void del_tree(struct tree *t);
void in_order(struct tree *t);
void pre_order(struct tree *t);
void post_order(struct tree *t);

// Regras sintáticas
// Obs: o argumento de E1 e T1 indica o filho a ser colocado à esquerda do novo
// nó criado (porque a árvore é construída de baixo para cima e tal)
struct tree* E();
struct tree* E1(struct tree *l);
struct tree* T();
struct tree* T1(struct tree *l);
struct tree* F();
struct tree* F1(struct tree *l);
struct tree* G();
struct tree* I();

int i;             // Posição atual de leitura
char buffer[1024]; // Buffer com a string de entrada

int main(int argc, char const *argv[])
{
    struct tree *t = NULL;
    int n;
    scanf("%d", &n);

    while (n--) {
        //gets(buffer);
        scanf("%s", buffer);
        i = 0;
        trim(buffer); // Remove espaços em branco
        t = E(); // Monta a árvore sintática

//        printf("Pre-fixa: ");
//        pre_order(t);
//        putchar('\n');

//        printf("Pos-fixa: ");
        post_order(t);
        putchar('\n');

        del_tree(t);
    }

    return 0;
}

void trim(char *str)
{
    char *p1 = str;
    char *p2 = str;

    while(*p2 != '\0') {
        *p1 = *p2++;
        if(*p1 != ' ')
            p1++;
    }
    *p1 = '\0';
}

void new_tree(struct tree **t)
{
    (*t) = (struct tree*) malloc(sizeof(struct tree));
    (*t)->left = NULL;
    (*t)->right = NULL;
}

void del_tree(struct tree *t)
{
    if (t != NULL) {
        del_tree(t->left);
        del_tree(t->right);
        free(t);
    }
}

void in_order(struct tree *t)
{
    if (t != NULL) {
        in_order(t->left);
        printf("%s ", t->info);
        in_order(t->right);
    }
}

void pre_order(struct tree *t)
{
    if (t != NULL) {
        printf("%s", t->info);
        pre_order(t->left);
        pre_order(t->right);
    }
}

void post_order(struct tree *t)
{
    if (t != NULL) {
        post_order(t->left);
        post_order(t->right);
        printf("%s", t->info);
    }
}

// E  -> T | T E1
struct tree* E()
{
    struct tree *t = NULL, // tree
                *l = NULL; // left child
    new_tree(&t);

    t = T(); // Primeiro operando
    if (buffer[i] == '+' || buffer[i] == '-') {
        l = t;
        t = E1(l); // Restante da expressão
    }
    return t;
}

// E1 -> '+' T | '-' T | '+' T E1 | '-' T E1
struct tree* E1(struct tree *l)
{
    struct tree *t = NULL, // tree
                *p = NULL, // parent
                *r = NULL; // right child

    if (buffer[i] == '+' || buffer[i] == '-') {
        new_tree(&t);
        t->info[0] = buffer[i];
        t->info[1] = '\0';
        ++i; // Avança no buffer
        t->left = l;
        r = T();
        t->right = r;
        p = E1(t);

        // Perceba que a árvore vai sendo construída de baixo para cima e da
        // esquerda para a direita
    }
    if (p != NULL)
        return p;
    if (t != NULL)
        return t;
    return l;
}

// T  -> F | F T1
struct tree* T()
{
    struct tree *t = NULL,
                *l = NULL;
    new_tree(&t);

    t = F();
    while (buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {
        l = t;
        t = T1(l);
    }
    return t;
}

// T1 -> '*' F | '/' F | '%' F | '*' F T1 | '/' F T1 | '%' F T1
struct tree* T1(struct tree *l)
{
    struct tree *t = NULL,
                *p = NULL,
                *r = NULL;

    if (buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '%') {
        new_tree(&t);
        t->info[0] = buffer[i];
        t->info[1] = '\0';
        ++i; // Avança no buffer
        t->left = l;
        r = F();
        t->right = r;
        p = T1(t);

        // Perceba que a árvore vai sendo construída de baixo para cima e da
        // esquerda para a direita
    }
    if (p != NULL)
        return p;
    if (t != NULL)
        return t;
    return l;
}

// F -> G | G F1
struct tree* F()
{
    struct tree *t = NULL,
                *l = NULL;
    new_tree(&t);

    t = G();
    while (buffer[i] == '^') {
        l = t;
        t = F1(l);
    }
    return t;
}

// F1 -> '^' G | '^' G F1
struct tree* F1(struct tree *l)
{
    struct tree *t = NULL,
                *p = NULL,
                *r = NULL;

    if (buffer[i] == '^') {
        new_tree(&t);
        t->info[0] = buffer[i];
        t->info[1] = '\0';
        ++i; // Avança no buffer
        t->left = l;
        r = G();
        t->right = r;
        p = F1(t);

        // Perceba que a árvore vai sendo construída de baixo para cima e da
        // esquerda para a direita
    }
    if (p != NULL)
        return p;
    if (t != NULL)
        return t;
    return l;
}


// G  -> '(' E ')' | I
struct tree* G()
{
    struct tree *t = NULL;
    new_tree(&t);

    if (buffer[i] == '(') {
        ++i; // Avança no buffer
        t = E();
        ++i; // Avança de novo por causa do fechamento de parênteses
    }
    else
        t = I();
    return t;
}

// I -> [0..9] | [0..9] I
struct tree* I()
{
    struct tree *t = NULL;
    new_tree(&t);

    int j = 0;
    while ((buffer[i] >= '0' && buffer[i] <= '9') || (buffer[i] >= 'a' && buffer[i] <='z') || (buffer[i] >= 'A' && buffer[i] <= 'Z')) {
        t->info[j] = buffer[i];
        ++i;
        ++j;
    }
    t->info[j] = '\0';
    return t;
}
