class ProductOfNumbers {
    vector<int>nums={1};
    int n;
    int ind=-1;
public:
    ProductOfNumbers() {
        n=1;
        ind=-1;
    }
    
    void add(int num) {
        if(num==0) ind=n;
        if(nums.back()==0) nums.push_back(num);
        else nums.push_back(nums.back()*num);
        n++;
    }
    
    int getProduct(int k) {
        if(ind>=(n-k)) return 0;
        if(nums[n-k-1]==0) return nums[n-1];
        else return nums[n-1]/nums[n-k-1]; 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */