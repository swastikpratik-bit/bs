def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

t = int(input())
for _ in range(t):
    n = int(input())
    k = list(map(int, input().split()))
    lcm_val = 1
    for ki in k:
        lcm_val = lcm(lcm_val, ki)
    ok = True
    for ki in k:
        if lcm_val // ki < sum(lcm_val // kj for kj in k):
            ok = False
            break
    if not ok:
        print(-1)
    else:
        print(' '.join(str(lcm_val // ki) for ki in k))