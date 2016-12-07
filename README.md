# Adam Ashcraft, Data Structures

# Final Project Report

METRICS CHOSEN 

1. Formatting:
	
	This metric was chosen to analyze the format style of the files. It looked through the lines of code counting the comments, number of lines, and looking for the longest line. Then it calculates the score with one of two formulas depending on if the longest line is longer than 80 characters. 
	
	If the longest line was larger than 80 characters, then it would divide the number of lines by the number of comments, multiply that by 100, and add 30% of the length of the longest line. If the longest line was smaller than 80 characters, then it would divide the number of lines by the number of comments, multiply that by 100, and subtract 30% of the length of the longest line.

2. Level of Nesting:

	I used a Stack object and a counter to keep track of the curly braces that signified a new level of nesting. The counter updates when the depth of the Stack reaches a new high. This counter kept saved the deepest level of nesting in the code. Another counter keeps track of the number of nests in the file. Then the score gets calculated by dividing the deepest level of nesting by the total number of nests and multiplying that by 500.
	
3. File Size (Not finished):

	This metric was going to check the length of the main.cpp file compared to the rest of the files. Now, it just checks the length of every file. It calculates the score by taking the length of the file and dividing it by two.

4. Naming Conventions (Not finished):

	This metric was going to check 10 variables and methods and average their lengths to find out if they were too long or too short. I hadn't worked out the score calculation yet.

5. I did not have the time to implement a fifth metric. I wanted to check for how at risk the program is for being able to be exploited to create a buffer overflow.

ARCHITECTURE OF THE TOOL

The tool would have gone through the given directory and found each .cpp, .c, .hpp, and .h file to be analyzed. Then it would read each line of each of the input files and put them in Vectors of String objects. Then it would analyze the code using the member functions in the metric files outlined above. Then the scores and details would be written to a text file depending on if a brief or verbose report was specified. The scores and output were still in progress.

ANNOTATED ANALYSIS

I was working on the output functionality before it was due. As of now, there is no output that can be produced from my tool.

CONCLUSION

Since the project was not complete when submitted, I did not have all the necessary information to put in the report to make it complete. The report was completed with the final product in mind in regards to the metrics and architecture.
