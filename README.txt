sample input:

test1:
9
add-screen Screen1 12 10 4 5 8 9
add-screen Screen2 20 25 3 4 12 13 17 18
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguoug-seats Screen2 4 10 3

test1/output:
successfully added screen
successfully added screen
successfully reserved 
successfully reserved
failed
1 2 3 4 5 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
4 3 2
4 5 6 7
none

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

test2
15
add-screen Screen1 14 12 5 6 9 10
add-screen Screen2 12 23 3 4 12 13 17 18
add-screen Screen3 20 20 5 6 5 10
add-screen Screen1 12 23 3 4 13 14 18 19
reserve-seat Screen1 4 5 6 7
reserve-seat Screen2 13 6 7 8 9 10
reserve-seat Screen3 4 5 6 7
reserve-seat Screen4 4 6 7 8 9 10
reserve-seat Screen2 13 4 5 6
get-unreserved-seats Screen2 13
get-unreserved-seats Screen1 4
get-unreserved-seats Screen4 13
suggest-contiguous-seats Screen1 3 3 4
suggest-contiguous-seats Screen2 4 12 4
suggest-contiguoug-seats Screen3 4 10 3

test2/output:
successfully added screen
successfully added screen
successfully added screen
failed, same screen already exists
successfully reserved
successfully reserved
successfully reserved
failed, no such screen available
failed
1 2 3 4 5 11 12 13 14 15 16 17 18 19 20 21 22 23
1 2 3 4 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
failed no such screen available
4 3 2
4 5 6 7
none

