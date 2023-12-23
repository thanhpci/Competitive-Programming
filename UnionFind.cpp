#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1000 // Adjust size as needed

vector<int> pset(MAX_N);

void initSet(int size)
{
    for (int i = 0; i < size; i++)
        pset[i] = i;
}

int findSet(int i)
{
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

void unionSet(int i, int j)
{
    pset[findSet(i)] = findSet(j);
}

bool sameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

int main()
{
    // Example usage:
    int size = 5; // Number of elements
    initSet(size);

    // Suppose we want to union elements 0 and 1
    unionSet(0, 1);

    // Check if elements 2 and 3 are in the same set
    if (sameSet(2, 3))
    {
        cout << "Yes, 2 and 3 are in the same set." << endl;
    }
    else
    {
        cout << "No, 2 and 3 are not in the same set." << endl;
    }

    // Check if elements 0 and 1 are in the same set
    if (sameSet(0, 1))
    {
        cout << "Yes, 0 and 1 are in the same set." << endl;
    }
    else
    {
        cout << "No, 0 and 1 are not in the same set." << endl;
    }

    return 0;
}
