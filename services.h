/// \file services.h
/// \copydoc services

/// \addtogroup services
/// Module de services ! Gestion mémoire et fonction portable de saisie de ligne.
/// En mettant partout \code #include "services.h" \endcode on bénéficie automatiquement
/// d'une "encapsulation" des allocations et libérations mémoires (malloc, free ...) qui permet
/// \li d'avoir une "protection" sur les échecs d'allocation
/// ( concrètement une terminaison immédiate du programme, ce n'est \b pas la solution ultime
/// mais évite un plantage ultérieur... )
/// \li de comptabiliser précisément le nombre d'allocations et de libérations
/// pour avoir un bilan complet avec alloc_bilan() et vérifier l'absence de fuite mémoire.
///
/// La fonction lire_ligne() est une alternative portable ( Windows / Unix )
/// à la place de fflush(stdin) + gets pour les saisies de lignes successives.
/// fflush(stdin) est spécifique à Windows, ne fait pas partie de la norme du C,
/// et ne fonctionne pas sur les systèmes Unix, pour de bonnes raisons
/// (stdin peut être redirigé depuis un fichier...)
///
/// \{


#ifndef SERVICES_H_INCLUDED
#define SERVICES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//===========================================================
/// \name Services de saisie.
/// A utiliser pour des saisies successives de lignes de texte en console.
/// \code
/// char saisie[MAX_LIGNE];
/// ...
/// while (...)
/// {
///     lire_ligne(saisie);
///     ... analyser la chaîne saisie
/// \endcode
/// \{

/// Constante à utiliser pour déclarer un tableau de char destiné aux saisies
#define MAX_LIGNE 250

/// Saisir une ligne de texte dans une chaîne s (tableau de MAX_LIGNE caractères).
int lire_ligne(char s[MAX_LIGNE]);

/// \}



//===========================================================
/// Affichage bilan allocations/libérations.
void alloc_bilan();

void *malloc_check(size_t size);
void free_check(void *ptr);
void *calloc_check(size_t nmemb, size_t size);
void *realloc_check(void *ptr, size_t size);
char *strdup_check(const char *s);


//===========================================================
/// \name Déroutage des fonctions mémoire standards vers les fonctions wrappers du module.
/// \{

#define malloc malloc_check
#define free free_check
#define calloc calloc_check
#define realloc realloc_check
#define strdup strdup_check

/// \}

#endif // SERVICES_H_INCLUDED

/// \}
