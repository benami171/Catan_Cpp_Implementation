#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int N = 6; // Size of the matrix
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Example positions for settlements/cities
    vector<pair<int, int>> settlements = {
        {0, 0}, {0, 3}, {0, 5},
        {1, 2}, {1, 4},
        {2, 1}, {2, 3}, {2, 5},
        {3, 0}, {3, 2}, {3, 4},
        {4, 1}, {4, 3}, {4, 5},
        {5, 0}, {5, 2}, {5, 4}
    };

    // Place settlements in the matrix
    for (auto &pos : settlements) {
        int i = pos.first;
        int j = pos.second;
        board[i][j] = 1;
    }

    // Print the matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}