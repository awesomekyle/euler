use std::thread;

mod e001;
mod e002;
mod e003;
mod e004;
mod e005;
mod e006;

fn main() {
    let functions: Vec<fn()->u64> = vec![
         e001::euler,
         e002::euler,
         e003::euler,
         e004::euler,
         e005::euler,
         e006::euler,
    ];
    let mut threads = vec![];

    // spawn threads for each project
    for ii in 0..functions.len() {
        let func = functions[ii];
        threads.push(thread::spawn(move || {
            return func();
        }));
    }

    // print out all results
    let mut ii = 0;
    for thread in threads {
        let result = thread.join();
        println!("{}: {}", ii, result.unwrap());
        ii += 1;
    }
}