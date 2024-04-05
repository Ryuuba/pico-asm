# Arrays
Most programming languages also allow the declaration of arrays of objects, that is, collections of identical components that can be referred to either individually or collectively. In C an array of ten integers can be defined with:

`int A[10];`

With arrays, the array index can be computed at run time. For example, the programmer may specify array element `A[i]`, where `i` is a variable whose value is computed at run time and which may assume any integer value from 0 through 9. Whereas in C the index of the first element in the array always has an index of 0, other programming languages allow more flexibility. In Pascal, for example, array declarations such as:

`A: array [-10..10] of integer`

are permitted. This declaration would result in an array of 21 integers with indices running from -10 to +10.

Accessing array elements presents a more complicated issue because of this need to compute the index at run time, and the possibility that indices may not begin with 0. The general expression for computing the machine address of an array element at run time is given by:

`ElementAddress = BASE + (INDEX - START)*SIZE`

where `BASE` is the starting address of the array, `INDEX` is the index of the desired element, `START` is the starting index of the array, and SIZE is the size of an individual element in bytes. Thus element 5 in the Pascal array declared above would have an address of `A + (5 - (-10))*4 = A + 60`. In C language, `START` value is always zero, then the computing of element address is summarize as follows:

`ElementAddress = BASE + INDEX*SIZE`