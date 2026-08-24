from typing import DefaultDict, List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Check for repeats by checking if the value
        # already exists in the dictionary
        row_values = DefaultDict(set)
        column_values = DefaultDict(set)
        # The mini box will have a subset of row_values
        # and column_values. We iterate through this
        # set in r // 3 and c / /3(floor division because the size
        # of the boz is 9 and equal parts is 3)
        mini_box_values = DefaultDict(set)

        for row in range(len(board)):
            for column in range(len(board)):
                if board[row][column] == ".":
                    continue

                if (
                    board[row][column] in row_values[row]
                    or board[row][column] in column_values[column]
                    or board[row][column] in mini_box_values[(row // 3), (column // 3)]
                ):
                    return False

                column_values[column].add(board[row][column])
                row_values[row].add(board[row][column])
                mini_box_values[((row // 3), (column // 3))
                                ].add(board[row][column])

        return True
