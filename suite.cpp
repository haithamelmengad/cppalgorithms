#include <iostream>
using namespace std;

int main()
{
    int debut(0);
    do {
        cout << "de (>= 1) ? ";
        cin >> debut;
    } while (debut < 1);
    
    int fin(0);
    do {
        cout << "a (>= " << debut << ") ? ";
        cin >> fin;
    } while (fin < debut);
    
    
    for(int i(debut); i <= fin; ++i){
        int counter = 0;
        int n = i;
        
        do { if ( n % 3 == 0 ) {
    
                n += 4;
                counter += 1;
            
            } else if ( n % 4 == 0 ){
                
                n /= 2;
                counter += 1;
                
            } else {
                
                n -= 1;
                counter += 1;
            }
        } while (n != 0);
        
        cout << i << "->" << counter << endl;
    }
    return 0;
}
