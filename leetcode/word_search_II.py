# https://leetcode.com/problems/word-search-ii/

from dataclasses import dataclass, field

@dataclass(slots=True)
class Trie:
    children: dict[str, "Trie"] = field(default_factory=dict)
    word: str | None = None


def add_word(trie: Trie, word: str):
    cur = trie
    for c in word:
        if c not in cur.children:
            cur.children[c] = Trie()
        cur = cur.children[c]
    cur.word = word


class Solution:
    def findWords(self, board: List[List[str]], words: list[str]) -> List[str]:
        root = Trie()
        for word in words:
            add_word(root, word)
        res = []

        def dfs(r, c, cur: Trie):
            if r < 0 or r >= len(board):
                return
            if c < 0 or c >= len(board[r]):
                return
            ch = board[r][c]
            if ch == '?':
                return
            if ch not in cur.children:
                return

            if cur.children[ch].word:
                res.append(cur.children[ch].word)
                cur.children[ch].word = None

            board[r][c] = '?'
            dfs(r + 1, c, cur.children[ch])
            dfs(r - 1, c, cur.children[ch])
            dfs(r, c + 1, cur.children[ch])
            dfs(r, c - 1, cur.children[ch])
            board[r][c] = ch


        for row in range(len(board)):
            for col in range(len(board[0])):
                dfs(row, col, root)
        return res
