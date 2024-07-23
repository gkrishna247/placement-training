def tower_of_hanoi_iterative(n, source, auxiliary, target):
    total_moves = 2 ** n - 1
    stacks = {
        source: list(range(n, 0, -1)),
        auxiliary: [],
        target: []
    }

    def move_disk(from_peg, to_peg):
        disk = stacks[from_peg].pop()
        stacks[to_peg].append(disk)
        print(f"Move disk {disk} from {from_peg} to {to_peg}")

    if n % 2 == 0:
        auxiliary, target = target, auxiliary

    for i in range(1, total_moves + 1):
        if i % 3 == 1:
            if len(stacks[source]) == 0:
                move_disk(target, source)
            elif len(stacks[target]) == 0:
                move_disk(source, target)
            elif stacks[source][-1] > stacks[target][-1]:
                move_disk(target, source)
            else:
                move_disk(source, target)
        elif i % 3 == 2:
            if len(stacks[source]) == 0:
                move_disk(auxiliary, source)
            elif len(stacks[auxiliary]) == 0:
                move_disk(source, auxiliary)
            elif stacks[source][-1] > stacks[auxiliary][-1]:
                move_disk(auxiliary, source)
            else:
                move_disk(source, auxiliary)
        elif i % 3 == 0:
            if len(stacks[auxiliary]) == 0:
                move_disk(target, auxiliary)
            elif len(stacks[target]) == 0:
                move_disk(auxiliary, target)
            elif stacks[auxiliary][-1] > stacks[target][-1]:
                move_disk(target, auxiliary)
            else:
                move_disk(auxiliary, target)

n = 3
tower_of_hanoi_iterative(n, 'A', 'B', 'C')
