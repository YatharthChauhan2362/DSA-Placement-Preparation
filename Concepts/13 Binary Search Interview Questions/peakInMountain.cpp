// Find Peek Element
// A peak element is an element that is strictly greater than its neighbors.
// You must write an algorithm that runs in O(log n) time.
#include <vector>
using namespace std;

class Solution
{
public:
	int find_peek(vector<int> arr)
	{
		int s = 0, e = arr.size() - 1;
		int mid = s + (e - s) / 2;
		while (s < e)
		{
			if (arr[mid] < arr[mid + 1])
				s = mid + 1;
			else
				e = mid;

			mid = s + (e - s) / 2;
		}
		return s;
	}
};
