# Spoj - CIFRAMG

## Idea

We can reduce the given problem to a range sum query problem and it's possible to ask the queries with a prefix sum array, but we have to optimize the way that we make the updates in that array. 

## Input

Suppose the following input:

**ADD 2 2 2**
**ADD 1 3 5**
**ADD 2 6 1**

The state of the array will be:

0 0 0 0 0 0 0					Initial state
0 0 2 0 0 0 0					ADD 2 2 2
0 5 7 5 0 0 0					ADD 1 3 5
0 5 8 6 1 1 0					ADD 2 6 1

## Solution

If we do this process to update the array, we get an O(n*q) complexity, where q is the number of updates, and it's not enough for the given time. So, what we can do is to use a prefix sum array. 

Using a prefix sum array we don't keep the true value of the current state, but we can recovery it. Given an update [a, b, v], i.e an update from prosition a to position b with value v, we can add v from a until the end of the array, because all the elements will receive this value on the prefix array, but, because we only want to update the array until the position b, so we have to decrease v from position b+1 until the end. 

OK! It doesn't improve the solution, just get worst, because now we do 2*n operations in the same update. But now, we can use a cool trick. Instead of update all the values. Given [a, b, v], we will add v to position a and subtract v from position b+1. Adding v to position a, what we do is to say to the prefix array, all the elements after here needs to receive v. But, how we can't add v to the elements after b, we subtract v from b+1, i.e all positions after b+1 needs to drecreses of v, because the first adding is not valid for it. 

So, now we have something like this

0  0  0  0  0  0  0					Iniial state
0  0  2 -2  0  0  0					ADD 2 2 2         ADD 2 to position 2 and subtract 2 from position 3
0  5  2 -2 -5  0  0 				ADD 1 3 5					ADD 5 to position 1 and subtract 5 from position 4
0  5  3 -2 -5  0 -1					ADD 2 6 1					ADD 1 to position 2 and subtract 1 from position 7

Now, if we have a query of type [a, b], that return the sum of elementes between a and b inclusive, we can do A = [0, a] i.e the sum of the prefix for a, and B = [0, b], and [a, b] = B-A. 

But wait, if we do this for all the queries, the solution is not good. Yes, this solution is only good for a unique query, which is not our case. So, we have to improve the way that we make our queries, and for that, we will use Fenwick Trees, or Binary Indexed Trees (BIT).

Using a BIT, we will get queries in O(log n), and updating in O(log n), and it is enough to the given time.


 
