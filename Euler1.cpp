//
//  Euler 1.cpp
//  
//
//  Created by H on 10/3/17.
//
//

#include <iostream> // input/output stream
#include <math.h> // use remainder operator

using std::cin; // Standard input
using std::cout; // Standard output

// Main function takes in a given integer n
// Returns the sum of multiples of 3 and 5 inferior to n
int main () {
    
    // Variables
    int multiples = 0;
    int n;
    // User input
    cin >> n;
    
    // Look for multiples
    for (int i = 0; i < n; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            multiples += i;
        }
    }
    // Machine output
    cout << "Your sum is : \n" << multiples << "\n";
}
