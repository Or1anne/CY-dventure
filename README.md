
# CY'dventure

## Summary
- [About](#about) Explain what the project is.
- [Content](#content) Explain what the project has as functionnality in the game.
- [Goal](#goal) Explain what is the goal to reach to win the game.
- [Group](#group) The group that has made the project.
- [Files](#files) Explain where are the files and what are their goal.
- [Compile](#compile) Explain what you need to do to compile or clean the game.
- [Preview](#preview) Some screenshot of the game once it is running.
- [CY-Tech](#cy-tech) Our school icon, where the project comes from.

## About

This is a project for the CY TECH School in Pre Ing 1 MIM 1. The directives are said in [this pdf file](./file à mettre)

## Content

Le jeu est composé de différents choix qui permettent d'avancer ou de perdre. Afin de faire un choix, il faut appuyer sur A,B ou C lorsqu'il y'en a 3. Des combats sont aussi présent dans le jeu avec la possibilité d'attaquer ou défendre, leur fonctionnement est expliqué a chaque début de combat. Les statistiques peuvent aussi changer au cours du jeu via différents équipement qu'on peut avoir au cours de l'aventture.

## Goal

Le but du jeu est d'avancé a travers la grotte en battant les différents ennemis sur notre chemin afin de récuperer l'épée légendaire se trouvont au fin fond de cette grotte.

## Group
Notre groupe est composé d' ORIANNE COURTADE, PRINCE KOUAKOU et NICOLAS LE MOIGNE

## Files 
[main.c] (https://github.com/Or1anne/CY-dventure/blob/master/main.c) est le fichier principal (main) et le point d'entré. Les fonctions du jeux sont dans le [function.h] (https://github.com/Or1anne/CY-dventure/blob/master/function.h) et  [function.c] (https://github.com/Or1anne/CY-dventure/blob/master/function.c). [fight.h] (https://github.com/Or1anne/CY-dventure/blob/master/fight.h) et  [fight.] (./CY-dventure/fight.) contiennent les fonctions de déroulement des combats et leur affichage. [player.h] (./CY-dventure/player.h) et  [player.c] (./CY-dventure/player.c) contiennent les statisitques des différents personnages et leur affichage. L'afffichage de l'inventaire de notre aventurier est contenu dans [invantory.h]  (./CY-dventure/invantory.h) et  [invantory.c]  (./CY-dventure/invantory.c). [save.h] (./CY-dventure/save.h) et [save.c] (./CY-dventure/save.c) permettent de sauvegarder la partie en cours et de la relancer a tout moment. Le dossier [story] (./CY-dventure/Story) contient l'ensemble des textes ( choix, etapes et fins) de l'histoire du jeu.
## Compile 
Pour compiler sur Linux, vous devez :  
1- faire make   
2- bin/CYdventure.exe   
Pour supprimer les dossiers crées par le makefile dans le terminal, on fait la commmande make clean 

## Preview
(facultatif)

# CY Tech 
![CY tech icon](./images/nom de l'image.png)
