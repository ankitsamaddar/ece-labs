# Computer Network Lab

## Assignment 1a



### Complete Code:

```py
#Code1 (Convert to function and user input)
def code1():
    print('\nCode1:Assing 2 numbers and perform various mathematical operations')
    a = float(input("enter the first number:"))
    b = float(input("Enter the second number:"))
    print("the sum of the numbers is ",a+b," \nmultipication is ",a*b,"\ndivision is ",a/b," \nsubstraction(b-a) is ",b-a,"\nexponent is ",a**b,"\nmodulus is ",a%b)

#Problem 2: Take 2 user defined string and perform concat operation.
def code2():
    print('\nCode2:Input two strings from the user and perform concatenation')
    a1=input("enter the first string:")
    b1=input("enter the second string:")
    c=a1+b1
    print("the concatenate string is: ",c)

#Problem 3: Input an list of 10 numbers and sort the list using ascending or descending
def code3():
    print('\nCode3:Input a list of 10 numbers and sort the list using ascending or descending')
    a=[]
    print("enter the elements in the array")
    for i in range(0,10) :
        var=int(input("enter number: "))
        a.append(var)
    print("The original array is: ",a)
    #Bubble Sort (Ascending)
    for i in range(10):
        for j in range (i+1,10):
            if(a[i]>a[j]):
                (a[i],a[j])=(a[j],a[i])
    print("the sorted in assending order is: ",a)
    des_a=a
    des_a.reverse()
    print("the sorted in descending order is: ",des_a)
    choice=input('Do you want to continue to code4 [Y/N]: ').lower()
    if (choice=='y'):
        code4(a)

#Problem 4: Take A new list of 5 numbers and add to the list using Insertion Sort ##Insertion Sort
def code4(arr):
    a=arr
    b=[]
    print('Code4:Take a new list of 5 numbers and add to the previous list using Insertion Sort')
    print("Enter five more numbers :")
    for i in range(5):
        new=int(input("enter the no:"))
        b.append(new)
    for i in range(5):
        l=len(bnum_1)
        for j in range(l):
            if(a[j]>b[i] and b[i]<a[j+1]):
                a.insert(j,b[i])
                break
    print('The elements after insertion in sorted list is: ',a)

# Implement Selection Sort,Quick Sort, Merge Sort
def code5():
    print('Code5:Input an array and Implement Selection Sort, Quick Sort or Merge Sort')
    len1=int(input('Enter the length of the array: '))
    arr=[]
    print('Enter the elements in the array')
    for i in range(len1):
        print("element",i+1,':')
        var=int(input())
        arr.append(var)
    print(arr)

    # Quick Sort
    def quicksort(array):
        less = []
        equal = []
        greater = []
        if len(array) > 1:
            pivot = array[0]
            for x in array:
                if x < pivot:
                    less.append(x)
                elif x == pivot:
                    equal.append(x)
                elif x > pivot:
                    greater.append(x)
            return quicksort(less)+equal+quicksort(greater)
        else:
            return array

    #Selection Sort
    def selectionsort(array):
        for i in range(len(array)):
            mini = min(array[i:]) #find minimum element
            min_index = array[i:].index(mini) #find index of minimum element
            array[i + min_index] = array[i] #replace element at min_index with first element
            array[i] = mini                  #replace first element with min element
        return array
    #Merge Sort
    def merge(left,right):
        result=[]
        i,j=0,0
        while i<len(left) and j<len(right):
            if left[i] < right[j]:
                result.append(left[i])
                i+=1
            else:
                result.append(right[j])
                j+=1
        result.extend(left[i:]) # since we want to add each element and not the object list
        result.extend(right[j:])
        return result

    def mergesort(array):
        if len(array)==1:
            return array
        middle=len(array)//2
        left_data=mergesort(array[:middle])
        right_data=mergesort(array[middle:])
        return merge(left_data,right_data)

    #choice
    choice = input('Enter 1 for QuickSort, 2 For SelectionSort and 3 for MergeSort: ')
    if (choice=="1"):
        quicksort(arr)
        print('The array sorted with quicksort is :',quicksort(arr))
    if (choice=="2"):
        print('The array sorted with selectionsort is :',selectionsort(arr))
    if (choice=="3"):
        print('The array sorted with mergesort is :',mergesort(arr))

def code6():
    print('Code6: Find out GCD of Two numbers')
    num1 = int(input("Enter 1st number: "))
    num2 = int(input("Enter 2nd number: "))
    i = 1
    while(i <= num1 and i <= num2):
        if(num1 % i == 0 and num2 % i == 0):
            gcd = i
        i = i + 1
    print("GCD is", gcd)

# def bitwise(bnum_1,bnum_2):

def code7():
    print('Code7:Binary Number operations')
    bnum_1=input("Enter the first binary number:")
    bnum_2=input("Enter the second binary number:")
    # adding zero padding
    diff = len(bnum_1)-len(bnum_2)
    if diff > 0 :
        bnum_2 = '0' * diff + bnum_2
    elif diff < 0 :
        bnum_1 = '0' * (-diff) + bnum_1
    print('The first number is ',bnum_1,' the second number is ',bnum_2)
    choice=input('Enter 1 for Bitwise Operations, 2 for Mathematic Operations: ')
    if choice=='1':
        #AND
        max_len=max(len(bnum_1),len(bnum_2))
        result=''
        for i in range(max_len):
            if bnum_1[i] == "1" and bnum_2[i] =='1':
                result+= "1"
            else:
                result+= "0"
        print('The result after AND operation is: ',result)
        #OR
        result=''
        for i in range(max_len):
            if bnum_1[i] == "1" or bnum_2[i] =='1':
                result+= "1"
            else:
                result+= "0"
        print('The result after OR operation is: ',result)
        #XOR
        result=''
        for i in range(max_len):
            if bnum_1[i] != bnum_2[i]:
                result+= "1"
            else:
                result+= "0"
        print('The result after XOR operation is: ',result)

    if choice=='2':
        #Addition
        def bin_add(bnum_1,bnum_2):
            result = ''
            carry= 0
            for i in range(len(bnum_1) -1 , -1, -1):
                x = int(bnum_1[i])
                y = int (bnum_2[i])
                add= x + y + carry
                if add>= 2 :
                    add-= 2
                    carry= 1
                    result= str(add) + result
                else:
                    carry= 0
                    result= str(add) + result
            if carry== 1 :
                result= '1' + result
            return result
        print('The result after Addition operation is: ',bin_add(bnum_1,bnum_2))
        #Substraction
        def bin_sub(bnum_1,bnum_2):
            result = ''
            borrow= 0
            for i in range(len(bnum_1) -1 , -1, -1):
                x = int(bnum_1[i])
                y = int (bnum_2[ i] )
                sub = x -y -borrow
                if sub < 0 :
                    sub += 2
                    borrow= 1
                else:
                    borrow= 0
                    result= str(sub) + result
            return result
        print('The result after Substraction operation is: ',bin_sub(bnum_1,bnum_2))
        #Multiplicatiom
        ans= "0"*len(bnum_1)
        for i in range(len(bnum_1)-1,-1,-1):
            if bnum_2[i]=='0'  :
                temp= "0"*len(bnum_1) + "0"*(len(bnum_1)-1-i)
                temp_ans = "0"+ans
                ans= bin_add(temp,temp_ans)
            else:
                temp= bnum_1+ "0"*(len(bnum_1)-1-i)
                temp_ans = '0'+ans
                ans= bin_add(temp,temp_ans)
        print('The result after Multiplication operation is: ',ans.lstrip('0'))
        #Division
        def binary_compare(a , b):
            for i in range(len(a)):
                if a[i] > b[i]:
                    return 1   # 1 if a > b
                elif a[i] < b[i]:
                    return -1  # -1 if a < b
                return 0 # 0 if a == b
        quotient = ''
        remainder = ''
        if (binary_compare(bnum_1,bnum_2)==-1): # if the first number is smaller than second divide the second with first
            dividend = bnum_2
            divisor = bnum_1
        else:
            dividend = bnum_1
            divisor = bnum_2
        for i in range(len(dividend)):
            remainder+= dividend[i]
            if binary_compare(remainder, divisor) >= 0 :
                remainder= bin_sub(remainder, divisor)
                quotient+= '1'
            else:
                quotient+= '0'
        print('The result after Division operation is: ',"\tQuoitent: ",quotient.lstrip('0'),'\tRemainder: ',remainder)

def main():
    u_in=input("Enter which code to run from 1 to 7 \n Eg: To run Code2 type 2\nEnter your choice: ")
    if (u_in=='1'):
        code1()
    elif (u_in=='2'):
        code2()
    elif(u_in=='3'):
        code3()
    elif(u_in=='4'):
        print('Please start from code3')
        code3()
    elif(u_in=='5'):
        code5()
    elif(u_in=='6'):
        code6()
    elif(u_in=='7'):
        code7()
    else:
        print("Wrong Input!! Try Again !!")
        main()

if __name__=='__main__':
    main()
```

### Output:

**Code1**:

```py
Enter which code to run from 1 to 7
 Eg: To run Code2 type 2
Enter your choice: 1

Code1:Assing 2 numbers and perform various mathematical operations
enter the first number:32
Enter the second number:6
the sum of the numbers is  38.0
multipication is  192.0
division is  5.333333333333333
substraction(b-a) is  -26.0
exponent is  1073741824.0
modulus is  2.0
```

**Code2**:

```py
Enter your choice: 2

Code2:Input two strings from the user and perform concatenation
enter the first string:Hello
enter the second string:Ankit
the concatenate string is:  Hello Ankit
```

**Code3** & **Code4**:

```py
Enter your choice: 3

Code3:Input a list of 10 numbers and sort the list using ascending or descending
enter the elements in the array
enter number: 78
enter number: 41
enter number: 1
enter number: 32
enter number: 7
enter number: 98
enter number: 14
enter number: 3
enter number: 24
enter number: 64
The original array is:  [78, 41, 1, 32, 7, 98, 14, 3, 24, 64]
the sorted in assending order is:  [1, 3, 7, 14, 24, 32, 41, 64, 78, 98]
the sorted in descending order is:  [98, 78, 64, 41, 32, 24, 14, 7, 3, 1]
Do you want to continue to code4 [Y/N]: y
Code4:Take a new list of 5 numbers and add to the previous list using Insertion Sort
Enter five more numbers :
enter the no:6
enter the no:87
enter the no:5
enter the no:2
enter the no:8
The elements after insertion in sorted list is:  [1, 2, 3, 5, 6, 7, 8, 14, 24, 32, 41, 64, 78, 98]
```

**Code5**:

```py
Enter your choice: 5
Code5:Input an array and Implement Selection Sort, Quick Sort or Merge Sort
Enter the length of the array: 5
Enter the elements in the array
element 1 :
35
element 2 :
1
element 3 :
64
element 4 :
5
element 5 :
32
[35, 1, 64, 5, 32]
Enter 1 for QuickSort, 2 For SelectionSort and 3 for MergeSort: 2
The array sorted with selectionsort is : [1, 5, 32, 35, 64]
```

**Code6**:

```py
Enter your choice: 6
Code6: Find out GCD of Two numbers
Enter 1st number: 25
Enter 2nd number: 5
GCD is 5
```

**Code7.1**:

```py
Enter your choice: 7
Code7:Binary Number operations
Enter the first binary number:000111
Enter the second binary number:010
The first number is  000111  the second number is  000010
Enter 1 for Bitwise Operations, 2 for Mathematic Operations: 1
The result after AND operation is:  000010
The result after OR operation is:  000111
The result after XOR operation is:  000101
```

**Code7.2**:

```py
Enter your choice: 7
Code7:Binary Number operations
Enter the first binary number:000111
Enter the second binary number:010
The first number is  000111  the second number is  000010
Enter 1 for Bitwise Operations, 2 for Mathematic Operations: 2
The result after Addition operation is:  001001
The result after Substraction operation is:  000101
The result after Multiplication operation is:  1110
The result after Division operation is:         Quoitent:  111111       Remainder:  00001
```
