#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int getMedian(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return getMedian(nums2, nums1);
    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0;
    int high = n1;
    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if (l1 <= r2 and l2 <= r1)
        {
            if (n1 + n2 % 2 == 0)
                return max(l1, l2) + min(r1, r2) / 2.0;
            else
            {
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.00;
}

int main()
{

    int v1;
    cout << "enter the no of elements for vector 1" << endl;
    cin >> v1;
    int v2;
    cout << "enter the no of elements for vector 2" << endl;
    cin >> v2;
    vector<int> v1Array(v1);
    vector<int> v2Array(v2);
    for (int i = 0; i < v1; i++)
    {
        int temp;
        cout << "enter the elements of v1 in" << i << " th place" << endl;
        cin >> temp;
        v1Array[i] = temp;
    }
    for (int i = 0; i < v2; i++)
    {
        int temp;
        cout << "enter the elements of v2 in" << i << " th place" << endl;
        cin >> temp;
        v2Array[i] = temp;
    }

    int ans = getMedian(v1Array, v2Array);
    cout << "the median of the two arrays is " << ans << endl;

    return 0;
}