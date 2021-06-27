# MiniShell | 42 - Common Core 
Note that this is an ongoing version of the 42-minishell project.
This README file will be updated step by step.

fonction pratique :

- which nom_de_la_commande - pour savoir on elle se trouve.

Part 1 - Baseline

1. Prompt creation									- OK
2. exit command 									- OK
3. pwd command										- OK
4. error 											- OK
5. (bonus) colored prompt							- OK

Part 2 - Le Parsing des autres commandes

1.  parsing : echo & -n flag						- to check
2.  export comma									- to check
3.  unset command									- to check
4.  env command										- to check
5.  split commands with ;							- to do
6.  ' and "											- to check
7.  <, > et “>>” must work just like bash.			- to check
    (no fd agregate).
8.  Pipes | must work just like bash
	(no multithread).								- to check
9.  env var											- to do
10. $? must work just like bash						- to do
11. ctrl-C, ctrl-D et ctrl-\ must display 
    the same thing displayed in  bash.				- to check
12. Touches haut et bas pour naviguer dans
    l’historique de commandes, que nous pouvons
    ensuite éditer (inline, pas dans l’historique)	- to do

test sur redirection :

(>) :
Le signe > est utilisé pour rediriger la sortie d'un programme vers autre chose que stdout.
Le écrase > le fichier s'il existe ou le crée s'il n'existe pas.

(>>) :
L' >> ajoute à un fichier ou crée le fichier s'il n'existe pas.
Le >> n'écrase pas le fichier mais ecris a la fin du fichier s'il existe ou le crée s'il n'existe pas.

Dans les deux cas, la sortie du programme est stockée dans le fichier dont le nom est fourni après l'opérateur de redirection.

exemple :

$ ls > allmyfiles.txt crée le fichier "allmyfiles.txt" et le remplit avec la liste des répertoires de la commande ls

$ echo "End of directory listing" >> allmyfiles.txt ajoute "Fin de liste de répertoires" à la fin du fichier "allmyfiles.txt"

$ > newzerobytefile crée un nouveau fichier de zéro octet avec le nom "newzerobytefile" ou écrase un fichier existant du même nom (ce qui lui donne une taille de zéro octet)

exeption : 

bash-3.2$ ls > lol > mdr > bijour

ls va etre copier dans bijour ; puis lol et mdr vont etre cree sans rien dedans.

en gros il cree lol et prend sont fd puis cree mdr et prend sont fd puis cree bijour prend son fd et print ls dedans.

pour le gere je pense il faut gere ls en premier et le copier dans un fichier temp si > ou >> est pressent puis en fonction du dernier arg renomer le fichier temp avec args_last.

bash-3.2$ echo < 
bash: syntax error near unexpected token `newline'
bash-3.2$ new commande....
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

(<<) :
le programe a gauche va devoir attendre que lutilisateur entre la meme string que a droite du << pour se lancer. pour chaque tentative il faudra afficher > plus la string entrer jusqu'a se quelle corresponde

exemple :

bash-3.2$ echo coucou << lol
> hello
> coucou
> lol
coucou
bash-3.2$ new commande....

se qui c'est passer est que le dit programe echo coucou a du attendre que l'utilisateur entre lol pour se lancer.

l'utilisateur n'est pas limiter a un seul mot clef :

bash-3.2$ echo coucou << lol alors << mdr bienvenue
> hello
> lol
> coucou
> mdr
coucou alors bienvenue
bash-3.2$ new commande....

les mots doivent etre entre dans l'ordre, si on avait entre mdr avent lol il n'aurait pas compter.

exemple :

bash-3.2$ echo coucou << lol alors << mdr bienvenue
> mdr
> lol
> mdr
coucou alors bienvenue
bash-3.2$ new commande....

les retour d'erreur existe si on ne lui donne pas de mots clef.

exemple :

bash-3.2$ echo coucou << 
bash: syntax error near unexpected token `newline'
bash-3.2$ new commande....
