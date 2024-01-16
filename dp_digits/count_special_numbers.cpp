// leetcode 2376
// “@鱼沙 首先数位dp中状态如果是二维dp[pos][state]则定义是没有限制limit下的计数，因为这样计数状态会有冲突。打个比方，统计321之前不重复整数时，当百位是2，十位是3时，个位上限是9，这时dp[0][{2,3}] = 8（去除2，3还剩8个不重复的数字）。但当百位是3，十位是2时，个位上限是1，这时dp[0][{2,3}]是有限制条件下的，如果不加以区分，会得到8。因此这里limit是用来区分定义状态冲突，所有数位dp类题目都要这么操作。isNum是这题前导0条件下和正常情况会冲突加的区分状态的变量，有的题目需要考虑前导0。”
// ----> 其实可以理解成将三维乃至四维dp压缩成了二维,因为is_limit和!is_num的情况在整个递归过程中只会出现一次,不需要进行记忆化,所以这里考虑直接压缩成二维的dp数组,并且用额外的判断来解决因为压缩dp数组维度而造成的可能的dp数组的冲突,换言之,这里题解里面的dp[i][mask]表示的是：当is_limit为false且is_num为true的情况下,考虑到从第i个位置开始填数字,且前面的集合情况为mask的情况下,可构造的符合条件的数组的数目
class Solution {
public:
    int countSpecialNumbers(int n) {
        auto s = to_string(n);
        int m = s.length(), memo[m][1 << 10];
        memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
        function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
            if (i == m)
                return is_num; // is_num 为 true 表示得到了一个合法数字
            // 只有“一般情况”(既不是limit,也不是前面全跳过),才符合我们对dp数组的定义,这时候才能直接读取记忆化存储过的值,不然可能会造成dp的冲突
            if (!is_limit && is_num && memo[i][mask] != -1)
                return memo[i][mask];
            int res = 0;
            // 可以跳过当前数位,注意这里一旦跳过了当前第i位,那么第i + 1位置的is_limit一定为false
            // 因为相当于你本来第i位置可以填一个数字,现在直接跳过(填0),那么这种情况下构造出来的数字一定比n小,i + 1位可以最大取到9
            if (!is_num) 
                res = f(i + 1, mask, false, false);
            int up = is_limit ? s[i] - '0' : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
            for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
                // d 不在 mask 中
                if ((mask >> d & 1) == 0)
                    // 如果i位置之前is_limit且i位置也取到了s[i] - '0',那么i + 1这一位的数字必定也要受到限制(连续一直受限)  
                    res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
            // 同样,只有“一般情况”,我们才记忆化记录
            if (!is_limit && is_num)
                memo[i][mask] = res;
            return res;
        };
        return f(0, 0, true, false);
    }
};
