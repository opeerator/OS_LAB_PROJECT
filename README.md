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

Cheers!