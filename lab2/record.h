/**
 * @file record.h
 * @author Liu JiaXing (lsnfzj@gmial.com)
 * @brief This is the header file for the Student2. It 
 * contains the necessary attributes and methods for the 
 * students' score records.
 * @version 0.1
 * @date 2023-03-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <string>
#include <map>

using namespace std;


class StudentRecord {
public:
    /**
     * @brief Construct a new Student Record object
     * 
     */
    StudentRecord();
    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName();
    /**
     * @brief Set the Name object
     * 
     * @param name 
     */
    void setName(string name);
    /**
     * @brief Set the Score object
     * 
     * @param course 
     * @param grade 
     */
    void setScore(const string course, const int grade);
    /**
     * @brief Get the Score object
     * 
     * @param course 
     * @return int 
     */
    int getScore(const string course);
    /**
     * @brief Get the Average object
     * 
     * @return double 
     */
    double getAverage();
    /**
     * @brief Get the Score object
     * 
     * @param index 
     * @return int 
     */
    int  getScore(int index);
    /**
     * @brief Determine whether a student has taken the course 
     * 
     * @param course 
     * @return true 
     * @return false 
     */
    bool isExist(string course);

private:
    string name;
    map<string, int> scores;
};
