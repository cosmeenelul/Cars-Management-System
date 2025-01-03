# Cars-Management-System
This project wrote in C Language is based on memory management using HEAP memory allocation 

# RO LANGUAGE 

# Sistem de Management al Mașinilor

## Descriere
**Sistemul de Management al Mașinilor** este o aplicație bazată pe consolă, scrisă în C. Aceasta facilitează gestionarea unei baze de date cu mașini, permițind operații precum vânzarea, adăugarea și reciclarea ("rabla") mașinilor. Sistemul este conceput pentru a fi compatibil cu programul RABLA din România, permițind utilizatorilor să gestioneze eficient procesele de proprietate și reciclare a mașinilor.

## Funcționalități

### Funcții principale
1. **Adăugare Mașină**
   - Adaugă dinamic o nouă mașină în sistem.
   - Captură detalii despre mașină precum marca, numărul de înmatriculare, anul fabricației și informații despre proprietar.

2. **Vânzare Mașină**
   - Actualizează numărul de înmatriculare al mașinii pe baza codului județului noului proprietar.
   - Incrementează numărul de proprietari anteriori.
   - Actualizează formatul numărului de înmatriculare astfel:
     - Prefixul devine codul județului noului proprietar.
     - Cifrele sunt incrementate cu 1.
     - Literele sunt mutate la următoarele din alfabet.

3. **Reciclare Mașină (Rabla)**
   - Resetează detaliile despre proprietar.
   - Setează numărul de proprietari la zero.
   - Golește numărul de înmatriculare.

### Formatul de intrare
- Intrarea începe cu numărul de mașini de inițializat.
- Comenzile includ:
  - `sell <car_license_plate> <new_owner_firstname> <new_owner_lastname> <new_owner_county>`
  - `add <car_brand> <car_license_plate> <year> <owner_firstName> <owner_lastName> <owner_county>`
  - `rabla <car_license_plate>`

### Ieșire
- Afișează detalii despre mașină, inclusiv marca, numărul de înmatriculare și numărul de proprietari anteriori pentru fiecare mașină care nu a fost reciclată.

## Instalare
1. Clonează acest repository:
   ```bash
   git clone https://github.com/yourusername/Car-Management-System.git
   ```
2. Navighează în directorul proiectului:
   ```bash
   cd Car-Management-System
   ```
3. Compilează programul folosind `gcc` sau orice compilator C:
   ```bash
   gcc -o car_management main.c
   ```
4. Rulează programul compilat:
   ```bash
   ./car_management
   ```

## Utilizare
1. Rulează programul.
2. Introdu numărul inițial de mașini și detaliile acestora.
3. Folosește comenzi precum `sell`, `add` sau `rabla` pentru a modifica baza de date.
4. Vizualizează ieșirea care arată starea fiecărei mașini.

## Exemplu
### Intrare:
```plaintext
2
Dacia B123ABC 2015 John Doe BZ 1
Renault C456DEF 2018 Jane Smith CJ 2
sell B123ABC Alice Brown TM
add Tesla T789GHI 2021 Elon Musk US
rabla C456DEF
```

### Ieșire:
```plaintext
Mașina Dacia cu nr. înmatriculare TM234BCD a avut 2 proprietari.
Mașina Tesla cu nr. înmatriculare US890HIJ a avut 0 proprietari.
```

---

# EN LANGUAGE
# Cars Management System

## Description
The **Car Management System** is a console-based application written in C. It facilitates the management of a car database by supporting various operations such as selling, adding, and recycling ("rabla") cars. The system is designed to be compatible with the Romanian RABLA program, allowing users to handle car ownership and recycling processes efficiently.

## Features

### Core Functionalities
1. **Add a Car**
   - Dynamically adds a new car to the system.
   - Captures car details such as brand, license plate, year of fabrication, and owner information.

2. **Sell a Car**
   - Updates the car’s license plate based on the new owner's county code.
   - Increments the number of previous owners.
   - Updates the license plate format by:
     - Changing the prefix to the new owner's county code.
     - Incrementing digits by 1.
     - Shifting letters to the next in the alphabet.

3. **Recycle a Car (Rabla)**
   - Resets the car’s owner details.
   - Sets the number of owners to zero.
   - Clears the license plate.

### Input Format
- Input begins with the number of cars to initialize.
- Commands include:
  - `sell <car_license_plate> <new_owner_firstname> <new_owner_lastname> <new_owner_county>`
  - `add <car_brand> <car_license_plate> <year> <owner_firstName> <owner_lastName> <owner_county>`
  - `rabla <car_license_plate>`

### Output
- Displays car details including brand, license plate, and the number of previous owners for each car that hasn’t been recycled.

## Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/Car-Management-System.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Car-Management-System
   ```
3. Compile the program using `gcc` or any C compiler:
   ```bash
   gcc -o car_management main.c
   ```
4. Run the compiled program:
   ```bash
   ./car_management
   ```

## Usage
1. Run the program.
2. Provide the initial number of cars and their details.
3. Use commands like `sell`, `add`, or `rabla` to modify the database.
4. View the output showing the status of each car.

## Example
### Input:
```plaintext
2
Dacia B123ABC 2015 John Doe BZ 1
Renault C456DEF 2018 Jane Smith CJ 2
sell B123ABC Alice Brown TM
add Tesla T789GHI 2021 Elon Musk US
rabla C456DEF
```

### Output:
```plaintext
The car Dacia with license plate TM234BCD has had 2 owners.
The car Tesla with license plate US890HIJ has had 0 owners.
```




