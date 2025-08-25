#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// distance between two points
double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// perimeter of triangle (i, j, k)
double perimeter(int i, int j, int k, const vector<double>& X, const vector<double>& Y) {
    return dist(X[i], Y[i], X[j], Y[j]) +
           dist(X[j], Y[j], X[k], Y[k]) +
           dist(X[k], Y[k], X[i], Y[i]);
}

// recursively reconstruct diagonals
void getDiagonals(int i, int j, const vector<vector<int>>& trace, vector<pair<int,int>>& diag) {
    int k = trace[i][j];
    if (k == -1) return;
    diag.push_back({i, j});
    getDiagonals(i, k, trace, diag);
    getDiagonals(k, j, trace, diag);
}

int main() {
    int n;
    cin >> n;   // number of vertices
    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }

    // DP table
    vector<vector<double>> f(n, vector<double>(n, 0));
    vector<vector<int>> trace(n, vector<int>(n, -1));

    for (int gap = 2; gap < n; gap++) {
        for (int i = 0; i + gap < n; i++) {
            int j = i + gap;
            f[i][j] = numeric_limits<double>::infinity();
            for (int k = i + 1; k < j; k++) {
                double cost = f[i][k] + f[k][j] + perimeter(i, k, j, X, Y);
                if (cost < f[i][j]) {
                    f[i][j] = cost;
                    trace[i][j] = k;
                }
            }
        }
    }

    cerr << "Minimum Ink = " << f[0][n - 1] << endl;

    // Reconstruct diagonals
    vector<pair<int,int>> diagonals;
    getDiagonals(0, n-1, trace, diagonals);

    // Print SVG directly to stdout
    int width = 600, height = 400;
    cout << "<svg xmlns='http://www.w3.org/2000/svg' width='" << width
         << "' height='" << height << "'>\n";
    cout << "<rect width='100%' height='100%' fill='white'/>\n";

    // Polygon edges
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        cout << "<line x1='" << X[i] << "' y1='" << Y[i]
             << "' x2='" << X[j] << "' y2='" << Y[j]
             << "' stroke='black' stroke-width='2'/>\n";
    }

    // Diagonals
    for (auto d : diagonals) {
        int i = d.first, j = d.second;
        cout << "<line x1='" << X[i] << "' y1='" << Y[i]
             << "' x2='" << X[j] << "' y2='" << Y[j]
             << "' stroke='red' stroke-dasharray='4'/>\n";
    }

    // Labels
    for (int i = 0; i < n; i++) {
        cout << "<circle cx='" << X[i] << "' cy='" << Y[i]
             << "' r='4' fill='blue'/>\n";
        cout << "<text x='" << X[i] + 8 << "' y='" << Y[i] - 8
             << "' font-size='14' fill='black'>" << i+1 << "</text>\n";
    }

    cout << "</svg>\n";

    return 0;
}
