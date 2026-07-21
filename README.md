# Student Registry System

## Project Description
The Student Registry System is a modular, console-based application developed in C. It is designed to manage academic student records efficiently, tracking essential details such as student IDs, full names, academic majors, Grade Point Average (GPA), and earned credits. The program incorporates built-in file persistence, ensuring that all records are automatically loaded upon startup and safely written to disk when exiting the application.

## How to Compile
You can compile the project using the provided `Makefile` via your terminal:

## Data Structure Design and Why It Was Organized That Way
Custom Student Structure (typedef struct): Groups disparate data types (int id, char name[100], char major[50], float gpa, int credits) into a single logical entity, mimicking real-world object modeling in C.

Global Array & Counter (Student registry[MAX_STUDENTS] and studentCount): Employs a fixed-size array capped at 100 maximum entries, tracked dynamically using an integer count variable.

Rationale: This lightweight approach avoids the overhead of complex dynamic memory pointers for a simple console registry, allowing rapid sequential lookups, straightforward index management, and easy array iteration for display and search operations.

## File Format Chosen (Text vs. Binary) and Why
Format Chosen: Plain Text file (students.dat) utilizing a custom pipe-delimited structure (|).

Rationale: Text-based storage is human-readable, making manual debugging, verification, and inspection of data files trivial if any corruption or parsing bugs occur. Using a delimiter like | rather than whitespace prevents conflicts with multi-word strings (such as full names like "Jane Doe" or majors like "Information Technology") during fprintf and fscanf operations.

## Test Cases Run and Results
Adding Students (Option 1): Tested inserting single and multiple student records. The system properly validated maximum capacity bounds to prevent overflow and successfully saved inputs.

Displaying All Students (Option 2): Verified tabular output alignment. Columns for ID, Name, Major, GPA, and Credits formatted correctly with neat spacing.

Searching and Filtering (Options 3, 4, & 5):

Search by ID: Successfully isolated matching individual records or returned a clean "not found" message.

GPA Threshold: Filtered and listed students meeting or exceeding target GPAs accurately.

Search by Major: Counted and listed all students enrolled in a specified major.

File Persistence (Option 6): Verified that choosing the exit option correctly flushes data to students.dat and that restarting the program seamlessly reloads the exact records back into memory.

## Design Decisions and Challenges Faced
Separation of Concerns: Divided the application into distinct layers—a header file (student_registry.h) for signatures and definitions, an implementation file (student_registry.c) for backend logic, and a driver file (main.c) for the interactive user menu loop. This ensures high code maintainability.

Challenge (C Standard Compatibility): Compatibility warnings arose in older compiler standards (such as C89/C90 used in Dev-C++) when declaring loop counter variables inside for loop headers (e.g., for (int i = 0; ...)). This was successfully resolved by hoisting counter declarations (int i;) to the top of each function scope to guarantee smooth cross-platform compilation.
