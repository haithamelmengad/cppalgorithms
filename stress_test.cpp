#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;
using std::cerr;


long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)numbers[i]) * ((long long)numbers[j]) > result) {
        result = ((long long)numbers[i]) * ((long long)numbers[j]);
      }
    }
  }
  return result;
}

long long MaxPairwiseProductFast (const vector<int>& numbers) {
    int n = numbers.size();
    int indexmax1 = -1;
    for (int i = 0; i < n; ++i) {
        if ( indexmax1 == -1 || numbers[i] - numbers[indexmax1] > 0) {
            indexmax1 = i;
        }
    }
    int indexmax2 = -1;
    for (int j = 0; j < n; ++j) {
        if ( (j != indexmax1) && (indexmax1 == -1 || (numbers[j] - numbers[indexmax2]) > 0)) {
            indexmax2 = j;
        }
    }
    return ((long long)(numbers[indexmax1]))* ((long long)(numbers[indexmax2]));
}

int main() {
    while (true) {
        int n = rand() % 10 + 2;
        cout << n << "\n";
        vector <int> a;
        for (int i=0; i<n; ++i) {
            a.push_back (rand() % 100000);
            cerr << a[i] << "\n";
        }
        long long slow = MaxPairwiseProduct(a);
        long long fast = MaxPairwiseProductFast(a);
        if (slow != fast){
            cerr<< "WRONG, this is slow:" << slow << "this is fast:" << fast << "\n";
            break;
        }
        else {
            cout << "cool" << "\n";
        }
    }

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    /* long long result = MaxPairwiseProduct(numbers);
    long long resultfast = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    cout << resultfast << "\n";
    return 0; */
}
