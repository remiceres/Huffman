# Huffman

Le contrôle continu est soumis à la règle du max , il n’est donc pas indispensable mais est fortement recommandé !

Les démos sur machine du projet « Code de Huffman » auront lieu fin décembre. Si vous désirez y participer, le binôme (groupe de deux étudiants) doit :
-  envoyer à Michel Meynard (meynard@lirmm.fr) et Pierre Pompidor (pompidor@lirmm.fr), une archive de vos codes 2 JOURS AVANT LA SOUTENANCE ;
-  en retour, nous vous enverrons un créneau plus précis de votre passage.

Veuillez dans votre archive (nommée par les noms des participants au projet), créer un petit fichier README qui indiquera l’état d’avancement de votre projet (et par exemple les bogues résiduels). Par ailleurs, TOUS les participants au projet devront être présents (les absents ne seront sinon pas notés).

Le jour de la soutenance, les participants doivent venir avec :
-  un micro rapport papier de 1 à 2 pages décrivant les choix importants effectués ;
-  les listings (fichiers sources) documentés (doxygen) ;
-  des réponses aux questions indiquées dans le CC ;

Chaque soutenance durera 12 à 15 minutes ! C’est extrêmement rapide, aussi soyez certain d’avoir les exécutables prêts à fonctionner sur votre compte Unix ainsi que les fichiers exemples. Une recompilation du projet durant la soutenance n’est pas envisageable !







 une démonstration de l’application durant 5 minutes (utilisant des fichiers fournis par les examinateurs) ;
— des réponses précises des 2 étudiants aux questions posées durant 5 minutes ;
— un micro rapport papier de 1 à 2 pages décrivant les choix importants effectués ;
— des listings papiers commentés (doxygen)




Quel est le nombre maximum de caractères (char) différents ?
— Comment représenter l’arbre de Huffman ? Si l’arbre est implémenté avec des tableaux (fg, fd, parent), quels
sont les indices des feuilles ? Quelle est la taille maximale de l’arbre (nombre de noeuds) ?
— Comment les caractères présents sont-ils codés dans l’arbre ?
— Le préfixe du fichier compressé doit-il nécessairement contenir l’arbre ou les codes des caractères ou bien les
deux (critère d’efficacité) ?
— Quelle est la taille minimale de ce préfixe (expliquer chaque champ et sa longueur) ?
— Si le dernier caractère écrit ne finit pas sur une frontière d’octet, comment le compléter ? Comment ne pas
prendre les bits de complétion pour des bits de données ?
— Le décompresseur doit-il reconstituer l’arbre ? Comment ?



Le projet est décomposé en deux programmes C :
huf.c
le programme de compression utilisé selon la syntaxe suivante :
$huf source dest
où
source
est un fichier quelconque et où
dest
est le nom du fichier généré par compression à la Huffman du
fichier
source
. Cette compression doit afficher les informations suivantes sur la sortie standard :
— liste des caractères et de leur probabilité d’apparition ;
— arbre de Huffman (tableaux fg fd parent ou par indentation) ;
— affichage des codes de chaque caractère (codeChar(E)=010100) ;
— longueur moyenne de codage ;
— taille originelle de la source, taille compressée et gain en pourcentage comme dans l’exemple suivant :
Taille originelle : 5194; taille compressée : 3761; gain : 27.6% !
dehuf.c
le programme de décompression utilisé selon la syntaxe suivante :
$dehuf dest
où
dest
est un fichier compressé à la Huffman. Le fichier décompressé sera envoyé directement sur la sortie
standard.