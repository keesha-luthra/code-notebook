class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        i = 0
        n = len(expression)

        def parse_expr():
            nonlocal i
            result = parse_term()

            while i < n and expression[i] == ',':
                i += 1
                result |= parse_term()

            return result

        def parse_term():
            nonlocal i
            result = {""}

            while i < n and expression[i] not in ',}':
                if expression[i] == '{':
                    i += 1
                    factor = parse_expr()
                    i += 1  # Skip closing brace
                else:
                    factor = {expression[i]}
                    i += 1

                result = {
                    a + b
                    for a in result
                    for b in factor
                }

            return result

        return sorted(parse_expr())