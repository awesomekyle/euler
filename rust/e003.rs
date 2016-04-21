mod common;

pub fn euler() -> u64 {
    let value: u64 = 600851475143;
    let root = (value as f64).sqrt() as u64;
    let mut largest_prime = 1;
    let mut cmp = 1;
    while cmp < root {
        if value % cmp == 0 && common::is_prime(cmp) {
            largest_prime = cmp;
        }
        cmp += 2;
    }
    return largest_prime;
}

#[allow(dead_code)]
fn main() {
    println!("{}", euler());
}