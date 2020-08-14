Author: Richany Nguon
Date: 05 08 2020

Simple Statistic Tool
Statistics tool to print basic information from a data set
Users are able to find a minimum, maximum, mean, and median of a numeric array.

Peer-graded Assignment: Expanded Build System and Memory
Submit by Aug 30, 11:59 PM PDT
Submit your assignment soon
Even though your assignment is due on Aug 30, 11:59 PM PDT, try to submit it 1 or 2 days early if you can. Submitting early gives you a better chance of getting the peer reviews you need in time.
InstructionsMy submissionDiscussions
Description:

In this programming assignment, you will get more experience with Git Version control, write more C-programming code, and integrate your code with your build system. You will reuse your version control repository and add some new c-programming functions that manipulate memory. You will test your code on your host machine, but your code should compile for both the target platform and host platform. We will use the target platform in future assignments.

After completing this assignment, you will be able to:

Incorporate a c-program application into your Make and GCC build system
Write c-program functions that manipulate memory
Execute and test your application by simulating it on the host machine
Environment Resources

If you have not already, the VM to develop with is available for download in our supplementary materials. Here is a link to those instructions: https://www.coursera.org/learn/introduction-embedded-systems/resources/jDf20

Version Control and Directory Structureless 
You are going to reuse your repository that you created in the Course 1 Module 1 final assessment. To get the final assessment provided files, download the git repository ese-coursera-assessment.git from github with the following clone link


If you already have this repository cloned to your local machine, be sure to do a git fetch to pull down the latest changes.


Complete the following steps to get started:

Open your repository.
Create a directory called course1.
Copy your stats code you worked on in Course 1 Module 1
Copy over your build system that you created in Course 1 Module 2.
Create any new files (as necessary).
Make your first commit here for your altered repository directory structure.
$ git commit -m “Reconfiguring repository for Course 1 Final Assessment”

Your source tree should look like the following:


File Requirements

For this part you will add some new files and new code to some existing files. You will be building off of your previous work from this course including using your build system from module 2. All code provided must be your own work. You may move your makefiles or add multiple makefiles if you choose to do so. You may not use any online example code or pre-written code.

main.c

Your main function will be very simple. You will just need to call a function that is defined in the course1.c source file. However, you need to use a compile time switch to wrap this function to call. This way we can have a simple main() function that can switch which course deliverable we wish to call by specifying the -DCOURSE1 compile time switch.


stats.c/stats.h

You need to modify your print_array() function in stats.c so that you can enable/disable debug printing with a compile time switch. This compile time switch should be enabled with a VERBOSE flag in the makefile ( -DVERBOSE ). If enabled, the print_array function should print as normal. If not defined, nothing should print. Additionally, you need to modify your use of printf to use the PRINTF macro defined in platform.h

memory.c/memory.h Requirementsless 
This file should already have some basic memory movement options. Now we will add some memory manipulation functions.

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

This function takes two byte pointers (one source and one destination) and a length of bytes to move from the source location to the destination.
The behavior should handle overlap of source and destination. Copy should occur, with no data corruption.
All operations need to be performed using pointer arithmetic, not array indexing
Should return a pointer to the destination (dst).
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

This function takes two byte pointers (one source and one destination) and a length of bytes to copy from the source location to the destination.
The behavior is undefined if there is overlap of source and destination. Copy should still occur, but will likely corrupt your data.
All operations need to be performed using pointer arithmetic, not array indexing
Should return a pointer to the destination (dst).
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

This should take a pointer to a source memory location, a length in bytes and set all locations of that memory to a given value.
All operations need to be performed using pointer arithmetic, not array indexing
Should return a pointer to the source (src).
You should NOT reuse the set_all() function
uint8_t * my_memzero(uint8_t * src, size_t length);

This should take a pointer to a memory location, a length in bytes and zero out all of the memory.
All operations need to be performed using pointer arithmetic, not array indexing
Should return a pointer to the source (src).
You should NOT reuse the clear_all() function
uint8_t * my_reverse(uint8_t * src, size_t length);

This should take a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.
All operations need to be performed using pointer arithmetic, not array indexing
Should return a pointer to the source.
int32_t * reserve_words(size_t length);

This should take number of words to allocate in dynamic memory
All operations need to be performed using pointer arithmetic, not array indexing
Should return a pointer to memory if successful, or a Null Pointer if not successful
void free_words(int32_t * src);

Should free a dynamic memory allocation by providing the pointer src to the function
All operations need to be performed using pointer arithmetic, not array indexing
data.c/data.h Requirementsless 
This file should do some very basic data manipulation.

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)

Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
All operations need to be performed using pointer arithmetic, not array indexing
The number you wish to convert is passed in as a signed 32-bit integer.
You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).
Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
The signed 32-bit number will have a maximum string size (Hint: Think base 2).
You must place a null terminator at the end of the converted c-string
Function should return the length of the converted data (including a negative sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
This function needs to handle signed data.
You may not use any string functions or libraries
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)

ASCII-to-Integer needs to convert data back from an ASCII represented string into an integer type.
All operations need to be performed using pointer arithmetic, not array indexing
The character string to convert is passed in as a uint8_t * pointer (ptr).
The number of digits in your character set is passed in as a uint8_t integer (digits).
You should be able to support bases 2 to 16.
The converted 32-bit signed integer should be returned.
This function needs to handle signed data.
You may not use any string functions or libraries
course1.c/course.h Requirementsless 
These files are new and will hold some final course assessment functions. You will be provided these files from your assessment zip file.

int8_t course1();

For this function you will need to call a handful of functions and test your function outputs. You only need to call each of the following functions once. These include test_data1(), test_data2(), test_memmove1(), test_memmove2(), test_memmove3(), test_memcopy(), test_memset(), and test_reverse().

int8_t test_data1();

This function will test to atoi and itoa conversions for you.

int8_t test_data2();

This function will test to atoi and itoa conversions for you.

int8_t test_memmove1();

This function will test non-overlapped memmove.

int8_t test_memmove2();

This function will test overlapped memmove where there is overlap of the end of destination and start of the source regions.

int8_t test_memmove3();

This function will test overlapped memmove where there is overlap of the start of destination and end of the source regions.

int8_t test_memcopy();

This function will test memcopy.

int8_t test_memset();

This function will test memset and memzero.

iInt8_t test_reverse();

This function will test reverse.

Review criterialess 
Once you complete the assignment, you will submit your code for peer review. The code will be reviewed using the following spreadsheet and then, based on the spreadsheet, the reviewers will grade your work using the provided rubric.

When you are satisfied with your assignment please compress your repository into a zip folder (including your top level repository directory) and upload the zip file onto Coursera. Name the zip file using the following format. Be sure this includes all files including the .git subfolder in the your repository.

Course1-<YOUR_LAST_NAME>.zip