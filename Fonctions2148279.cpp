#include "Fonctions2148279.h"
char choix;


void afficherMenu()    // Affiche le menu de sélection
{
   system("cls");

   cout << setfill('-') << setw(28) << "-" << " Calendrier Grégorien " << setfill('-') << setw(28) << "-" << endl;
   cout << setfill('-') << setw(24) << "-" << " présenté par  Olivier Nadeau " << setfill('-') << setw(24) << "-" << endl << endl;;
   cout << "  1. Afficher les informations d'un mois et d'une année donnée" << endl;
   cout << "  2. Afficher le calendrier mensuel d'un mois et d'une année donnée" << endl;
   cout << "  3. Afficher le calendrier trimestriel d'un mois et d'une année donnée" << endl;
   cout << "  4. Afficher le calendrier complet d'une année donnée" << endl;
   cout << "  5. Quitter le programme" << endl << endl;

   cout << setfill('-') << setw(78) << "-" << endl;
   cout << setfill(' ') << setw(0) << " " << endl;        // Retirer le caractère de remplacement 
   cout << "Votre choix --> ";
 }

int validerChoixMenu(char min, char max)   // Valide si le choix est entre 1 et 5 
{
   cin >> choix;
   while (!(choix >= min && choix <= max)) // tant que choix n'est pas entre min et max, on recommence
   {

      cout << "Erreur : Le choix n'est pas valide. Il doit être compris entre 1 à 5" << endl;

      system("pause > null");

      afficherMenu();
      cin >> choix;
   }   
  
   return choix;
   cout << endl;
}




int demanderAnnee()  // Demmande l'année
{
   system("cls");
   int annee;

   cout << "Veuillez indiquer l'année : " << endl;
   cin >> annee;

   while (annee <= 1581)   // Tant que l'année n'est pas plus grande que 1582, on recommence 
   {     
      system("cls");
      cout << "Erreur : L'année doit être supérieure ou égale à 1582." << endl;
      system("pause > null");
      system("cls");
      cout << "Veuillez indiquer l'année : " << endl;
      cin >> annee;      
   }  

   return annee;
}

int demanderMois()    // Demande le mois
{
   system("cls");
   int mois;
   cout << "Veuillez indiquer le numéro du mois : " << endl;
   cin >> mois;

   while (mois < 0 || mois > 11)  // tant que le mois n'est pas compris entre 0 et 11, on recommence
   {
      system("cls");
      cout << "Erreur: Le numéro du mois doit être compris entre 1 et 12." << endl;
      system("pause > null");
      system("cls");
      cout << "Veuillez indiquer le numéro du mois : " << endl;
      cin >> mois;
   }

   return mois;
}




void afficherInfoMois(int annee, int mois)   // Affiche les information d'une année et d'un mois donné
{
   system("cls");
   mois--;
   int jour;

   string jourSemaine[] = { "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };

   int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   int nbJoursMois[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
   string listeMois[] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin",
                        "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

   int y = annee - 1;
   long int premierJour = (y + y / 4 - y / 100 + y / 400 + t[mois] + 1) % 7;  // Calcul pour connaitre la position du premier jour du mois


   if (annee % 4 == 0 || (annee % 4 == 0 && annee % 100 != 0))     // Si l'année est bisxtile
   {
      if (premierJour > 6)
      {
         premierJour = 0;
      }
      else if (premierJour != 6)
      {
         premierJour++;
      }

      if (mois==1)
      {
         cout << "------------------------ " << listeMois[mois] << " - " << annee << "------------------------" << endl << endl;
         cout << "Le premier jour du mois est un " << jourSemaine[premierJour] << endl;
         cout << "Ce mois contient 29 jours." << endl << endl;
         cout << "------------------------------------------------------------" << endl << endl;
      }
      else
      {
         if (premierJour > 6)
         {
            premierJour = 0;
         }
         else if (premierJour != 6)
         {
            premierJour++;
         }
      cout << "------------------------ " << listeMois[mois] << " - " << annee << "------------------------" << endl << endl;
      cout << "Le premier jour du mois est un " << jourSemaine[premierJour] << endl;
      cout << "Ce mois contient " << nbJoursMois[mois] << " jours." << endl << endl;
      cout << "------------------------------------------------------------" << endl << endl;
      }
   }
   else
   {
      if (premierJour > 6)
      {
         premierJour = 0;
      }
      else if (premierJour != 6)
      {
         premierJour++;
      }

      
      cout << "------------------------ " << listeMois[mois] << " - " << annee << "------------------------" << endl << endl;
      cout << "Le premier jour du mois est un " << jourSemaine[premierJour] << endl;
      cout << "Ce mois contient " << nbJoursMois[mois] << " jours." << endl << endl;
      cout << "------------------------------------------------------------" << endl << endl;
   }
   
   /*cout << mois << endl;
   cout << premierJour << endl;
   cout << listeMois[mois] << endl;
   cout << nbJoursMois[mois] << endl << endl;*/

   jourSemaine->clear();
   system("pause > null");
}







void afficherCalendrierMensuel(int annee, int mois, bool affichagePause, bool clearScreen)    // Affiche le calendrier d'un mois donné
{
   if (clearScreen)
   {
      system("cls");
   }
   int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };     
   int nbJoursMois[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
   string listeMois[] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin",
                        "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

   cout << "  --------------------------------" << endl;
   cout << "   Calendrier - Mensuel - " << annee << endl;
   cout << "  --------------------------------" << endl;
   int jours;
   int premierJour;

   mois--;

   int y = annee - 1;
   premierJour = (y + y / 4 - y / 100 + y / 400 + t[mois]+1) % 7;     // Calcul pour connaitre la position du premier jour du mois

   if (premierJour > 6)
   {
      premierJour = 0;
   }
   else if (premierJour != 6)
   {
      premierJour++;
   }

   
         if (annee % 4 == 0 || (annee % 4 == 0 && annee % 100 != 0))       // Si l'année est bisxtile
            jours = 29;
         else
            jours = nbJoursMois[mois];

      cout << endl << "  ------------" << listeMois[mois] << "-------------" << endl;

      cout << "  Dim  Lun  Mar  Mer  Jeu  Ven  Sam  " << endl;

      int k;                                                  // affichage des jours dans les bonnes colonnes
      for (k = 0; k < premierJour; k++)
        cout << "     ";

      for (int j = 1; j <= jours; j++)
      {
         k++;
         cout << setw(5) << j;
         if (k > 6)
         {
            k = 0;
            cout << endl;
         }
      }

      if (k)
         cout << endl;

      premierJour = k;

      cout << "  ----------------------------------" << endl << endl;
   

      if (affichagePause)
      {
         system("pause > null");
      }
      return;
}








void afficherCalendrierTrimestriel(int annee, int mois)       //affiche un calendrier Trimestriel(3 mois)
{
   mois--;
   system("cls");
   int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   int nbJoursMois[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
   string listeMois[] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin",
                        "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

   cout << "  --------------------------------" << endl;
   cout << "   Calendrier - Trimestriel - " << annee << endl;
   cout << "  --------------------------------" << endl;
   int jours;
   int premierJour;   

   int y = annee - 1;
   premierJour = (y + y / 4 - y / 100 + y / 400 + t[mois] + 1) % 7;    // Calcul pour connaitre la position du premier jour du mois

      mois - 2;

      


      for (int i = 0; i < 3; i++)
      {

      if (premierJour > 6)
      {                                                    
         premierJour = 0;
      }
      else if (premierJour != 6)
      {
         premierJour++;
      }


      if (annee % 4 == 0 || (annee % 4 == 0 && annee % 100 != 0))
         jours = 29;
      else
      {
         jours = nbJoursMois[mois];
      }

      cout << endl << "  ------------" << listeMois[mois-1] << " " << annee << "------------" << endl;

      cout << "  Dim  Lun  Mar  Mer  Jeu  Ven  Sam  " << endl;

      int k;                                                       // affichage des jours dans les bonnes colonnes
      for (k = 0; k < premierJour-1; k++)
         cout << "     ";

      for (int j = 1; j <= jours; j++)
      {
         k++;
         cout << setw(5) << j;
         if (k > 6)
         {
            k = 0;
            cout << endl;
         }
      }

      if (k)
         cout << endl;

      premierJour = k;

      cout << "  ----------------------------------" << endl;

      mois++;
      

   }

   system("pause > null");
   return;
}








void afficherCalendrierAnnuel(int annee)                         // Affiche le calendrier annuel d'une année donnée
{
   system("cls");

   int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   int nbJoursMois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
   string listeMois[] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin",
                        "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };


   cout << "  --------------------------------" << endl;
   cout << "           Calendrier - " << annee << endl;
   cout << "  --------------------------------" << endl << endl;
   int jours;
   int courante;

   int y = annee - 1;
   courante = (y + y / 4 - y / 100 + y / 400 + t[0] + 1) % 7;    // // Calcul pour connaitre la position du premier jour du mois

   for (int i = 0; i < 12; i++)
   {
      int nbc = 28 - (listeMois[i].size() + 4);

      if (i == 1)
         if (annee % 400 == 0 || (annee % 4 == 0 && annee % 100 != 0))
            jours = 29;
         else
            jours = nbJoursMois[i];
      else
         jours = nbJoursMois[i];


      cout << "  " << setfill('-') << setw(nbc / 2) << "-" << " " << listeMois[i] << " " << annee << " " << setw(nbc / 2) << "-" << endl;
      cout << setfill(' ') << setw(0) << " " << endl;  // Retirer le caractère de remplacement 

      cout << "  Dim  Lun  Mar  Mer  Jeu  Ven  Sam" << endl;

      int k;                                                    // affichage des jours dans les bonnes colonnes
      for (k = 0; k < courante; k++)
         cout << "     ";

      for (int j = 1; j <= jours; j++)
      {
         k++;
         cout << setw(5) << j;
         if (k > 6)
         {
            k = 0;
            cout << endl;
         }
      }

      if (k)
         cout << endl;

      courante = k;

      cout << "  ---------------------------------" << endl;
      system("pause > null");
      system("cls");
   }

   system("pause > null");
   return;   
}


// Fin du code