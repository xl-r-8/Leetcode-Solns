class Allocator {
    vector<int> memory;
    int msize;
public:
    Allocator(int n) {
        memory = vector<int>(n, 0); // Initialize with 0 (unallocated)
        msize=n;
    }
    
    int allocate(int size, int mID) {
        int ind=-1;
        int i=0;
        while(i<msize){
        // for(int i=0;i<msize; i++){
            if(memory[i]==0){
                bool okay=true;
                if(i+size>msize) return -1;
                for(int j=0; j<size;j++){
                    if(memory[i+j]!=0){
                        okay=false;
                        i+=j+1;
                        break;
                    }
                }
                if(okay){
                    ind=i;
                    for(int j=0; j<size;j++){
                        memory[i+j]=mID;
                    }
                    return ind;
                }
            }
            else i++;
        }
        return ind;
    }
    
    int freeMemory(int mID) {
        int count=0;
        int i=0;
        while(i<msize){
           if(memory[i]==mID){
            memory[i]=0;
            count++;
           }
           i++;
        }
        return count;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */