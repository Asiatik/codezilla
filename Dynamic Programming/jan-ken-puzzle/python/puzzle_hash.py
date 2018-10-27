# Jan-Ken-Puzzle Solver
# 9293925 Caroline
# 9442688 Felipe
import random
from collections import OrderedDict


# positions of 4 connected neighbors
rowNbr = [-1, 1, 0, 0]
colNbr = [0, 0, -1, +1]
# dictionary of bad pieces for each piece
invalid_moves = {1: [0, 1, 3], 2: [0, 1, 2], 3: [0, 2, 3]}


def computeHash(table, board):
    key = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] != 0:
                key ^= table[i][j][board[i][j]]
    return key


def DFS(board, i, j, visited): 
    rows = len(board)
    cols = len(board[0])

    visited[i][j] = True

    # visit all connected neighbors
    for k in range(4): 
        iNbr = i + rowNbr[k]
        jNbr = j + colNbr[k]
        # check if safe
        if ((iNbr >= 0 and iNbr < rows) and (jNbr >= 0 and jNbr < cols)):
            if (not visited[iNbr][jNbr] and board[iNbr][jNbr]):
                # visit neighbor
                DFS(board, iNbr, jNbr, visited)


def checkIslands(board):
    rows = len(board)
    cols = len(board[0])
    # initialize cells as unvisited
    visited = [[False for j in range(cols)] for i in range(rows)] 

    # traverse all cells to find islands
    count = 0
    for i in range(rows): 
        for j in range(cols): 
            # if a cell with value 1 is not visited yet,  
            # then new island found 
            if visited[i][j] == False and board[i][j]: 
                # visit all cells in this island
                # and increment island count 
                DFS(board, i, j, visited) 
                count += 1
                if (count > 1):
                    # if there's more than one island,
                    # board has no solution
                    return False
    return True


def solve(cache, table, board, solutions, pieces):
    success = False
    state_hits = 0

    rows = len(board)
    cols = len(board[0])

    # check cache (memoization)
    key = computeHash(table, board)
    if key in cache:
        return cache[key]

    # check for islands
    if (not checkIslands(board)):
        cache[key] = [False, 0]
        return cache[key]
        
    # store solution if found
    if (pieces == 1):
        for i in range(len(board)):
            for j in range(len(board[i])):
                if (board[i][j] != 0):
                    solutions.append([i+1, j+1, board[i][j]])
                    cache[key] = [True, 1]
                    return cache[key]

    # check all alive pieces for possible jumps
    for i in range(len(board)):
        for j in range(len(board[i])):
            current = board[i][j]
            # if current is piece
            if (current != 0):
                # check all neighbors 
                for k in range(4): 
                    iNbr = i + rowNbr[k]
                    jNbr = j + colNbr[k]
                    # check if neighbor exists and is valid
                    if ((iNbr >= 0 and iNbr < rows) and (jNbr >= 0 and jNbr < cols)):
                        neighbor = board[iNbr][jNbr]
                        if (neighbor not in invalid_moves[current]):
                            # execute jump
                            board[iNbr][jNbr] = current
                            board[i][j] = 0
                            pieces -= 1
                            # recurse for new state
                            jump = solve(cache, table, board, solutions, pieces)
                            if (jump[0]):
                                success = True
                                state_hits += jump[1]
                            # undo jump
                            board[iNbr][jNbr] = neighbor
                            board[i][j] = current
                            pieces += 1
    # tried all possible jumps for current state
    if (not success):
        cache[key] = [False, 0]
    else:
        cache[key] = [True, state_hits]
    return cache[key]


def main():
    # read board
    R, C = input().split()
    R = int(R)
    C = int(C)
    
    # initialize empty boad
    pieces = 0
    board = [x[:] for x in [[0] * int(C)] * int(R)]

    # initialize zobrist hashing table
    table = [[[random.randint(1,2**64 - 1) for i in range(4)]for j in range(C)] for k in range(R)]
       
    # fill board
    for i in range(R):
        line = input().split()
        for j in range(C):
            board[i][j] = int(line[j])
            if (board[i][j] != 0):
                pieces += 1
    
    # search for solutions
    solutions = []
    cache = OrderedDict()
    solve(cache, table, board, solutions, pieces)
    hits = cache.popitem()[1][1]

    print(hits)
    print(len(solutions))
    # display sorted unique solutions
    for solution in sorted(solutions):
        for value in solution:
            print(str(value), end=' ')
        print()

if __name__ == '__main__':
    main()
