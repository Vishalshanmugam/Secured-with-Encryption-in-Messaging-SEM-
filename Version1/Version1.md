# 🔐 Secure Terminal Messaging System in C

A lightweight, terminal-based encrypted messaging application written in C. This project demonstrates the fundamentals of symmetric encryption using the XOR cipher with character-level transformations and manual buffer control.

---

## 🧠 Project Summary

This application allows two users to:

- **Encrypt** a message using a shared secret key.
- **Decrypt** the encrypted message using the same key.
- Understand basic symmetric key encryption using character-level XOR operations.

---

## ⚙️ How It Works

The encryption and decryption are handled using a simple XOR cipher:
- Each character of the message is XORed with a character from the key.
- The key loops if it's shorter than the message.
- The process is symmetric: XOR-ing the encrypted message again with the same key decrypts it.

---

## 🖥️ Features

- Menu-based interface for encryption and decryption.
- Input sanitation and memory-safe operations.
- Encrypted output displayed in hexadecimal format.
- Avoids external cryptographic libraries for transparency and learning.

---

## 🚀 Getting Started

### 🔧 Prerequisites

- A C compiler (e.g., `gcc`)
- Linux or Windows terminal

### 🛠️ Compilation

```bash
gcc -o secure_message secure_message.c
