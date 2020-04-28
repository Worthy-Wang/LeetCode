#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

/*
Time complexity: O(N)
Space complexity: O(1)
*/
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        int index = 1;
        for (int i = 2; i < nums.size(); i++)
        {   
            if (nums[index -1] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};



int main()
{
    vector<int> vec{1,1,2};
    Solution s;
    cout << s.removeDuplicates(vec) << endl;
    return 0;
}