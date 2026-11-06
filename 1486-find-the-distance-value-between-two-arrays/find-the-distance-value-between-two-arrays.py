class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        # count = 0

        # for i in arr1:
        #     flag = True

        #     for j in arr2:
        #         if abs(i - j) <= d:
        #             flag = False
        #             break

        #     if flag:
        #         count += 1

        # return count

        arr2.sort()
        count = 0

        for x in arr1:
            l, r = 0, len(arr2) - 1
            flag = True

            while l <= r:
                mid = (l + r) // 2

                if abs(x - arr2[mid]) <= d:
                    flag = False
                    break
                elif arr2[mid] < x:
                    l = mid + 1
                else:
                    r = mid - 1

            if flag:
                count += 1

        return count
