#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QTableView>
#include <QDebug>
#include <QWidget>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. Connexion à la base de données MySQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // Utiliser le pilote MySQL
    db.setHostName("localhost");  // Nom de l'hôte
    db.setDatabaseName("jeu");    // Nom de la base de données
    db.setUserName("salia");      // Nom d'utilisateur pour la base
    db.setPassword("diallo");     // Mot de passe de l'utilisateur

    // 2. Vérification de la connexion
    if (!db.open()) { // Si la connexion échoue
        qDebug() << "La connexion à la base de données a échoué :" << db.lastError().text();
        return -1; // Quitter l'application avec un code d'erreur
    }
    qDebug() << "Connexion réussie à la base de données."; // Message si reussi

    // 3. Configuration du modèle pour interagir avec la table SQL
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("jeu"); // Spécifier le nom de la table
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // Modifier les champs directement dans la base
    model->select(); // Charger les données de la table

    // 4. Vérification des données chargées
    if (model->rowCount() == 0) { // Si aucune ligne n'est trouvée
        qDebug() << "Aucune donnée trouvée dans la table `jeu`.";
    }

    // 5. Création de l'interface utilisateur
    QWidget window; // Fenêtre principale
    QVBoxLayout *layout = new QVBoxLayout(&window); // pour organiser les widgets

    QTableView *tableView = new QTableView(); // Vue pour afficher les données sous forme de tableau
    tableView->setModel(model); // Associer le modèle de données à la vue
    tableView->resizeColumnsToContents(); // Ajuster la taille des colonnes en fonction du contenu
    layout->addWidget(tableView); // Ajouter la vue au layout principal

    // 6. Configuration de la fenêtre principale
    window.setLayout(layout);
    window.setWindowTitle("Affichage des joueurs"); // Titre de la fenêtre
    window.resize(600, 400); // Taille de la fenêtre
    window.show(); // Afficher la fenêtre

    // 7. Exécution de l'application
    return a.exec(); // Démarrer la boucle d'événements Qt
}


