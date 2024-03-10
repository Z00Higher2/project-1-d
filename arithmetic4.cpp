// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1D

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() 
{
    int correctAnswers = 0;
    string line, leftPart;
    double rightPart;
    vector<pair<string, double>> data;
    srand(time(0)); // Seed the random number generator with the current time

    // Open the CSV file
    ifstream file("problems.csv");
    if (!file.is_open()) 
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Read data from the file
    while (getline(file, line)) 
    {
        stringstream ss(line);
        getline(ss, leftPart, ',');
        ss >> rightPart;
        data.push_back(make_pair(leftPart, rightPart)); // Store the problem and its answer
    }
    file.close(); // Close the file

    int totalQuestions = data.size(); // Total number of questions
    while (!data.empty()) 
    {
        int randIndex = rand() % data.size(); // Select a random index for the next question
        cout << "Problem: " << data[randIndex].first << " = "; // Display the problem
        double userInput;
        cin >> userInput; // Get user's answer
        // Check if the user's answer is correct
        if (abs(userInput - data[randIndex].second) < 0.001) 
        {
            cout << "True" << endl; // Print "True" if correct
            correctAnswers++;
        } 
        else 
        {
            cout << "False" << endl; // Print "False" if incorrect
        }

        // Remove the answered question from the list
        data[randIndex] = data.back();
        data.pop_back();

        // Check if at least 60% of the answers are correct; if so, stop the quiz
        if (static_cast<double>(correctAnswers) / totalQuestions >= 0.6) 
        {
            cout << "Persentage: 60% is correct. " << endl;
            break;
        }
    }

    // Print the final percentage of correct answers
    
    cout << "percent: " << (static_cast<double>(correctAnswers) / totalQuestions) * 100 << "%" << endl;

    return 0;
}
