Liste des fichiers avec leurs contenus 
Deux dossiers :
  - 1er dossier : headers
    - item.h : contient la classe Item et les prototypes des fonctions associées
    - map.h : contient la classe Map et les prototypes des fonctions associées
    - mob.h : contient la classe Mob et les prototypes des fonctions associées
    - player.h : contient la classe Player et les prototypes des fonctions associées
    - utils.h : contient les prototypes des fonctions utilitaires générales du jeu

  - 2ème dossier : sourcefiles
    - item.c : contient la définition des fonctions de item.h
    - map.c : contient la définition des fonctions de map.h
    - mob.c : contient la définition des fonctions de mob.h
    - player.c : contient la définition des fonctions de player.h
    - utils.c : contient la définition des fonctions de utils.h
    - main.c : contient la fonction principale du programme

À la racine : 
  - Makefile : contient la fonction de compilation du programme
  - README : contient les informations sur le projet

Les instructions de compilation :
  - Pour compiler le programme, il faut utiliser la commande suivante : make
    Celle-ci va générer un fichier "main" qui est le programme à exécuter.

Les instructions de lancement :
  - Pour lancer le programme, il faut utiliser la commande suivante : ./main

La liste des fonctionnalités implémentées
  Fonctionnalités dites de base :
    - Le jeu est composé d'un plateau bidimensionnel sur lequel le personnage peut se déplacer
    - Certains types de terrain de sont pas accessibles par le personnage à moins d'items spécifiques
    - Le personnage peut intéragir avec son environnement (construire un mur, prendre un objet dans un coffre)
    - Le joueur peut sauvegarder jusqu'à 3 parties maximum (fichiers sauvegardés dans le dossier save)
    - Il est possible de configurer le joueur (nom, emoji de jeu) ainsi que le monde (taille du plateau)
    - Des mobs sont présents sur la carte et un système de combat tour par tour est disponible
    - Le joueur peut augmenter ses capacités grâce à un système d'expérience (le joueur gagne des points d'expérience en tuant des monstres)
    
  Fonctionnalités dites d'évolution :
    - Les mobs sont intelligents et se dirigent vers le personnage si ce dernier se trouve dans un rayon de 15 blocs
    - Le système de génération du monde est intelligent et produit des évènements cohérents
    - L'affichage est limité, le joueur ne peut voir qu'à 5 blocs maximum et seuls les blocs déjà visités sont visibles sur la carte globale du monde (disponible seulement depuis l'inventaire du joueur)
    - Un système d'inventaire de taille limitée (en l'occurence 10 slots) est disponible
    - Des conteneurs capables de contenir des items sont disponibles et le joueur peut prendre les items à l'intérieur
    - L'affichage est en couleur
    
Un mini manuel utilisateur
//TODO
