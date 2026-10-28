class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while tx > sx and ty > sy and tx != ty:

            if tx > ty:
                tx %= ty
            else:
                ty %= tx

        if tx == sx and ty == sy:
            return True

        if tx == sx:
            return (ty - sy) % tx == 0 and ty >= sy
            
        if ty == sy:
            return (tx - sx) % ty == 0 and tx >= sx

        return False
