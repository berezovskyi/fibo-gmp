# fibo-gmp

This program computes the *Nth* element of the Fibonacci series. Presented
implementation uses an iterative algorithm that performs matrix multiplication
and recursive powering. Program is written in C99 and uses GNU MP library.

Read more about the approach on the
[ICS 161 Lecture notes](http://www.ics.uci.edu/~eppstein/161/960109.html) page.

## Installation

In order to build the program, simply run `make`. The program depends on the
`libgmp`. On Ubuntu, it is installed this way:

    sudo apt-get install libgmp-dev

## Sample output

    $ ./fibo 1001 1001st Fibonacci number: 703303677114228158218352548771835497
    701812698363587327426049050871545371181969335797422494945626117334877504492
    417659910881863632654502236471060120533741212738673391111981393731255987676
    90091902245245323403501
