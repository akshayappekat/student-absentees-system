# Absent Date Checker for College

This C program checks and displays the absent dates of a student, ensuring that it only shows dates when the college is open. It considers weekends and public holidays when filtering out the dates.

## Features

- **Input of Absent Dates**  
  The user is prompted to enter the number of absent dates and then the specific dates in the format `day month year`.

- **Day of the Week Calculation**  
  The program calculates the day of the week for each given absent date using the `mktime` function from the `time.h` library.

- **Holiday Check**  
  The program checks if the date corresponds to any of the following public holidays:
  - **26th January** (Republic Day)
  - **15th August** (Independence Day)
  - **2nd October** (Gandhi Jayanti)

- **Weekend Check**  
  The program ensures that weekends (Saturdays and Sundays) are excluded from the list of absent dates, as these are non-working days for the college.

- **Output**  
  The program outputs only the dates that are not weekends and not public holidays, formatted with the day of the week.

## How It Works

1. The user is asked to input the number of absent dates.
2. For each absent date:
   - The program calculates the day of the week.
   - Checks if the date is a weekend or public holiday.
3. If the date is neither a weekend nor a public holiday, it is displayed with the day of the week.

### Example Output:

## Technical Details

- **Libraries Used**:
  - `stdio.h` for standard input and output operations.
  - `time.h` for date-time calculations.
  
- **Functions**:
  - `isLeapYear()`: Checks if a given year is a leap year.
  - `getDayOfWeek()`: Returns the day of the week for a given date.
  - `isPublicHoliday()`: Checks if a given date is a public holiday (Republic Day, Independence Day, Gandhi Jayanti).

## Improvements for Future Development

- **Input Validation**: Implement input validation for correct date format and range.
- **Support for More Holidays**: Add more national and regional holidays to the list.
- **File Input/Output**: Allow reading dates from a file and outputting the results to a file.
