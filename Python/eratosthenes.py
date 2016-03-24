
def sieve_of_eratosthenes(x, y):
    multiples = set()
    list_primes = []
    for i in range(2, y + 1):
        if i not in multiples:
            list_primes.append(i)
            multiples.update(range(i * i, y + 1, i))
    flag = 0
    for n in list_primes:
        if n >= x:
            flag = 1
            print(n)
    if flag == 0:
        print("No primes found")


sieve_of_eratosthenes(50, 300)

