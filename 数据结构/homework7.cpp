/*5.1 Given input {4371,1323,6173,4199,4344,9679,1989} and a hash function h(x) = x(mod 10) show the resulting*/

/*a. seperate chaining hash table*/
solve:
    h(4371) = 1;
    h(1323) = 3;
    h(6173) = 3;
    h(4199) = 9;
    h(4344) = 4;
    h(9679) = 9;
    h(1989) = 9;

/*b. open addressing hash table using linear probing*/
solve:
    4371 mod 10 = 1
    1323 mod 10 = 3 
    6173 mod 10 = 3
        collision: (3 + 1) mod 10 = 4
    4199 mod 10 = 9
    4344 mod 10 = 4
        collision: (4 + 1) mod 10 = 5
    9679 mod 10 = 9
        collision: (9 + 1) mod 10 = 0
    1989 mod 10 = 9
        collision: (9 + 1) mod 10 = 0
        collision: (9 + 2) mod 10 = 1
        collision: (9 + 3) mod 10 = 2
    
/*c. open addressing hash table using quadratic probing*/
solve:
    4371 mod 10 = 1
    1323 mod 10 = 3 
    6173 mod 10 = 3
        collision: (3 + 1^2) mod 10 = 4
    4199 mod 10 = 9
    4344 mod 10 = 4
        collision: (4 + 1^2) mod 10 = 5
    9679 mod 10 = 9
        collision: (9 + 1^2) mod 10 = 0
    1989 mod 10 = 9
        collision: (9 + 1^2) mod 10 = 0
        collision: (9 + 2^2) mod 10 = 3
        collision: (9 + 3^2) mod 10 = 8

/*d. open addressing hash table with second hash function h2(x) = 7 - (x mod 7)*/
solve:  
    4371 mod 10 = 1
    1323 mod 10 = 3 
    6173 mod 10 = 3
        collision: (3 + h2(6173)) mod 10 = 4
    4199 mod 10 = 9
    4344 mod 10 = 4
        collision: (4 + h2(4344)) mod 10 = 7
    9679 mod 10 = 9
        collision: (9 + h2(9679)) mod 10 = 1
        collision: (9 + 2*h2(9679)) mod 10 = 3
        collision: (9 + 2*h2(9679)) mod 10 = 5
    1989 mod 10 = 9
        collision: (9 + h2(1989)) mod 10 = 5
        collision: (9 + 2*h2(1989)) mod 10 = 1
        ...
        collision: (9 + 5*h2(1989)) mod 10 = 9

/*5.2 Show the result of rehashing the hash tables in Exercise 5.1.*/
a:
    0
    1 -> 4371 -> NULL
    2
    3 -> 6173 -> 1323 -> NULL
    4 -> 4344 -> NULL
    5
    6
    7
    8
    9 -> 1989 -> 9679 -> 4199 -> NULL

b:
    0   9679
    1   4371
    2   1989
    3   1323
    4   6173
    5   4344
    6
    7
    8
    9   4199

c:
    0   9679
    1   4371
    2   
    3   1323
    4   6173
    5   4344
    6
    7
    8   1989
    9   4199

d:
    0   
    1   4371
    2   
    3   1323
    4   6173
    5   9679
    6
    7   4344
    8   
    9   4199

/*5.6 What are the advantages and disadvantages of the various collision resolution strategies?*/
Advantages of chain address method
Compared with the open addressing method, the zipper method has the following advantages:
(1) the chain address method is simple to deal with conflicts, and there is no stacking phenomenon, that is, non synonyms will never conflict, so the average search length is short;
(2) because the node space of each linked list in the chain address method is dynamically applied, it is more suitable for the case that the table length cannot be determined before the table is created;
(3) in order to reduce conflicts, the open addressing method requires a smaller loading factor α, so it will waste a lot of space when the node scale is large. In the chain address method, α ≥ 1 can be adopted, and when the nodes are large, the pointer field added in the chain address method can be ignored, so the space is saved;
(4) in the hash table constructed by the chain address method, the operation of deleting nodes is easy to realize. Simply delete the corresponding nodes on the list. For the hash table constructed by the open address method, the delete node can not simply leave the space of the deleted node empty, otherwise, it will cut off the search path of the synonym node which fills in the hash table after it. This is because in all kinds of open address methods, empty address unit (i.e. open address) is the condition of search failure. Therefore, to delete a hash table with open address method, you can only mark the deleted node, but not delete the node.
Disadvantages of chain address method
The disadvantage of the chain address method is that the pointer needs extra space, so when the node size is small, the open address method saves space. If the saved pointer space is used to expand the size of the hash table, the load factor will be smaller, which reduces the conflict in the open address method, so as to improve the average search speed. () ()