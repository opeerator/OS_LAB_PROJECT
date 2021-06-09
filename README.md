# Multithreaded Coin Toss Project
A coin toss project for OS lab class. Written in C by Ali Yamini for Dr.Zamanifar class in SRBIAU. Created at: ۱۴۰۰/۰۳/۱۹

### Compile 

To be able to run the project please follow the steps:

- [x] First clone the project to your desired directory.

- [x] Go to the root directory and run the following in terminal:
    ```c
    gcc -o main main.c -lpthread
    ```
- [x] You can run the file with arguments or without arguments. The first argument is to set the number of people and the second argument is for the number of tosses for each person:
    ```c
    ./main 100 10000
    ```
### [main.c](main.c)

In the [main.c](main.c) file we have all the project functions. You can change some of the constants defined bellow:

```
Constants:
  -- CCOUNT: 20 // Total number of coins.
  -- PROBABILITY: 50 // Probability of having each side of the coin.
  -- CSIDES: {"X", "0"} // Shape of each side of the coins.
  -- persons: 100 // Number of people tossing the coins.
  -- tries: 10000 // Number of tosses for each person.
```

##### List of predefined arguments:
| Title       | Type   | Default     | Comments                                                                                                   |
| ------------- |:------:| ---------:  |-----------------------------------------------------------------------------------------------------------:|
First Argument           |  int   | 100 | Number of people in the experiment. | 
Second Argument           |  int   | 10000 | Number of tries for each person. |                                                                   

##### Coin flipping performance:
| Threads       | Flips   | Global [ms]     | Local [ms]                                                                                                   |
| ------------- |:------:| ---------:  |-----------------------------------------------------------------------------------------------------------:|
1           |  10000   | 0.153000 ms | 0.121000 ms
10          |  10000   | 0.584000 ms | 2.391000 ms
100         |  10000   | 9.618000 ms | 24.529000 ms
1000        |  10000   | 98.682000 ms | 5760.308000 ms

| Threads       | Flips   | Global [ms]     | Local [ms]                                                                                                   |
| ------------- |:------:| ---------:  |-----------------------------------------------------------------------------------------------------------:|
100         |  1       | 5.762000 ms | 8.496000 ms
100         |  10      | 16.995000 ms | 24.968000 ms
100         |  100     | 20.164000 ms | 49.285000 ms
100         |  1000    | 18.260000 ms | 68.544000 m
100         |  10000   | 8.739000 ms | 90.573000 ms

| Threads       | Flips   | Global [ms]     | Local [ms]                                                                                                   |
| ------------- |:------:| ---------:  |-----------------------------------------------------------------------------------------------------------:|
1           |  10000   | 0.215000 ms | 0.258000 ms
10          |  1000    | 1.206000 ms | 5.942000 ms
100         |  100     | 18.766000 ms | 61.433000 ms
1000        |  10      | 80.156000 ms | 387.905000 ms
10000       |  1       | 631.335000 ms | 562.462000 ms

Cheers!