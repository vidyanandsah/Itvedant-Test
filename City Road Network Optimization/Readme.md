# Road Project Management
This program helps manage road construction projects. It allows you to:

Sort road projects by priority and cost.
Search for specific road projects by their unique identifier.
Determine the minimum set of roads needed to connect all areas in the city using the Minimum Spanning Tree (MST) concept.
Thought Process
When working with road construction projects, we have to make decisions based on two important factors: priority and cost. Higher priority projects should be handled first, but within the same priority level, cheaper projects are better. That’s why we decided to sort the projects first by priority (in descending order) and then by cost (in ascending order).

Once the projects are sorted, we use a search function to find a particular road project based on its unique identifier. This makes it easy to quickly locate any project in the sorted list.

Finally, we use the Minimum Spanning Tree (MST) algorithm to figure out the least number of roads needed to connect all the areas. The idea behind MST is to connect all areas with the minimum cost while avoiding unnecessary roads. We used Prim’s Algorithm for this, which is efficient and works by expanding the connection to the cheapest neighboring area. It’s like starting from one area and always picking the cheapest road to the next area until all areas are connected.

## Algorithms Used
## 1. Sorting:
We used Custom Sorting based on two factors:

Priority: Projects with higher priority should come first.
Cost: If two projects have the same priority, the cheaper one should come first.

## 2. Searching:
To search for a road project by its identifier, we simply loop through the list of projects. We compare each project’s identifier to the one we're looking for. If we find a match, we print its position in the sorted list; if not, we inform the user that the project wasn’t found.

## 3. Minimum Spanning Tree (MST):
We used Prim’s Algorithm for this. The algorithm helps us connect all areas with the minimum number of roads and lowest cost. We start with any area and pick the cheapest road to the next area. This process continues until all areas are connected.

## Why These Methods?
Sorting by priority and cost ensures that we handle the most important projects first and save money by picking the cheaper ones when priorities are the same.
Searching lets us quickly find any road project based on its ID, which is helpful when we need to look up specific information.
Prim’s Algorithm is ideal for finding the cheapest way to connect all areas. It’s efficient and guarantees that we use the least number of roads and lowest possible cost.
How to Use
Input the number of road projects.
Enter the details for each project: identifier, priority, cost, and the areas it connects.
The program will:
Sort and display the road projects based on priority and cost.
Allow you to search for a specific road project.
Calculate and display the minimum set of roads required to connect all areas.

# Time and Space Complexity of the Code
## 1. Sorting the Road Projects:
We are sorting the list of road projects based on two criteria: priority (descending) and cost (ascending).
The sorting step uses std::sort, which is an efficient sorting algorithm with an average and worst-case time complexity of O(N log N), where N is the number of road projects.
### Time Complexity of Sorting: O(N log N), where N is the number of road projects.
### Space Complexity of Sorting: O(N) for the space required to store the list of road projects.

## 2. Searching for a Road Project by its ID:
In the search function, we loop through the sorted list of road projects and compare each project’s identifier with the search input.
In the worst case, we might have to search through all N projects if the identifier is at the end or not present at all.
### Time Complexity of Searching: O(N), where N is the number of road projects.
### Space Complexity of Searching: O(1), as we are not using extra space, just scanning through the list.

## 3. Minimum Spanning Tree (MST) Calculation Using Prim’s Algorithm:
We use Prim's algorithm, which is implemented using a priority queue (std::priority_queue).
In each step, the algorithm pops the minimum edge from the priority queue, processes it, and updates the priority queue with adjacent nodes. This process repeats until all areas are connected.
The priority queue operations (push and pop) take O(log E) time, where E is the number of edges (roads).
For each road project, we do a constant amount of work to add edges to the priority queue. So, the overall time complexity for Prim’s algorithm is O(E log V), where E is the number of edges (roads) and V is the number of nodes (areas).
### Time Complexity of MST Calculation: O(E log V), where E is the number of roads and V is the number of areas.
### Space Complexity of MST Calculation: O(V + E), where V is the number of areas and E is the number of roads, since we store the adjacency list for all areas and the priority queue.

## 4. Overall Time and Space Complexity:
Overall Time Complexity:
Sorting: O(N log N)
Searching: O(N)
MST Calculation: O(E log V)
Total Time Complexity: O(N log N + E log V) (sorting + searching + MST calculation)
Overall Space Complexity:
Sorting: O(N)
Searching: O(1)
MST Calculation: O(V + E)
otal Space Complexity: O(N + V + E) (for storing road projects, adjacency list, and priority queue)
Summary:
# Time Complexity: O(N log N + E log V)
# Space Complexity: O(N + V + E)
Where:

N is the number of road projects.
E is the number of roads (edges).
V is the number of areas (nodes).

