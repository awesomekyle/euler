fn num_digits(mut value: u64) -> u32 {
    let mut digits = 1;
    while value / 10 > 0 {
        value /= 10;
        digits = digits + 1;
    }
    return digits;
}

fn is_palindrome(mut value: u64) -> bool {
    let digits = num_digits(value);
    let mid = digits / 2;
    let mut current = 0;
    while current < mid {
        let right = (10 as u64).pow(current + 1);
        let left = (10 as u64).pow(digits - (current + 1));

        let left_digit = (value / left) % 10;
        let right_digit = (value % right) / (10 as u64).pow(current);

        if left_digit != right_digit {
            return false;
        }
        value = value / right;
        value = value * right;
        current += 1;
    }
    return true;
}

pub fn euler() -> u64 {
    let mut largest: u64 = 0;
    for n1 in 100..999 {
        for n2 in 100..999 {
            let multiple = n1 * n2;
            if is_palindrome(multiple) && multiple > largest {
                largest = multiple;
            }
        }
    }
    return largest;
}

#[allow(dead_code)]
fn main() {
    println!("{}", euler());
}