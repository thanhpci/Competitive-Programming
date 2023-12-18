
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findPermutation(int n, int k) {
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }
    
    if (k == 0) {
        return array;
    }
    
    for (int i = n - 1; i > 0; --i) {
        if (k >= i) {
            reverse(array.end() - i - 1, array.end());
            k -= i;
        }
        
        if (k == 0) {
            break;
        }
    }
    
    if (k > 0) {
        reverse(array.end() - k - 1, array.end() - k + 1);
    }
    
    return array;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> permutation = findPermutation(n, k);
    
    for (int num : permutation) {
        cout << num << ' ';
    }
    cout << endl;
    
    return 0;
}
