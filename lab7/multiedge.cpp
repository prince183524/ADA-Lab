#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    set<pair<int, int>> edgeSet;
    bool hasMultiEdge = false;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v); 
        pair<int, int> edge = {u, v};
        if (edgeSet.count(edge)) {
            cout << "Multiedge detected between " << u << " and " << v << endl;
            hasMultiEdge = true;
        } else {
            edgeSet.insert(edge);
        }
    }

    if (!hasMultiEdge) {
        cout << "No multiedges found." << endl;
    }

    return 0;
}