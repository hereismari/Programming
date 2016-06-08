
# KMP

### Motivational Problem

You have 2 strings *__s__* and *__w__*, of length *__n__* and *__m__* respectively, and you want to know if string *__w__*
is a substring of *__s__*. 
You develop a cool and intuitive algorithm *O(nm)* that runs incredibly fast in your test cases, but when the strings start 
to get bigger... Your code is very slow and ineffective. So you need a better solution, right?

KMP is an algorithm *O(n + m)* (if *__s__* and *__w__* are big strings it makes a loooot of difference) that checks if *__w__*
is a substring of *__s__*.

### How does it works?

The KMP algorith has basically two parts:

  1. Prefix function
  2. String Matching

So, in the Prefix function what the algorithm does is to find in the string *__s__* for each letter (*s[0], s[1], ..., s[n-1]*)
what is the larger prefix of *__w__* possible using only this letter and the ones in the left of it, in other words what
is the biggest prefix of string *s[0:i]* where i is an integer [0, n-1]. So what we have in the end of this funcition is an
array with the 
  

Try to implement it! Doubts? see the *code.cpp* file to see the implementantion in C++ with comments :smile:!

### Other problems that it can solve?
