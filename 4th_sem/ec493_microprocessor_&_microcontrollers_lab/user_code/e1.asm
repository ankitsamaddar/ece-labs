     LXI H,A00H
 L1:DCX H
     MOV A,L
     ORA H
     JNZ L1
     RET