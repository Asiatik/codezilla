import queue
visited = []
MAX = 20
adj = {1: set([2,3,5]), 2: set([3]), 3: set([8,4]), 4:6}
q = queue.Queue(MAX)

def dfs(s):
	if s in visited : 
		return
	visited.append(s)
	print(s)
	children = adj.get(s)
	if children != None:
		if isinstance(children,int):	# Case : values are not a set
			dfs(children)
		else :							# Case : values are a set
			for i in children:
				dfs(i)
	return

def test():
	global visited
	visited = []
	print("dfs : ")
	dfs(1)

test()