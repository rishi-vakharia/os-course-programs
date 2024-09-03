#!/bin/sh

# Using AWK – Write a Shell script to: (The input file “employee.txt” will be given)


# Display a given file.
echo "employee.txt file:"
awk '{print;}' employee.txt
echo ""

# Print the lines which match with a given pattern.
awk '/Jason|Sanjay/' employee.txt
echo ""

# Print only a specific field in the file.
echo "Type in the number of the field: "
read num
awk "{print $"$num";}" employee.txt
echo ""

# Format a given file with Name, Designation, Department and Salary headings 
# and at the end of a file print Report Generated.
awk 'BEGIN {print "Name\tDesignation\tDepartment\tSalary";}
{print $2,"\t",$3,"\t",$4,"\t",$NF;}
END{print "\n************************************************";}' employee.txt
echo "\n"

# Find the employees, who have id > 200
awk '$1 >400' employee.txt
echo "\n"

# Find the list of employees in a Technology Department.
awk '$4 ~/Technology/' employee.txt
echo "\n"

# Print the number of employees in Technology Department.
awk 'BEGIN { count=0;}
$4 ~ /Technology/ { count++; }
END { print"No. of employees in Technology department are",count;}' employee.txt
echo "\n"