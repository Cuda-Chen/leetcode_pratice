class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(!m.count(index)) {
            m[index] = number;
            mm[number].insert(index);
            return;
        }

        int num = m[index];
        mm[num].erase(index);
        m[index] = number;
        mm[number].insert(index);
    }
    
    int find(int number) {
        if(!mm.count(number) || mm[number].size() < 1)
            return -1;
        
        return *(mm[number].begin());
    }

private:
    unordered_map<int, int> m; // {idx, num}
    unordered_map<int, set<int>> mm; // {num, idxs (sorted)}
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
