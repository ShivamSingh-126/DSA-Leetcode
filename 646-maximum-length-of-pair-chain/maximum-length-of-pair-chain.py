class Solution:
    def findLongestChain(self, pairs: list[list[int]]) -> int:
        
        n=len(pairs)
        pairs.sort(key=lambda x: x[1])
        start1 = pairs[0][0]
        end1 = pairs[0][1]
        count=1

        for i in range(1,n):
            start2 = pairs[i][0]
            end2 = pairs[i][1]

            if start2 > end1:
                count +=1
                end1 = max(end1,end2)


        return count
