# Train Ticket Booking System (C++)

## About the Project

The Train Ticket Booking System is a console-based application developed using C++. It manages passenger ticket bookings using the Queue data structure from the Standard Template Library (STL).

Passengers are added to a waiting queue, and tickets are booked in the order they arrive, following the FIFO (First In, First Out) principle.

## Features

- Add passengers to the queue.
- Book train tickets for passengers in the queue.
- Check available tickets.
- Display the waiting list.
- View all available train stations.
- Automatically calculate ticket fare based on the number of stops.
- Validate station numbers and prevent identical source and destination stations.

## Technologies Used

- C++
- Standard Template Library (STL)
- Queue
- Structures
- Functions
- Arrays and Strings
- Loops and Conditional Statements

## Available Stations

1. Pune
2. Lonavala
3. Karjat
4. Kalyan
5. Thane
6. Dadar
7. Mumbai
8. Nashik
9. Manmad
10. Nagpur

## Fare Calculation

The fare is calculated based on the number of stops between the source and destination.

- Base fare: Rs. 50
- Additional fare: Rs. 20 per extra stop

**Example:**

For a journey from Pune to Karjat:

- Number of stops = 2
- Fare = 50 + 20 × (2 - 1)
- Total fare = Rs. 70

## How to Run the Project

### Step 1: Clone the Repository

```bash
git clone https://github.com/your-username/train-ticket-booking-system.git
```

### Step 2: Open the Project Folder

```bash
cd train-ticket-booking-system
```

### Step 3: Compile the Program

```bash
g++ main.cpp -o train
```

### Step 4: Run the Program

For Windows:

```bash
train.exe
```

For Linux:

```bash
./train
```

## Main Menu

```text
Train Ticket Booking System

1. Add passenger in queue
2. Book the ticket
3. Availability of tickets
4. Waiting list
5. View stations
6. Exit

Select the operation:
```

## Concepts Used

- **Queue:** Maintains passengers in FIFO order.
- **Structure:** Stores passenger information such as name, source and destination.
- **Functions:** Divides the program into smaller, manageable parts.
- **Arrays:** Stores the available station names.
- **Loops:** Allows users to perform multiple operations.
- **Conditional Statements:** Handles different menu operations and validations.

## Project Objective

The objective of this project is to understand and implement the Queue data structure in C++ through a simple real-world train ticket booking application.

## Project Type

Group Project