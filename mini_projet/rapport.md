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
• Créer un labyrinthe ;
• Charger un labyrinthe ;
• Jouer ;
• Quitter.

## CR 2 Un manuel pour le joueur : le fonctionnement du point de vue de l’utilisateur ;
Lors de la création du labyrinthe, l’utilisateur pourra choisir la taille du labyrinthe (hauteur et
largeur impaire) ainsi que son nom.
 Chaque labyrinthe généré est enregistré dans un fichier au
format .cfg et est automatiquement chargé
Lance une partie avec un labyrinthe préalablement chargé. L’utilisateur peut alors se déplacer
dans les couloirs du labyrinthe avec l’aide des touches z, q, s et d suivie de la touche entrée :
## CR 2 Un manuel pour le développeur qui reprendra votre code, montrant :
### ▪ Ce qui a été réalisé, et ce qui reste à faire ;

### Le fonctionnement des points clés de votre projet, du point de vue du programmeur ;
 Chaque labyrinthe généré est enregistré dans un fichier au
format .cfg et est automatiquement chargé
### Les limitations et/ou bugs connus:
fonctioon vérifier paramètre à ajouter