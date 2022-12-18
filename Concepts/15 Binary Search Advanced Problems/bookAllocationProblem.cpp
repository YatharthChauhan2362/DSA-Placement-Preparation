// Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks
// he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The
// day in Ayush's world has IOOAIOO seconds. There are some rules that are followed by
// Ayush while studying.
// 1. He reads the chapter in a sequential order, i.e. he studies i+lth chapter only after he
// studies ith chapter.
// 2. If he starts some chapter on a particular day he completes it that day itself.
// 3. He wants to distribute his workload over 'N' days, so he wants to minimize the
// maximum amount of time he studies in a day.
// Your task is to find out the minimal value of the maximum amount of time for which
// Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.

// Sample Input 1:
// 1
// 3 5
// 1 2 2 3 1

// Sample Output 1:
// 4

// Explanation Of Sample Input 1:
// The ayush will read the chapter as follows,
// Day 1 : 1 , 2         Time required : 3
// Day 2 : 3             Time required : 2
// Day 3 : 4 , 5         Time required : 4
// So the maximum time in a day is 4.

// Sample Input 2:
// 1
// 4 7
// 2 2 3 3 4 4 1

// Sample Output 2:
// 6

// Explanation Of Sample Input 2:
// The ayush will read the chapter as follows,
// Day 1 : 1 , 2          Time required : 4
// Day 2 : 3 , 4          Time required : 6
// Day 3 : 5              Time required : 4
// Day 4 : 6 , 7          Time required : 5
// So the maximum time in a day is 6.

#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    // cout << "checking for mid "<< mid <<endl;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
        if (studentCount > m)
        {
            return false;
        }
        // cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            // cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}