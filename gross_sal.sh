echo "Enter Basic Salary:"
read basic
da=$((basic))
hra=$((basic * 15 / 100))
gross=$((basic + da + hra))
echo "Gross Salary: $gross"
