use std::io;
use std::collections::HashMap;


fn get_input() -> String {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).expect("Failed");
    buffer
}


fn main() {

    let _n: u32 = get_input().trim().parse().unwrap();
    let mut pairs = HashMap::new();

    let colors = get_input().split_whitespace()
        .map(|x| x.parse::<u32>())
        .collect::<Result<Vec<u32>, _>>()
        .unwrap();

    for color in colors {
        let count = pairs.entry(color).or_insert(0);
        *count += 1;
    }

    let mut count: i32 = 0;
    for (_, value) in &pairs {
        // println!("{}: {}", key, value);
        count += value / 2;
    }

    println!("{}", count);

}
