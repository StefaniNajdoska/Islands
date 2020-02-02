# Islands Counting

## Task description:

The goal is to count and print the number of islands in the given map. The map consists of a 2 dimensional matrix of 1’s and 0’s, with 1’s representing land, and 0’s representing sea. Continues list of “1” is considered as one island. The correct answer in the example bellow is 4 islands.

## Understanding the problem

Given a binary matrix where 0 represents water and 1 represents land, count the number of islands in it. A island is formed by connected one’s.
``` 
int island[12][10] = {
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	1, 0, 0, 0, 0, 1, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};
```
![Islands example1](https://i0.wp.com/www.techiedelight.com/wp-content/uploads/Number-of-islands-2.png?zoom=2&resize=396%2C356&ssl=1)

Above image highlights water in blue and land in gre in a 10 x 10 matrix. There are total five islands present int the above matrix. They are marked by numbers 1-5 in below image.

![Islands example2](https://i2.wp.com/www.techiedelight.com/wp-content/uploads/Number-of-islands-3.png?zoom=2&resize=393%2C352&ssl=1)


