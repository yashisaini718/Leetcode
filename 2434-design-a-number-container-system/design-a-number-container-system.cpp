class NumberContainers {
    map<int,int> numIndex;
    map<int,set<int>> indNum;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(numIndex.find(index)!=numIndex.end()){
            indNum[numIndex[index]].erase(index);
            if(indNum[numIndex[index]].size()==0){
                indNum.erase(numIndex[index]);
            }
        }
        numIndex[index]=number;
        indNum[number].insert(index);
    }
    
    int find(int number) {
        if(indNum.find(number)==indNum.end()){
            return -1;
        }
        return *(indNum[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */