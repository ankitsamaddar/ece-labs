## Experiment 3b

# 

**Statement**: Write a Python Code to perform Checksum algorithm using both with error and without error.

### Pseudocode

* Define a function named "add_frames" that takes two parameters "a" and "b" as binary strings and returns a binary string as the sum of the two input binary strings.
* Initialize a variable "l" as the length of binary string "a".
* Convert binary string "a" and "b" to integer by calling "int(a, 2)" and "int(b, 2)" respectively and store them in "in_a" and "in_b".
* Add "in_a" and "in_b" and store the result in "add".
* Convert "add" to a binary string using "bin(add)" and slice the first two characters "0b" from it using "[2:]".
* Define a function named "oneComp" that takes a binary string "s" and returns its one's complement as a binary string.
* Initialize a function named "sender" that takes two parameters "frames" and "flen".
* Set the first frame in "frames" as the variable "a".
* Initialize an empty string variable "ck_data" for storing the checksum data.
* Initialize two empty string variables "s1" and "s2" for storing the two parts of checksum data.
* Loop over the remaining frames in "frames" starting from the second frame:
  a. Assign the value of "a" to a temporary variable "tmp".
  b. Call the "add_frames" function by passing "a" and the current frame as parameters and update the value of "a" to the returned sum.
  c. Print the addition operation and the result.
* Assign "a" to "ck_data".
* Check if the length of "ck_data" is greater than "flen".
  a. If it is, subtract "flen" from the length of "ck_data" and assign the remaining bits to "s2". The remaining bits before "s2" will be assigned to "s1".
* Call the "add_frames" function by passing "s1" and "s2" as parameters and update the value of "ck_data" to the returned sum.
* Check if the length of "ck_data" is less than "flen".
  a. If it is, add "flen" minus the length of "ck_data" number of "0" bits to the beginning of "ck_data".
* Print the "ck_data" and its one's complement.
* Append the "ck_data" to "frames".
* Initialize an empty string variable "send".
* Loop over the "frames" and concatenate each frame to "send".
* Print the final concatenated string "send" as the checksum encoded data being sent to the receiver.
* Return the "frames".
* Define a function named "receiver" that takes two parameters "frames" and "cr" where "cr" is optional with a default value of 0.
* Set the first frame in "frames" as the variable "a".
* Initialize a variable "flen" as the length of binary string "a".
* Loop over the remaining frames in "frames" starting from the second frame:
  a. Assign the value of "a" to a temporary variable "tmp".
  b. Call the "add_frames" function by passing "a" and the current frame as parameters and update the value of "a" to the returned sum.
  c. Print the addition operation and the result.
* Assign "a" to "fr".
* Initialize two empty string variables "s1" and "s2" for storing the two parts of checksum data.
* Check if the length of the calculated frame is less than the frame length (flen), and if so, add leading zeros to make the frame length equal to flen.
* After adding all frames, print the resulting frame (fr).
* Check if the resulting frame (fr) is equal to a string of '1's of the same length as fr. If so, print "Received Without Error!" to indicate that no errors were detected.
* If the resulting frame (fr) is not equal to a string of '1's of the same length as fr, print "Error. Transmit Again!" to indicate that an error was detected.
* Define a main function that prompts the user to input the first binary string and the frame length.
* Check if the length of the first binary string is not divisible by the frame length. If so, add trailing zeros to the string to make it divisible by the frame length.
* Create an empty list called frames.
* Iterate over the first binary string in increments of the frame length and append each subframe to the frames list.
* Print the subframes in the frames list.
* Print "\nSender ->" to indicate that the sender is transmitting data.
* Call the sender function with the frames list and the frame length as arguments, and assign the return value to a variable called checksum_data.
* Print "\nWITHOUT ERROR" to indicate that the data was transmitted without errors.
* Print "\nReceiver ->" to indicate that the receiver is receiving data.
* Call the receiver function with the checksum_data list as an argument, and print the output.
* Print "\nWITH ERROR" to indicate that the receiver is receiving data with errors.
* Call the receiver function with the checksum_data list and cr=1 as arguments, and print the output.
* If the name of the script is " **main** ", call the main function.

### Code

```python
def add_frames(a,b)->str:
    l = len(a)
    # convert a,b to binary integer
    in_a=int(a,2)
    in_b=int(b,2)
    add=in_a+in_b
    return str(bin(add))[2:]


def oneComp(s)->str:
    ans=""
    for bit in s:
        if bit=='0':
            ans+='1'
        else:
            ans+='0'
    return ans
def sender(frames,flen):
    a=frames[0]
    ck_data=''
    sl,s2='',''
    for i in range(1,len(frames)):
        tmp=a
        a=add_frames(a,frames[i])
        print(f"Addition of {tmp}+{frames[i]}={a} ")

    ck_data = a

    if (len(ck_data) > flen):
        extra_bits = len(ck_data)-flen
        s2 = ck_data[extra_bits:]
        s1 = (flen-len(ck_data)) *'0'+ ck_data[:extra_bits]
    ck_data = add_frames(s1, s2)
    if (len(ck_data) < flen):
        ck_data = (flen-len(ck_data)) *'0'+ ck_data
    print(f"After adding all frames: {ck_data}")
    ck_data = oneComp(ck_data)
    print(f"Checksum: {ck_data}")
    frames.append(ck_data)
    send=""
    for frame in frames:
        send += frame
    print(f"Sending Checksum encoded data to Recxever: {send}")
    return frames

def receiver(frames, cr=0):
    a=frames[0]
    flen=len(a)
    for i in range(1, len(frames)):
        tmp=a
        a = add_frames(a, frames[i])
        print(f"Addition of {tmp}+{frames[i]}: {a}")
    fr = a
    s1, s2 ='',''
    if (len(fr) > flen):
        extra_bits = len(fr)-flen
        s2 = fr[extra_bits:]
        s1 = (flen-len(fr))*'0'+fr[: extra_bits]
    fr = add_frames(s1, s2)
    if (len(fr)<flen):
        fr = (flen-len(fr)) *'0'+fr
    # Trigger error
    if cr == 1:
        fr += '101'
    print(f"After adding all frames: {fr}")

    if fr==('1'*len(fr)) :
        print(f"Recieved Without Error!")
    else:
        print("Error. Transmit Again!")

def main():
    data=input("enter the first binary string: ")
    flen=int(input("Enter the length of the frame: "))
    l = len(data)
    diff=l%flen
    if(diff!=0):
        data+='0'*(flen-diff)
    print(f"The data after zero padding is: " ,data)
    frames =[]
    for i in range(0,l,flen):
        frames.append(data[i:i+flen])
    print(f"The subframes are: {frames}")
    print(f"\nSender ->")
    checksum_data = sender(frames,flen)
    print("\nWTTHOUT ERROR")
    print(f"\nfteceiver <-")
    receiver(checksum_data)
    print("\nWITH ERROR")
    print(f"\nReceiver <-" )
    receiver(checksum_data,cr=1)

if __name__ =="__main__":
    main()
```

### Output

```python
enter the first binary string:11101010101111010101011110101
Enter the length of the frame: 8
The data after zero padding is:  11101010101111010101011110101000
The subframes are: ['11101010', '10111101', '01010111', '10101000']

Sender ->
Addition of 11101010+10111101=110100111
Addition of 110100111+01010111=111111110
Addition of 111111110+10101000=1010100110
After adding all frames: 10101000
Checksum: 01010111
Sending Checksum encoded data to Recxever: 1110101010111101010101111010100001010111

WTTHOUT ERROR

fteceiver <-
Addition of 11101010+10111101: 110100111
Addition of 110100111+01010111: 111111110
Addition of 111111110+10101000: 1010100110
Addition of 1010100110+01010111: 1011111101
After adding all frames: 11111111
Recieved Without Error!

WITH ERROR

Receiver <-
Addition of 11101010+10111101: 110100111
Addition of 110100111+01010111: 111111110
Addition of 111111110+10101000: 1010100110
Addition of 1010100110+01010111: 1011111101
After adding all frames: 11111111101
Error. Transmit Again!
```
