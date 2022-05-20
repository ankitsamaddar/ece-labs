// BUBBLE SORTING
// Store from memory location C020 five consecutive nos to be sorted in ascending order
# BEGIN 9000
	   MVI D,05	// Counter

W:	   LXI H,9050
	   MVI C,05	// Counter

X:	   MOV A,M
	   INX H
	   MOV B,M
	   CMP B  //if (A<B) carry is 1, else (A>B) carry is 0
	   JC Y 
	   JZ Y
	   MOV M,A
	   DCX H
	   MOV M,B
	   INX H

Y:	   DCR C
	   JNZ X
	   DCR D
	   JNZ W
	   HLT
// EXAMPLE 9050 -> BBH,AAH,99H,88H,77H,66H
// ANSWER 9050 -> 66H,77H,88H,99H,AAH,BBH
# ORG 9050
# DB 07H,03H,03H,18H,77H,06H
