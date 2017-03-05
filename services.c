/// \file services.c
/// \copydoc services

/// \addtogroup services
/// \{

#include "services.h"


/// Saisir une ligne de texte dans une chaîne s (tableau de MAX_LIGNE caractères).
/// Equivalent à gets mais "mange" le retour ligne et vérifie les débordements.
/// Renvoie 0 (Pas de problème) si elle réussit à lire au moins un retour ligne, et 1 sinon.
/// Dans le cas d'une saisie de ligne vide (retour ligne immédiat)
/// retourne 0 (Pas de problème) et la chaîne est vide.
int lire_ligne(char s[MAX_LIGNE])
{
    char *ret;

    // Lecture sur l'entrée standard
    ret = fgets(s, MAX_LIGNE, stdin);

    // fgets laisse le retour ligne '\n' dans la chaîne : on l'enlève
    if (ret!=NULL)
        s[strlen(s)-1]='\0';

    return ret!=NULL ? 0 : 1;
}


//===========================================================
/// \name Bilan allocations/libérations
/// \{

/// Total des appels malloc
int alloc_nb_malloc = 0;

/// Total des appels free
int alloc_nb_free = 0;

/// Total des appels calloc
int alloc_nb_calloc = 0;

/// Total des appels realloc
int alloc_nb_realloc = 0;

/// Total des appels strdup
int alloc_nb_strdup = 0;


/// Affichage bilan allocations/libérations.
void alloc_bilan()
{
    int totalloc = alloc_nb_malloc + alloc_nb_calloc + alloc_nb_realloc + alloc_nb_strdup;
    int totfree = alloc_nb_free + alloc_nb_realloc;
    printf("\n");
    printf("Allocations : %d ( %d allocations, %d liberations)\n",
           totalloc-totfree, totalloc, totfree);
    printf(" allocations : %d malloc, %d calloc, %d strdup, %d realloc\n",
           alloc_nb_malloc, alloc_nb_calloc, alloc_nb_strdup, alloc_nb_realloc);
    printf(" liberations : %d free, %d realloc\n",
           alloc_nb_free, alloc_nb_realloc);
}

// On neutralise les alias sur les fonctions d'allocation pour utiliser les vraies
#undef malloc
#undef free
#undef calloc
#undef realloc
#undef strdup


//===========================================================
/// \name Wrappers pour les fonctions d'allocation/libération
/// \{


void *malloc_check(size_t size)
{
    void *mem;
    mem = malloc(size);
    assert( mem!=NULL );
    alloc_nb_malloc++;
    return mem;
}

void free_check(void *ptr)
{
    assert(ptr!=NULL);
    free(ptr);
    alloc_nb_free++;
}

void *calloc_check(size_t nmemb, size_t size)
{
    void *mem;
    mem = calloc(nmemb, size);
    assert( mem!=NULL );
    alloc_nb_calloc++;
    return mem;
}

void *realloc_check(void *ptr, size_t size)
{
    ptr = realloc(ptr, size);
    assert( ptr!=NULL );
    alloc_nb_realloc++;
    return ptr;
}

char *strdup_check(const char *s)
{
    char *dup;
    assert( s!=NULL );
    dup = strdup(s);
    assert( dup!=NULL );
    alloc_nb_strdup++;
    return dup;
}

// Ne pas mettre de code ci après (alias allocations neutralisés)

/// \}
/// \}
