#consignes

## A faire
* Envoyer à meynard@lirmm.fr et pompidor@lirmm.fr
* Archive nommée par les noms du groupe
* Fichier README qui indiquera l’état d’avancement de votre projet (et par exemple les bogues résiduels)
* un micro rapport papier de 1 à 2 pages décrivant les choix importants effectués PAPIER;
* les listings (fichiers sources) documentés (doxygen) PAPIER
* des réponses aux questions indiquées dans le CC
* affichage propre


* Quel est le nombre maximum de caractères (char) différents ?
* Comment représenter l’arbre de Huffman ? Si l’arbre est implémenté avec des tableaux (fg, fd, parent), quels
sont les indices des feuilles ? Quelle est la taille maximale de l’arbre (nombre de noeuds) ?
* Comment les caractères présents sont-ils codés dans l’arbre ?
* Le préfixe du fichier compressé doit-il nécessairement contenir l’arbre ou les codes des caractères ou bien les
deux (critère d’efficacité) ?
* Quelle est la taille minimale de ce préfixe (expliquer chaque champ et sa longueur) ?
* Si le dernier caractère écrit ne finit pas sur une frontière d’octet, comment le compléter ? Comment ne pas
prendre les bits de complétion pour des bits de données ?
* Le décompresseur doit-il reconstituer l’arbre ? Comment ?


## cahier des charge du programme
* projet est décomposé en deux programmes C : huf.c ($huf source dest) / dehuf.c ($dehuf source)
* Compression  afficher les informations suivantes sur la sortie standard :
    * Liste des caractères et de leur probabilité d’apparition ;
    * Arbre de Huffman (tableaux fg fd parent ou par indentation) ;
    * affichage des codes de chaque caractère (codeChar(E)=010100) ;
    * longueur moyenne de codage ;
    * Taille originelle de la source, taille compressée et gain en pourcentage (Taille originelle : 5194; taille compressée : 3761; gain : 27.6% !)
* Le fichier décompressé sera envoyé directement sur la sortie
