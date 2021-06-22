import java.util.*;

/*
小猴子下山，沿着下山的路有一排桃树，每棵树都结了一些桃子。小猴子想摘桃子，但是有一些条件需要遵守，小猴子只能沿着下山的方向走，不能回头，每颗树最多摘一个，而且一旦摘了一棵树的桃子，就不能再摘比这棵树结的桃子少的树上的桃子。那么小猴子最多能摘到几颗桃子呢？
举例说明，比如有5棵树，分别结了10，4，5，12，8颗桃子，那么小猴子最多能摘3颗桃子，来自于结了4，5，8颗桃子的桃树。
 */
public class main {
    public static void main(String[] args) {
        int[] peaches = {5, 10, 4, 5, 12, 8};
        System.out.println(pick(peaches));
    }

    // 小猴子最多能摘几个桃子
    static int pick(int[] peaches) {
        int[] dp = new int[peaches.length];
        dp[0] = 1;
        for (int i = 1; i < peaches.length; i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {

                if ((peaches[i] > peaches[j])) {
                    if (temp < dp[j])
                        temp = dp[j];
                }
            }
            dp[i] = temp + 1;
        }

        int maxLength = 0;
        for (int i = 0; i < dp.length; i++) {
            if (dp[i] > maxLength) {
                maxLength = dp[i];
            }
        }
        //System.out.println(maxLength);
        return maxLength;
    }

}
