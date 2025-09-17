fn recursive_fib(num:i32) -> i32
{
    if num == 0 {
        return 0;
    }
    else if num == 1 {
        return 1;
    }
    else {
        return recursive_fib(num -2) + recursive_fib(num - 1);
    }
}

fn iterative_fib(num:i32) -> i32 
{
    let mut val = 0;
    let mut first_val = 0;
    let mut second_val = 1;
    let mut i = 2;
    if num == 0 {
        return 0;
    }
    else if num == 1 {
        return 1;
    }
    else {
        while i <= num {
            val = first_val + second_val;
            first_val = second_val;
            second_val = val;
            i += 1;
        }
        return val;
    }

}

fn print_values() 
{
    println!("Recursive Fibonacci: {}", recursive_fib(20));
    println!("Iterative Fibonacci: {}", iterative_fib(20));
}

fn main() 
{
    print_values()
}
