# fibo-gmp

This program computes the *Nth* element of the Fibonacci series. Presented
implementation uses an iterative algorithm that performs matrix multiplication
and recursive powering. Program is written in C99 and uses GNU MP library.

Read more about the approach on the
[ICS 161 Lecture notes](http://www.ics.uci.edu/~eppstein/161/960109.html) page.

The license is valid as long as you link against GNU MP
[dynamically](http://programmers.stackexchange.com/a/158792/53086).

## Installation

In order to build the program, simply run `make`. The program depends on the
`libgmp`. On Ubuntu, it is installed this way:

    sudo apt-get install libgmp-dev

## Sample output

    $ ./fibo 1001
    1001st Fibonacci number: 70330367711422815821835254877183549770181269836358
    732742604905087154537118196933579742249494562611733487750449241765991088186
    363265450223647106012053374121273867339111198139373125598767690091902245245
    323403501
