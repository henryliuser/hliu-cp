class Solution:
    def decodeCiphertext(self, text: str, rows: int) -> str:
        ans = []
        cols = len(text) // rows
        for i in range(cols):
            for j in range(rows):
                if i + j < cols:
                    ans.append(text[j*cols + i + j])
                else: break
        return "".join(ans).rstrip()
