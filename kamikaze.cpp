classe kamikaze hérite de IComportement {
    éxécter(b, milieu) {
        Voisins = milieu.getVoisins(b)
        Si Voisins non vide {
            Cible = voisin le plus proche
            Direction = calculerangle(b.position, cible.position)
            b.setOrientation(DirectionAttaque)
        }
        b.bouger()
    }
}
