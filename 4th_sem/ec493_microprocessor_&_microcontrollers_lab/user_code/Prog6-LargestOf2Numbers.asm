// LARGEST OF TWO 8 BIT NUMBERS
# BEGIN 9000H
	   MVI A,96
	   MVI B,A4
	   CMP B
	   JNC AHEAD
	   MOV A,B
	  STA 9060

AHEAD:	   RST 1