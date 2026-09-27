class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"

        m, n = len(num1), len(num2)
        result = [0] * (m + n)

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                a = int(num1[i])
                b = int(num2[j])

                product = a * b
                total = product + result[i + j + 1]

                result[i + j + 1] = total % 10
                result[i + j] += total // 10

        # Convert digits to a string, skipping leading zeros
        start = 0

        while start < len(result) and result[start] == 0:
            start += 1

        return "".join(map(str, result[start:]))