
fn main() {
    let mut total = 0;
    let mut last = 1;
    let mut current = 1;
    while last + current <= 4000000 {
        let next = last + current;
        if next % 2 == 0 {
            total += next;
        }

        last = current;
        current = next;
    }
    println!("Total: {}", total);
}