#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista
{
    char nome[100];
    int punti;
    int partite_giocate;
    int goal_fatti;
    int goal_subiti;
    struct lista *next;
} Lista;

Lista *crea_nodo(char *nome, int punti, int partite_giocate, int goal_fatti, int goal_subiti)
{
    Lista *nuovo = (Lista *)malloc(sizeof(Lista));
    if (nuovo == NULL)
    {
        printf("Errore di allocazione memoria.\n");
        exit(1);
    }
    strcpy(nuovo->nome, nome);
    nuovo->punti = punti;
    nuovo->partite_giocate = partite_giocate;
    nuovo->goal_fatti = goal_fatti;
    nuovo->goal_subiti = goal_subiti;
    nuovo->next = NULL;
    return nuovo;
}

Lista *inserisciInTesta(Lista *head, char *nome, int punti, int partite_giocate, int goal_fatti, int goal_subiti)
{
    Lista *nuovo = creaNodo(nome, punti, partite_giocate, goal_fatti, goal_subiti);
    nuovo->next = head;
    return nuovo;
}

Lista *inserisciInCoda(Lista *head, char *nome, int punti, int partite_giocate, int goal_fatti, int goal_subiti)
{
    Lista *nuovo = creaNodo(nome, punti, partite_giocate, goal_fatti, goal_subiti);
    if (head == NULL)
        return nuovo;

    Lista *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = nuovo;
    return head;
}
