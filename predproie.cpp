#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main(){
    // Réduire le format d'affichage
    cout << setprecision(4);
    
    // Paramètres
    double taux_croissance_lapins(0.3);
    double taux_attaque(0.01);
    double taux_croissance_renards(0.008);
    double taux_mortalite(0.1);
    int duree(50);
    
    double renards_i(0.0);
    double lapins_i(0.0);
    
    // ===== PARTIE 1 =====
    // Saisie des populations initiales
    
    int depart_r(0.0);
    do {cout << "Combien de renards au départ (>= 2) ? ";
        cin >> depart_r;
    } while (depart_r < 2);
    
    int depart_l(0.0);
    do {cout << "Combien de lapins au départ  (>= 5) ? ";
        cin >> depart_l;
    } while (depart_l < 5);
    
    // ===== PARTIE 2 =====
    // Première simulation
    
    cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
    renards_i = depart_r;
    lapins_i = depart_l;
    for ( int i = 1; i <= 50; ++i) {
        double nb_lapins = lapins_i*(1.0 + taux_croissance_lapins - taux_attaque* renards_i);
        double nb_renards = renards_i*(1.0 + taux_attaque * lapins_i * taux_croissance_renards
                                       - taux_mortalite);
        if (nb_renards < 0) {
            nb_renards = 0;
        }
        if (nb_lapins < 0) {
            nb_lapins = 0;
        }
        
        if (nb_lapins == 0 && nb_renards == 0) {
            cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards
            << " renards" << endl;
            break;
        }
        
        cout << "Après " << i << " mois, il y a " << nb_lapins << " lapins et " << nb_renards
        << " renards" << endl;
        
        renards_i = nb_renards;
        lapins_i = nb_lapins;
    }
    
    // ===== PARTIE 3 =====
    // Variation du taux d'attaque
    cout << endl;
    
    double taux_attaque_i(0.0);
    do {cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
        cin >> taux_attaque_i;
    } while (taux_attaque_i > 6 || taux_attaque_i < 0.5);
    
    
    double taux_attaque_f(0.0);
    do {cout << "taux d'attaque à la fin  en % (entre " << taux_attaque_i;
        cout << " et 6) ? ";
        cin >> taux_attaque_f;
    } while (taux_attaque_f > 6 || taux_attaque_f < taux_attaque_i);
    
    
    
    for (double j(0.0); taux_attaque_i + j < taux_attaque_f; ++j){
        double taux_attaque = (taux_attaque_i+ j)/100;
        bool stabilite_renards = 1;
        bool stabilite_lapins = 1;
        bool remontee_renards = 0;
        bool remontee_lapins = 0;
        int counter = 1;
        double nb_lapins;
        double nb_renards;
        renards_i = depart_r;
        lapins_i = depart_l;
        
        cout <<  endl << "***** Le taux d'attaque vaut " << taux_attaque*100 << "%" <<  endl;
        
        do {    nb_lapins = lapins_i*(1.0 + taux_croissance_lapins - taux_attaque* renards_i);
            nb_renards = renards_i*(1.0 + taux_attaque * lapins_i * taux_croissance_renards
                                    - taux_mortalite);
            if (nb_renards < 2) {
                nb_renards = 0;
            }
            if (nb_lapins < 2) {
                nb_lapins = 0;
            }
            
            if (nb_renards < 5) {
                stabilite_renards = 0;
            }
            if (renards_i < 5 && nb_renards >5){
                remontee_renards = 1;
            }
            if (nb_lapins < 5) {
                stabilite_lapins = 0;
            }
            if (lapins_i < 5 && nb_lapins > 5){
                remontee_lapins = 1;
            }
            
            lapins_i = nb_lapins;
            renards_i = nb_renards;
            counter += 1;
        } while ((nb_lapins >= 2 || nb_renards >= 2) && counter <= duree );
        
        cout << "Après " << counter-1 << " mois, il y a " << nb_lapins << " lapins et " << nb_renards
        << " renards" << endl;
        
        
        
        if (stabilite_renards && stabilite_lapins){
            cout << "Les lapins et les renards ont des populations stables." << endl;
        }
        
        if (stabilite_renards == 0){
            cout << "Les renards ont été en voie d'extinction" << endl;
            if (remontee_renards == 1){
                cout << "mais la population est remontée ! Ouf !" << endl;
            } else {
                cout << "et les renards ont disparu :-(" << endl;
            }
        }
        if (stabilite_lapins == 0){
            cout << "Les lapins ont été en voie d'extinction" << endl;
            if (remontee_lapins == 1) {
                cout << "mais la population est remontée ! Ouf !" << endl;
            } else {
                cout << "et les lapins ont disparu :-(" << endl;
            }
        }
        
    }
    
    return 0;
}
