class Solution:
    def minSumSquareDiff(
        self,
        nums1: list[int],
        nums2: list[int],
        k1: int,
        k2: int
    ) -> int:
        diff = sorted(
            (abs(a - b) for a, b in zip(nums1, nums2)),
            reverse=True
        )

        k = k1 + k2
        n = len(diff)

        if sum(diff) <= k:
            return 0

        diff.append(0)

        for i in range(n):
            count = i + 1
            gap = diff[i] - diff[i + 1]
            cost = gap * count

            if k >= cost:
                k -= cost
                diff[i] = diff[i + 1]
            else:
                level_drop, remainder = divmod(k, count)
                level = diff[i] - level_drop

                for j in range(i + 1):
                    diff[j] = level

                for j in range(remainder):
                    diff[j] -= 1

                k = 0
                break

        return sum(x * x for x in diff)