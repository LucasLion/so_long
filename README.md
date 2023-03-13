# Description de `so_long`

`so_long` est un projet en C que j'ai codé pour l'école 42. C'est un jeu de type "Sokoban" interactif, où le joueur doit collecter tous les objets et atteindre la sortie tout en évitant les ennemis.

Le but de ce projet est de mettre en pratique les connaissances en programmation en C, en algorithmique et en graphisme, ainsi que de comprendre le fonctionnement d'une bibliothèque graphique telle que la minilibx.

## Utilisation

Pour jouer à `so_long`, il faut d'abord le compiler en utilisant la commande `make` dans le terminal. Ensuite, il suffit d'exécuter le programme en fournissant le chemin du fichier de carte en argument, par exemple :

``` sh
./so_long maps/map.ber
```
Le jeu se lance alors dans une nouvelle fenêtre graphique. Le joueur peut se déplacer en utilisant les touches directionnelles, collecter les objets en marchant dessus, et atteindre la sortie pour gagner la partie.

## Fonctionnement

Le programme `so_long` utilise la bibliothèque graphique MLX42 pour afficher les éléments du jeu dans une fenêtre graphique. Il lit le fichier de carte fourni en argument pour déterminer la position de chaque élément (joueur, objets, ennemis, murs, etc.) et dessine chaque élément à l'écran en utilisant des images préchargées.

Le joueur peut se déplacer en utilisant les touches directionnelles, et le programme vérifie à chaque mouvement s'il y a une collision avec un mur, un objet ou un ennemi. Si le joueur collecte tous les objets et atteint la sortie, il gagne la partie.

## Sprites

Les sprites utilisés sont ceux du jeu vidéo "Advance Wars 2: Black Hole Rising" sur GameBoy Adance.
Ils sont disponible pour usage personnel sur le site : www.spritersressources.com

## Conclusion

so_long est un projet amusant et intéressant qui permet de mieux comprendre la programmation en C, l'algorithmique et le graphisme. Le jeu est simple mais efficace, et peut être amélioré pour ajouter de nouvelles fonctionnalités ou pour rendre le gameplay plus intéressant. Le projet est disponible sur la plateforme GitHub de l'école 42 et peut être utilisé comme base pour créer d'autres jeux en ligne de commande.
