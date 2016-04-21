mkdir bin

rustc rust/%1.rs -o bin/%1-rust.exe

bin\%1-rust.exe
