import random
rng = random.Random()

def qsort(a, l, r):
    if l >= r:
        return
    mid = a[rng.randint(l, r)]
    i, j = l, r
    while i <= j:
        while a[i] < mid:
            i += 1
        while a[j] > mid:
            j -= 1
        if i <= j:
            a[i], a[j] = a[j], a[i]
            i += 1
            j -= 1
    qsort(a, l, j)
    qsort(a, i, r)