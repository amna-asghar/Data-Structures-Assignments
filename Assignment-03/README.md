Word Frequency Search Engine (Hash Table)
This assignment implements a search engine to process text files and manage word frequencies using a Custom Hash Table with Separate Chaining.

Overview
The program reads input.txt, counts unique words (case-insensitive), and provides an interactive interface for querying or deleting words.

Key Features
Case-Insensitive: Treats "Word" and "word" as identical.

O(1) Search: Uses a Hash Table for average constant time complexity.

Smart Parsing: Handles punctuation, word boundaries, and internal apostrophes.

Dynamic Deletion: Supports deleting words via the -word prefix.

Data Structures and Logic
Collision Resolution: Separate Chaining (Linked Lists).

Load Factor: Automatically rehashes when load factor exceeds 0.75.

Rehashing: Resizes capacity to the next prime number from a predefined list for optimal distribution.

Methods: Includes put(), get(), contains(), delete(), and size().

How to Run
Place 22l-6819.cpp and input.txt in the same folder.

Compile the code:
g++ 22l-6819.cpp -o search_engine

Run the executable:
./search_engine

Usage Example
Distinct words found: 9852

france
"france" appears 59 times.
-france
"france" has been deleted
