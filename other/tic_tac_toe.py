#  X | O | X
# ---+---+---
#  O | O | X
# ---+---+---
#  X | X | O

board = [[' '] * 3 for _ in range(3)]

def print_board():
    print("---+---+---\n".join(" " + " | ".join(row) + "\n" for row in board))
    # for i, row in enumerate(board):
    #     print(" " + " | ".join(row))
    #     if i != 2: print("---+---+---")

def is_valid(x, y):
    return 0 <= x < 3 and 0 <= y < 3 and board[x][y] == ' '

def game_over():  # returns 'X', 'O', or False, 'TIE'
    for row in board:  # horizontal match
        if row[0] != ' ' and len(set(row)) == 1: return row[0]
    for i in range(3):
        col = [board[x][i] for x in range(3)]
        if col[0] != ' ' and len(set(col)) == 1: return col[0]
    diag1 = [board[x][x] for x in range(3)]
    if diag1[0] != ' ' and len(set(diag1)) == 1: return diag1[0]
    diag2 = [board[x][y] for x,y in zip(range(3), range(2,-1,-1))]
    if diag2[0] != ' ' and len(set(diag2)) == 1: return diag2[0]
    if turn_count == 9: return "TIE"
    return False

turn = True  # True: X,  False: O
turn_count = 0
done = False
while not done:
    # prompt user to pick a square to occupy
    print_board()
    turn_count += 1
    piece = 'X' if turn else 'O'
    prompt = f"Turn {turn_count}: {piece} | Select a coordinate: "
    while True:
        row, col = map(int, input(prompt).split())  # '1 2', '3 3', '2 1' -> {row col}
        row, col = row-1, col-1
        if is_valid(row, col):
            board[row][col] = piece
            break
        print("That coordinate is invalid. Try again.")
    done = game_over()
    if done != False:
        print()
        print_board()
        print(done)
        print(f"Game over in {turn_count} turns!")
    turn = not turn
    print()

print("Goodbye.")
