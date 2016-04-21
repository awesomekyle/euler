pub fn is_prime(num: u64) -> bool {
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
