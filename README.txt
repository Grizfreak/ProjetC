Liste des fichiers avec leurs contenus 
Trois dossiers :
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
    
  - 3ème dossier : fichiers de sauvegarde
    - Ce dossier contient les fichiers binaires des parties sauvegardées (jusqu'à 3 maximum)


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
    
    
Le mini manuel utilisateur :
C'est dans cette partie que nous allons vous expliquer comment jouer au jeu, vous êtes prêt ? C'est parti !

  - But du jeu
      Survivre à tout prix ! Vous allez attrrir dans un monde où les monstres n'auront qu'une envie : vous dévorer. Déplacez-vous sur la carte, trouvez des items, ouvrez des coffres, terrasser des monstres et devenez plus fort en gagnant de l'expérience !
      
  - Lancer/Charger une partie
      Pour lancer une toute nouvelle partie, il suffit de sélectionner la première option du menu qui apparaît dès que vous lancez le jeu, entrez alors 1 puis pressez Entrée. Vous avez ensuite le choix de la taille de la carte (entre 10 et 500 blocs) mais également le choix de votre nom d'aventurier ainsi que de l'emoji que vous souhaitez jouer (parmi les emojis suivants : Chat, Chien, Souris, Hamster et Lapin). Une fois tout cela effectué, vous apparaissez sur la carte, vous pouvez alors commencer à jouer.
      Pour charger une partie déjà enregistrée, il faut sélectionner l'option n°2 du menu apparaissant juste après le lancement du jeu. Écrivez ensuite le numéro du slot dans lequel vous avez précedemment enregistré le fichier. Si tout se passe bien, vous devriez retrouver votre ancienne partie sauvegardée et vous allez pouvoir recommencer à jouer !
  
  - Sauvegarder une partie
      Vous voulez continuer à jouer, mais vous manquez de temps ? Aucun souci, vous pouvez sauvegarder jusqu'à 3 parties grâce à un système de sauvegarde ! Pour cela, il vous suffit de vous rendre dans votre inventaire en appuyant sur 'b', puis en appuyant sur 's' vous allez pouvoir sauvegarder votre partie dans un des 3 slots proposé. Tapez alors le numéro du slot désiré puis pressez Entrée. Vous pouvez alors choisir soit de quitter le jeu soit de continuer à jouer.

  - Quitter une partie
      Pour quitter une partie, plusieurs choix s'offrent à vous. Vous pouvez tout aussi bien quitter le jeu dès le lancement en sélectionnant l'option n°3 'Quit', mais également à partir de votre inventaire en sauvegardant la partie puis en entrant 'y' pour quitter le jeu.
  
  - Se déplacer
      Pour échapper aux mobs qui vous courent après, vous allez devoir vous déplacer sur la carte. Pour cela, rien de plus simple, il faut presser une touche parmi celles proposées afin de vous déplacer soit au Nord ('z'), au Sud ('s'), à l'Est ('d') ou bien à l'Ouest ('q'). Toutefois attention, il n'est pas possible de se déplacer sur l'eau (à moins d'avoir un certain item particulier :) ) et il est très risqué de s'aventurer dans la lave.
  
  - Les combats contre les mobs
      Pour survivre, il va falloir se battre ! Un combat se déclenche lorsque vous vous trouvez sur le même bloc qu'un mob. Attention, un mob pour poursuivra certainement jusqu'en enfer si vous ne le tuez pas ! Vous apprendrez à les connaître, certains sont très puissants. Les monstres sont classés selon 5 catégories (Very Small, Small, Medium, Large, Very Large et Gigantic), il ne sert à rien de préciser que lorsque vous vous trouvez face à un niveau Gigantic dès le début il vaut mieux fuir :)). 
      Une fois dans le combat, un ASCII 'VS' apparaît, vous voyez alors le monstre que vous affrontez ainsi que le différentes options qui s'offrent à vous. Vous pouvez attaquer le monstre, vous défendre ou bien fuir. Pour réaliser chaque action, il vous faudra résoudre une petite énigme (ne vous inquiétez pas, ce n'est pas très compliqué), le monstre effectuera ensuite son action (il ne saît qu'attaquer (งツ)ว). 
        - Si vous choisissez d'attaquer, le mob prendra des dégâts, vous pourrez alors voir combien de pv il lui reste. 
        - Si vous choisissez de vous défendre, vous ne prendrez aucun dégâts (mais le mob non plus !)
        - Si vous choisissez de fuir, le mob n'aura pas le temps de vous attaquer
      Vous pourrez alors tenter de terrasser le monstre en enchaînant les attaques ! Il disparaîtra alors de la carte, néanmoins, si vous choisissez de fuir, soyez sûr que le monstre voudra vous suivre, il faudra alors trouver un moyen de le semer !
  
  - Les coffres et les items
      Lors de votre aventure, vous allez pouvoir récupérer des items dans des coffres dispersés sur la carte. Pour récupérer un item, il vous suffit de vous rendre sur un bloc coffre (pour savoir ce qu'est un bloc coffre, rendez-vous à la fin de ce fichier). Un item aléatoire vous est alors proposé, vous pouvez alors choisir de le prendre et de le ranger dans votre inventaire en entrant le numéro de slot dans lequel vous souhaitez le ranger, ou alors de l'abandonner (notez que le coffre disparaîtra mystérieusement dans cas la). Il existe 4 catégories d'items différentes :
        - L'item effet Heal, cet item permet lors de son utilisation de regagner un certains nombre de points de vie
        - L'item effet Boost Attack, cet item permet de booster temporairement l'attaque du joueur avec un certain pourcentage
        - L'item effet Wall, cet item peut être posé sur la carte à tout moment (notez que les monstres ne peuvent pas aller dessus)
        - L'item effet ????, cet item pourrait bien permettre de s'affranchir de certaines règles
      Pour utilsier un item, il vous suffit de vous rendre dans votre inventaire en pressant 'b', puis vous pouvez choisir d'utiliser un item en entrant 'u' puis le numéro de slot de l'item. L'item prendra alors effet !
    
  - La carte
      Il est possible à tout moment (sauf lorsque le joueur est dans un combat) de consulter la carte du monde. Il est important de savoir qu'il y à "2 cartes" :
        - La première est celle de 5 * 5 présente au dessus du menu de déplacement, cette carte symbolise en réalité le champs de vision du personnage et il est impossible de vois plus loin que cette distance.
        - La seconde carte est quant à elle accessible depuis l'inventaire du joueur (appuyer sur 'b'). Cette autre carte symbolise l'entiereté du monde, néanmoins seuls les blocs sur lesquels le joueur est passé sont visibles (sinon ça serait trop simple :)) )
  
  - Le système d'expérience / levels
      Le monde dans lequel vous allez jouer est régi par un système d'expérience et de niveau. En effet, il est possible d'améliorer ses capacités aux combats en gagnant de l'expérience. "Mais comment ?" vous me direz; il faut tuer des mobs pour y parvenir, plus le type/niveau du mob est élevé, plus l'expérience gagnée est importante. Vous pouvez à tout moment consulter les caractéristiques de votre personnage en accédant à l'inventaire.
        - Pour chaque niveau gagné, vous regénérez tous vos pv et vous gagnez 5 pvs maximum supplémentaire
        - Pour chaque niveau gagné, vous gagnez 2 points d'attaque supplémentaire
        
  - Les différentes blocs de la carte
      Vous trouverez ici tous les blocs et entités disponibles dans le jeu, ainsi que leur couleur textuelle (on est dans un fichier texte :( )
        - Bloc d'herbe (Vert Clair)   : 艸
        - Bloc d'eau (Bleu)           : ≈
        - Bloc de terre (Blanc)       : ⏚
        - Bloc coffre (Marron)        : ⍟
        - Bloc nénuphar (Vert Foncé)  : ɞ
        - Bloc de sable (Jaune)       : ▦ 
        - Bloc de mur (Gris Foncé)    : ■
        - Bloc de lave (Rouge)        : ≈
        - Bloc de pierre (Gris Clair) : ⧍
        - Entité Monstre              : 👹
        - Bloc de vide (Blanc)        : X
