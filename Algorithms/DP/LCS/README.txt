Problem:

Given a sequence of elements, a subsequence of it can be obtained by
removing zero or more elements from the sequence, preserving the relative
order of the elements. 
Note that for a substring, the elements need to be contiguous in a given
string, for a subsequence it need not be. Eg: S1="ABCDEFG" is the given
string. "ACEG", "CDF" are subsequences, where as "AEC" is not. For a string
of lenght n the total number of subsequences is pow(2,n) (Each character can
be taken or not taken).
Now the question is, what is the length of the longest subsequence that is
common to the given two Strings S1 and S2.
Lets denote length of S1 by N and length of S2 by M.
