 class bestiolefactory  {
    private : 
        static Instance
        ConfigInitiale (ex: 0.2 gégaire 0.2... etc)

    public :
        static getInstance() {
            Si InstanceUnique nulle alors = new Bestiolefacory()
            return InstanceUnique
        }

        Bestiole créerBestiole(milieu m) {
            Comportement choisi = tirerAuSortLaConfig()

            NouvelleBestiole b = new Bestiole()
            b.setComportement(choisi)

            b.initCoords(m.width, m.height)
            retourner b
        }
}