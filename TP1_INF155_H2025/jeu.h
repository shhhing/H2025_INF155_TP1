
#ifndef JEU_H
#define JEU_H

#include "terrain.h"
#include <stdbool.h>

#define JOUEUR_CARBURANT_INITIAL    2
#define COUT_DEPLACEMENT_VOISIN     1
#define BONUS_CARBURANT             5
#define TOTAL_CARBURANT_NIVEAU_1    100

//  *****************************
//  Definitions des types publics
//  *****************************

typedef enum {
    DIRECTION_ERRONEE = -1,
    DIRECTION_DROITE,
    DIRECTION_BAS,
    DIRECTION_HAUT,
    DIRECTION_GAUCHE
} t_direction;
#define NB_DIRECTIONS   4

typedef enum {
    JEU_ETAT_ECHEC = 1,
    JEU_ETAT_VICTOIRE,
    JEU_ETAT_EN_COURS
} t_jeu_etat;

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

/**
 * @brief Met à jour la quantite de carburant du joueur apres un deplacement.
 *        Annule la quantite de carburant sur la case du joueur.
 * @name jeu_maj_carburant_joueur
 * @param joueur_ligne la ligne à laquelle se trouve maintenant le joueur
 * @param joueur_colonne la colonne à laquelle se trouve maintenant le joueur
 * @param joueur_carburant l'adresse ou placer la nouvelle quantite de carburant du joueur apres deplacement
 * @param terrain Le terrain sur lequel le joueur s'est déplacé
 */
void jeu_maj_carburant_joueur(int joueur_ligne, int joueur_colonne, int* joueur_carburant, t_terrain terrain);

/**
 * @brief Déplacé le joueur dans une direction donnee.
 * @name jeu_deplacer_joueur
 * @param joueur_ligne l'adresse de la ligne à laquelle se trouve le joueur avant le deplacement et qui sera mise à jour
 * @param joueur_colonne l'adresse de la colonne à laquelle se trouve le joueur avant le deplacement et qui sera mise à jour
 * @param direction la direction dans laquelle on veut deplacer le joueur
 * @return True si le deplacement a pu se faire dans les limites du terrain, false sinon
 */
bool jeu_deplacer_joueur(int* joueur_ligne, int* joueur_colonne, t_direction direction);

/**
 * @brief Initialise le terrain de jeu avec les stations de gas.
 * Initialise la position de destination ainsi que la position initiale du joueur et sa quantite de carburant.
 * @name jeu_init
 * @param terrain Le terrain sur lequel seront placées les stations de gas
 * @param joueur_ligne l'adresse de la ligne ou positionner le joueur
 * @param joueur_colonne l'adresse de la colonne ou positionner le joueur
 * @param joueur_carburant l'adresse ou placer la quantite de carburant du joueur
 * @param destination_ligne l'adresse de la ligne de la case à atteindre
 * @param destination_colonne l'adresse de la colonne de la case a atteindre
 */
void jeu_init(t_terrain terrain, int* joueur_ligne, int* joueur_colonne,
                                        int* joueur_carburant, int* destination_ligne, int* destination_colonne);

/**
 * @brief Affiche une direction en toutes lettres
 * @name jeu_afficher_direction
 * @param direction la direction a afficher
 */
void jeu_afficher_direction(t_direction direction);

/**
 * @brief Récupère une direction saisie sous la forme d'une chaine de caractères,
 * s'assure qu'elle est valide et retourne la constante correspondante.
 * @ame jeu_verifier_choix_deplacement
 * @param choix Une chaine de caractère constituant un choix de direction du joueur
 * @return DIRECTION_ERRONEE si la chaine ne correspond pas à l'une des quatre directions.
 * Sinon, retourne DIRECTION_HAUT ou DIRECTION_BAS ou DIRECTION_DROITE ou DIRECTION_GAUCHE selon la direction choisie
 */
t_direction jeu_verifier_choix_deplacement(char* choix);

/**
 * @brief Calcule la position d'un voisin dans une direction donnee.
 * @name jeu_calculer_voisin
 * @param case_ligne la ligne de la case de depart
 * @param case_colonne la colonne de la case de depart
 * @param direction la direction dans laquelle se trouve le voisin
 * @param voisin_ligne l'adresse ou placer la ligne du voisin selon la direction
 * @param voisin_colonne l'adresse ou placer la colonne du voisin selon la direction
 */
void jeu_calculer_voisin(int case_ligne, int case_colonne, t_direction direction, int* voisin_ligne, int* voisin_colonne);

/**
 * @brief Vérifie si le jeu est terminé ou non.
 * @name jeu_verifier_fin
 * @param joueur_ligne la ligne à laquelle se trouve le joueur
 * @param joueur_colonne la colonne à laquelle se trouve le joueur
 * @param joueur_carburant la quantite de carburant actuel du joueur
 * @param destination_ligne la ligne de la destination
 * @param destination_colonne la colonne de la destination
 * @return JEU_ETAT_VICTOIRE si le joueur a atteint la case d'arrivée.
 * JEU_ETAT_ECHEC si le joueur n'a plus de carburant.
 * JEU_ETAT_EN_COURS si la partie est en cours.
 */
int jeu_verifier_fin(int joueur_ligne, int joueur_colonne, int joueur_carburant,
                                                    int destination_ligne, int destination_colonne);

#endif //JEU_H