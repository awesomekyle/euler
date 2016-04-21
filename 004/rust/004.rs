fn num_digits(mut value: u32) -> u32 {
    let mut digits = 1;
    while value / 10 > 0 {
        value /= 10;
        digits = digits + 1;
    }
    return digits;
}

fn is_palindrome(mut value: u32) -> bool {
    let digits = num_digits(value);
    let mid = digits / 2;
    let mut current = 0;
    while current < mid {
        let right = (10 as u32).pow(current + 1);
        let left = (10 as u32).pow(digits - (current + 1));

        let left_digit = (value / left) % 10;
        let right_digit = (value % right) / (10 as u32).pow(current);

        if left_digit != right_digit {
            return false;
        }
        value = value / right;
        value = value * right;
        current += 1;
    }
    return true;
}

fn main() {
    let mut largest = 0;
    for n1 in 100..999 {
        for n2 in 100..999 {
            let multiple = n1 * n2;
            if is_palindrome(multiple) && multiple > largest {
                largest = multiple;
            }
        }
    }
    println!("Largest Multiple: {}", largest);
}