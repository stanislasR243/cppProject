class Multiple hérite de IComportement {
    Attributs : Comportementcourant (un de ceux définis)

    exécuter(b, milieu) {
        Si Probabilité(changement) {
            ComportementCourant = choisirAléatoirement(...)
        }
        ComportementCourant.exécuter(b,milieu)
    }
}