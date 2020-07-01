def prime_factorize(n):
    i = 2
    res = []
    while i * i <= n:
        while n % i == 0:
            n //= i
            res.append(i)
        i += 1
    if n > 1:
        res.append(n)
    return res
