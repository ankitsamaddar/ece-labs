# Microprocessor and Microcontrollers Lab (EC493)

This folder contains the necessary files for running the programs created during the EC493 Microprocessor and Microcontrollers Lab. The lab focuses on the use of the 8085 microprocessor, a widely used processor in the industry. 

To run the programs in this folder, you will need to have Java installed on your computer. The folder contains the 8085 Compiler, which is used to compile the assembly code written in the 8085 instruction set architecture. The 8085 Compiler is open-source software created by JUBIN MITRA and can be found at https://github.com/8085simulator/8085simulator.

## Running the Programs

To run the programs, follow these steps:

1. Install Java on your computer if you have not already done so.
2. Clone or download this repository to your local machine.
3. Navigate to the root folder of the repository and double-click on the `Run.bat` file. This will launch the 8085 Compiler with the necessary settings and load the default program.
4. To run a different program, navigate to the `user_code` directory and open the desired program in a text editor. Edit the program as needed, and then save the file.
5. Back in the 8085 Compiler, go to the File menu and select "Open." Navigate to the `user_code` directory and select the program you just edited. This will load the program into the Compiler.
6. Click on the "Run" button to execute the program.

## Programs

The `user_code` directory contains the following programs:

- `e1.asm`: A sample program that demonstrates the use of the 8085 instruction set.
- `Prog1-AdditionOf28bitNumbers.asm`: A program that adds two 28-bit numbers.
- `Prog2-SubstractionOf28bitNumbers.asm`: A program that subtracts two 28-bit numbers.
- `Prog3-1'sComplimentOfA8bitNumbers.asm`: A program that finds the 1's complement of an 8-bit number.
- `Prog4-2'sComplimentOfA8bitNumbers.asm`: A program that finds the 2's complement of an 8-bit number.
- `Prog5-AddOf2-8bitNumbers.asm`: A program that adds two 8-bit numbers.
- `Prog5-AddOf2-8bitNumbersWithCarry.asm`: A program that adds two 8-bit numbers with carry.
- `Prog6-LargestOf2Numbers.asm`: A program that finds the largest of two numbers.
- `Prog7-Addtwo16bitNumber.asm`: A program that adds two 16-bit numbers.
- `Prog8-LargestInArray.asm`: A program that finds the largest number in an array.
- `Prog9-Sorting.asm`: A program that sorts an array in ascending order.

The programs listed above were done in class and can be used as a reference for  the programs are run on a real 8085 system using the opcodes at college. 

This setup is not necessary for running the programs here, as the 8085 Compiler handles the opcodes for you.

## About the 8085 Compiler

The 8085 Compiler used in this lab was created by Jubin Mitra and is available on GitHub at [GitHub - 8085simulator/8085simulator](https://github.com/8085simulator/8085simulator). This compiler is used to compile and run the 8085 assembly language programs used in this lab.
