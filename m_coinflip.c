// Ali Yamini - Multi-threaded coin flipping
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int persons = 100, tries = 10000;

    // Command line input checks
    if(argc==1)
    {
        printf("No command line arguments!\n");
        printf("Persons: %d (Default), Tries: %d (Default)\n", persons, tries);
    }
    if(argc==2)
    {
        persons = atoi(argv[1]);
        printf("%d command line argument received!\n", argc - 1);
        printf("Persons: %d, Tries: 10000 (Default)\n", persons);
    }
    if(argc>=3)
    {
        persons = atoi(argv[1]);
        tries = atoi(argv[2]);
        printf("%d command line argument received!\n", argc - 1);
        printf("Persons: %d, Tries: %d\n", persons, tries);
    }

    return 0;
}