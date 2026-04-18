Word Frequency Search Engine (Hash Table)A C++ based search engine that processes text files to track word frequencies using a custom Hash Table implementation.🚀 Features$O(1)$ Search: Average constant time complexity using hashing.Separate Chaining: Handles collisions via linked lists.Dynamic Rehashing: Resizes automatically when load factor $\alpha > 0.75$.Smart Parsing: Case-insensitive, handles punctuation and apostrophes.Interactive CLI: Query frequencies or delete words (using -word).🛠️ Data StructuresHash Table: Custom implementation with prime number capacities.Collision Handling: Separate Chaining (Linked Lists).💻 How to RunPlace input.txt in the folder.Compile and run:Bashg++ 22l-6819.cpp -o search_engine
./search_engine
🎮 UsagePlaintext> france
"france" appears 59 times.

> -france
"france" has been removed.
