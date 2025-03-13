
#ifndef INTERACTION_H
#define INTERACTION_H


typedef enum {
    ACTION_INVALIDE, ACTION_DEPLACER, ACTION_ACHETER_BONUS, ACTION_QUITTER
} t_action;

//  ************************************
//  Declarations des fonctions publiques
//  ************************************

/**
 * @brief Affiche une petite presentation du jeu.
 * @name interaction_presenter_jeu
  */
void interaction_presenter_jeu();

/**
 * @brief Affiche les options du menu de jeu.
 * Une option non valide sera grise.
 * @name interaction_afficher_options
 * @param carburant la quantite de carburant du joueur
 */
void interaction_afficher_options(int carburant);

/**
 * @brief Demande un choix à l'utilisateur sur une des options du menu
 * @name interaction_demander_action
 * @param carburant la quantite de carburant du joueur
 * @return ACTION_DEPLACER, ACTION_ACHETER_BONUS ou ACTION_QUITTER selon l'option choisie par le joueur
 */
int interaction_demander_action(int carburant);

/**
 * @Brief Demande une direction de deplacement au joueur.
 * @name interaction_demander_direction_deplacement
 * @return DIRECTION_ERRONEE si la direction choisie est invalide.
 * DIRECTION_DROITE, DIRECTION_BAS, DIRECTION_HAUT ou DIRECTION_GAUCHE selon le choix du joueur, sinon
 */
int interaction_demander_direction_deplacement(int interaction_demander_direction_deplacement);

/**
 * @brief Affiche un message d'échec de la mission.
 * @name interaction_afficher_echec
 */
void interaction_afficher_echec();


/**
 * @brief Affiche un message de victoire de la mission ainsi que la quantite de carburant restant
 *        dans le reservoir du joueur.
 * @name interaction_afficher_victoire
 * @param carburant la quantité de carburant du joueur.
 */
void interaction_afficher_victoire(int carburant);

/**
 * @brief Vérifie que l'action choisie par le joueur est correcte.
 * @name interaction_verifier_choix_action
 * @param action l'action choisie par le joueur
 * @param carburant la quantite de carburant du joueur
 * @return action si elle est correcte, ACTION_INVALIDE sinon
 */
int interaction_verifier_choix_action(int action, int carburant);


#endif //INTERACTION_H
