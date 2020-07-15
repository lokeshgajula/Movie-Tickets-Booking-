# Movie-Tickets-Booking-
*** this project is solely made as a personal implementation of the problem statement and as a reference to other. This is not ment to be plagiarized.***
a programatic implementation of movie reservation using c.
problem statement:
developing an application following funcionalities.


1)Add a screen
Ability to register a screen
a.screen name
b.number of rows
c.total seats per row
d.list of aisle seats for each row

screen name is the primary identifier.
format for command for adding  a screen
add-screen <screen-name> <number-of-rows> <total-seats-per-row> <space-separated-list-of-aisle-seats>
eg.
 add-screen Screen1 12 10 4 5 8 9
 this-commands registers a screen with same 'Screen1' which has 12 rows with 10 seats each. Seat numbers 4,5 , 8 aand 9 are aisle seats.
 output:
 successfully added - if the request is successful.
 failed  -   if the request fails
 
2)Reserve seats
Ability to  reserve seats in a screen if they are available
format for command for reserving seats
reserve-seats <screen-name> <row-number> <space-separated-list-of-seats-to-be-reserved>
 eg.
 reserve-seat Screen1 4 5 6 7
 This command reserves seats in 'Screen1', row 4 , seats 5,6,and 7 if they are not already reserved.
 output:
 successfully reserved - if the request is successful
 failed - if the request fails.

3)Get unreserved seats for a row
Ability to fetch unreserved seats for a row in a given screen
format for the command for getting unreserved seats
get-unreserved-seats <screen-name> <row-number>
 eg.
 get-unreserved-seats Screen1 4
 this command returns the list of unreserved seats in 'Screen1' in row4.
 output:
 1 2 3 4 8 9 10
 
4)Suggest seats based on user preference
This sommand suggest contiguous seat numbers based on users perference. This functionality should take into account aisle seats as well since that will decide if contiguous seats are possible for the users choice. if no contiugous combinations is possible the response should specify that it is not feasable to fulfull the request. This Format for the command to get seat suggestion.
suggest-contiguous-seats <screen-name> <number-of-seats> <row-number> <choice-of-seat-number>
 eg.
 suggest-contiguous-seats Screen1 3 3 4
 This command returns list of cotiguous seats from row 3 from 'Screen1' either starting or ending with seat number 4. if no such combination exist then response should be 'none'
 output:
 2 3 4
 if no seat combination exists
 none
 
 NOTE: in the code if the array size if less than the test case input there will be some errors. so if you have high no of test cases then you should change the arrays size in the code.
