class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:

        res = []

        start, end = newInterval

        for s, e in intervals:

            # Case 1: Current interval is completely before newInterval
            if e < start:
                res.append([s, e])

            # Case 2: Current interval is completely after newInterval
            elif end < s:
                res.append([start, end])

                # Add all remaining intervals directly
                res.extend(intervals[intervals.index([s, e]):])
                return res

            # Case 3: The intervals overlap, so merge them
            else:
                start = min(start, s)
                end = max(end, e)

        # Add the merged interval after processing all intervals
        res.append([start, end])

        return res