## Description

Le but de ce projet est de créer un Othello (Reversi) dans un premier temps en ligne de commande, puis en interface graphique en utilisant la librairie wxWidgets.

## Compilation

Pour compiler le projet, il faut utiliser la commande `make run` à la racine du projet.

## Fonctionnalités

### Réglage de la vitesse
Il est possible de régler la vitesse de jeu des bots à la compilation en rajoutant `speed=x` à la commande `make run`, avec x=1000 pour avoir un jeu un peu plus lent et agréable ou au contraire x=10 pour tester les bots sur des grandes grilles sans trop prendre de temps.

### Réglage de la taille de la grille
On peut également régler la taille de la grille en ajoutant `taille=x`. Avec une taille inférieure à 8 on ne peut pas jouer en tant qu'humain mais aucune idée de pourquoi. Cela deviendra donc un mode de test ultra rapide pour les bots. "It's a feature not a bug",Grace Hopper.
Evidemment en dessous de n=4 cela n'est pas possible.

### Implémentation des IAs
Nous avons implémenté deux des trois IAs demandées.
`IA Facile` : Algorithme où le bot joue au hasard.
`IA Moyen` : Algorithme glouton
Au final l'IA en moyen n'est guère plus efficace que le facile.
De plus si on lance une partie avec les deux IAs en difficulté moyenne la partie sera toujours la même.
`IA Difficile` : Algorithme MinMax 


## Problèmes
L'algorithme MinMax ne fonctionne pas il doit y avoir quelque chose de mal compris dans le fonctionnement de celui ci car quand je le lance j'ai un peu l'impression qu'il joue juste le premier coup qu'il trouve et il perds à chaque fois donc pas si difficile que ça. Mais pas le temps de le terminer.

On a voulu rajouter des sons mais ça ne fonctionne pas, on arrive pas a charger le son.

## Auteurs

Auteurs : Chambe Vivien, Tellier Rozen Adjamé

Dessins : Tellier Rozen Adjamé
