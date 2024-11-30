# Maximum Movies Problem 
## Problem Overview
The task at hand is to find the maximum number of "movies" (pairs of superstars) that can be created based on collaboration preferences. Each movie must consist of exactly two superstars who are willing to work together, and each superstar can only participate in one movie. The solution needs to maximize the number of valid movie pairs while respecting these conditions.

## Thought Process
To solve this problem, we can think of it as a matching problem in a graph. Each superstar is a node, and an edge between two nodes represents that the two superstars are willing to collaborate. The goal is to form as many valid pairs (movies) as possible. Since no superstar can be part of more than one movie, this becomes a maximum matching problem.

## Why DFS?
To find valid matches (pairs of superstars), I used Depth First Search (DFS). DFS is great for searching through the graph. It tries to find a path (or match) by going deeper from one node to another. Once a match is found, it returns back and tries to find more matches for other superstars. This allows us to explore all potential pairings efficiently.

## Matching and Bipartite Graphs
The problem can be seen as a bipartite graph problem, where the goal is to pair nodes (superstars) from one side with nodes on the other side. While this problem is not strictly bipartite, it still benefits from the idea of pairing up nodes (superstars) as we would in a bipartite graph.

We used DFS to try and match a superstar with another superstar in a way that no superstar is involved in more than one pair. The match process continues until we’ve either matched all possible pairs or exhausted all possibilities.

## Time Complexity Consideration
Since we need to check all possible edges (collaborations) to form valid pairs, the time complexity is proportional to the number of superstars (nodes) and their preferences (edges). This makes the solution O(N * E), where 
N is the number of superstars and E is the number of edges (collaborations).

## Final Complexity Summary
### Time Complexity: O(N⋅E)
### Space Complexity: O(N+E)

## Why This Approach?
Efficiency: DFS is chosen because it allows us to explore potential matches quickly and backtrack when necessary.
Simplicity: The graph representation (adjacency list) is straightforward, and using DFS to find a maximum matching is a known approach that works well for this type of problem.
Realistic Constraints: The approach ensures that no superstar is reused in multiple movies, and it correctly handles all edge cases.

## Capping the Result
In some cases, we can’t have more than 𝑁/2
N/2 pairs because there are only N superstars, and each superstar can only participate in one movie. So, the final result is capped at min (maxPairs,N/2), ensuring that the answer never exceeds the number of possible pairs.

## Code Explanation
Input Handling: First, we input the number of superstars and their collaboration preferences. The preferences are stored in an adjacency list (graph), where each superstar's list contains the other superstars they are willing to work with.

DFS for Matching: We attempt to find matches for each superstar. For each unmatched superstar, we call dfs() to try and pair them with another superstar. If a valid match is found, we update the match array to record the pair.

Result Calculation: After attempting to find all possible matches, we return the maximum number of valid movies (pairs), which is capped at N/2.
