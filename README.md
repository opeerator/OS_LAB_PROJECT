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
1           |  10000   | 100 | 0.174000 ms | 0.139000 ms
10          |  10000   | 100 | 0.584000 ms | 2.391000 ms
100         |  10000   | 100 | 8.305000 ms | 8.305000 ms
1000        |  10000   | 100 | 93.041000 ms | 14314.549000 ms

| Threads       | Flips   | Global [ms]     | Local [ms]                                                                                                   |
| ------------- |:------:| ---------:  |-----------------------------------------------------------------------------------------------------------:|
100         |  1       | 100 | 5.762000 ms | 8.496000 ms
100         |  10      | 100 | 6.668000 ms | 6.915000 ms
100         |  100     | 100 | 20.164000 ms | 49.285000 ms
100         |  1000    | 100 | 16.406000 ms | 48.405000 ms
100         |  10000   | 100 | 9.287000 ms | 35.796000 ms

| Threads       | Flips   | Global [ms]     | Local [ms]                                                                                                   |
| ------------- |:------:| ---------:  |-----------------------------------------------------------------------------------------------------------:|
1           |  10000   | 100 | 0.161000 ms | 0.175000 ms
10          |  1000    | 100 | 1.145000 ms | 3.612000 ms
100         |  100     | 100 | 22.498000 ms | 89.420000 ms
1000        |  10      | 100 | 72.322000 ms | 555.562000 ms
10000       |  1       | 100 | 508.470000 ms | 517.965000 ms

Cheers!