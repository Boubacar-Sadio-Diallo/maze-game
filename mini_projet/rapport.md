PRESENTATION DU PROJET
Le but du projet est la réalisation d’un générateur de labyrinthe, et de son utilisation dans un
jeu.

Ce projet se fera en quatre étapes,

## CR 1 Un manuel pour le joueur : le fonctionnement du point de vue de l’utilisateur ;
    Les symboles # représentent les murs du labyrinthe, l’entrée est en haut à gauche representé par 0 et 
    et la sortie en bas à droite represente par _. Le personnage à déplacer est représenté par la lettre o. La porte de
    sortie est représentée par le symbole _. les cellules vides sont les potentiels chemins

## CR 2 Un manuel pour le développeur qui reprendra votre code, montrant :
### ▪ Ce qui a été réalisé, et ce qui reste à faire ;

### Le fonctionnement des points clés de votre projet, du point de vue du programmeur ;

ctte permiere etape dont il etait question de mettre en place la generation de labyrinthe nécessité de kruskal pour qui le fait fonctionner

### Les limitations et/ou bugs connus:
a taille constante une fois initialié le labyrinthe je n'arrive plus à chnager les dimensions ????? problème resolu car je ne supprimer pas les .o

## Etape1 : L’algorithme de génération de labyrinthe parfait de taille fixe 11*25.
### compte-rendu sur cette étape est complété.
Le but est de réaliser un générateur de labyrinthe parfait de taille fixe 11*25. L’algorithme de
génération choisit est celui de kruskal. L’affichage sera fait en mode console, tel que présenté
à la Figure 1. Les symboles # représentent les murs du labyrinthe, l’entrée est en haut à gauche
et la sortie en bas à droite. Le personnage à déplacer est représenté par la lettre o. La porte de
sortie est représentée par le symbole –
.
#################################################################################################
### même chose que la deuxième étape pour le compte rendu
2. Etape 2 /6 points
Au démarrage du programme, un menu permet à l’utilisateur de :
### Créer un labyrinthe ;
   
### Charger un labyrinthe ;
    Le programme doit alors lire un fichier
    pour recharger un labyrinthe précédemment créé. L’utilisateur est alors renvoyé au menu.
• Jouer :
### fonctionnalités impléménetées
    on vérifie les deplacements de joueur par la fonciton verifier_limites
    on vérifie le  de joueur par la fonciton verifier_limites
    ...

• Quitter.

## CR 2 Un manuel pour le joueur : le fonctionnement du point de vue de l’utilisateur ;
Lors de la création du labyrinthe, l’utilisateur pourra choisir la taille du labyrinthe (hauteur et
largeur impaire) ainsi que son nom.
 Chaque labyrinthe généré est enregistré dans un fichier au
format .cfg et est automatiquement chargé
Lance une partie avec un labyrinthe préalablement chargé. L’utilisateur peut alors se déplacer
dans les couloirs du labyrinthe avec l’aide des touches z, q, s et d suivie de la touche entrée :
## CR 2 Un manuel pour le développeur qui reprendra votre code, montrant :
    -1 : Mur (#)

-2 : Entrée (o)

-3 : Sortie (_)

0 : Chemin ( )

-4 : Clé (par ex., k à l'affichage/sauvegarde)

-5 : Trésor / Bonus (par ex., b)

-6 : Piège / Malus (par ex., m)
### ▪ Ce qui a été réalisé, et ce qui reste à faire ;

### Le fonctionnement des points clés de votre projet, du point de vue du programmeur ;
 Chaque labyrinthe généré est enregistré dans un fichier au
format .cfg et est automatiquement chargé
### Les limitations et/ou bugs connus:
fonctioon vérifier paramètre à ajouter
3. Etape 3 /6 points
Nous aurons besoin d'un nouveau fichier score.c pour gérer la lecture, l'écriture et le tri de ces scores.

Trois sortes d’objets sont éparpillées de façon aléatoire dans le labyrinthe :
• Une clé, permettant d’ouvrir la porte de sortie du labyrinthe qui se trouve maintenant
verrouillée au début de la partie et qui empêche le joueur de sortir ;
• Des trésors, accordant un certain nombre de points fixes : les bonus d’une valeur de X
points ;
• Des pièges, retirant un certain nombre de points fixes : les malus d’une valeur de Y
points.
A l’initialisation du labyrinthe, la clé et les différentes sortes de bonus/malus sont créées et
réparties au hasard dans le labyrinthe. Le labyrinthe, sa clé et ses bonus/malus ainsi créés seront
sauvegardés.
Un score sera attribué au joueur qui sera fonction de sa rapidité (en nombre de déplacements,
pas en temps) à trouver la clé puis la sortie, et des bonus et/ou malus rencontrés lors de son
parcours. Le score est affiché à chaque déplacement et en fin de partie.
Lorsque l’utilisateur décide de jouer, il joue sa partie comme dans l’étape précédente à la
différence près qu’il doit d’abord ramasser la clé pour pouvoir sortir du labyrinthe. Une fois le
joueur sorti, si son score fait partie des 10 meilleurs déjà enregistrés, le programme l’invite à
saisir son nom et l’enregistre dans un fichier d’extension .score et au nom du labyrinthe.
z
s
q d
Mini-projet d’introduction à la programmation /5------
Une nouvelle entrée sera ajoutée au menu permettant au joueur de visualiser les 10 meilleurs
scores pour le labyrinthe actuellement chargé.

backlog
// void placer_objets(Labyrinthe *lab, int nb_bonus, int nb_malus)
3. 🎮 Logique de Jeu (jeu.c)

C'est ici que se trouve le plus gros changement. La fonction jouer() devient un gestionnaire d'état.

A. jouer(Labyrinthe *lab)

La boucle while(1) principale doit être modifiée :

Affichage : Mettre à jour afficher_labyrinthe (ou printf dans

Affichage : Mettre à jour afficher_labyrinthe (ou printf dans jouer) pour montrer le score actuel et si le joueur a la clé.

printf("Score: %d | Coups: %d | Clé: %s\n", joueur->score, joueur->moves, joueur->has_key ? "Oui" : "Non");
Fin de partie : Si la partie est gagnée, appelez une nouvelle fonction gerer_highscore(lab, joueur).

### 4. 🏆 Système de High Score (Nouveau : score.c)

Ce nouveau fichier gérera la persistance des scores.

void afficher_scores(const char *nom_labyrinthe)

Ouvre le fichier ./data/<nom_labyrinthe>.score en mode lecture ("r").

S'il n'existe pas, affiche "Aucun score pour ce labyrinthe."

Lit et affiche les 10 lignes (scores).

void gerer_highscore(Labyrinthe *lab, Player *joueur)

Crée le nom du fichier score (./data/<nom_labyrinthe>.score).

Charge les scores : Lit tous les scores (max 10) du fichier dans un tableau ScoreEntry scores[11].

Calcule le score final : Le score doit pénaliser le nombre de coups.

score_final = joueur->score - (joueur->moves / 2); (par exemple). Vous devez définir cette formule.

Vérifie si c'est un high score : Compare score_final au dernier score du tableau (scores[9]).

Si ce n'est pas un high score (ou si le tableau n'est pas plein), ne fait rien et return.

Si c'est un high score :

Demande au joueur de saisir son nom (fgets).

Ajoute le nouveau score au tableau.

Trie le tableau : qsort(scores, nb_scores, sizeof(ScoreEntry), comparateur_scores);

Sauvegarde les scores : Ouvre le fichier en mode écriture ("w") et réécrit les 10 meilleurs scores (en ignorant le 11ème s'il y en a un).

int comparateur_scores(const void *a, const void *b)

Fonction C standard pour qsort.

Elle doit trier par score (décroissant) et, si les scores sont égaux, par moves (croissant).

5. 🖥️ Menu Principal (menu.c)

Ajouter une nouvelle entrée, par exemple "5. Voir les meilleurs scores".

Le case 5: doit vérifier si un labyrinthe est chargé (if (lab == NULL)).

Si oui, appeler afficher_scores(lab->nom).