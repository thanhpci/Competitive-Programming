#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    int total_minutes = 0;
    for (int i = 0; i < N; i++) {
        int hours, minutes;
        cin >> hours >> minutes;
        total_minutes += hours * 60 + minutes;
    }

    int card_240_count = total_minutes / 240;
    total_minutes %= 240;

    int card_180_count = ceil((double)total_minutes / 180.0);

    double total_price = card_240_count * 10.90 + card_180_count * 9.15;

    int dong = (int)total_price;
    int xu = round((total_price - dong) * 100);

    cout << dong << "." << xu << endl;

    return 0;
}
