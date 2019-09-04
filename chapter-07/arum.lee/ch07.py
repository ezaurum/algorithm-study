from copy import copy
    
def isConnected(G):
	start_node = list(G)[0]
	color = {v: 'white' for v in G}
	color[start_node] = 'gray'
	S = [start_node]
	while len(S) != 0:
		u = S.pop()
		for v in G[u]:
			if color[v] == 'white':
				color[v] = 'gray'
				S.append(v)
			color[u] = 'black'
	return list(color.values()).count('black') == len(G)

def odd_degree_nodes(G):
	odd_degree_nodes = []
	for u in G:
		if len(G[u]) % 2 != 0:
			odd_degree_nodes.append(u)
	return odd_degree_nodes

def from_dict(G):
	links = []
	for u in G:
		for v in G[u]:
			links.append((u,v))
	return links

def fleury(G):
	odn = odd_degree_nodes(G)
	if len(odn) > 2 or len(odn) == 1:
		return 'Not Eulerian Graph'
	else:
		g = copy(G)
		trail = []
		if len(odn) == 2:
			u = odn[0]
		else:
			u = list(g)[0]
		while len(from_dict(g)) > 0:
			current_vertex = u
			for u in g[current_vertex]:
				g[current_vertex].remove(u)
				g[u].remove(current_vertex)
				bridge = not isConnected(g)
				if bridge:
					g[current_vertex].append(u)
					g[u].append(current_vertex)
				else:
					break
			if bridge:
				g[current_vertex].remove(u)
				g[u].remove(current_vertex)
				g.pop(current_vertex)
			trail.append((current_vertex, u))
	return trail

print('Konigsberg Bridge')
G = {0: [2, 2, 3], 1: [2, 2, 3], 2: [0, 0, 1, 1, 3], 3: [0, 1, 2]}
print(fleury(G))

print('Eulerian Trail')
G = {1: [2, 3], 2: [1, 3, 4], 3: [1, 2, 4], 4: [2, 3]}
print(fleury(G))
