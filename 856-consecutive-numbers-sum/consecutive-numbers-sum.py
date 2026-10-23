class Solution(object):
    def consecutiveNumbersSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        # count=0
        # for i in range(1,n+1):
        #     sum=0
        #     for j in range(i,n+1):
        #         sum+=j
        #         if sum == n:
        #             count+=1
        #             break
        #         if sum > n:
        #             break

        # return count

        count=0
        k=1

        while k*(k+1) // 2 <= n:
            remaining = n - k*(k-1) // 2

            if remaining % k == 0:
                count += 1

            k+=1

        return count