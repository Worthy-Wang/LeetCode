#include <iostream>
#include <vector>
#include <algorithm>
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
        if (nums.empty())
            return 0;
        int index = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[index] != nums[i])
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