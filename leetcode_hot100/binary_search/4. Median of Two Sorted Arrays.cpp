class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0) { // 偶数情况：取中间两个数的平均值
            int left = find(nums1, 0, nums2, 0, total/2);
            int right = find(nums1, 0, nums2, 0, total/2 + 1);
            return (left + right) / 2.0; // 需要得到float，所以用2.0
        } else { // 奇数情况：直接取中位数
            return find(nums1, 0, nums2, 0, total/2 + 1);
        }
    }

    // nums1 从 x 开始找
    // nums2 从 y 开始找
    // 找到第k小的数
    int find(vector<int>& nums1, int x, vector<int>& nums2, int y, int k) {
        // 确保前一个数组size更小，这样只需要检查nums1是否数组越界
        if (nums1.size() - x > nums2.size() - y)
            return find(nums2, y, nums1, x, k);
        
        // 已经递归到第k个值，可以出结果了
        if (k == 1 && x < nums1.size()) {
            return min(nums1[x], nums2[y]);
        }

        // 如果nums1已经用完了，那就只需要线性遍历nums2
        if (x == nums1.size()) {
            return nums2[y+k-1];
        }

        // 每次把两个数组往后推k/2得到新下标：x+k/2和y+k-k/2（注意这里有除不尽的情况，不能直接写成k/2）
        // 因为测算k的时候包括原本x,y的位置，所以要-1才是新下标nx,ny
        // 推完之后更大的那个数组保留(目标值可能在这截儿)，推完之后更小的那个数组可以删掉一截k/2
        int nx = min((int)nums1.size() - 1, x + k/2 - 1), ny = y + k - k/2 - 1;
        if (nums1[nx] < nums2[ny]) {
            // nx更小，删掉nums1一截
            return find(nums1, nx + 1, nums2, y, k - (nx - x + 1));
        } else {
            return find(nums1, x, nums2, ny + 1, k - (ny - y + 1));
        }
    } 
};