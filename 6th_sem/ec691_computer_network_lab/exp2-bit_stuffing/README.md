## Experiment 2

Write a Python Code to perform Bit-Stuffing on an user defined sequence and De-Stuffing on the generated Bit-Stuffed sequence.

### Pseudocode

1. Take input from the user for the data frame and flag.
2. Calculate the length of the flag.
3. Add the flag to the beginning of the data frame.
4. Calculate the length of the new frame.
5. Create an empty list called "l".
6. Perform bit stuffing on the frame:
   a. Initialize a variable "c" to zero.
   b. Iterate over the frame from the length of the flag to the length of the frame.
   c. If the current bit is 1, increment the variable "c". Otherwise, reset it to zero.
   d. If "c" reaches 5, insert a 0 bit after the 5th consecutive 1 bit, and reset "c" to 0.
   e. Add the position of the inserted bit to the list "l".
7. Display the stuffed frame and the positions of the inserted bits.
8. Perform bit de-stuffing on the frame:
   a. Initialize a variable "pos" to 0.
   b. Iterate over the positions in the list "l".
   c. Remove the bit at the position indicated by the current element in the list "l".
   d. Decrement the length of the list "l".
   e. Increment the variable "pos".
9. Display the de-stuffed frame.

### Code(In Python)

```python
frame = input("Enter the data frame(without any flag):")
flag = input("Enter the flag:")

fl_len = len(flag)
frame = flag+frame
fr_len = len(frame)
l = []
print(f"The frame is {frame}")
#Bit-Stuffing
c=0
for i in range(fl_len,fr_len):
    if(frame[i]=='1'):
        c+=1
    else:
        c=0
    if(c==5):
        frame=frame[:i+1]+0+frame[i:]
        c=0
        l.append(i+1)
    else:
        i=i+1

print(f"The stuffed frame is {frame}\n the list is{l}")
#De-Stuffing
pos=0
l_len=len(l)
while(l_len>0):
    frame=frame[:l[pos]-1]+frame[l[pos]+1:]
    l_len-=1
    pos+=1
print(f"The destuffed frame is {frame}")
```

### Output

```python-repl
Enter the data frame(without any flag):10111110111101
Enter the flag:11011
The frame is 1101110111110111101
The stuffed frame is 110111011111010111101
 the list is[12]
The destuffed frame is 1101110111110111101
```
