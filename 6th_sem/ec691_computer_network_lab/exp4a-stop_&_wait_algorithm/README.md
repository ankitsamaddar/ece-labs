## **Experiment 4a**

**Statement**: Write a Python Code to perform Stop and Wait Algorithm as per explained in the laboratory.

### Pseudocode

1. The function `mod2add` returns the sum of two binary bits modulo 2 after performing an exclusive OR (xor) operation on the corresponding binary digits of each operand.
2. The `sender` function takes a binary string as input and sends it bit by bit to the `receiver` function. It uses the `pos` variable to keep track of the position of the bit being sent.
3. The `receiver` function receives the bit sent by the sender and randomly decides whether to receive it or not. It then sends an acknowledgement back to the sender indicating whether the bit was received or lost.
4. The `main` function prompts the user to input a binary string and then sends it to the `sender` function. It then prints the final received data.
5. Inside the `sender` function, the `pos_r` variable is used to keep track of the position of the received bit, and the `received_data` variable is used to store the bits that were successfully received.
6. Inside the `sender` function, the `pos` variable is used to generate a random position to simulate the transmission error.
7. The `sender` function uses the `i` variable to keep track of the position of the bit being sent.
8. The `while` loop inside the `sender` function continues until all the bits in the binary string have been sent and successfully received.
9. Inside the `sender` function, if the received position `pos_r` matches the sent position `pos`, the bit is considered received successfully, and the next bit is sent. Otherwise, the previous bit is resent.
10. The `max_retry` variable inside the `sender` function is commented out, but it could be used to limit the number of retries in case of too many transmission errors.
11. The `main` function prompts the user to input a binary string using the `input` function. Alternatively, a hardcoded binary string can be used by commenting out the `input` function and using a string literal instead.

### Code

```python
"""Exp4a: Stop & Wait ARQ Protocol"""
__author__ = "Ankit Samaddar"

import random
def mod2add(bit, check_bit):
    return (bit + check_bit) % 2

def sender(data):
    i = 0
    received_data = ``
    max_retry=0
    pos=0
    while i < len(data):
        print("\nSender->")
        bit = data[i]
        print("Sending bit: ", bit)
        pos_r, received_data = receiver(bit, pos, received_data)
        pos = mod2add(pos,1) # next bit position
        if pos == pos_r:  # if successful will send the next bit
            print("\nSender->")
            print(f"Received POS: {pos} for bit:", bit)
            i += 1
        else:
            print("\nSender->")
            print(
                f"ACK Recieved: {pos}\nError in transmission. Resending bit: {bit}")
            if max_retry>10:
                print("Max retry Exceeded. Exiting !!")
                exit()
            max_retry+=1

    return received_data


def receiver(bit, pos_r, received_data): #recieved_data is memory of reciever
    pos_s = pos_r # previous
    pos = random.randint(0, 1) # error if pos != pos_r
    if pos == pos_r:
        received_data += bit
        pos_r = mod2add(pos_r,1)
        print("Bit received successfully!")
    else:
        print("Bit lost. Resending previous bit.")
    return pos_r, received_data


def main():
    data = `1101011011`
    print("Sending data: ", data)
    print("\nFinal Received data: ", sender(data))

if __name__ == "__main__":
    main()
```

### Output

```python
Sending data:  1101011011

Sender->
Sending bit:  1
Bit received successfully!

Sender->
Received POS: 1 for bit: 1

Sender->
Sending bit:  1
Bit received successfully!

Sender->
Received POS: 0 for bit: 1

Sender->
Sending bit:  0
Bit received successfully!

Sender->
Received POS: 1 for bit: 0

Sender->
Sending bit:  1
Bit lost. Resending previous bit.

Sender->
ACK Recieved: 0
Error in transmission. Resending bit: 1

Sender->
Sending bit:  1
Bit lost. Resending previous bit.

Sender->
ACK Recieved: 1
Error in transmission. Resending bit: 1

Sender->
Sending bit:  1
Bit received successfully!

Sender->
Received POS: 0 for bit: 1

Sender->
Sending bit:  0
Bit received successfully!

Sender->
Received POS: 1 for bit: 0

Sender->
Sending bit:  1
Bit lost. Resending previous bit.

Sender->
ACK Recieved: 0
Error in transmission. Resending bit: 1

Sender->
Sending bit:  1
Bit received successfully!

Sender->
Received POS: 1 for bit: 1

Sender->
Sending bit:  1
Bit received successfully!

Sender->
Received POS: 0 for bit: 1

Sender->
Sending bit:  0
Bit lost. Resending previous bit.

Sender->
ACK Recieved: 1
Error in transmission. Resending bit: 0

Sender->
Sending bit:  0
Bit received successfully!

Sender->
Received POS: 0 for bit: 0

Sender->
Sending bit:  1
Bit lost. Resending previous bit.

Sender->
ACK Recieved: 1
Error in transmission. Resending bit: 1

Sender->
Sending bit:  1
Bit received successfully!

Sender->
Received POS: 0 for bit: 1

Sender->
Sending bit:  1
Bit lost. Resending previous bit.

Sender->
ACK Recieved: 1
Error in transmission. Resending bit: 1

Sender->
Sending bit:  1
Bit lost. Resending previous bit.

Sender->
ACK Recieved: 0
Error in transmission. Resending bit: 1

Sender->
Sending bit:  1
Bit received successfully!

Sender->
Received POS: 1 for bit: 1

Final Received data:  1101011011
```
