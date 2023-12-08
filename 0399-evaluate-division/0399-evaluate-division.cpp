class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    // Function to build a graph where each edge represents a division equation
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0]; // Extract the numerator
            string v = equations[i][1]; // Extract the denominator
            double val = values[i];     // Extract the division value

            // Create edges in both directions (u/v and v/u)
            graph[u][v] = val;          // Edge from u to v with weight val
            graph[v][u] = 1.0 / val;    // Edge from v to u with weight 1/val
        }
    }

    // Depth-first search to find a path from start to end and calculate the result
    double dfs(const string& start, const string& end, unordered_set<string>& visited) {
        if (graph.find(start) == graph.end()) return -1.0; // If start is not in the graph, return -1.0

        // If there is a direct edge from start to end, return its value
        if (graph[start].find(end) != graph[start].end()) return graph[start][end];

        // Mark the start node as visited
        visited.insert(start);

        // Explore all neighbors of the start node
        for (auto& neighbour : graph[start]) {
            if (visited.find(neighbour.first) == visited.end()) { // If the neighbor is not visited
                double tempResult = dfs(neighbour.first, end, visited); // Recursively call dfs for the neighbor
                if (tempResult != -1.0) {
                    // If a valid path is found, multiply the edge value and return
                    return tempResult * neighbour.second;
                }
            }
        }

        // If no valid path is found, return -1.0
        return -1.0;
    }

    // Main function to process queries
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildGraph(equations, values); // Build the graph from equations
        vector<double> results;

        // Process each query
        for (auto& query : queries) {
            unordered_set<string> visited; // Set to keep track of visited nodes
            double result = dfs(query[0], query[1], visited); // Perform DFS to find the result of the query
            results.push_back(result); // Add the result to the results vector
        }

        return results; // Return the final results
    }
};