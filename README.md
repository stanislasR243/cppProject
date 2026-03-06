# cppProject

# Git Guide – Utilisation du dépôt

Ce dépôt est partagé afin que plusieurs personnes puissent travailler sur le projet en parallèle.  
Ce document explique **les commandes git de base**, le **workflow recommandé**, ainsi que **les erreurs à éviter**.

L’objectif est que chacun puisse contribuer facilement **sans créer de conflits ou casser le dépôt**.

---

# 1. Cloner le dépôt

La première étape consiste à récupérer le dépôt sur votre machine locale.

```bash
git clone <repo_url>
cd <repo_name>
```

Cela télécharge l’ensemble du projet ainsi que son historique.

⚠️ Cette commande ne doit être exécutée **qu’une seule fois**.

---

# 2. Workflow recommandé

Voici l’ordre de travail standard à suivre :

```bash
git pull
# modifier les fichiers

git add .
git commit -m "description claire des modifications"
git push
```

Explication :

1. **git pull** → récupère les modifications des autres personnes  
2. modifier le code  
3. **git add** → ajoute les fichiers modifiés  
4. **git commit** → enregistre les modifications localement  
5. **git push** → envoie les modifications sur le dépôt partagé  

---

# 3. Récupérer les modifications du dépôt

Avant de commencer à travailler, il faut **toujours synchroniser votre version** avec le dépôt :

```bash
git pull
```

Cela évite les conflits et permet de travailler sur la version la plus récente.

---

# 4. Ajouter les fichiers modifiés

Après avoir modifié du code, vous devez indiquer à git quels fichiers doivent être enregistrés.

Ajouter tous les fichiers modifiés :

```bash
git add .
```

Ajouter un fichier spécifique :

```bash
git add nom_du_fichier.py
```

---

# 5. Faire un commit

Un commit correspond à **un point de sauvegarde dans l’historique du projet**.

```bash
git commit -m "message décrivant les modifications"
```

Exemples :

```bash
git commit -m "Correction du calcul de la loss"
git commit -m "Ajout du script de preprocessing"
git commit -m "Amélioration du modèle de super-resolution"
```

Bonnes pratiques :

- écrire un message **court mais explicite**
- éviter les messages vagues comme `"update"` ou `"fix"`
- un commit doit correspondre à **une modification logique**

---

# 6. Envoyer les modifications sur le dépôt

Une fois le commit effectué, il faut envoyer les modifications sur le serveur :

```bash
git push
```

Cela rend les changements **visibles pour toute l’équipe**.

---

# 7. Vérifier l’état du dépôt

Pour voir les fichiers modifiés :

```bash
git status
```

Pour voir les différences dans les fichiers :

```bash
git diff
```

Pour voir l’historique des commits :

```bash
git log
```

---

# 8. Gestion des conflits

Un conflit peut apparaître si deux personnes modifient **la même partie d’un fichier**.

Dans ce cas :

1. faire un `git pull`
2. git indiquera les fichiers en conflit
3. ouvrir le fichier concerné
4. choisir la version correcte
5. supprimer les marqueurs de conflit

Exemple de conflit dans un fichier :

```
<<<<<<< HEAD
votre version
=======
autre version
>>>>>>> branch
```

Une fois le conflit résolu :

```bash
git add fichier_conflit
git commit
git push
```

---

# 9. Bonnes pratiques importantes

### Toujours faire un pull avant de commencer

```bash
git pull
```

### Faire des commits régulièrement

Cela permet :

- d’éviter de perdre du travail
- de garder un historique clair
- de faciliter les corrections

### Éviter d’ajouter des fichiers lourds

Ne pas ajouter :

- datasets volumineux
- fichiers temporaires
- checkpoints de modèles
- outputs intermédiaires

Ces fichiers doivent être ignorés avec `.gitignore`.

### Garder le dépôt propre

- supprimer les fichiers inutiles
- commenter le code
- écrire des commits clairs

---

# 10. Commandes utiles

Voir la branche actuelle :

```bash
git branch
```

Annuler les modifications d’un fichier :

```bash
git restore nom_du_fichier.py
```

Annuler un fichier ajouté par erreur :

```bash
git reset nom_du_fichier.py
```

---

# 11. En cas de problème

Si quelque chose ne fonctionne pas :

1. vérifier l’état du dépôt

```bash
git status
```

2. récupérer les dernières modifications

```bash
git pull
```

3. éviter les commandes destructives si vous n’êtes pas sûr de leur effet

---

# Résumé rapide

Workflow standard :

```bash
git pull
git add .
git commit -m "description"
git push
```

---

Si vous avez un doute ou un problème, n’hésitez pas à demander avant de faire une manipulation risquée.
