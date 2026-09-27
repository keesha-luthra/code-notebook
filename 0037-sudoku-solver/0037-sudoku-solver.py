class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        empty = []

        # Track existing digits and empty cells
        for r in range(9):
            for c in range(9):
                num = board[r][c]

                if num == ".":
                    empty.append((r, c))
                else:
                    b = (r // 3) * 3 + (c // 3)
                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[b].add(num)

        def backtrack(pos):
            if pos == len(empty):
                return True

            r, c = empty[pos]
            b = (r // 3) * 3 + (c // 3)

            for num in "123456789":
                if (num in rows[r] or
                    num in cols[c] or
                    num in boxes[b]):
                    continue

                # Place digit
                board[r][c] = num
                rows[r].add(num)
                cols[c].add(num)
                boxes[b].add(num)

                if backtrack(pos + 1):
                    return True

                # Undo if this choice fails
                board[r][c] = "."
                rows[r].remove(num)
                cols[c].remove(num)
                boxes[b].remove(num)

            return False

        backtrack(0)