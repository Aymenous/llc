#include <stdio.h>

struct cell{
    int v;
    struct cell *suiv;
};

int longuerLLC(struct cell *llc) {
    struct cell *current = llc;

    int longueur = 0;
    while (current->suiv != NULL) {
        current = current->suiv;
        longueur++;
    }
    return longueur;
}

void ajouterFin(struct cell *llc){

    struct cell *newC;
    newC = malloc(sizeof(struct cell));
    printf("Valuer V: \n");
    scanf("%d" ,&newC->v);
    newC->suiv = NULL;

    struct cell *current = llc;
    while (current->suiv != NULL) {
        current = current->suiv;
    }

    current->suiv = newC;
}

void ajouterPosition(int position, struct cell *llc) {
    struct cell *newC;
    newC = malloc(sizeof(struct cell));
    printf("ajouter valuer, fi position %d : \n", position);
    scanf("%d" ,&newC->v);

    struct cell *current = llc;

    for(int i =0; i<position; i++) {
        current = current->suiv;
    }

    newC->suiv = current->suiv;
    current->suiv = newC;
}

void afficherLLC(struct cell *llc) {
    struct cell *current = llc;
    while (current->suiv != NULL) {
        current = current->suiv;
        printf("%d |", current->v);
    }
}

int main()
{
    struct cell *llc;
    llc = malloc(sizeof(struct cell));

    // Ajouter sons utilization des fonction.
    struct cell *c1;
    c1 = malloc(sizeof(struct cell));
    c1->v = 150;
    c1->suiv = NULL;
    llc->suiv = c1;
    printf("c1 v: %d\n", llc->suiv->v);

    // Ajouter multi-valeurs.
    int n = 5;
    for(int i = 0; i<n; i++) {
        ajouterFin(llc);
    }

    int x = longuerLLC(llc);
    printf("longueur %d", x);        

    printf("\n");
    afficherLLC(llc);
    printf("\n");

    ajouterPosition(3,llc);

    printf("\n");
    afficherLLC(llc);
    printf("\n");

    // supprimer debut de llc.
    llc = llc->suiv;
    afficherLLC(llc);
    printf("\n");

    return 0;
}
