# Trains
CS315 Project -- Simulates Trains at a Switching Station
Write a program that simulates trains at a switching station.

At the beginning of the simulation, there are n trains. Each starts with c cars. Each car has a fixed size s that limits how much it can carry. The sizes of the cars in each train are 1 ... c, from the front to the back of the train. Trains are loaded with more valuable materials toward the back of the train, so the value of a train is the sum of p*s, where p is the position of each car (starting at 1) and s is its size. So the starting value of each train is 1*1 + 2*2 + ... + c*c = c(c+1)(2c+1)/6.

At each step, the simulation tosses an n-sided die, which indicates which train is the donor of this step. The simulation then tosses tosses a 2-sided die, indicating whether to remove a car from the front (if the die shows 1) or the back of the donor train (if the die shows 2). Ths simulation then tosses an n-sided die, indicating which train accepts the donated car. It is possible for the donor to get its own car back. The accepting train puts the donated car at its front. When a car moves to a new position, it retains its original size, but the values of the train it left and the train it joins do change, because cars are now in a different position.

The simulation ends when any train becomes empty or t steps, whichever comes first.

2. What to do
Write a program called trains that simulates the switching station. This program must take n, c, and t as command-line parameters. The program must fail gently if any of these parameters is ridiculous, such as n = 0 or c = -5. The program must read a stream of integers from standard input as its source of randomness; this feature allows us to test the program in a deterministic way. After each step, the program should print (to standard output) which train donates a car (front or back) to which recipient and the value of each train after the step. When the simulation finishes (either because a train has become empty or the number of steps has reached its limit), the program prints which train has the largest value (if there is a tie, select the earliest train in the collection).

The program must use a doubly-linked list to implement the trains You must not use a library routine (such as C++ std::list or Java java.util.LinkedList) for linked lists; you must write your own routines. This restriction is frustrating, but the point of the exercise is to learn how these lists work. You may use array, struct, and class elements, but not C++ vectors or Java Lists. \fBDo not use code you find on the Internet; you will get 0 points and be charged with academic misconduct if we detect any such code.\fP

Try to make the program modular, with separate routines for the main loop, for reading the next random number, for evaluating the value of a train, and for donating and accepting a car.
