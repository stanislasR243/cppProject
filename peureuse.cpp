class peureuse herite de IComportement {
    execute(b, milieu) {
        Voisins = milieu.getVoisins(b)
        Si nombre(Voisins) > Seuil {
            Direction fuite = opposé
            b.setVitesse(VitesseMax)
            b.setOrientation(Direction fuite)
        } Sinon {
            b.setVitesse(Vitesse normale)
        }
        b.bouger
        }
    }
