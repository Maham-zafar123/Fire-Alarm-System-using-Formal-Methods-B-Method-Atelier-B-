# Fire-Alarm-System-using-Formal-Methods-B-Method-Atelier-B-
A formally verified Fire Alarm System modeled using the B-Method in Atelier B, including specification, refinement, implementation, and generated C code.
# 🔥 Fire Alarm System using Formal Methods (B-Method)

## 📌 Overview
This project models a **Fire Alarm System** using **formal methods** with the **B-Method** and **Atelier B**. The system is designed to ensure high reliability and correctness through mathematical specification, refinement, and proof-based verification.

The project demonstrates how safety-critical systems can be formally modeled, verified, and implemented.

---


- **Maham Zafar**

---

## 🎯 Project Objectives
- Model a fire alarm system using formal specifications
- Ensure system correctness using invariants
- Generate and discharge proof obligations
- Refine abstract models into implementation
- Generate executable C code

---

## ⚙️ System Description

The system operates in three states:

- **OFF** → Alarm is inactive  
- **ON** → Alarm is active (fire detected)  
- **TEST** → System is under maintenance/testing  

---

## 🧩 Key Components

### 🔹 Variables
- `alarm_state` → Current state of system  
- `sensor_status` → Detects fire (TRUE/FALSE)  
- `test_mode_enabled` → Indicates test mode  

---

### 🔹 Invariants (System Rules)
- Alarm can only be ON if fire is detected  
- Test mode must be enabled when in TEST state  
- Test mode must be disabled otherwise  

---

## 🔄 Operations

| Operation | Description |
|----------|------------|
| **ActivateAlarm** | Activates alarm when fire is detected |
| **DeactivateAlarm** | Turns alarm OFF manually |
| **UpdateSensorStatus** | Updates fire detection status |
| **EnterTestMode** | Enables maintenance mode |
| **ExitTestMode** | Returns system to normal state |

---

## 🚀 Initialization
Initial system state:
- Alarm OFF  
- No fire detected  
- Test mode disabled  

---

## ✅ Formal Verification

The system was verified using **Atelier B**, ensuring correctness through proof obligations.

- ✔️ Total Proof Obligations: **11**
- ✔️ Successfully Discharged: **11 / 11**

This confirms:
- System invariants are always preserved  
- All operations are logically consistent  
- No invalid state transitions occur  

---

## 🔁 Refinement

The abstract model was refined into a more concrete version:
- Maintains correctness of original model  
- Moves toward implementation-level detail  
- Ensures step-by-step system validation  

---

## 💻 Implementation

The refined model was implemented using:
- Concrete variables  
- Conditional logic (IF statements)  
- Structured operations  

---

## ⚡ Generated C Code

Using Atelier B, the system was automatically translated into **C code**, demonstrating:
- Practical implementation of formal models  
- Real-world applicability of formal verification  

---

## 🛠️ Technologies Used
- **B-Method**
- **Atelier B**
- **C Programming (Auto-generated)**

---

## 📊 Project Significance
This project highlights:
- Reliability of formal methods in safety-critical systems  
- Error-free system design through mathematical proofs  
- Real-world application in alarm and monitoring systems  

---

## 📂 Repository Structure
