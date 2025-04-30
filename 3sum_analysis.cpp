#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <chrono>
#include <iostream>
using namespace std;


 
        vector<vector<int>> threeSum(vector<int>& nums) {
            set<vector<int>> sortedResult;
            vector<vector<int>> finalResult;
            for(int i = 0; i < nums.size(); i++){
                for (int j = i+1;  j < nums.size(); j++){
                    for(int k = j+1; k < nums.size(); k++){
                        if(nums[i] + nums[j] + nums[k] == 0 && i != j && i != k && j!= k){
                            vector<int> triple;
                            triple = {nums[i],nums[j], nums[k]};
                            sort(triple.begin(), triple.end());
                            sortedResult.insert(triple);
                        }
                    }
                }
            }
    
        for(vector<int> v:sortedResult){
            finalResult.push_back(v);
        }
            
    
       return finalResult;
        }


    vector<int> generateInput(int n){
        vector<int> nums;

        int a = rand() % 100 -50;
        int b = rand() % 100 -50;
        int c = - a - b;

        nums.push_back(a);
        nums.push_back(b);
        nums.push_back(c);

        while(nums.size() < n){
            nums.push_back(rand() % 100 -50);
        }
        return nums;
    }



int main(int argc, char const *argv[])
{
    for(int i =  100; i < 8000; i+= 100){
    vector<int> tester = generateInput(i);
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = threeSum(tester);
    auto end = chrono::high_resolution_clock::now();
    double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    cout << i << " "<< time_ms << endl;

}
    
    
    
    return 0;
}


