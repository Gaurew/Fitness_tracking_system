#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
class Basic_details
{
protected:
    string gender;
    string name;
public:
    int feet;
    int inches;
    int centimeters;
    double kilo;
    double bmi;
    void getname(){
        cout<<"Hey "<<name<<endl;
    }
    void registerUser(string username, string password)
    {
        name = username;
        ofstream outFile("user_credentials.txt", ios::app);
        outFile << name << ":" << password << endl;
        outFile.close();
    }
    bool loginUser(const string &username, const string &password)
    {
        ifstream inFile("user_credentials.txt");
        string storedUsername, storedPassword;
        while (getline(inFile, storedUsername, ':')
         && getline(inFile, storedPassword))
        {
            if (storedUsername == username && storedPassword == password)
            {
                cout << "Login successful!" << endl;
                return true;
            }
        }
        cout << "Login failed. Incorrect username or password." << endl;
        return false;
    }
    void Gender(string s)
    {
        if (s == "M"|| s=="m")
        {
            gender = "Male";
        }
        else if (s =="F" ||s =="f")
        {
            gender = "Female";
        }
    }
    int convertToCentimeters(int feet, int inches)
    {
        feet = feet;
        inches = inches;
        centimeters = (feet * 12 + inches) * 2.54;
    }
    void weight(double kg)
    {
        kilo = kg;
    }
    void BMI()
    {
        double bmi = (kilo) / (pow(((double)(centimeters) / 100), 2));
        cout <<"Your BMI is "<<bmi<<endl;
    }
    void health_rating()
    {
        if (bmi < 18.5)
        {
            cout << "UnderWeight" << endl;
            cout << "Health Risk: Minimal" << endl;
        }
        else if (bmi > 18.5 && bmi < 24.9)
        {
            cout << "Normal" << endl;
            cout << "Health Risk: Minimal" << endl;
        }
        else if (bmi > 25 && bmi < 29.9)
        {
            cout << "Overweight" << endl;
            cout << "Health Risk: Increased" << endl;
        }
        else if (bmi > 30 && bmi < 34.9)
        {
            cout << "Obese" << endl;
            cout << "Health Risk: High" << endl;
        }
    }
};
class FoodItem {
protected:
    string name;
    float calories;
    float protein;
    float fat;
public:
   public:
    FoodItem(){
        name ="";
        calories=0;
        protein=0;
        fat = 0;
    } 
    FoodItem(string name, int calories, int protein, int fat) {
        this->name = name;
        this->calories = calories;
        this->protein = protein;
        this->fat = fat;
    }

    string getName() const {
        return name;
    }

    int getCalories() const {
        return calories;
    }

    int getProtein() const {
        return protein;
    }

    int getFat() const {
        return fat;
    }
};

class ConsumedFood : public FoodItem {
public:
    ConsumedFood() {
        name = "";        
        calories = 0;     
        protein = 0;     
        fat = 0;        
    }

// Parameterized Constructor (Adding food to your plate)
    ConsumedFood(const FoodItem& food, int servings) {
        name = food.getName();                
        calories = food.getCalories() * servings;    
        protein = food.getProtein() * servings;    
        fat = food.getFat() * servings;     
    }
};

class DailyFoodLog {
private:
    static const int MaxFoods = 100;
    ConsumedFood consumed[MaxFoods]; // Array to store consumed foods
    int numFoods;
    int totalCalories;
    int totalProtein;
    int totalFat;

public:
    DailyFoodLog(){
        totalCalories=0;
        totalFat=0;
        totalProtein=0;
        numFoods=0;
    }

    void addFood(const FoodItem& food, int servings) {
        if (numFoods < MaxFoods) {
            consumed[numFoods] = ConsumedFood(food, servings);
            totalCalories += food.getCalories() * servings;
            totalProtein += food.getProtein() * servings;
            totalFat += food.getFat() * servings;
            numFoods++;
        } else {
            cout << "Maximum number of foods reached." << endl;
        }
    }

    void displaySummary() {
        cout << "\nFoods Consumed Today:" << endl;
        for (int i = 0; i < numFoods; ++i) {
            cout << "Name: " << consumed[i].getName() << ", Calories: "
             << consumed[i].getCalories() << ", Protein: " << consumed[i].getProtein()
             << "g, Fat: " << consumed[i].getFat() << "g" << endl;
        }

        cout << "\nTotal Calories Consumed: " << totalCalories << " calories" << endl;
        cout << "Total Protein Consumed: " << totalProtein << " grams" << endl;
        cout << "Total Fat Consumed: " << totalFat << " grams" << endl;
    }
};
int main()
{
    Basic_details bd;
    bd.registerUser("Gaurav","123@gauri");
    string enteredUsername, enteredPassword;
    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    if (bd.loginUser(enteredUsername, enteredPassword)) {
        bd.getname();
        string gender;
        cout<<"Enter M for male or F for female: ";
        cin>>gender;
        bd.Gender(gender);
        int feet;
        cout<<"Enter feet: ";
        cin>>feet;
        int inches;
        cout<<"Enter Inches: ";
        cin>>inches;
        bd.convertToCentimeters(feet,inches);
        double weight;
        cout<<"Enter weight in Kg: ";
        cin>>weight;
        bd.weight(weight);
        bd.BMI();
        bd.health_rating();
        FoodItem oats("oats",372, 14,7);
        FoodItem banana("Banana",89, 1, 0);
        FoodItem egg("Egg",147,14,10);
        FoodItem rice("Rice",173, 5, 2);
        FoodItem paneer("Paneer",265,18.3,20.8);

        DailyFoodLog foodLog;
        cout<<"Nutritional Values are per (100)g "<<endl;

        char more;
        do {
            cout << "Enter the name of the food you ate: ";
            string foodName;
            cin>> foodName;
            int servings;
            cout << "Enter the number of servings: ";
            cin >> servings;

            // Search for the food in the registered food items
            if (foodName == oats.getName()) {
                foodLog.addFood(oats, servings);
            } else if (foodName == banana.getName()) {
                foodLog.addFood(banana, servings);
            } else if (foodName == egg.getName()) {
                foodLog.addFood(egg, servings);
            } else if (foodName == rice.getName()) {
                foodLog.addFood(rice, servings);
            } else if (foodName == paneer.getName()) {
                foodLog.addFood(paneer, servings);
            }
            cout << "Did you eat anything else (Y/N)? ";
            cin >> more;
        } while (more == 'Y' || more == 'y');

        // Display the summary of consumed foods and nutrition
        foodLog.displaySummary();
    } else {
        // Prevent access to other parts of the program
        cout << "Access denied" << endl; 
    }
    return 0;
}