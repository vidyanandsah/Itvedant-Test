#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <set>

using namespace std;

// Structure to represent a road project
// Think of this as a "blueprint" for each road project, with its ID, priority, cost, and the areas it connects
struct RoadProject {
    string identifier;
    int priority;
    int cost;
    string area1, area2;
};

// Comparator for sorting the projects
// This function helps sort the projects in a way that's meaningful: higher priority first, lower cost second
bool compare(const RoadProject &a, const RoadProject &b) {
    if (a.priority != b.priority)
        return a.priority > b.priority; // Higher priority projects come first
    return a.cost < b.cost; // For the same priority, cheaper roads come first
}

// Function to search for a road project by its identifier
// Imagine you're looking for a specific road in the sorted list. This function does just that!
void searchRoadProject(const vector<RoadProject> &projects, const string &id) {
    for (size_t i = 0; i < projects.size(); i++) {
        if (projects[i].identifier == id) {
            cout << id << " found at position " << i + 1 << " in the sorted list." << endl;
            return;
        }
    }
    cout << id << " not found." << endl;
}

// Function to find the Minimum Connection Plan using Prim's Algorithm
// This is the magic function that connects all areas with the cheapest cost (if possible)
void minimumConnectionPlan(const vector<RoadProject> &projects) {
    // Build adjacency list for the graph

    unordered_map<string, vector<pair<int, string>>> adj;
    set<string> areas; // Keep track of all unique areas
    for (const auto &project : projects) {
        adj[project.area1].push_back({project.cost, project.area2});
        adj[project.area2].push_back({project.cost, project.area1});
        areas.insert(project.area1);
        areas.insert(project.area2);
    }

    // Use Prim's algorithm to find MST (Minimum Spanning Tree)
    unordered_map<string, bool> visited; // To keep track of which areas we've connected
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

    int totalCost = 0, roadCount = 0;

    // Start from an arbitrary area
    auto start = areas.begin(); // Pick the first area from the list
    pq.push({0, *start}); // Start with a cost of 0

    while (!pq.empty()) {
        auto [cost, area] = pq.top(); // Grab the cheapest road available
        pq.pop();

        if (visited[area]) continue; // Skip areas we've already connected

        visited[area] = true; // Mark this area as connected
        totalCost += cost; // Add the road cost to the total
        roadCount++; // Count the road as used

        // Explore all neighbors of this area
        for (const auto &[nextCost, nextArea] : adj[area]) {
            if (!visited[nextArea]) {
                pq.push({nextCost, nextArea}); // Add unvisited neighbors to the priority queue
            }
        }
    }

    // Check if we've managed to connect all areas
    if (visited.size() != areas.size()) {
        cout << "It is not possible to connect all areas." << endl;
        return;
    }

    // If we succeeded, print the results
    cout << "Minimum number of road projects needed: " << roadCount - 1 << endl; // Subtract 1 because we started with a dummy road
    cout << "Total cost of selected projects: " << totalCost << endl;
}

int main() {
    int n;
    cout << "Enter the number of road projects: ";
    cin >> n; // Input how many road projects we have

    vector<RoadProject> projects(n);

    // Input the road projects
    // We're going to collect all the road details here.
    cout << "Enter the details of road projects (ID Priority Cost Area1 Area2):\n";
    for (int i = 0; i < n; i++) {
        cin >> projects[i].identifier >> projects[i].priority >> projects[i].cost >> projects[i].area1 >> projects[i].area2;
    }

    // Sort the projects based on priority and cost
    // Now, let's organize the road projects in a way that makes sense (priority + cost).
    sort(projects.begin(), projects.end(), compare);

    // Output the sorted list
    // Here's what the sorted list looks like.
    cout << "Sorted list of road projects:\n";
    for (const auto &project : projects) {
        cout << project.identifier << " " << project.priority << " " << project.cost << " " << project.area1 << " " << project.area2 << endl;
    }

    // Search for a specific road project
    // Time to play detective and search for a specific road project by its ID.
    string searchId;
    cout << "Enter the road project ID to search: ";
    cin >> searchId;
    searchRoadProject(projects, searchId);

    // Determine the Minimum Connection Plan
    // Finally, let's find the cheapest way to connect all areas (if possible).
    minimumConnectionPlan(projects);

    return 0;
}
