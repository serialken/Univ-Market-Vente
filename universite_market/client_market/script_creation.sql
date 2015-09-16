# SQLiteManager Dump
# Version: 1.2.4
# http://www.sqlitemanager.org/
# 
# Serveur: localhost
# Généré le: Tuesday 21st 2011f June 2011 02:25 pm
# SQLite Version: 3.6.15
# PHP Version: 5.3.0
# Base de données: BDD_COMM.db
# --------------------------------------------------------

#
# Structure de la table: ACT_BIOCH
#
CREATE TABLE 'ACT_BIOCH' ( 'id_act_bioch' INTEGER PRIMARY KEY, 'nb_patient' VARCHAR(10) , 'nb_tube' VARCHAR(10) , 'nb_ise' VARCHAR(10) , 'nb_test_glu' VARCHAR(10) , 'nb_test_trans' VARCHAR(10) , 'nb_test_crp' VARCHAR(10) , 'nb_test_hdl' VARCHAR(10) , 'id_client' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: ACT_HEMATO
#
CREATE TABLE 'ACT_HEMATO' ( 'id_act_hemato' INTEGER PRIMARY KEY, 'nb_patient' VARCHAR(10) , 'nb_cbc' VARCHAR(10) , 'nb_vs' VARCHAR(10) , 'nb_slide' VARCHAR(10) , 'nb_ret' VARCHAR(10) , 'type_travail' INT , 'id_client' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: ARTICLE
#
CREATE TABLE 'ARTICLE' ( 'id_article' INTEGER PRIMARY KEY, 'code_article' TEXT, 'libelle' TEXT );
# --------------------------------------------------------


#
# Structure de la table: CLIENT
#
CREATE TABLE 'CLIENT' ( 'id_client' INTEGER PRIMARY KEY, 'nom' VARCHAR(50) , 'adresse' TINYTEXT , 'ville' VARCHAR(25) , 'code_postal' VARCHAR(10) , 'telephone' VARCHAR(15) , 'fax' VARCHAR(15) , 'pays' VARCHAR(50) , 'mail' VARCHAR(60) , 'date_creation' VARCHAR(10) , 'statut' INT , 'duree_client' VARCHAR(10) , 'effectif' VARCHAR(4) , 'chiffre_affaire' VARCHAR(12) , 'commentaire' TEXT , 'categorie' INT , 'classification' INT , 'nb_patient' VARCHAR(6) , 'nb_ouverture' VARCHAR(2) , 'soc_codcli' VARCHAR(10) , 'id_user' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: CLIENT_SECTEUR
#
CREATE TABLE 'CLIENT_SECTEUR' ( 'id_client_secteur' INTEGER PRIMARY KEY, 'id_client' INTEGER , 'id_secteur' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: CONTACT
#
CREATE TABLE 'CONTACT' ( 'id_contact' INTEGER PRIMARY KEY, 'civilite' INT , 'nom' VARCHAR(15) , 'prenom' VARCHAR(25) , 'mail' VARCHAR(60) , 'telephone' VARCHAR(15) , 'statut' INT , 'association' VARCHAR(50) , 'id_poste' INTEGER , 'id_client' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: DISTRIB
#
CREATE TABLE 'DISTRIB' ( 'id_distrib' INTEGER PRIMARY KEY, 'libelle' VARCHAR(50) );
# --------------------------------------------------------


#
# Structure de la table: FACTURE
#
CREATE TABLE 'FACTURE' ( 'id_facture' INTEGER PRIMARY KEY, 'date_achat' DATE , 'num_facture' VARCHAR(20) , 'montant' VARCHAR(6) , 'id_client' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: INSTRU_ACHAT
#
CREATE TABLE 'INSTRU_ACHAT' ( 'id_instru_achat' , 'date_achat' DATE , 'mode_paiement' INT , 'prix' VARCHAR(6) , 'prochain_achat' DATE );
# --------------------------------------------------------


#
# Structure de la table: INSTRU_BIOCH
#
CREATE TABLE 'INSTRU_BIOCH' ( 'id_instru_bioch' INTEGER , 'marque' VARCHAR(20) , 'modele' VARCHAR(20) , 'specificite' INT , 'carac_machine' INT , 'lis' INT , 'id_satisfaction' INTEGER , 'id_achat' INTEGER , 'id_client' INTEGER , 'id_reactif' INTEGER , 'id_distrib' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: INSTRU_HEMATO
#
CREATE TABLE 'INSTRU_HEMATO' ( 'id_instru_hemato' INTEGER PRIMARY KEY, 'marque' VARCHAR(20) , 'modele' VARCHAR(20) , 'specificite' INT , 'carac_machine' INT , 'lis' INT , 'passeur_tube' INT , 'id_satisfaction' INTEGER , 'id_achat' INTEGER , 'id_client' INTEGER , 'id_reactif' INTEGER , 'id_distrib' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: NOTE
#
CREATE TABLE 'NOTE' ( 'id_note' INTEGER PRIMARY KEY, 'titre' VARCHAR(50) , 'date' DATE , 'type' INT , 'emetteur' VARCHAR(50) , 'compte_rendu' TINYTEXT , 'action' VARCHAR(100) , 'etat' INT , 'vente_realise' INT , 'objectif_etape' TINYTEXT , 'objectif_final' TINYTEXT , 'id_contact' INTEGER , 'id_client' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: POSTE_CONTACT
#
CREATE TABLE 'POSTE_CONTACT' ( 'id_poste' INTEGER PRIMARY KEY, 'libelle' TEXT );
# --------------------------------------------------------


#
# Structure de la table: PRODUIT_FACTURE
#
CREATE TABLE 'PRODUIT_FACTURE' ( 'id_produit_facture' INTEGER PRIMARY KEY, 'code_article' VARCHAR(10) , 'quantite' VARCHAR(3) , 'prix_unitaire' VARCHAR(5) , 'montant' VARCHAR(6) , 'id_facture' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: REACTIF
#
CREATE TABLE 'REACTIF' ( 'id_reactif' INTEGER PRIMARY KEY, 'type' INT , 'marque' VARCHAR(20) , 'packaging' INT , 'qualite' CHAR , 'prix' VARCHAR(6) , 'prochaine_commande' DATE , 'modele_associe' VARCHAR(20) , 'id_distrib' INTEGER );
# --------------------------------------------------------


#
# Structure de la table: SATISFACTION
#
CREATE TABLE 'SATISFACTION' ( 'id_satisfaction' INTEGER PRIMARY KEY, 'easy_to_use' CHAR , 'cadence' CHAR , 'qualite_interv' CHAR , 'prix_maintenance' VARCHAR(6) , 'type_contrat' INT , 'garantie_duree' VARCHAR(2) , 'commentaire' TEXT );
# --------------------------------------------------------


#
# Structure de la table: SECTEUR
#
CREATE TABLE 'SECTEUR' ( 'id_secteur' INTEGER PRIMARY KEY, 'libelle' VARCHAR(50) );
# --------------------------------------------------------


#
# Structure de la table: USER
#
CREATE TABLE 'USER' ( 'id_user' INTEGER PRIMARY KEY, 'login' VARCHAR(8) , 'password' VARCHAR(10) , 'nom' VARCHAR(15) , 'prenom' VARCHAR(25) , 'statut' VARCHAR(25) );
INSERT INTO 'USER' ('id_user', 'login', 'password', 'nom', 'prenom' , 'statut') VALUES ('NULL', 'toto', 'toto', 'toto', 'toto', 'nada');
# --------------------------------------------------------


#
# Propriété de la fonction: IF
#
/*
function sqliteIf($compare, $good, $bad){ if ($compare) { return $good; } else { return $bad; } }
*/

#
# Propriété de la fonction: md5rev
#
/*
function md5_and_reverse($string) { return strrev(md5($string)); }
*/
