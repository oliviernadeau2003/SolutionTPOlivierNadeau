// But : Afficher un calendrier avec les jours de la semaine, mois par mois en utilisant les fonctions
// Le programme affiche un menu offrant les choix suivants :
// 1. Afficher les informations d'un mois et d'une ann�e donn�e
// 2. Afficher le calendrier d'un mois et d'une ann�e donn�e
// 3. Afficher le calendrier du mois pr�c�dent, du mois courant et du mois suivant d'un mois et d'une ann�e donn�e
// 4. Afficher le calendrier complet d'une ann�e donn�e
// Auteur : Karine Moreau
// Date : 2021-10-14

#include "Fonctions2148279.h"

int main()
{
   setlocale(LC_ALL, "");
   // D�claration des variables
   char choix;
   int annee;
   int mois;

   afficherMenu();
   choix = validerChoixMenu('1', '5');

   // Tant que le choix de l'utilisateur n'est pas de quitter, le programme recommence
   while (choix != '5')
   {
      // Dans tous les cas le programme doit demander une ann�e
      annee = demanderAnnee();
      if (choix != '4')
         mois = demanderMois();

      // Selon le choix que l'utilisateur a fait, le programme appelle la bonne fonction
      switch (choix)
      {
      case '1':
         afficherInfoMois(annee, mois);
         break;
      case '2':
         afficherCalendrierMensuel(annee, mois, true, true);
         break;
      case '3':
         afficherCalendrierTrimestriel(annee, mois);
         break;
      case '4':
         afficherCalendrierAnnuel(annee);
         break;
      }
      afficherMenu();
      choix = validerChoixMenu('1', '5');
   }
   system("pause");
   return 0;
}