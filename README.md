# CCTech June 2020 Software Developer Hiring Challenge Solution

Program 1 : Check if the given point lies inside or outside a polygon?
Description : Given a polygon and a point 'p', find if 'p' lies inside the polygon or not. The points lying on the border are considered inside.

	
Write a function that takes two arguments as a input and return True if 'p' lies inside the polygon else False.
Do not use any built-in or library functions. This question is to test you ability to create the required algorithm.
Input 1 : array consisting the coordinates of polygon in 2-D
Input 2 : coordinated of points in 2-D
Output : True if point 'p' lies inside the polygon else False

Example :

Case 1 :

Input -
$ Polygon$ : $ [[1,0], [8,3], [8,8], [1,5]] $
$ P $: $ [3,5] $
Output : True

Case 2 :

input -
$ Polygon $ : $ [[-3,2], [-2,-0.8], [0,1.2], [2.2,0], [2,4.5]]$
$ P $ : $[0,0]$
Output : False

Commands to execute program:
g++ -o poly Polygon.cpp
poly.exe
