#include <iostream>
using namespace std;

int main(){
    cout << "Donnez l'heure de début de la location (un entier) : ";
    int debut;
    cin >> debut;
    
    cout << "Donnez l'heure de fin de la location (un entier) : ";
    int fin;
    cin >> fin;
    int jour(0);
    int nuit(0);
    
    if ( debut > 24 || debut < 0 || fin < 0 || fin> 24 ){
        cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
        return 0;
    } else if ( debut == fin ){
            cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
        return 0;
    } else if ( debut > fin ){
            cout << "Bizarre, le début de la location est après la fin ..." << endl;
        return 0;
    } else {
            cout << "Vous avez loué votre vélo pendant" << endl;
            if (debut < 17 && fin > 7) {
                if(fin <= 17){
                    if (debut > 7 ){
                    jour = fin - debut;
                    } else {
                    jour = fin - 7;
                    }
                } else {
                    if (debut > 7 ){
                        jour = 17 - debut;
                    } else {
                        jour = 17 - 7;
                    }
                }
            }
    }
            nuit = fin - debut - jour;
            if (nuit > 0) {
                cout << nuit << " heure(s) au tarif horaire de " << 1 << " franc(s)" << endl;
            }
            if (jour > 0) {
            cout << jour << " heure(s) au tarif horaire de " << 2
            << " franc(s)" << endl;
            }
    
            int total = jour*2 + nuit;
            cout << "Le montant total à payer est de " << total << " franc(s)." << endl;
        
    return 0;
}
