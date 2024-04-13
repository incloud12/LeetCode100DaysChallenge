class DinnerPlates {
public:
    DinnerPlates(int capacity) : capacity{capacity} {}
    
    void push(int val) {
        if (holes.size() == 0) {
            if (stacks.size() % capacity == 0) {
                stackSizes.push_back(1);
            } else {
                stackSizes.back()++;
            }
            stacks.push_back(val);
        } else {
            int pos = *holes.begin();
            holes.erase(holes.begin());
            stacks[pos] = val;
            stackSizes[pos / capacity]++;
        }
    }
    
    int pop() {
        if (stacks.size() == 0) {
            return -1;
        }
        int val = stacks.back();
        stacks.pop_back();
        if (stacks.size() % capacity == 0) {
            stackSizes.pop_back();
        } else {
            stackSizes.back()--;
        }
        while (stacks.size() > 0 && stacks.back() == 0) {
            stacks.pop_back();
            holes.erase(holes.find(stacks.size()));
            if (stacks.size() % capacity == 0) {
                stackSizes.pop_back();
            }
        }
        return val;
    }
    
    int popAtStack(int index) {
        if (index >= stackSizes.size() || stackSizes[index] == 0) {
            return -1;
        }
        if (index + 1 == stackSizes.size()) {
            return pop();
        }
        int pos = capacity * index + stackSizes[index] - 1;
        int val = stacks[pos];
        stacks[pos] = 0;
        holes.insert(pos);
        stackSizes[index]--;
        return val;
    }

private:
    vector<int> stacks;
    vector<int> stackSizes;
    set<int> holes;
    int capacity;
};
