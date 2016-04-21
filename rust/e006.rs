
pub fn euler() -> u64 {
    let square = |value| value * value;
    let sum_factorial = |value|
    {
        let mut sum = 0;
        for ii in 1..(value+1) {
            sum += ii;
        }
        return sum;
    };

    // calculate sum of squares
    let mut sum_of_squares = 0;
    for ii in 1..100 {
        sum_of_squares += square(ii);
    }
    // calculate square of sums
    let square_of_sums = square(sum_factorial(100));
    return (square_of_sums - sum_of_squares) as u64;
}

#[allow(dead_code)]
fn main() {
    println!("{}", euler());
}