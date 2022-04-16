# suduko_solver
A c++ program to solve a suduko using back tracking within few seconds
Algorithm:-
1)Create a 9 by 9 2d array
2)Check if the position is unassigned or not.
3) Check wheter the current position is safe or not. Like in box,rows,and col in typical suduko games
4) Create a solver function that implements backtracking using recursion method
5) print the grid if solution found
Time complexity: O(9^(n*n))
for every unassigned value there are 9 possible values
Space Complexity: O(n*n). 
To store the output array a matrix is needed
