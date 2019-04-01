import sys

parents = []


def read_line(split_func=None):
    line =  sys.stdin.readline().strip()
    if split_func:
        return [split_func(x) for x in line.split(' ')]
    return line


def reset_parents(size):
    global parents
    parents = [i for i in range(size + 1)]


def find_parent(a):
    if parents[a] == a:
        return a
    parents[a] = find_parent(parents[a])
    return parents[a]


def union_set(a, b):
    parents[find_parent(a)] = find_parent(b)


def count_componentes(size):
    count = 0
    for i in range(1, size + 1):
        if parents[i] == i:
            count += 1
    return count


def minimum_spanning_tree(roads, airport_cost):
    minimun_cost = 0
    extra_airports = 0
    for road_cost, node_i, node_j in roads:
        if find_parent(node_i) != find_parent(node_j):
            union_set(node_i, node_j)
            if road_cost < airport_cost:
                minimun_cost += road_cost
            else:
                minimun_cost += airport_cost
                extra_airports += 1

    return minimun_cost, extra_airports


def main():
    ncases = int(read_line())

    for case in range(ncases):
        nlocations, nroads, airport_cost = read_line(split_func=int)

        roads = []
        for i in range(nroads):
            location_i, location_j, road_cost = read_line(split_func=int)
            roads.append((road_cost, location_i, location_j))

        roads.sort()

        reset_parents(nlocations)
        cost, extra_airports = minimum_spanning_tree(roads, airport_cost)
        components = count_componentes(nlocations)

        cost += components * airport_cost
        nairports = components + extra_airports

        print('Case %d: %d %d' % (case + 1, cost, nairports))


if __name__ == '__main__':
    main()
