## **Experiment 3a**

Write a Python Code to perform Cyclic Redundancy Check using both with error and without error.

---

### Pseudocode

Function - exor

1. Define a function named exor that takes in two arguments, a and b, and returns a string.
2. Calculate the length of the string a and assign the value to the variable frame_len.
3. Create an empty string named result.
4. For each index i in the range of 0 to frame_len, do the following:
   1. If the character at index i in string a is not equal to the character at index i in string b, concatenate '1' to result.
   2. Otherwise, concatenate '0' to result.
5. Return the value of result.

Function - mod2div

1. Define a function named mod2div that takes in two arguments, key and data, and returns a string.
2. Calculate the length of the string data and assign the value to the variable dlen.
3. Calculate the length of the string key and assign the value to the variable klen.
4. Extract a substring of the first klen characters from string data and pass it along with key as arguments to the exor function. Assign the result to the variable rem.
5. For each index i in the range of klen to dlen, do the following:
   a. If the character at index 1 in the string rem is '1', extract a substring from index 1 to the end of rem and concatenate the character at index i from data to the end. Assign the resulting string to the variable k_frame.
   b. If the character at index 1 in the string rem is '0', create a string of klen '0' characters and concatenate the character at index i from data to the end. Assign the resulting string to the variable k_frame.
   c. Pass k_frame and key as arguments to the exor function and assign the result to the variable rem.
6. Return the value of rem.

Function - control

1. Define a function named control that takes in three arguments, data, key, and cr (default value 0) and does not return anything.

2. Concatenate len(key)-1 '0' characters to the end of string data and assign the resulting string to the variable k_data.

3. Pass k_data and key as arguments to the mod2div function and assign the result to the variable rem.

4. Concatenate the original data and the last character of rem to the end of data and assign the resulting string to the variable s_data.

5. If cr is equal to 1, concatenate '110' and the last character of rem to the end of the original data, and assign the resulting string to s_data.

6. Print the following message to the console:
   
   a. "Sender:"
   
   b. "Original data: " followed by the value of data
   
   c. "Key is: " followed by the value of key
   
   d. "Data with zeros added: " followed by the value of k_data
   
   e. "CRC encoded data: " followed by the value of s_data

7. Pass s_data and key as arguments to the mod2div function and assign the result to the variable r_rem.

8. If the integer value of r_rem is equal to 0, print the following message to the console:
   
   a. "Reciever:"
   
   b. "Recieved data: " followed by the value of s_data
   
   c. "Remainder is: " followed by the value of r_rem
   
   d. "Success!!Data Recieved Without Error."

9. If the integer value of r_rem is not equal to 0, print the following message to the console:
   
   a. "Reciever:"
   
   b. "Recieved data: " followed by the value of s_data
   
   c. "Remainder is: " followed by the value of r_rem
   
   d. "Error!! Resend Data"

Function - main

The main function is defined, which does the following:

1. Prints "DATA WITHOUT ERROR".
2. Assigns a value of "1101011011" to data and a value of "10011" to key.
3. Calls the control function with data and key as arguments.
4. Prints "DATA WITH ERROR".
5. Calls the control function with data, key, and cr=1 as arguments.

---

### Code

```python
"""day4.py: Python Program to perform Cyclic Redundancy Check using both with error and without error."""
__author__ = "Ankit Samaddar"

def exor(a, b) -> str:
    frame_len=len(a)
    result=''
    for i in range(frame_len):
        if a[i] != b[i]:
            result+='1'
        else:
            result+='0'
    return result

def mod2div(key,data):
    dlen=len(data)
    klen=len(key)
    rem=exor(key,data[:klen])
    for i in range(klen,dlen):
        if rem[1]=='1':
            k_frame=rem[1:]+data[i]
            rem=exor(key,k_frame)
        elif rem[1]=='0':
            key_0='0'*klen
            k_frame=rem[1:]+data[i]
            rem=exor(key_0,k_frame)
    return rem

def control(data,key,cr=0):
    k_data=data+'0'*(len(key)-1)
    rem=mod2div(key,k_data)
    s_data=data+rem[1:]
    if cr==1: #trigger error
        s_data=data+'110'+rem[1:]
    print(
        f"Sender:\nOriginal data: {data}\nKey is: {key} \nData with zeros added: {k_data} \nCRC encoded data: {s_data}")
    r_rem=mod2div(key,s_data)
    if int(r_rem)==0:
        print(f"\nReciever:\nRecieved data: {s_data}\nRemainder is: {r_rem}\nSuccess!!Data Recieved Without Error.")
    else:
        print(f"\nReciever:\nRecieved data: {s_data}\nRemainder is: {r_rem}\nError!!Resend Data.")

def main():
    print("\nDATA WITHOUT ERROR:")
    data='1101011011'
    key='10011'
    control(data,key)
    print("\nDATA WITH ERROR:")
    control(data, key,cr=1) #cr=1 will trigger error in data


if __name__ == "__main__":
    main()
```

---

### Output

```python-repl
DATA WITHOUT ERROR:
Sender:
Original data: 1101011011
Key is: 10011
Data with zeros added: 11010110110000
CRC encoded data: 11010110111110

Reciever:
Recieved data: 11010110111110
Remainder is: 00000
Success!!Data Recieved Without Error.

DATA WITH ERROR:
Sender:
Original data: 1101011011
Key is: 10011
Data with zeros added: 11010110110000
CRC encoded data: 11010110111101110

Reciever:
Recieved data: 11010110111101110
Remainder is: 01101
Error!!Resend Data.
```

-----
