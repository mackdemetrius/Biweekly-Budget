// Initialize an array to store expenses
let expenses = [];
let income = 0;

// Add expense button handler
document.getElementById("addExpenseBtn").onclick = function() {
    const category = document.getElementById("category").value;
    const amount = parseFloat(document.getElementById("amount").value);

    // Validate inputs
    if (category && !isNaN(amount) && amount > 0) {
        expenses.push({ category, amount });
        updateExpenseList();
        document.getElementById("category").value = ''; // Reset category input
        document.getElementById("amount").value = ''; // Reset amount input
    } else {
        alert("Please enter valid expense details.");
    }
};

// Calculate remaining funds button handler
document.getElementById("calculateBtn").onclick = function() {
    income = parseFloat(document.getElementById("income").value);
    if (isNaN(income) || income <= 0) {
        alert("Please enter a valid income.");
        return;
    }

    // Calculate total expenses
    let totalExpenses = 0;
    expenses.forEach(exp => totalExpenses += exp.amount);

    // Calculate remaining balance
    const remaining = income - totalExpenses;
    document.getElementById("result").textContent = `Remaining Funds: $${remaining.toFixed(2)}`;
};

// Function to update the displayed list of expenses
function updateExpenseList() {
    const list = document.getElementById("expenseList");
    list.innerHTML = ''; // Clear the list

    expenses.forEach(exp => {
        const li = document.createElement("li");
        li.textContent = `${exp.category}: $${exp.amount}`;
        list.appendChild(li);
    });
}
