#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int width;
    int length;
    bool canPlaceOnTop(const Box& b) const {
        return width < b.width && length < b.length;
    }
};

int findMaxHeight(int currentHeight, const Box& lastBox, vector<Box>& remainingBoxes) {
    int maxHeight = currentHeight;

    for (int i = 0; i < remainingBoxes.size(); i++) {
        if (remainingBoxes[i].canPlaceOnTop(lastBox)) {
            Box currentBox = remainingBoxes[i];

            remainingBoxes.erase(remainingBoxes.begin() + i);
            maxHeight = max(maxHeight, findMaxHeight(currentHeight + 1, currentBox, remainingBoxes));

            remainingBoxes.insert(remainingBoxes.begin() + i, currentBox);
        }
    }

    return maxHeight;
}

int main() {
    int N;
    cin >> N;

    vector<Box> boxes(N);

    for (int i = 0; i < N; i++) {
        cin >> boxes[i].width >> boxes[i].length;
        if (boxes[i].width > boxes[i].length) {
            swap(boxes[i].width, boxes[i].length);
        }
    }

    Box initialBox = {1000000, 1000000}; 
    cout << findMaxHeight(0, initialBox, boxes) << endl;

    return 0;
}
