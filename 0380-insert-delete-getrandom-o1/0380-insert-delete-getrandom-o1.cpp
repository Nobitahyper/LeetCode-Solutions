class RandomizedSet {
public:
    unordered_map<int, int> valToIndex;
    vector<int> values;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
      if (valToIndex.find(val) != valToIndex.end())
      {
          return false;
      }
      values.push_back(val);
      valToIndex[val] = values.size() - 1;
      return true;
    }
    
    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end())
        {
            return false;
        }
        int last = values.back();
        valToIndex[last] = valToIndex[val];
        values[valToIndex[val]] = last;
        values.pop_back();
        valToIndex.erase(val);
        return true;

    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */