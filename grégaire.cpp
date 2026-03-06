class Grégaire hérite de IComportement {
    éxécuter(b, milieu) {
        Voisins = milieu.getVoisins(b)
        Si Voisins non vide {
            DirectioMmoyene = Moyenne des Voisins
            b.setOrientation(DirectionMoyenne)
        }
        b.bouger()
    }
}