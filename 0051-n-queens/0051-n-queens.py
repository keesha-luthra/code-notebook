class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        result = []

        board = [["."] * n for _ in range(n)]

        cols = set()
        diagonals = set()
        anti_diagonals = set()

        def backtrack(row):
            if row == n:
                solution = []

                for r in board:
                    solution.append("".join(r))

                result.append(solution)
                return

            for col in range(n):

                # Main diagonal: row - col
                # Anti diagonal: row + col
                if col in cols:
                    continue

                if row - col in diagonals:
                    continue

                if row + col in anti_diagonals:
                    continue

                # Place queen
                board[row][col] = "Q"

                cols.add(col)
                diagonals.add(row - col)
                anti_diagonals.add(row + col)

                backtrack(row + 1)

                # Remove queen
                board[row][col] = "."

                cols.remove(col)
                diagonals.remove(row - col)
                anti_diagonals.remove(row + col)

        backtrack(0)

        return result