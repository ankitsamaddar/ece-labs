// LARGEST IN A LIST
# BEGIN 9000H
	   LXI H,9050
	   MVI B,05	// Counter
	   MOV A,M
	   DCR B

A:	   INX H
	   CMP M
	   JNC B
	   MOV A,M

B:	   DCR B
	   JNZ A
	   STA 9060
	   HLT
# ORG 9050
# DB 28H,98H,14H,32H,56H
