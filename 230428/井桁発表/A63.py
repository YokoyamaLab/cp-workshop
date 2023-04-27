from collections import deque

N, M = map(int, input().split()) #入力
edges = [ list(map(int, input().split())) for i in range(M) ]

G = [ list() for i in range(N) ] # 隣接リストの作成
for A, B in edges:
	G[A-1].append(B-1)
	G[B-1].append(A-1)

#BFS
dist = [ -1 ] * (N)
dist[0] = 0
Q = deque()
Q.append(0)

while len(Q) >= 1:
	# キュー Q の先頭要素を取り除き、その値を pos に代入する
	pos = Q.popleft()
	for next in G[pos]:
		if dist[next] == -1:
			dist[next] = dist[pos] + 1
			Q.append(next)

# 頂点 1 から各頂点までの最短距離を出力
for i in range(N):
	print(dist[i])