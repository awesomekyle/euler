fn is_prime(num: u64) -> bool {
    if num <= 1 {
        return false;
    }

    if num <= 3 {
        return true;
    }

    if num % 2 == 0 || num % 3 == 0 {
        return false;
    }

    let mut cmp = 5;
    while (cmp*cmp) <= num {
        if (num % cmp == 0) || (num % (cmp + 2)) == 0 {
            return false;
        }
        cmp += 6;
    }

    return true;
}


fn main() {
    let value: u64 = 600851475143;
    let root = (value as f64).sqrt() as u64;
    let mut largest_prime = 1;
    let mut cmp = 1;
    while cmp < root {
        if value % cmp == 0 && is_prime(cmp) {
            largest_prime = cmp;
        }
        cmp += 2;
    }
    println!("Largest Factor: {}", largest_prime);
}