class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());

        if (geneBank.find(endGene) == geneBank.end()) return -1;

        queue<string> q;
        q.push(startGene);

        unordered_set<string> visited;
        visited.insert(startGene);

        int mutations = 0;

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                if (current == endGene) return mutations;

                for (int j = 0; j < current.size(); j++) {
                    char originalChar = current[j];
                    for (char gene : genes) {
                        current[j] = gene;
                        if (geneBank.find(current) != geneBank.end() && visited.find(current) == visited.end()) {
                            q.push(current);
                            visited.insert(current);
                        }
                    }
                    current[j] = originalChar;

                }
            }
            ++mutations;
        }
        return -1;
    }
};

   
