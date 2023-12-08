
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create a graph using adjacency list representation
        vector<vector<int>> graph(numCourses);
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        // Arrays to keep track of visited and rescursion stack
        vector<bool> visited(numCourses, false), recStack(numCourses, false);

        // Check each course
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (isCyclic(i, graph, visited, recStack)) {
                    return false; // Cycle detected
                }
            }
        }

        return true; // No cycle detected
    }

    bool isCyclic(int curr,  const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recStack) {
        if (recStack[curr]) return true;

        if (visited[curr]) return false;

        visited[curr] = true;
        recStack[curr] = true;

        for (int neighbor : graph[curr]) {
            if (isCyclic(neighbor, graph, visited, recStack)) {
                return true;
            }
        }

        recStack[curr] = false;
        return false;
    }
};
