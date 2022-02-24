// very famous problem
// the given array denotes the height of the building
// with width of each building as 1
// arr = [6 2 5 4 5 1 6]

// so we have to fins a rectangle having maximum area
// so the logic is, for each element find next smallest element to left and next smallest element to right
// whatever that width is, multyiply it by the hieght (value of the array at that index)
// whatever will be the maximum area, is the answer
// just one thing is ki corner points ko kya value dein, taaki answer therek aaywe
// so problemo is big, but basic, so I aint solving

// for roght we can have extreme as n+1
//  for left we can have as -1
// think about it 

// width will be right - left -1
// area is width *height

