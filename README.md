# MiniShell | 42 - Common Core 
Our own Shell.

Part 1 - Baseline

1. Prompt creation									- OK
2. exit command 									- OK
3. pwd command										- OK
4. error 											- OK
5. (bonus) colored prompt							- OK

Part 2 - Le Parsing des autres commandes

1.  parsing de la commande echo plus flags -n		- a voir fonctionnement
2.  commande export									- a voir fonctionnement
3.  commande unset									- a voir fonctionnement
4.  commande env									- a voir fonctionnement
5.  séparer les commandes avec ;					- a faire
6.  ' et "											- a voir fonctionnement
7.  Les redirections <, > et “>>” doivent
    marcher comme dans bash.						- a voir fonctionnement
    (sauf aggrégations de fd).
8.  Pipes | doivent marcher comme dans bash à 	
    l’exception du multiligne.						- a voir fonctionnement
9.  Les variables d’environnement					- a faire
10. $? doit marcher comme dans bash					- a faire
11. ctrl-C, ctrl-D et ctrl-\ doivent afficher 
    le même résultat que dans bash.					- a voir fonctionnement
12. Touches haut et bas pour naviguer dans
    l’historique de commandes, que nous pouvons
    ensuite éditer (inline, pas dans l’historique)	- a faire
