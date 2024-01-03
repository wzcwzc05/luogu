#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void get_primes(int n, int primes[]) {
    int count = 0;
    for (int num = 2; num <= n; num++) {
        if (is_prime(num)) {
            primes[count] = num;
            count++;
        }
    }
}

void prime_factors(int num, int primes[], int prime_count, int factors[]) {
    int count = 0;
    for (int i = 0; i < prime_count; i++) {
        while (num % primes[i] == 0) {
            factors[count] = primes[i];
            count++;
            num /= primes[i];
        }
        if (num == 1) {
            break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int composites[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &composites[i]);
    }

    int limit = 0;
    for (int i = 0; i < n; i++) {
        if (composites[i] > limit) {
            limit = composites[i];
        }
    }

    int primes[limit];
    get_primes((int)sqrt(limit), primes);

    int prime_set[limit];
    int set_count = 0;
    for (int i = 0; i < n; i++) {
        int factors[limit];
        prime_factors(composites[i], primes, (int)sqrt(limit), factors);
        for (int j = 0; j < limit; j++) {
            if (factors[j] != 0) {
                int found = 0;
                for (int k = 0; k < set_count; k++) {
                    if (prime_set[k] == factors[j]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    prime_set[set_count] = factors[j];
                    set_count++;
                }
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < set_count - 1; i++) {
        printf("%d ", prime_set[i]);
    }
    printf("%d", prime_set[set_count - 1]);

    return 0;
}
