class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Graph representation using adjacency list and in-degree array
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        // Building the graph
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        // Queue for nodes with zero in-degree
        queue<int> zeroInDegree;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                zeroInDegree.push(i);
            }
        }

        vector<int> order;
        while (!zeroInDegree.empty()) {
            int current = zeroInDegree.front();
            zeroInDegree.pop();
            order.push_back(current);

            // Decreasing in-degree of adjacent nodes
            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegree.push(neighbor);
                }
            }
        }

        // If all courses are included in the order, return it
        if (order.size() == numCourses) {
            return order;
        }

        // If not all courses are included, a cycle exists
        return {};
    }
};

