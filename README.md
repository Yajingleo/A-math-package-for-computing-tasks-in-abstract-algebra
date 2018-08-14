# Chain-complex-mod-2

Here is a C++ code to compute the homology of chain complexes with Z/2 grading over Z/2. This algorithm is based on 
a cancellation lemma which is special to Z/2 coefficient. The time complexity is linear, which is very efficient compared with 
method using solving linear equations. 

A chain complex is an mathematical object in algebraic topology to define invariants for topological spaces. A chain complex is a chain of linear spaces V_i and a sequence of maps d_i: V_i -> V_(i-1) satisfing d_i composed with d_(i-1) is 0. The homology is a sequence of vector spaces h_i, which is the kernel of d_i modulo the image of d_(i+1).   

The most simplified definition is as follows: a vector space V and a linear map d: V -> V such that d composed with d is 0. The homology is kernel(d)/Image(d). 

In general, computing homology is equivalent to solving linear equations. See the following article for more details
http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.41.2252&rep=rep1&type=pdf

The time complexity using linear algebra such as [Gaussian eliminations](https://jeremykun.com/2013/04/10/computing-homology/) or matrix algebra is usually between O(n^2) and O(n^3). However, using Z/2 coefficients, the time complexity can be reduced to linear. This is what is implemented here. 

