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
- Generates a log of **all corrections** made.

## 📁 Project Structure

