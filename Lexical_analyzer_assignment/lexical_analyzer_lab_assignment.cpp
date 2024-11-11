#include <bits/stdc++.h>
using namespace std;

vector<pair<int, string>> ans;

bool isValidVariableName(const string &name) {
    if (name.empty() || (!isalpha(name[0]) && name[0] != '_')) {
        return false;
    }
    for (char c : name) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

bool isValidFunctionName(const string &name) {
    if (name.empty() || (!isalpha(name[0]) && name[0] != '_')) {
        return false;
    }
    for (char c : name) {
        if (!isalnum(c) && c != '_' && c != '(' && c != ')') {
            return false;
        }
    }
    return true;
}

bool isAllDigits(const string &str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

bool containsArithmeticOperator(const string &str) {
    string operators = "+-*/%";
    for (char c : str) {
        if (operators.find(c) != string::npos) {
            return true;
        }
    }
    return false;
}

void process(int lineNo, const string &s) {
    string temp;
    istringstream iss(s);
    while (iss >> temp) {
        // Handle different constructs based on the current token
        if (temp == "#include") {
            ans.push_back({lineNo, "Header File Declaration."});
            continue;
        }
        if (temp == "using") {
            ans.push_back({lineNo, "Namespace Declaration."});
            continue;
        }
        if (temp == "return") {
            ans.push_back({lineNo, "Return Called."});
            continue;
        }

        // Handle data types
        if (temp == "int" || temp == "char" || temp == "string" || temp == "float" || temp == "double") {
            ans.push_back({lineNo, temp + " = Keyword."});
            continue;
        }

        // Handle built-in names
        if (temp == "cin" || temp == "cout" || temp == "<<" || temp == ">>") {
            ans.push_back({lineNo, temp + " = Built-in Name."});
            continue;
        }

        // Handle control flow keywords
        if (temp == "if" || temp == "else") {
            ans.push_back({lineNo, "Condition Declaration."});
            continue;
        }

        // Handle brackets
        if (temp == "{" || temp == "}") {
            ans.push_back({lineNo, '"' + temp + '"' + " = Bracket Sequence."});
            continue;
        }

        // Handle equality operators
        if (temp == "=" || temp == "==" || temp == "!=") {
            ans.push_back({lineNo, '"' + temp + '"' + " = Equality Operator."});
            continue;
        }

        // Check if it's a valid variable or function name
        if (isValidVariableName(temp)) {
            ans.push_back({lineNo, '"' + temp + '"' + " = Valid Variable."});
            continue;
        }
        else if (isValidFunctionName(temp)) {
            ans.push_back({lineNo, '"' + temp + '"' + " = Valid Function Name."});
            continue;
        }
        else if (isAllDigits(temp)) {
            ans.push_back({lineNo, '"' + temp + '"' + " = Constant."});
            continue;
        }
        else if (containsArithmeticOperator(temp)) {
            ans.push_back({lineNo, '"' + temp + '"' + " = Arithmetic Operator."});
            continue;
        }

        // If none of the above, mark as invalid
        ans.push_back({lineNo, '"' + temp + '"' + " = Error: Invalid Identifier."});
    }
}

int main() {
    ifstream inFile("input.txt");

    int cnt = 1;
    if (inFile.is_open()) {
        string input;
        while (getline(inFile, input)) {
            process(cnt, input);
            cnt++;
        }
    }

    // Output the results
    for (const auto &it : ans) {
        cout << "Line No: " << it.first << ' ' << it.second << endl;
    }

    inFile.close();
    return 0;
}
