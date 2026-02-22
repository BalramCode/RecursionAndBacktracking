// 🧠 Universal Recursion + Backtracking Template


void solve(/* input parameters */, vector<int>& path /* or string */, /* other state */) {

    // 1️⃣ BASE CASE → when solution is ready
    if(/* condition when answer is formed */) {
        // print or store answer
        return;
    }

    // 2️⃣ CHOICES → try all possible options
    for(int choice = start; choice < end; choice++) {

        // 3️⃣ CHECK → is this choice valid?
        if(/* isSafe or valid condition */) {

            // 4️⃣ DO → choose
            path.push_back(choice);   // or mark visited / place item

            // 5️⃣ RECUR → go deeper
            solve(/* updated parameters */, path);

            // 6️⃣ UNDO → backtrack
            path.pop_back();  // or unmark visited
        }
    }
}

// 1️⃣ Can I stop? → BASE CASE
// 2️⃣ What choices do I have?
// 3️⃣ Can I choose this? → CHECK
// 4️⃣ Choose
// 5️⃣ Explore
// 6️⃣ Undo

// 👉 STOP → CHOOSE → EXPLORE → UNDO

// 🧩 Template for Decision Problems (True/False)
bool solve(int i, /* state */) {

    if(/* reached goal */)
        return true;

    if(/* invalid */)
        return false;

    // try choices
    if(solve(i+1, /* state */))
        return true;

    if(solve(i+1, /* state */))
        return true;

    return false;
}

// 🧠 How to Identify Which Template to Use

// 🟢 If question says
// 👉 “Print all / Generate all” → Backtracking template

// 🟢 If question says
// 👉 “Count ways” → Return int recursion

// 🟢 If question says
// 👉 “Is possible / exist” → Boolean recursion

// 🟢 If question says
// 👉 “Minimum / Maximum” → recursion + compare



// ⚡ Ultimate Cheat Formula

// 👉 Recursion = Smaller version of same problem

// 👉 Backtracking = Try → Explore → Undo