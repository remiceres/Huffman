# A faire

* corrigé docs

* netoyer l'archive


* les listings (fichiers sources) documentés (doxygen) PAPIER
    * doxygen
    * cd/latex
    * make

* Archive nommée par les noms du groupe

* Envoyer à meynard@lirmm.fr et pompidor@lirmm.fr




















======================================================================

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
    * Stocker l'arbre est plus efficace en terme de taille de stokage ainsi qu'en efficacité lors de la décomprétion.
* Quelle est la taille minimale de ce préfixe (expliquer chaque champ et sa longueur) ?
    * Le préfixe est composé de 3 octet magiques (Pas obligatoire) permétant d'identifié pouvant être décompréssé. 1 octet représentant le nombre de bits utile du dernier octet puis l'arbre.
* Si le dernier caractère écrit ne finit pas sur une frontière d’octet, comment le compléter ? Comment ne pas
prendre les bits de complétion pour des bits de données ?
    * on le complete avc des 0 inutile.
    * Lors de la décomprétion on vérifie si on est sur le dernier octet, si c'est le cas on ne traite que les bits utile. le nombre de bits utile a été récupéré dans l'entête.
* Le décompresseur doit-il reconstituer l’arbre ? Comment ?
    * oui, a partir de l'entête. Dans notre cas l'arbre est reconstruit dans un tableau de `Noeuds`.
