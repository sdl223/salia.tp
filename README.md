# Création d'une Interface Graphique avec Qt et MySQL sur LINUX

Ce TP a pour objectif de créer une application graphique connectée à une base de données MySQL. Voici les étapes clés et une description des fichiers inclus dans ce projet.

## Outils

- Logiciels requis :
  - installer Qt Creator
  - installer MySQL pour la gestion de la base de données.
    
## Structure du Projet

### Fichiers Inclus

1. **widget.h**
   - Déclaration de la classe `Widget`, héritant de `QWidget`.
   - Inclus les définitions nécessaires pour la gestion de l'interface graphique.

2. **widget.cpp**
   - Implémentation de la classe `Widget`.
   - Chargement des composants de l'interface via la classe `Ui::Widget`.

3. **main.cpp**
   - Point d'entrée de l'application.
   - Implémente :
     - La connexion à la base de données MySQL.
     - L'utilisation d'un modèle `QSqlTableModel` pour interfacer avec une table SQL.
     - La création et l'affichage de l'interface utilisateur avec un `QTableView`.

## Étapes de Mise en Place

1. **Installation des Dépendances**
   - Installer Qt :
     ```bash
     sudo apt update
     sudo apt install qtcreator qtbase5-dev qt5-qmake
     ```
   - Installer MySQL :
     ```bash
     sudo apt install mysql-server libmysqlclient-dev
     ```
   - Installer les modules Qt SQL :
     ```bash
     sudo apt install libqt5sql5 libqt5sql5-mysql
     ```

2. **Création de la Base de Données**
   - Accéder à MySQL et créer une base de données nommée `jeu` :
     ```
CREATE DATABASE jeu;
USE jeu;
CREATE TABLE jeu (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nom VARCHAR(255) NOT NULL,
    club VARCHAR(255) NOT NULL
);
INSERT INTO jeu (id, nom, club) VALUES
    (1, 'Ronaldo', 'Madrid'),
    (2, 'Grizou', 'Barca');

     ```

3. **Configuration du Projet Qt**
   - Initialiser un projet Qt dans Qt Creator.
   - Ajouter les modules SQL dans le fichier `.pro` :
     ```plaintext
     QT += core gui sql
     ```

4. **Implémentation du Code**
   - Ajouter et configurer les fichiers `widget.h`, `widget.cpp`, et `main.cpp` comme fourni.
   - Compiler et exécuter le projet pour vérifier l'affichage de la table `jeu`.

5. **Exécution de l'Application**
   - Lancer l'application avec :
     ```bash
     ./nom_du_projet
     ```
   - Une fenêtre affichant les données de la table `jeu` sera affichée.

## Fonctionnalités

- Connexion à une base de données MySQL.
- Affichage des données via une interface graphique.
- Modification en temps réel des champs de la base de données directement depuis l'interface utilisateur.

## Instructions pour GitHub

1. **Initialiser un Dépôt Git**
   ```bash
   git init
   git add .
   git commit -m "Initial commit"
   ```

2. **Ajouter un Repository Distant**
   ```bash
   git remote add origin https://github.com/votre-utilisateur/nom-du-repository.git
   git push -u origin main
   ```

3. **Documentation**
   - Inclure ce fichier `README.md` dans le repository.
   - Fournir des captures d'écran de l'application en exécution.

---

Ce TP permet de maîtriser les bases de l'interfaçage graphique avec Qt et la gestion des bases de données SQL. Les étapes présentées doivent être suivies rigoureusement pour garantir le succès du projet.


