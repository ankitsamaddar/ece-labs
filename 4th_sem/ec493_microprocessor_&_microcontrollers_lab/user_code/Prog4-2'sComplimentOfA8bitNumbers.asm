// 2's COMPLEMENT OF AN 8-BIT NUMBER
// The number to be complemented is stored in 9050
// Answer is stored in 9051
# BEGIN 9000H
	   LDA 9050
	   CMA
	   INR A
	   STA 9051
	   HLT
// EXAMPLE-> 9050=96
// Answer-> 9051=6A

# ORG 9050
# DB 96H
