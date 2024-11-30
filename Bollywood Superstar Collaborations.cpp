#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

// Function to perform DFS and try to find an augmenting path for matching
bool dfs(int node, vector<vector<int>>& graph, vector<int>& match, vector<bool>& visited) {
    // Loop through all the collaborators (neighbors) of the current node
    for (int neighbor : graph[node]) {
        // If the neighbor is already visited in this DFS call, skip it
        if (visited[neighbor]) continue;
        visited[neighbor] = true;

        // If the neighbor is not matched yet or we can rematch its current partner
        if (match[neighbor] == -1 || dfs(match[neighbor], graph, match, visited)) {
            // If a match is found, assign the current node to the neighbor and vice versa
            match[node] = neighbor;
            match[neighbor] = node;
            return true;
        }
    }
    return false;  // No match found for this node
}

// Function to calculate the maximum number of movies (pairs of superstars)
int maxMovies(int n, vector<vector<int>>& preferences) {
    // Graph to store collaboration preferences (adjacency list)
    vector<vector<int>> graph(n + 1);  // Superstars are 1-indexed
    for (int i = 0; i < n; ++i) {
        for (int neighbor : preferences[i]) {
            graph[i + 1].push_back(neighbor);  // Add each collaboration to the graph
        }
    }

    // Array to track who each superstar is paired with (match array)
    vector<int> match(n + 1, -1);  // -1 means no current match
    int maxPairs = 0;  // To count the total number of valid pairs (movies)

    // Try to match each superstar with another one
    for (int i = 1; i <= n; ++i) {
        // If the current superstar is not yet matched, try to find a match using DFS
        vector<bool> visited(n + 1, false);  // Array to keep track of visited superstars
        if (match[i] == -1 && dfs(i, graph, match, visited)) {
            // If a valid match is found, increment the pair count
            ++maxPairs;
        }
    }

    // The result can't exceed N/2, since we can form at most N/2 pairs
    return min(maxPairs, n / 2);  // Ensure we don't have more pairs than N/2
}

int main() {
    // Input the number of superstars
    int n;
    cin >> n;

    // Input the collaboration preferences for each superstar
    vector<vector<int>> preferences(n);  // List to store preferences for each superstar
    cin.ignore();  // To ignore any leftover newline character after reading n

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);  // Read the entire line of collaboration preferences
        int neighbor;
        size_t pos = 0;

        // Split the line into individual superstar preferences
        while ((pos = line.find(' ')) != string::npos) {
            neighbor = stoi(line.substr(0, pos));  // Convert the number to an integer
            preferences[i].push_back(neighbor);    // Add this preference to the current superstar's list
            line.erase(0, pos + 1);  // Remove the processed part of the string
        }
        // Add the last preference if there's any remaining
        if (!line.empty()) {
            preferences[i].push_back(stoi(line));  // Convert and add the last superstar's preference
        }
    }

    // Compute the maximum number of movies (pairs of superstars)
    cout << maxMovies(n, preferences) << endl;  // Output the result
    return 0;
}


