# CS 3503 Assignment 2 - Data Representation and Mapping

## Author
Haziel Varela

## Description
Advanced data representation functions for Owl Tech's CPU design team.

## What's New
- Direct mapping functions ( oct / hex / bin )
- Signed number representations
- Reused test framework from A1

## Build Instructions
'''bash
gcc -o convert convert.c main.c
./convert
'''

## Test Results
Summary: 51/51 tests passed

## Notes
Useful way to learn fast conversions using bit patterns and how computers store negative numbers. Part 2 was more difficult than Part 1. Had trouble with some oct_to_hex tests but managed to fix the function. Creating main.c was easier since I just had to adjust from main.c of A1.