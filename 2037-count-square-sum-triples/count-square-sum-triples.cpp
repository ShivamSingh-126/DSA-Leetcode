class Solution {
public:
    int countTriples(int n) {
        //  Brute force
        // int count = 0;
        // for (int i = 1; i < n; i++) {
        //     for (int j = 1; j < n; j++) {
        //         for (int c = 1; c <= n; c++) {
        //             if (i * i + j * j == c * c) {
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;

        // Optimal solution
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int sum=i*i+j*j;
                int check=sqrt(sum);
                if(check<=n && check*check==sum) count++;
            }
        }
        return count;
    }
};