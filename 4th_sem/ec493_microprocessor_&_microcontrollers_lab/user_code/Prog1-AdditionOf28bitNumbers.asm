// 8 BIT ADDITION
// Result is stored in 9010
# BEGIN 9000H
	   MVI A,99
	   MVI B,48
	   ADD B
	   STA 9010
	   HLT
// EXAMPLE-> 99+48=E1
