fn divisible(value: u64) -> bool {
    let divisors = [20,19,9,17,16,13,11,7];
    for d in &divisors {
        if (value % d) != 0 {
            return false;
        }
    }
    return true;
}

pub fn euler() -> u64 {
    let mut value = 20u64;
    loop {
        if divisible(value) {
            break;
        }
        value += 20;
    }
    return value;
}

#[allow(dead_code)]
fn main() {
    println!("{}", euler());
}