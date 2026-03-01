# C-AddressBook: A Persistent CLI Contact Manager

A robust, terminal-based application written in **C** for managing personal contacts. [cite_start]This project demonstrates core low-level programming concepts including **file I/O**, **structs**, and **CRUD logic**. Unlike simple memory-only programs, this tool ensures your data persists across sessions by synchronizing with a local `.csv` database.

---

## ✨ Key Features

* [cite_start]**Persistent Storage:** Automatically saves and loads data from `addressbook.csv`.
* **Comprehensive CRUD Operations:**
    * [cite_start]**Create:** Add new contacts with Name, Phone, and Email.
    * [cite_start]**Read/Search:** Find contacts by Name, Phone Number, or Email address.
    * [cite_start]**Update:** Modify existing contact details (phone and email) selectively.
    * [cite_start]**Delete:** Remove entries based on Name, Phone, or Email.
* [cite_start]**Batch Listing:** View all stored contacts in a clean, formatted list.
* [cite_start]**Data Integrity:** Includes checks for full contact books (100 contact limit) and missing records.

---

## 🛠️ Technical Stack

* [cite_start]**Language:** C (C99/C11).
* **Data Structure:** `struct` based records for organized data handling.
* [cite_start]**Storage Format:** CSV (Comma Separated Values) for easy external viewing and portability.
* **Build Tool:** GNU Make.

---

## 🚀 Getting Started

### Prerequisites
* A C compiler (e.g., `gcc`).
* `make` utility.

### Installation & Execution
1. Clone the repository to your local machine.
2. Open your terminal in the project directory.
3. Build and run the project using the provided Makefile:
   ```bash
   make run
