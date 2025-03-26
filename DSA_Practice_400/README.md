Link to DSA Sheet by Shradda Kapra:

https://docs.google.com/spreadsheets/d/1v347oEzuzzUhqrF_sN279QUCjbQGeEvTMSBG0KJwljQ/edit?gid=0#gid=0


TCS NQT 2025 Question:
1. There is an matrix of `M*N`. Return whether sub matrix of `A*B` exist in the matrix such that mean of sum of element is 7.

2. You are given the lower limit, l and upperlimit, u and sorted integer array of size n. Returns the pairs such that element does not occurs in integer array.
Example: 
l = 1
u = 10
n = 1
arr: 5

Output: [1,4][6,10]

My Approach: 
- Create a hashArray of size l-u+1 with false being initial value.
- run the loop over l to u
    - check if current l exists in the array through binary search. if exists then mark it true in hashArray
- initialise t1 as l
- run another loop over hashArray:
    - if curr is true then push the the pair(t1,l+i-1) to the result.