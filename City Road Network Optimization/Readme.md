### Road Project Management
This program helps manage road construction projects. It allows you to:

Sort road projects by priority and cost.
Search for specific road projects by their unique identifier.
Determine the minimum set of roads needed to connect all areas in the city using the Minimum Spanning Tree (MST) concept.
Thought Process
When working with road construction projects, we have to make decisions based on two important factors: priority and cost. Higher priority projects should be handled first, but within the same priority level, cheaper projects are better. That’s why we decided to sort the projects first by priority (in descending order) and then by cost (in ascending order).

Once the projects are sorted, we use a search function to find a particular road project based on its unique identifier. This makes it easy to quickly locate any project in the sorted list.

Finally, we use the Minimum Spanning Tree (MST) algorithm to figure out the least number of roads needed to connect all the areas. The idea behind MST is to connect all areas with the minimum cost while avoiding unnecessary roads. We used Prim’s Algorithm for this, which is efficient and works by expanding the connection to the cheapest neighboring area. It’s like starting from one area and always picking the cheapest road to the next area until all areas are connected.

## Algorithms Used
# 1. Sorting:
We used Custom Sorting based on two factors:

Priority: Projects with higher priority should come first.
Cost: If two projects have the same priority, the cheaper one should come first.

# 2. Searching:
To search for a road project by its identifier, we simply loop through the list of projects. We compare each project’s identifier to the one we're looking for. If we find a match, we print its position in the sorted list; if not, we inform the user that the project wasn’t found.

# 3. Minimum Spanning Tree (MST):
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

