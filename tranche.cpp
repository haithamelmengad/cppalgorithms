
#include <iostream>

#include <iostream>
#include <vector>
#include <array>

using namespace std;

int somme_consecutifs_max (vector <int> ligne){
    int current_sum = 0;
    int highest_sum = 0;
    for (auto element : ligne) {
        if (element != 0){
            current_sum += element;
            if (current_sum > highest_sum){
                highest_sum = current_sum;
            }
        } else {
            current_sum = 0;
        }
    }
    return highest_sum;
}

vector <size_t> lignes_max (vector<vector<int> > tableau){
    vector <size_t> lignes_result;
    int highest_sum = 0;
    for (size_t i = 0; i < tableau.size(); ++i) {
        vector <int> ligne = tableau[i];
        int current_sum = somme_consecutifs_max(ligne);
        if (current_sum == highest_sum ){
            lignes_result.push_back(i);
        } else if ( current_sum > highest_sum) {
            highest_sum = current_sum;
            lignes_result.clear();
            lignes_result.push_back(i);
        }
    }
    return lignes_result;
}

vector<vector<int> > tranches_max (vector <vector<int> > tableau) {

bool isEmpty = true;
for (auto ligne : tableau){
    for(auto element : ligne){
        if ( element != 0){
            isEmpty = false;
        }
    }
}
if (isEmpty == true ){
    return tableau;
    } else {
        vector<vector<int> > tranches_result;
        vector <size_t> indices = lignes_max(tableau);
        for ( size_t i = 0; i < indices.size(); ++i){
            tranches_result.push_back(vector <int> ());
            size_t index = indices[i];
            for ( size_t j = 0; j < tableau[index].size(); ++j){
                int number = tableau[index][j];
                tranches_result[i].push_back(number);
            }
        }
        return tranches_result;
    }
}

int main(){
    vector <vector<int> > tableauTest (  { { 2, 1, 0, 2, 0, 3, 2 }, { 0, 1, 0, 7, 0 }, { 1, 0, 1, 3, 2, 0, 3, 0, 4 }, { 5, 0, 5 }, { 1, 1, 1, 1, 1, 1, 1 } } );
    tableauTest = tranches_max(tableauTest);
    for (auto ligne : tableauTest){
        for(auto element : ligne ){
            cout << element << " ;" ;
        }
        cout << endl;
    }
}
