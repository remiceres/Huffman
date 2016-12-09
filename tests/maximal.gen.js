'use strict';

const filepath = '/media/matteo/34F9-D788/maximal.txt';
const blocksize = 1048576;

// Script utilisé pour générer un fichier contenant les lettres
// données en quantité 2x supérieures par étape, permettant d'obtenir
// un arbre de longueur maximale
const fs = require('fs');
const file = fs.createWriteStream(filepath);

const startChar = '0'.charCodeAt(0);
const numChars = 30;

let currentChar = 0;
let remainingChars = 1;

// Fonction de rappel pour écrire le prochain caractère dans le fichier.
const writeNext = () => {
    if (remainingChars == 0) {
        currentChar++;

        if (currentChar == numChars) {
            // terminé !
            console.log('OK!');
            file.end();
            return;
        }

        remainingChars = Math.pow(2, currentChar);
        console.log(
            'Écriture de', remainingChars, 'x',
            String.fromCharCode(startChar + currentChar)
        );
    }

    const tchar = String.fromCharCode(startChar + currentChar);
    let writing = '';

    while (remainingChars && writing.length < blocksize) {
        writing += tchar;
        remainingChars--;
    }

    if (!file.write(writing)) {
        // on doit attendre le vidage du tampon
        file.once('drain', writeNext);
        return;
    }

    // l'écriture a réussi, on peut passer au suivant
    writeNext();
};

console.info('/!\\ Attention ! Ce script génère un fichier de plusieurs ');
console.info('    gigaoctets de données de test. Assurez-vous d\'utiliser ');
console.info('    un média non-sensible aux multiples écritures et disposant ');
console.info('    de suffisamment de place.\n');
console.info('=============================================================\n');

console.info('Fichier :', filepath);
console.info('Taille de bloc : ', blocksize, 'octets');
console.info('Pour modifier ces params, éditer le script\n');

console.info('=============================================================\n');

console.info('Démarrage dans 10 secondes (Ctrl+C pour annuler)...\n');
setTimeout(writeNext, 10000);
