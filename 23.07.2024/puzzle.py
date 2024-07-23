from collections import deque
goal_state = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]
]
moves = {
    'up': (-1, 0),
    'down': (1, 0),
    'left': (0, -1),
    'right': (0, 1)
}
def is_goal(state):
    return state == goal_state
def get_blank_position(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return (i, j)
    return None
def swap(state, pos1, pos2):
    new_state = [row[:] for row in state]
    new_state[pos1[0]][pos1[1]], new_state[pos2[0]][pos2[1]] = new_state[pos2[0]][pos2[1]], new_state[pos1[0]][pos1[1]]
    return new_state
def get_neighbors(state):
    neighbors = []
    blank_pos = get_blank_position(state)
    for move, (dx, dy) in moves.items():
        new_pos = (blank_pos[0] + dx, blank_pos[1] + dy)
        if 0 <= new_pos[0] < 3 and 0 <= new_pos[1] < 3:
            new_state = swap(state, blank_pos, new_pos)
            neighbors.append((move, new_state))
    return neighbors
def bfs(initial_state):
    queue = deque([(initial_state, [])])
    visited = set()
    while queue:
        current_state, path = queue.popleft()
        if is_goal(current_state):
            return path
        state_tuple = tuple(tuple(row) for row in current_state)
        if state_tuple in visited:
            continue
        visited.add(state_tuple)
        for move, neighbor in get_neighbors(current_state):
            queue.append((neighbor, path + [move]))
    return None
initial_state = [
    [1, 2, 3],
    [4, 0, 5],
    [7, 8, 6]
]
solution = bfs(initial_state)
print("Solution:", solution)
