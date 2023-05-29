n, x = map(int, input().split())
a = list(map(int, input().split()))

r = 0
s = 0
ans = 0
for l in range(n):
    while r < n and s < x:
        s += a[r]
        r += 1
    ans = max(ans, r - l)
    s -= a[l]

print(ans)
