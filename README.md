
# Health and Nutrition Management System

## Overview

This C++ program is designed to assist users in managing their personal health and nutrition. It provides functionalities for user registration, login, health assessment, and food consumption tracking. The program uses object-oriented principles to organize data and interactions effectively.

## Features

### User Registration and Login

- **User Registration**: Users can register with a username and password. Their credentials are securely stored for future logins in a text file (`user_credentials.txt`).

- **User Login**: Registered users can log in by entering their username and password. The program verifies their credentials against the stored data, providing access upon successful login.

### Personal Health Assessment

- **BMI Calculation**: After logging in, users provide their gender, height (in feet and inches), and weight (in kilograms). The program calculates their Body Mass Index (BMI).

- **Health Rating**: Based on the calculated BMI, the program provides a health rating, categorizing the user's health status as Underweight, Normal, Overweight, or Obese, with associated health risk levels.

### Food Consumption Tracking

- **Food Database**: The program maintains a database of predefined food items, each with nutritional information, including calories, protein, and fat per 100 grams.

- **Daily Food Log**: Users can log their daily food consumption by entering the names of foods they've eaten and the number of servings for each item. The program calculates and displays the total daily calories, protein, and fat intake.

### Object-Oriented Structure

- **Class Hierarchy**: Object-oriented programming principles are used to represent food items, consumed foods, and daily food logs using classes such as `FoodItem`, `ConsumedFood`, and `DailyFoodLog`.

### Security

- **Credential Security**: User credentials are stored securely in a text file (`user_credentials.txt`), and the program checks the entered credentials during login to ensure user privacy.

### User Interaction

- **Console Interface**: The program interacts with users through the console, providing clear prompts for input and displaying results.

## Getting Started

1. Clone or download the repository to your local machine.

2. Compile the code using a C++ compiler. For example, you can use g++:
   ```shell
   g++ -o health_management health_management.cpp
   ```

3. Run the compiled executable:
   ```shell
   ./health_management
   ```

4. Follow the on-screen prompts to register, log in, and utilize the program's features.

## Dependencies

- This program is written in C++ and uses standard libraries. No external dependencies are required.

## Acknowledgments

- This project was created as a demonstration of C++ programming skills and object-oriented design principles.

---

Feel free to customize this README file to include any additional information or specific instructions for your project.
