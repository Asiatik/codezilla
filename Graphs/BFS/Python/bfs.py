import queue
visited = []
MAX = 20
adj = {1: set([2,3,5]), 2: set([3]), 3: set([8,4]), 4:6}
q = queue.Queue(MAX)

def bfs(x):
	visited.append(x)
	print(x)
	q.put(x)
	while q.empty() == False:
		s = q.get()
		children = adj.get(s)
		if children != None:
			if isinstance(children,int):	# Case : values are not a set
				if children in visited:
					continue
				visited.append(children)
				print(children)
				q.put(children)
			else :							# Case : values are a set
				for i in children:
					if i in visited:
						continue
					visited.append(i)
					print(i)
					q.put(i)


def test():
	global visited
	print("bfs : ")
	visited = []
	bfs(1)

test()