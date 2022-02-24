
// given an array
// arr [3 0 0 2 0 4]
// so the values of the array represent the height of the building
// so the question is that in the case of rain, where all the water will get filled
// return the volume (area) of that water

// so we will calculate the height of water above each bulding
// multiply it by 1(the width) and you shall get the area

// so for each building we will find the maximum value to the left and maximum value to the right (not NGL and NGR)
// and height of water above each building would be minimum of max_left and max_right - height of building
// calculating max_left and max_rigt is fairly simple
// no need of stacks
// sum up the heiht of water above each building and you will get thwe answer

// THIS IS NOT A STACK QUESTION!!!
