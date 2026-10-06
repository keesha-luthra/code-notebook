class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        result = []
        i = 0
        n = len(words)

        while i < n:

            # Find words that fit on this line
            line_words = []
            line_length = 0

            while i < n:
                word_length = len(words[i])

                if line_length + word_length + len(line_words) <= maxWidth:
                    line_words.append(words[i])
                    line_length += word_length
                    i += 1
                else:
                    break

            # Last line -> left justified
            if i == n:
                line = " ".join(line_words)
                line += " " * (maxWidth - len(line))
                result.append(line)
                break

            # Only one word -> left justified
            if len(line_words) == 1:
                line = line_words[0]
                line += " " * (maxWidth - len(line))
                result.append(line)
                continue

            # Normal justified line
            spaces = maxWidth - line_length
            gaps = len(line_words) - 1

            space_each = spaces // gaps
            extra = spaces % gaps

            line = ""

            for j in range(gaps):
                line += line_words[j]
                line += " " * (space_each + (1 if j < extra else 0))

            line += line_words[-1]

            result.append(line)

        return result