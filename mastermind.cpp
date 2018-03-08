#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
    bool rightColor = false;
    const char couleurs[] = ".RGBCYM";
    for ( size_t i = 0 ; i < strlen(couleurs); i++ ){
        if ( c == couleurs[i] ){
            rightColor = true;
        }
    }
    return rightColor;
}

// ======================================================================
bool verifier(char c1, char& c2, int& score){
    bool istheSame= false;
    if ( c1 == c2 ) {
        istheSame = true;
        score += 1;
        c2 = 'x';
    }
    return istheSame;
}

// ======================================================================
void apparier(char c1, char& c2, char& c3, char& c4, int& score){
    bool test = verifier(c1, c2, score);
    if (!(test)){
        test = verifier(c1,c3, score);
        if (!(test)){
            verifier(c1,c4,score);
            
        }
    }
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4){
    const char guess[] = {r1,r2,r3,r4,'\0'};
    char correct[] = {c1,c2,c3,c4,'\0'};
    char code[] = "----";
    int correctNb = 0;
    for (size_t i =0; i < strlen(guess); i++ ){
        if (guess[i] == correct[i]){
            code[i] = '#';
            correct[i] = 'x';
            correctNb += 1;
        }
    }
    int score = 0;
    
    if(code[0] != '#'){      apparier(guess[0],correct[3], correct[1], correct[2], score);
    }
    if(code[1] != '#'){      apparier(guess[1],correct[0], correct[3], correct[2], score);
    }
    if(code[2] != '#'){      apparier(guess[2],correct[0], correct[1], correct[3], score);
    }
    if(code[3] != '#'){      apparier(guess[3],correct[0], correct[1], correct[2], score);
    }
    
    char code_final[] = "----";
    afficher(correctNb, '#');
    afficher(score,'+');
    afficher((4-(score+correctNb)), '-');
    
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{ if ( c1 == r1 && c2 == r2 && c3 == r3 && c4 == r4 ){
    return true;
} else {
    return false;
}
}

// ======================================================================
void jouer(int coup = 8)
{   char correct[] = "xxxx";
    for (size_t i = 0; i < strlen(correct); i++){
        correct[i]= tirer_couleur();
    }
    int coupsNb = coup;
    char guess[]= "xxxx";
    while ( !(gagne(guess[0], guess[1], guess[2], guess[3], correct[0], correct[1], correct[2], correct[3])) and coup-- ){
        for (size_t j = 0; j <strlen(guess); j++){
            guess[j]=lire_couleur();
        }
        afficher_coup(guess[0], guess[1], guess[2], guess[3], correct[0], correct[1], correct[2], correct[3]);
    }
    if (gagne(guess[0], guess[1], guess[2], guess[3], correct[0], correct[1], correct[2], correct[3])){
        message_gagne(coupsNb-coup);
    } else {
        message_perdu(correct[0], correct[1], correct[2], correct[3]);
    }
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
