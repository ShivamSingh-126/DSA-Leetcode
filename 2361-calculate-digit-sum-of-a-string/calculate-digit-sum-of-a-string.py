class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while(len(s) > k):
            ans=""
            for i in range(0,len(s),k):
                total = sum(int(ch) for ch in s[i:i+k])
                ans += str(total) 

            s = ans


        return s