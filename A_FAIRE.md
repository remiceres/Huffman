# consignes

## A faire
* Envoyer à meynard@lirmm.fr et pompidor@lirmm.fr
* Archive nommée par les noms du groupe
* Fichier README qui indiquera l’état d’avancement de votre projet (et par exemple les bogues résiduels)
* un micro rapport papier de 1 à 2 pages décrivant les choix importants effectués PAPIER;
* les listings (fichiers sources) documentés (doxygen) PAPIER
* des réponses aux questions indiquées dans le CC
* affichage propre


* Quel est le nombre maximum de caractères (char) différents ?
    * Le nombre maximum de caractères est 256.
* Comment représenter l’arbre de Huffman ? Si l’arbre est implémenté avec des tableaux (fg, fd, parent), quels sont les indices des feuilles ? Quelle est la taille maximale de l’arbre (nombre de noeuds) ?
    * L'arbre de huffman est représenté par une structure possédant les varriables `pere`,`fg`, `fd` et `frequences`.
    * Si l’arbre est implémenté avec des tableaux (fg, fd, parent), les indices des feuilles corresponde au code du carractère.
    * L'arbre peut avoir au maximum 256 Noeuds.
* Comment les caractères présents sont-ils codés dans l’arbre ?
    * il sont codé par leurs code ASCii.
* Le préfixe du fichier compressé doit-il nécessairement contenir l’arbre ou les codes des caractères ou bien les
deux (critère d’efficacité) ?
    * Le préfixe du fichier compressé doit contenir soit l'arbre soit les codes des caractères.
    * Stocker l'arbre est plus efficace que stoker les codes des caractères.
* Quelle est la taille minimale de ce préfixe (expliquer chaque champ et sa longueur) ?
    * Le préfixe est composé de 3 octet magiques permétant d'identifié pouvant être décompréssé. 1 octet représentant le nombre de bits utile du dernier octet puis l'arbre.
* Si le dernier caractère écrit ne finit pas sur une frontière d’octet, comment le compléter ? Comment ne pas
prendre les bits de complétion pour des bits de données ?
    * on le complete avc des 0 inutile.
    * Lors de la décomprétion on vérifie si on est a la fin du fichier, si c'est le cas on ne traite que les bits utile récupéré dans l'entête
* Le décompresseur doit-il reconstituer l’arbre ? Comment ?
    * oui, a partir de l'entête.


## cahier des charge du programme
* projet est décomposé en deux programmes C : huf.c ($huf source dest) / dehuf.c ($dehuf source)
* Compression  afficher les informations suivantes sur la sortie standard :
    * Liste des caractères et de leur probabilité d’apparition ;    
    * Arbre de Huffman (tableaux fg fd parent ou par indentation) ;
    * affichage des codes de chaque caractère (codeChar(E)=010100) ;
    * longueur moyenne de codage ;
    * Taille originelle de la source, taille compressée et gain en pourcentage (Taille originelle : 5194; taille compressée : 3761; gain : 27.6% !)
* Le fichier décompressé sera envoyé directement sur la sortie
