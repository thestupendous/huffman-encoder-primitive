this project is an implementation of the huffman's algorithm.

What's Huffman's Algorithm
	Huffman's algorithm is used to compress long textual messages by changing
	the binary code of every character used in the text. It provides a table
	containing the mappings of every character to their binary code representations.


Why Huffman's Algorithm
	If we type a text and send it to someone, each character occupies 8 bits.
	So, the total hardware space used by the message becomes 8 times the length of
	the message (in bits). A better way can be found by realising that our message
	may not contain all the characters that are available in an 8-bit representation.
	We don't want to waste bits on characters that we don't need. For this, we can
	just find out the number of different characters that are present in our message.
	Then,


The Algorithm


More than just a mere project, it is a memorandum of my learning process.
This project contains more than just project related files. It also includes 
the files that I created to understand the concepts that are required to
complete this project. For example, the merge sort function does a stable sort.
A quick sort, however, does not. For the implementation of Huffman's algorithm,
I prefer merge sort. But still I included files for quick sort. I even added
programs that prove the difference between a stable and unstable sort.

