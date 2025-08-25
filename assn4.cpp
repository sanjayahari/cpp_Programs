#include <iostream>   // for cout, cerr
#include <cmath>      // for log2
#include <string>     // for string
using namespace std;

// Function to decide line color based on intersections
string colorFor(int val, int threshold) {
    if (val == 0) return "green";
    else if (val <= threshold) return "blue";
    else return "red";
}

int main() {
    int n = 7;
    int perm[7] = {3, 7, 1, 5, 2, 6, 4};

    // Count intersections (simple O(n^2))
    int perSeg[7] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((perm[i] - perm[j]) * (i - j) < 0) {
                perSeg[i]++;
                perSeg[j]++;
            }
        }
    }

    int threshold = (int)floor(log2(n));

    // SVG setup
    int width = 600, height = 300;
    int margin = 50;
    int spacing = (width - 2 * margin) / (n - 1);
    int yTop = 50, yBottom = 250;

    int bottomX[8], topX[8];
    for (int i = 1; i <= n; i++) bottomX[i] = margin + (i - 1) * spacing;
    for (int i = 0; i < n; i++) topX[perm[i]] = margin + i * spacing;

    // Output SVG
    cout << "<svg xmlns='http://www.w3.org/2000/svg' width='" 
         << width << "' height='" << height + 40 << "'>\n";
    cout << "<rect width='100%' height='100%' fill='white'/>\n";

    // Draw connecting lines
    for (int i = 1; i <= n; i++) {
        cout << "<line x1='" << bottomX[i] << "' y1='" << yBottom
             << "' x2='" << topX[i] << "' y2='" << yTop
             << "' stroke='" << colorFor(perSeg[i - 1], threshold)
             << "' stroke-width='2'/>\n";
    }

    cout << "</svg>\n";

    // Debug marker (goes to console, not SVG if redirected)
    cerr << "----- END SVG -----" << endl;
    return 0;
}
