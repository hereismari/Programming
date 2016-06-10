
# KMP

### Motivational Problem

You have 2 strings *__s__* and *__w__*, of length *__n__* and *__m__* respectively, and you want to know if string *__w__*
is a substring of *__s__*. 
You develop a cool and intuitive algorithm *O(nm)* that just shifts the word *__w__* and compare to the substring of *__s__* in that position, this runs incredibly fast in your test cases, but when the strings start 
to get bigger... Your code is very slow and ineffective. So you need a better solution, right?

KMP is an algorithm *O(n + m)* (if *__s__* and *__w__* are big strings it makes a loooot of difference) that checks if *__w__*
is a substring of *__s__*.

### How does it works?

The KMP algorith has basically two parts:

  1. Prefix function
  2. String Matching

"The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst case complexity to *O(n + m)*. KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text (since they matched the pattern characters prior to the mismatch). We take advantage of this information to avoid matching the characters that we know will anyway match."

So, in the Prefix function what we want to do is define an array *__f__* that stores the length of the maximum matching proper prefix which is also a suffix of the sub-pattern *__w[0..i]__*.

Example:

  w = “AAACAAAAAC”, f[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]. 
  Because:
  - "A", is the first letter so f[0] = 0 (this always happens)
  - "AA", the maximum proper prefix which is also a suffix is "A" that has length 1, so f[1] = 1
  - "AAA", the maximum proper prefix wnich is also a suffix is "AA" that has length 2, so f[2] = 2
  - "AAAC", the maximum proper prefix wnich is also a suffix is "" that has length 0, so f[3] = 0
  - "AAACA", the maximum proper prefix wnich is also a suffix is "A" that has length 1, so f[4] = 1
  - "AAACAA", the maximum proper prefix wnich is also a suffix is "AA" that has length 2, so f[5] = 2
  - "AAACAAA", the maximum proper prefix wnich is also a suffix is "AAA" that has length 2, so f[6] = 3
  - "AAACAAAA", the maximum proper prefix wnich is also a suffix is "AAA" that has length 2, so f[7] = 3
  - "AAACAAAA", the maximum proper prefix wnich is also a suffix is "AAA" that has length 2, so f[8] = 3
  - "AAACAAAAC", the maximum proper prefix wnich is also a suffix is "AAAC" that has length 2, so f[9] = 4

Then, the String Matching will consist of comparing *__s__* with *__w__* if a match happens (s[i] == w[j]) then
continue comparing, if j == m it's a reeeal match! if s[i] != w[j], then j = f[j] (if j == 0: i++).

Try to implement it! Doubts? see the *code.cpp* file to see the implementantion in C++ with comments :smile:!

### Other problems that it can solve?

  - (SPOJ : NHAY - KMP)[http://br.spoj.com/problems/NHAY/]
