fn multiple_of_int(value: u64, multiple: u64) -> bool {
    if multiple == 0 {
        return false;
    }

    return value % multiple == 0;
}

fn multiple_of_3_or_5(value: u64) -> bool {
    return multiple_of_int(value,3) || multiple_of_int(value,5);
}

fn main() {
    let mut total = 0;
    for n in 1..1000 {
        if multiple_of_3_or_5(n) {
            total += n;
        }
    }
    println!("Total: {}", total);
}