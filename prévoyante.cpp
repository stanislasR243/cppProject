classe Prévoyante hérite de IComportement {
    éxécuter(b,milieu) {
        Voisins=milieu.getVoisins(b)
        Pour chaque V dans voisins {
            PositionFutureV = V.position + V.vitesse
            Si PositionFutureV risque de collision avec b {
                Ajuster orientation de b
            }
        }
        b.bouger()
    }
}