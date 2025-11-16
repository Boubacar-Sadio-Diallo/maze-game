# Mini-Projet : Labyrinthe 2D

* **Auteur :** Boubacar Sadio DIALLO
* **Email :** boubacar-sadio.diallo@ecole.ensicaen.fr
* **Cadre :** Mini-projet d'Introduction à la Programmation

---

## 1. Objectif du Projet

Ce dossier contient le code source complet d'un jeu de labyrinthe 2D en console, réalisé en langage C (norme C99).

L'application permet de :
* **Générer** des labyrinthes parfaits de taille dynamique (via l'algorithme de Kruskal).
* **Sauvegarder** et **Charger** des labyrinthes (fichiers `.cfg`).
* **Jouer** dans le labyrinthe, en gérant une clé, des bonus (trésors) et des malus (pièges).
* **Gérer** un classement des 10 meilleurs scores pour chaque labyrinthe (fichiers `.score`).

## 2. Contenu du Dossier (Composants)

Le projet est structuré comme suit :

* `Makefile` : Fichier principal pour la compilation. Gère la création du jeu (`make exec`), des tests (`make test`), et le nettoyage (`make clean`).
* `script.sh` : Script d'automatisation pour simplifier l'utilisation du `Makefile` (ex: `./script.sh run`).
* `Doxyfile` : Fichier de configuration pour la génération de la documentation technique.
* `rapport.pdf` : Le rapport final du projet, incluant le manuel utilisateur et l'analyse technique.

* `include/` : Contient tous les fichiers d'en-tête (`.h`) définissant les structures de données (`Labyrinthe`, `Player`, `ScoreEntry`) et les prototypes de fonctions.
* `src/` : Contient tous les fichiers source (`.c`) implémentant la logique du projet (génération, jeu, menu, sauvegarde, score).
* `tests/` : Contient les fichiers de tests unitaires (utilisant MinUnit) pour valider la logique du code.
* `data/` : Répertoire de travail où sont stockés les labyrinthes (`.cfg`) et les scores (`.score`) générés par l'application.
* `doc/` : Répertoire de sortie pour la documentation générée par Doxygen (`make doxy`).
* `bin/` : Répertoire de sortie pour les exécutables (`exec` et `execTest`).
* `lib/` : Répertoire de sortie pour les fichiers objets (`.o`).

## 3. Commandes Principales de Manipulation

Le projet est entièrement géré par un script d'automatisation (`script.sh`) qui pilote le `Makefile`.

### a. Rendre le script exécutable:
(Cette commande n'est à exécuter qu'une seule fois)
chmod +x script.sh

### b. Compiler le projet (Jeu + Tests) :
./script.sh all

### c. Lancer le jeu:
./script.sh run

### d. Lancer les tests unitaires :
./script.sh test

### e. Vérifier les fuites memoires
Que vous soyez sur Mac OS ou Linux, le script est capable de détecter le système:
taper simplement:

./script.sh check-mem

### f. le lien vers la documentation:
http://127.0.0.1:5500/mini_projet/docs/html

> Pour les commandes avancées (comme `doc` ou `zip`) et pour une description détaillée du fonctionnement, veuillez consulter le **Manuel Utilisateur** inclus dans le **`rapport.pdf`**.

## 4.  **Manuel du développeur :**
Les différents manuels (utilisateur, développeur) sont présent dans le compte-rendu du projet.

## 5. Structure du Projet
La structure est plus détaillée dans le rapport.
.
├── Doxyfile
├── README.md
├── bin
├── data
│   ├── 13.cfg
│   └── ze.score
├── docs
├── include
│   ├── affichage.h
│   ├── generation.h
│   ├── jeu.h
│   ├── labyrinthe.h
│   ├── menu.h
│   ├── player.h
│   ├── sauvegarde.h
│   └── score.h
├── lib
├── makefile
├── minunit
│   └── minunit.h
├── script.sh
├── src
│   ├── algo_generation.c
│   ├── jeu.c
│   ├── labyrinthe.c
│   ├── main.c
│   ├── menu.c
│   ├── player.c
│   ├── sauvegarde.c
│   ├── score.c
│   └── util.c
└── tests
    └── testGeneration.c
