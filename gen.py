import random
n = 10
q = random.randint(1,20)
l = ['Q','U']
xx = []
print(n)
for i in range(n):
    xx.append(random.randint(0,100))
print(*xx)
print(q)
for i in range(q):
    c = random.choice(l)
    x = random.randint(1,n-1)
    y = random.randint(0,100)
    while(c == 'Q' and (y <= x or y > n)):
        y = random.randint(1,n)
    print(c,x,y)
