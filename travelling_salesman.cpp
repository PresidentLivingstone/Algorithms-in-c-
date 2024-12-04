#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateTourDistance(const vector<vector<int>>& dist, const vector<int>& tour) {
    int totalDist = 0;
    for (int i = 0; i < tour.size() - 1; i++) {
        totalDist += dist[tour[i]][tour[i + 1]];
    }
    totalDist += dist[tour[tour.size() - 1]][tour[0]]; // returning to the start city
    return totalDist;
}

int main() {
    // Distance matrix (cities are 0, 1, 2)
    vector<vector<int>> dist = {
        {0, 10, 15},
        {10, 0, 35},
        {15, 35, 0}
    };

    vector<int> cities = {0, 1, 2}; // City 0, City 1, City 2
    int minDist = INT_MAX;
    vector<int> bestTour;

    // Generate all permutations of the cities and check the distances
    do {
        int tourDist = calculateTourDistance(dist, cities);
        if (tourDist < minDist) {
            minDist = tourDist;
            bestTour = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    cout << "Minimum Distance: " << minDist << endl;
    cout << "Best Tour: ";
    for (int city : bestTour) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
