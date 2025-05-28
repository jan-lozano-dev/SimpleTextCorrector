# SimpleTextCorrector

A basic spell checker written in C++ that uses word frequency to suggest corrections. Developed for the **Programació 1** course (UPC, Q2 2024/25), it reads a dictionary and a text file, detects misspelled words, and corrects them based on frequency and Levenshtein distance = 1.

## 📌 Description

This program processes a text file and automatically corrects spelling mistakes. It uses a dictionary stored as a Binary Search Tree (BST), where each word has an associated frequency. When an unknown word is encountered, it generates candidate corrections using edit operations and selects the most frequent valid option.

## 🔧 Features

- Dictionary stored as a **Binary Search Tree (BST)**.
- Handles spelling corrections using **Levenshtein distance 1**:
  - Insertion
  - Deletion
  - Substitution
  - Transposition
- Prioritizes corrections by **word frequency**.
- Maintains **original punctuation** and word positions.
- Generates a log of **all corrections** made. (.reg file)

## 📁 Project Structure
:
    - BST (Binary Search Tree) with insert and find optimized recursive functions.
    - ParFreq data type. A pair that contains a string and a frequency. Example: apple 100.
    - Diccionari: object structured as a BST of ParFreq, which contains words and their
      respective frequencies gotten from diccionari.txt file.
    - Corrector: Does checks on input file, changes the text to correct spelling, and creates
      register file with all changes made to the .inp file.

## 📥 Input Files
1. **Dictionary file** (`diccionari.txt`):  
   Format: one word and its frequency per line  
   Example:
   hello 100
   programming 45
   the 1000

2. **Text file** (`input.txt`)
   
## 📤 Output Files
1. **Corrected text file** (`output.txt`)
2. **Register File** (`sample1.reg`)

