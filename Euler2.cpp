#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> Fibonacci({1,2});
    
    int sum_of_pairs;
    
    int n;
    int i = 2;
    
    do{
        n =Fibonacci[i-1] + Fibonacci[i-2];
        Fibonacci.push_back (n);
        if (n % 2 == 0){
            sum_of_pairs += n;
        }
        i+=1;
    } while (n<= 4000000);
    
    cout << sum_of_pairs+2 << endl ;
    return 0;
}

